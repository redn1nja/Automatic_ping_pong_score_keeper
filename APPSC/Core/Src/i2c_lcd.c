/*
 * i2c_lcd.c
 *
 *  Created on: 14 Aug 2019
 *      Author: dit
 */

#include "main.h"
#include "i2c_lcd.h"

// Send byte or nibble to LCD module via PCF8574
uint8_t i2cLcd_SendByte(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t data, uint8_t opts){
	// Opts[0] - R/S select
	// Opts[1] - initialization

	HAL_StatusTypeDef hal_stat;
	uint8_t i2c_frame_data[5];
	uint8_t cmd;
	uint8_t wait_bf;
	uint8_t i2c_frame_size;
	uint8_t n;
	uint8_t lcd_opts;

	// Select between command/data frame
	cmd = opts & I2CLCD_OPTS_RS;

	// Toggle between waiting 1ms or poll Busy Flag
	wait_bf = opts & I2CLCD_OPTS_WAIT_BF;

	// Frame size for I2C communication.
	if (opts & I2CLCD_OPTS_4B) {
		i2c_frame_size = 2;
	}
	else {
		i2c_frame_size = 4;
	}

	// Add final all 1s on the 4 data bits to be able to read BusyFlag after a transaction
	i2c_frame_size += wait_bf;

	lcd_opts = (I2CLCD_RS & cmd) | (I2CLCD_BL & h_i2cLcd->blacklight) | (I2CLCD_E);

	i2c_frame_data[0] = (data & 0xF0) | lcd_opts;
	i2c_frame_data[1] = i2c_frame_data[0] & (~I2CLCD_E);

	i2c_frame_data[2] = ((data << 4) & 0xF0) | lcd_opts;
	i2c_frame_data[3] = i2c_frame_data[2] & (~I2CLCD_E);

	// Preferably remove this
	if(wait_bf)
		i2c_frame_data[i2c_frame_size-1] = i2c_frame_data[i2c_frame_size-2] | 0x80;

	// HAL transmits i2c_frame_data[0],[1], ... , i2c_frame_data[i2c_frame_size-1]
	hal_stat = i2cLcd_I2cWrite(h_i2cLcd, i2c_frame_data, i2c_frame_size);

	//i2cLcd_WaitBusyFlag();
	if (wait_bf) {
		n = 0;
		do {
			hal_stat |= HAL_I2C_Master_Receive(h_i2cLcd->hi2c, h_i2cLcd->i2c_addr, i2c_frame_data,
										1, 10);
			n++;
		} while ( (n < I2CLCD_MAX_BF_POLLS) && (i2c_frame_data[0] & 0x80) );
	}
	else {
		i2cLcd_Delay_ms(1);
	}

	return (uint8_t) hal_stat;

}


uint8_t i2cLcd_ReadByte(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t * data){

	HAL_StatusTypeDef hal_stat;
	uint8_t i2c_frame_data[5];

	uint8_t lcd_opts;

	lcd_opts = (I2CLCD_BL & h_i2cLcd->blacklight) /*| (I2CLCD_E)*/ | (I2CLCD_RW);

	// first need to write 0xF to data bits of PCF, E and R
	i2c_frame_data[0] = (0xF0) | lcd_opts;
	i2c_frame_data[1] = i2c_frame_data[0] | (I2CLCD_E);

	i2c_frame_data[2] = 0;
	i2c_frame_data[3] = 0;

	// HAL receives i2c_frame_data[0],[1], ... , i2c_frame_data[i2c_frame_size-1]
	hal_stat = i2cLcd_I2cWrite(h_i2cLcd, i2c_frame_data, 2);
	hal_stat |= i2cLcd_I2cRead(h_i2cLcd, &i2c_frame_data[2], 1);

	hal_stat |= i2cLcd_I2cWrite(h_i2cLcd, i2c_frame_data, 2);
	hal_stat |= i2cLcd_I2cRead(h_i2cLcd, &i2c_frame_data[3], 1);

	*data = (i2c_frame_data[2] & 0xF0) | ( (i2c_frame_data[3] >> 4) & 0x0F);

	return (uint8_t) hal_stat;
}



uint8_t i2cLcd_SendChar(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t chr){

	return i2cLcd_SendByte(h_i2cLcd, chr, I2CLCD_OPTS_DATA);
}

