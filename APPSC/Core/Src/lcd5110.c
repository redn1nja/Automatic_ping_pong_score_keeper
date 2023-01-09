// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "lcd5110.h"

//#include "stm32f30x.h"
//#include "stm32f30x_rcc.h"
//#include "stm32f30x_gpio.h"
//#include "stm32f30x_spi.h"

#include "font6x8.h"	  // רנטפע

#include <limits.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>

const LCD5110_canvas_t lcd5110_def_scr = {
		{ 0, 0, LCD_WIDTH, LCD_HEIGHT }, //	frame
		{ 0, 0}, 							 // cursor
		1									 // Refresh on endl
};

//! Semantic of C inline differs much from C++ inline.
//! https://stackoverflow.com/questions/6312597/is-inline-without-static-or-extern-ever-useful-in-c99
extern inline void LCD5110_refresh(LCD5110_display* lcd_conf);
extern inline void LCD5110_set_cursor(int x, int y, LCD5110_display* lcd_conf);
extern inline point_t LCD5110_get_cursor(LCD5110_display* lcd_conf);
extern inline inline void LCD5110_clear_scr(LCD5110_display* lcd_conf);
extern inline void LCD5110_clear_win(LCD5110_canvas_t* win, LCD5110_display* lcd_conf);
extern inline void LCD5110_fill_scr(LCD5110_display* lcd_conf);
extern inline void LCD5110_fill_win(LCD5110_canvas_t* win, LCD5110_display* lcd_conf);
extern inline void LCD5110_endl(LCD5110_display* lcd_conf);
extern inline void LCD5110_print(const char* str, int color, LCD5110_display* lcd_conf);

static inline int LCD5110_max(int a, int b) {
	return a > b ? a : b;
}

static inline int LCD5110_min(int a, int b) {
	return a < b ? a : b;
}


#if 0
void LCD5110_line(int x1, int y1, int x2, int y2, int color, LCD5110_display* lcd_conf)
{
	int zn = x1 - x2;
	//float k = (y1-y2)/zn;
	//float b = y1 - k*x1;
	int yb = LCD5110_min(y1, y2);
	int ye = LCD5110_max(y1, y2);
	int xb = LCD5110_min(x1, x2);
	int xe = LCD5110_max(x1, x2);
	if ((ye - yb) < (xe - xb)) {
		for (int i = xb; i <= xe; ++i) {
			int cur_y = (y1 - y2) * (i - x1) / zn + y1;
			LCD5110_putpix(i, cur_y, color, &lcd_conf->hw_conf);
		}
	} else {
		for (int i = yb; i <= ye; ++i) {
			int cur_x = (i - y1) * zn / (y1 - y2) + x1;
			LCD5110_putpix(cur_x, i, color, &lcd_conf->hw_conf);
		}
	}
}
#endif

void LCD5110_wline(int x1, int y1, int x2, int y2, int color,
					LCD5110_canvas_t* win, LCD5110_display* lcd_conf)
{
	x1 += win->frame.x0;
	y1 += win->frame.y0;
	x2 += win->frame.x0;
	y2 += win->frame.y0;

	int zn = x1 - x2;
	//float k = (y1-y2)/zn;
	//float b = y1 - k*x1;
	int yb = LCD5110_min(y1, y2);
	int ye = LCD5110_max(y1, y2);
	int xb = LCD5110_min(x1, x2);
	int xe = LCD5110_max(x1, x2);
	if ((ye - yb) < (xe - xb)) {
		for (int i = xb; i <= xe; ++i) {
			int cury = (y1 - y2) * (i - x1) / zn + y1;
			if( i    >= win->frame.x0 && i    < win->frame.x0 + win->frame.width &&
				cury >= win->frame.y0 && cury < win->frame.y0 + win->frame.height )
			{
				LCD5110_putpix(i, cury, color, &lcd_conf->hw_conf);
			}

		}
	} else {
		for (int i = yb; i <= ye; ++i) {
			int curx = (i - y1) * zn / (y1 - y2) + x1;
			if( curx >= win->frame.x0 && curx < win->frame.x0 + win->frame.width &&
				i    >= win->frame.y0 && i    < win->frame.y0 + win->frame.height )
			{
				LCD5110_putpix(curx, i, color, &lcd_conf->hw_conf);
			}
		}
	}
}

