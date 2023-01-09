// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

/*
 * lcd5110_hal.c
 *
 *  Created on: 2 ñ³÷. 2017
 *      Author: indrekis
 */

#include "lcd5110_ll.h"
#include "lcd5110_hal.h"

//! Int, because it is (presumably) faster, and we do not store pix_coord instances
typedef struct
{
	unsigned int adr;
	unsigned char mask;
} pix_coord;

static inline pix_coord xy_to_pix(int x, int y)
{
	pix_coord res;
	res.adr = (y >> 3) * LCD_WIDTH + x;
	res.mask = (1 << (y & 0x07));

	return res;
}

void LCD5110_clrscr(LCD5110_conf* lcd_conf) {
	for (int i = 0; i < LCD5110_BUFFER_SIZE; ++i) {
		lcd_conf->video_buffer[i] = 0;
	}
}

void LCD5110_fillscr(LCD5110_conf* lcd_conf) {
	for (int i = 0; i < LCD5110_BUFFER_SIZE; ++i) {
		lcd_conf->video_buffer[i] = 0xFF;
	}
}

void LCD5110_putpix(int x, int y, int color, LCD5110_conf* lcd_conf) {
	if ( (x < 0) || (y < 0) || (x > LCD_WIDTH-1) || (y > LCD_HEIGHT-1))
		return;
	pix_coord  c = xy_to_pix(x, y);

	if (color)
		lcd_conf->video_buffer[c.adr] |= c.mask;
	else
		lcd_conf->video_buffer[c.adr] &= ~c.mask;
}

void LCD5110_setpix(int x, int y, LCD5110_conf* lcd_conf) {
	if ((x < 0) || (y < 0) || (x > LCD_WIDTH-1) || (y > LCD_HEIGHT-1))
		return;
	pix_coord  c = xy_to_pix(x, y);

	lcd_conf->video_buffer[c.adr] |= c.mask;
}

void LCD5110_clrpix(int x, int y, LCD5110_conf* lcd_conf) {
	if ((x < 0) || (y < 0) || (x > LCD_WIDTH-1) || (y > LCD_HEIGHT-1))
		return;
	pix_coord  c = xy_to_pix(x, y);

	lcd_conf->video_buffer[c.adr] &= ~c.mask;
}

void LCD5110_invpix(int x, int y, LCD5110_conf* lcd_conf) {
	if ((x < 0) || (y < 0) || (x > LCD_WIDTH-1) || (y > LCD_HEIGHT-1))
		return;
	pix_coord  c = xy_to_pix(x, y);

	lcd_conf->video_buffer[c.adr] ^= c.mask;
}

//! TODO: optimize! Slow!
void LCD5110_fill_region(int x0, int y0, int w, int h, int color, LCD5110_conf* lcd_conf) {
	for (int i = x0; i < x0+w; ++i)
		for (int j = y0; j < y0+h; ++j)
			LCD5110_putpix(i, j, color, lcd_conf);

}

//! TODO: optimize! Slow!
//! TODO: add different bitmap modes -- OR/AND/XOR
void LCD5110_drawBitmap(int x, int y, const unsigned char* bitmap, int cols, int rows, int invert, LCD5110_conf* lcd_conf)
{
	for(int cx=0; cx<cols; cx++)
	{
		for (int cy=0; cy<rows; cy++)
		{
			unsigned char temp = bitmap[(cy/8)*cols + cx];
			temp &= 1<<(cy%8);
			LCD5110_putpix(x+cx, y+cy,  invert ? !temp : temp, lcd_conf);
		}
	}
}