uint8_t i2cLcd_SendCmd(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t args){

	return i2cLcd_SendByte(h_i2cLcd, args, I2CLCD_OPTS_COMMAND | I2CLCD_OPTS_NOINIT );
}

uint8_t i2cLcd_SendCmd_4b(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t args){

	return i2cLcd_SendByte(h_i2cLcd, args, I2CLCD_OPTS_INIT );
}





uint8_t i2cLcd_WriteCustomChar(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t cgaddr, uint8_t * chardef){
	uint8_t i;
	uint8_t hal_stat;
	uint8_t _addr;

	cgaddr = (cgaddr << 3);
	hal_stat = 0;

	// get the current DDRAM address
	hal_stat |= i2cLcd_GetCursorPosition(h_i2cLcd, &_addr);

	for(i=0; i<8; i++){
		h_i2cLcd->cgram_addr = CGRAM_ADDR | (cgaddr | i);
		hal_stat |= i2cLcd_SendCmd(h_i2cLcd, h_i2cLcd->cgram_addr );

		hal_stat |= i2cLcd_SendChar(h_i2cLcd, chardef[i]);
	}

	// restore DDRAM address such that further writes are in DDRAM section
	hal_stat |= i2cLcd_SetCursorPosition(h_i2cLcd, _addr);

	return hal_stat;
}



uint8_t i2cLcd_EntryIncrEn(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t incr_en){
	if (incr_en) h_i2cLcd->entry_mode_set |=  (DIR_INCR_DECR) ;
	else h_i2cLcd->entry_mode_set &= ~(DIR_INCR_DECR) ;
	return i2cLcd_SendCmd(h_i2cLcd, h_i2cLcd->entry_mode_set );
}

uint8_t i2cLcd_EntryShiftEn(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t shift_en){
	if (shift_en) h_i2cLcd->entry_mode_set |=  (SHIFT) ;
	else h_i2cLcd->entry_mode_set &= ~(SHIFT) ;
	return i2cLcd_SendCmd(h_i2cLcd, h_i2cLcd->entry_mode_set );
}


uint8_t i2cLcd_Shift(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t disp_or_cursor, uint8_t right_left){
	if (disp_or_cursor) h_i2cLcd->cursor_display_shift |= (CD_SHIFT_DSIPLAY) ;
	else h_i2cLcd->cursor_display_shift &= ~(CD_SHIFT_DSIPLAY) ;
	if (right_left) h_i2cLcd->cursor_display_shift |= (CD_SHIFT_RIGHT) ;
	else h_i2cLcd->cursor_display_shift &= ~(CD_SHIFT_RIGHT) ;
	return i2cLcd_SendCmd(h_i2cLcd, h_i2cLcd->cursor_display_shift );
}

uint8_t i2cLcd_Blink(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t blink_en){
	if (blink_en) h_i2cLcd->diplay_ctrl |= DISP_CTRL_BLINK_ON;
	else h_i2cLcd->diplay_ctrl &= ~(DISP_CTRL_BLINK_ON);
	return i2cLcd_SendCmd(h_i2cLcd, h_i2cLcd->diplay_ctrl );
}

uint8_t i2cLcd_Cursor(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t cursor_en){
	if (cursor_en) h_i2cLcd->diplay_ctrl |= (DISP_CTRL_CURSOR_ON);
	else h_i2cLcd->diplay_ctrl &= ~(DISP_CTRL_CURSOR_ON);
	return i2cLcd_SendCmd(h_i2cLcd, h_i2cLcd->diplay_ctrl );
}