void LCD5110_wrect(rect_t* rect, int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf) {
	LCD5110_wline(rect->x0, 			  rect->y0,
				  rect->x0+rect->width-1, rect->y0, 				 color, win, lcd_conf);
	LCD5110_wline(rect->x0, 			  rect->y0 + rect->height-1,
				  rect->x0+rect->width-1, rect->y0 + rect->height-1, color, win, lcd_conf);
	LCD5110_wline(rect->x0, 			  rect->y0,
				  rect->x0,  			  rect->y0 + rect->height-1, color, win, lcd_conf);
	LCD5110_wline(rect->x0+rect->width-1, rect->y0,
				  rect->x0+rect->width-1, rect->y0 + rect->height-1, color, win, lcd_conf);
}

void LCD5110_rect(rect_t* rect, int color,
		LCD5110_display* lcd_conf) {
	LCD5110_wrect(rect, color, &lcd_conf->def_scr, lcd_conf);
}

void LCD5110_win_draw_frame(int color, LCD5110_canvas_t* win, LCD5110_display* lcd_conf) {
	LCD5110_rect(&win->frame, color, lcd_conf);
}

void LCD5110_rect_fill(rect_t* rect, int color,
		LCD5110_display* lcd_conf) {
	//! Slow!
	for (int i = rect->x0; i < rect->x0+rect->width; ++i)
		for (int j = rect->y0; j < rect->y0+rect->height; ++j)
			LCD5110_putpix(i, j, color, &lcd_conf->hw_conf);
}

void LCD5110_wrect_fill(rect_t* rect, int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf) {
	//! Slow!
	int right = LCD5110_min(rect->x0 + rect->width,  win->frame.width);
	int down =  LCD5110_min(rect->y0 + rect->height, win->frame.height);

	for (int i = win->frame.x0 + rect->x0; i < win->frame.x0 + right - 1; ++i)
		for (int j = win->frame.y0  + rect->y0; j < win->frame.y0 + down - 1; ++j)
			LCD5110_putpix(i, j, color, &lcd_conf->hw_conf);
}

void LCD5110_putchar(int px, int py, char ch, int color, LCD5110_display* lcd_conf) {
	const unsigned char *fontpointer = base_font;
	LCD5110_drawBitmap(px, py, fontpointer + ch * base_font_width,
						base_font_width, base_font_height, !color, &lcd_conf->hw_conf);
}

void LCD5110_wputchar(int px, int py, char ch, int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf) {
	if (win->cursor.y < 0 || win->cursor.x < 0)
		return;
	if ( win->cursor.x + base_font_width > win->frame.width ||
		 win->cursor.y + base_font_height > win->frame.height )
		return;
//! TODO: Print part of char
	const unsigned char *fontpointer = base_font;
	LCD5110_drawBitmap(px + win->frame.x0, py + win->frame.y0, fontpointer + ch * base_font_width,
						base_font_width, base_font_height, !color, &lcd_conf->hw_conf);
}


void LCD5110_putstr(int x, int y, const char str[], int color,
		LCD5110_display* lcd_conf) {
	while (*str != 0) {
		LCD5110_putchar(x, y, *str, color, lcd_conf);
		x = x + base_font_width;
		str++;
	}
}

void LCD5110_wputstr(int x, int y, const char str[], int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf) {
	while (*str != 0) {
		LCD5110_wputchar(x, y, *str, color, win, lcd_conf);
		x = x + base_font_width;
		str++;
	}
}

// http://stackoverflow.com/questions/8257714/how-to-convert-an-int-to-string-in-c

