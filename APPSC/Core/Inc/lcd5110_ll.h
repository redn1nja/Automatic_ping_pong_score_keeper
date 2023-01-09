/*
 * lcd5110_ll.h -- LCD 5110 low-level interface.
 *
 * RST		Reset pin for LCD
 * CE		Chip enable for SPI3
 * DC		Data/Command pin
 * DIN		MOSI pin for SPIx
 * CLK		CLOCK pin for SPIx
 * VCC3.3V 	VCC Power
 * LIGHT	GND	If you connect this to GND, backlight is turned on
 * GND		GND	Ground
 *
 * IT is expected, that SPI and all used pins are correctly initialized
 * (for example by cube-generated code, though, can be initialized by
 * any suitable means).
 *
 * SPI Configuration:
 * Frame format -- "Motorola"
 * Data size -- 8 bit
 * First bit -- MSB First
 * Speed -- 4Mbit/s or less (prescaler for 64MHz -- 8 or more)
 * Clock polarity (CPOL) -- Low
 * Clock phase (CPHA) -- 1 Edge
 * (So called mode 00)
 * CRC Calculation -- disabled
 * NSS -- Software.
 *  Created on: 1 ñ³÷. 2017
 *      Author: indrekis
 */

#ifndef APPLICATION_USER_LCD5110_LL_H_
#define APPLICATION_USER_LCD5110_LL_H_

#include <stdbool.h>

#include "spi.h"
#include "gpio.h"

#define BLACK 1
#define WHITE 0

#define LCD_WIDTH 84
#define LCD_HEIGHT 48
#define LCD5110_BUFFER_SIZE (LCD_WIDTH * LCD_HEIGHT/8)

enum LCD5110_errors{LCD5110_OK, LCD5110_bad_opcode, LCD5110_bad_dmode,
					LCD5110_bad_voltage, LCD5110_bad_TC, LCD5110_bad_bias,
					LCD5110_bad_fn_mode,
					LCD5110_bad_coordinate,
					};

#define LCD5110_MODE_SET_MASK (1<<3)
// 0b10D0E,
//     000 --- all off, blank
// 	   100 --- normal mode
// 	   001 --- all on, black
// 	   101 --- inverted mode

typedef enum {LCD5110_NORMAL_MODE    = 4 | LCD5110_MODE_SET_MASK,
				   LCD5110_INVERTED_MODE  = 5 | LCD5110_MODE_SET_MASK,
				   LCD5110_ALL_WHITE_MODE = 0 | LCD5110_MODE_SET_MASK,
				   LCD5110_ALL_BLACK_MODE = 1 | LCD5110_MODE_SET_MASK
				} LCD5110_modes;

typedef struct LCD5110_conf
{
	SPI_HandleTypeDef* spi_handle;

	uint16_t 	  spi_cs_pin;
	GPIO_TypeDef *spi_cs_port;

	uint16_t 	  rst_pin;
	GPIO_TypeDef *rst_port;

	uint16_t 	  dc_pin;
	GPIO_TypeDef *dc_port;

	unsigned char video_buffer[LCD5110_BUFFER_SIZE]; // LCD buffer

} LCD5110_conf;

//! Should be called no later than 50ms after poweron or LCD can be damaged!
int LCD5110_init(LCD5110_conf* 		lcd_conf,
				 LCD5110_modes 		dmode,
				 uint8_t 	  	    voltage,
				 uint8_t		    temp_coeff,
				 uint8_t		    bias
);

//! Send buffer to display
void LCD5110_refresh_ll(LCD5110_conf* lcd_conf);

//! Set voltage is not included -- safety reasons.
int LCD5110_set_mode(LCD5110_modes mode, LCD5110_conf* lcd_conf);
int LCD5110_set_temp_coef(uint8_t TC, LCD5110_conf* lcd_conf);
int LCD5110_set_bias(uint8_t bias, LCD5110_conf* lcd_conf);

#endif /* APPLICATION_USER_LCD5110_LL_H_ */