uint8_t i2cLcd_Init(i2cLcd_HandleTypeDef * h_i2cLcd){
	uint8_t ret;
	ret = 0;

	h_i2cLcd->function_set = FUNC_SET | FUNC_SET_DLEN_8B;
	h_i2cLcd->blacklight = I2CLCD_BL;
	h_i2cLcd->entry_mode_set = MODE_SET ;
	h_i2cLcd->cursor_display_shift = CD_SHIFT;

	// As per HD44780, if reset timing cannot be generated, initilization should be a sequence
	// of 0x3 writes with specific delays afterwards

	ret |= i2cLcd_SendCmd_4b(h_i2cLcd, h_i2cLcd->function_set);
	i2cLcd_Delay_ms(4);
	ret |= i2cLcd_SendCmd_4b(h_i2cLcd, h_i2cLcd->function_set);
	ret |= i2cLcd_SendCmd_4b(h_i2cLcd, h_i2cLcd->function_set);

	h_i2cLcd->function_set = FUNC_SET | FUNC_SET_DLEN_4B;
	ret |= i2cLcd_SendCmd_4b(h_i2cLcd, h_i2cLcd->function_set);

	h_i2cLcd->function_set = FUNC_SET | FUNC_SET_DLEN_4B | FUNC_SET_LINES_2 | FUNC_SET_FO_5X8;
	ret |= i2cLcd_SendCmd(h_i2cLcd, h_i2cLcd->function_set);

	h_i2cLcd->diplay_ctrl = DISP_CTRL | DISP_CTRL_CURSOR_ON | DISP_CTRL_BLINK_ON | DISP_CTRL_DISPLAY_ON;
	ret |= i2cLcd_SendCmd(h_i2cLcd, h_i2cLcd->diplay_ctrl);

	ret |= i2cLcd_SendCmd(h_i2cLcd, h_i2cLcd->entry_mode_set);

	i2cLcd_ClearDisplay(h_i2cLcd);

	i2cLcd_Delay_ms(5);
	return ret;
}



uint8_t i2cLcd_ClearDisplay(i2cLcd_HandleTypeDef * h_i2cLcd){

	//return i2cLcd_SendByte(h_i2cLcd, CLR_DISPLAY, 0);
	return i2cLcd_SendCmd(h_i2cLcd, CLR_DISPLAY);
}


uint8_t i2cLcd_ReturnHome(i2cLcd_HandleTypeDef * h_i2cLcd){
	return i2cLcd_SendCmd(h_i2cLcd, RET_HOME );
}


uint8_t i2cLcd_SetCursorPosition(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t pos){
	return i2cLcd_SendByte(h_i2cLcd, DDRAM_ADDR | pos, I2CLCD_OPTS_NOINIT);
}

uint8_t i2cLcd_GetCursorPosition(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t * pos){
	uint8_t hal_stat;
	hal_stat = i2cLcd_ReadByte(h_i2cLcd, pos );
	*pos = *pos & 0x7F;
	return hal_stat;
}

uint8_t i2cLcd_CreateHandle(i2cLcd_HandleTypeDef *h_i2cLcd, I2C_HandleTypeDef *h_i2c, uint8_t i2c_slave_addr){

	uint8_t init_state;
	init_state = 0x00; // all inputs of PCF
	// Bind I2C HAL handler
	if (h_i2c == NULL)
		return -1;

	h_i2cLcd->hi2c = h_i2c;

	// Set slave address
	h_i2cLcd->i2c_addr = i2c_slave_addr;

	//return HAL_I2C_Master_Transmit(h_i2cLcd->hi2c, h_i2cLcd->i2c_addr, &init_state, 1, 10);
	return i2cLcd_I2cWrite(h_i2cLcd, &init_state, 1);
}


uint8_t i2cLcd_Backlight(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t backlight){
	if (backlight){
		h_i2cLcd->blacklight = I2CLCD_BL;
	}
	else{
		h_i2cLcd->blacklight = 0;
	}

	return 0;
}



// Low level function wrappers
// Can be

uint8_t i2cLcd_I2cWrite(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t * data, uint8_t len){

	return HAL_I2C_Master_Transmit(h_i2cLcd->hi2c, h_i2cLcd->i2c_addr, data, len, 10);
}

uint8_t i2cLcd_I2cRead(i2cLcd_HandleTypeDef * h_i2cLcd, uint8_t * data, uint8_t len){

	return HAL_I2C_Master_Receive(h_i2cLcd->hi2c, h_i2cLcd->i2c_addr, data, len, 10);
}

uint8_t i2cLcd_Delay_ms(uint32_t delay_ms){
	// Change the delay function call if HAL_ is not available
	HAL_Delay(delay_ms);
	return 0;
}


uint8_t i2cLcd_Delay_us(uint32_t delay_us){
	// Change the delay function call if HAL_ is not available
	// currently it delays a millisecond at minimum
	uint32_t delay_ms;
	delay_ms = (delay_us >> 10); // divide by 1024
	if (delay_ms == 0) delay_ms = 1;

	HAL_Delay(delay_us);
	return 0;
}