void LCD5110_putint(int val, int x, int y, int base, int color,
		LCD5110_display* lcd_conf) {
	LCD5110_wputint(val, x, y, base, color, &lcd_conf->def_scr, lcd_conf);
}

void LCD5110_wputint(int val, int x, int y, int base, int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf)
{
	const int max_digits = log2(INT_MAX) + 1;
	char buf[max_digits];
	char * itoa(int, char *, int); //! Nonstandard!
	itoa(val, buf, 10);
	LCD5110_wputstr(x, y, buf, color, win, lcd_conf);
}


void LCD5110_clear_char(int x1, int y1, int color, LCD5110_display* lcd_conf){
	//! Stupid
	rect_t rect={x1, y1, x1 + base_font_width, y1 + base_font_height};
	LCD5110_rect_fill(&rect, color, lcd_conf);
}

void LCD5110_wclear_char(int x1, int y1, int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf) {
	//! Stupid
	rect_t rect={x1, y1, x1 + base_font_width, y1 + base_font_height};
	LCD5110_wrect_fill(&rect, color, win, lcd_conf);
}

 void LCD5110_wclear_str(int x, int y, int len, int color,
		 LCD5110_canvas_t* win, LCD5110_display* lcd_conf) {
	for (int i = 0; i<len; ++i)
	{
		LCD5110_wclear_char(x, y, color, win, lcd_conf);
		x = x + base_font_width;
	}
}

 void LCD5110_clear_str(int x, int y, int len, int color, LCD5110_display* lcd_conf)
{
	LCD5110_wclear_str(x, y, len, color, &lcd_conf->def_scr, lcd_conf);
}


void LCD5110_wset_cursor(int x, int y, LCD5110_canvas_t* win, LCD5110_display* lcd_conf)
{
	win->cursor.x = x;
	win->cursor.y = y;
}

point_t LCD5110_wget_cursor(LCD5110_canvas_t* win, LCD5110_display* lcd_conf){
	return win->cursor;
}

void LCD5110_wendl(LCD5110_canvas_t* win, LCD5110_display* lcd_conf) {
	win->cursor.y += base_font_height + 1;
	win->cursor.x = 2;
	if (win->refresh_on_endl)
		LCD5110_refresh(lcd_conf);
}



void LCD5110_wprint(const char* str, int color, LCD5110_canvas_t* win,
		LCD5110_display* lcd_conf) {
	while (*str != 0) {
		if (*str != '\n') {
			LCD5110_wputchar(win->cursor.x, win->cursor.y, *str, color, win, lcd_conf);
		}
		win->cursor.x += base_font_width;

		if (((win->cursor.x + base_font_width > win->frame.width ) &&
				*(str + 1) != '\n') || *str == '\n')
		{
			LCD5110_wendl(win, lcd_conf);
			if( isspace(*(str + 1)) )
				++str;
		}
		if (win->cursor.y + base_font_height > win->frame.height)
			break;
		str++;

	}
}
// http://stackoverflow.com/questions/150543/forward-an-invocation-of-a-variadic-function-in-c
int LCD5110_wprintf(LCD5110_display* lcd_conf, int color, LCD5110_canvas_t* win, char *fmt,
		...) {
	char buf[100];
	int res;

	va_list vargs;
	va_start(vargs, fmt);

	res = vsnprintf(buf, sizeof(buf), fmt, vargs);
	LCD5110_wprint(buf, color, win, lcd_conf);

	if (win->refresh_on_endl)
		LCD5110_refresh(lcd_conf);

	va_end(vargs);

	return res;
}


int LCD5110_printf( LCD5110_display* lcd_conf, int color, char *fmt, ...)
{
	char buf[100];
	int res;

	va_list vargs;
	va_start(vargs, fmt);

	res = vsnprintf(buf, sizeof(buf), fmt, vargs);
	LCD5110_print(buf, color, lcd_conf);

	if (lcd_conf->def_scr.refresh_on_endl)
		LCD5110_refresh(lcd_conf);

	va_end(vargs);

	return res;
}
