#ifndef LCD_NOKIA_5110_H
#define LCD_NOKIA_5110_H

#include <stdint.h>
#include <stdbool.h>

#include "lcd5110_ll.h"
#include "lcd5110_hal.h"
#include "spi.h"
#include "gpio.h"

typedef struct
{
	int16_t x, y;
} point_t;


typedef struct
{
	int16_t x0, y0, width, height;
} rect_t;


typedef struct
{
	rect_t frame;
	point_t cursor;
	bool refresh_on_endl;
} LCD5110_canvas_t;

extern const LCD5110_canvas_t lcd5110_def_scr;

typedef struct
{
	LCD5110_conf	 hw_conf;
	LCD5110_canvas_t def_scr;
} LCD5110_display;


inline void LCD5110_refresh(LCD5110_display* lcd_conf)
{
	LCD5110_refresh_ll(&lcd_conf->hw_conf);
}

void LCD5110_rect(rect_t *rect, int color, LCD5110_display* lcd_conf);
void LCD5110_wrect(rect_t *rect, int color,
					LCD5110_canvas_t* win, LCD5110_display* lcd_conf);

void LCD5110_rect_fill(rect_t* rect, int color, LCD5110_display* lcd_conf);
void LCD5110_wrect_fill(rect_t* rect, int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf);

void LCD5110_win_draw_frame(int color, LCD5110_canvas_t* win, LCD5110_display* lcd_conf);

void LCD5110_putchar(int px, int py, char ch, int color, LCD5110_display* lcd_conf);
void LCD5110_wputchar(int px, int py, char ch, int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf);

void LCD5110_putstr(int x, int y, const char str[], int color,
		LCD5110_display* lcd_conf);
void LCD5110_wputstr(int x, int y, const char str[], int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf);

void LCD5110_putint(int val, int x, int y, int base, int color, LCD5110_display* lcd_conf);
void LCD5110_wputint(int val, int x, int y, int base, int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf);

void LCD5110_clear_char(int x1, int y1, int color, LCD5110_display* lcd_conf);
void LCD5110_wclear_char(int x1, int y1, int color,
		LCD5110_canvas_t* win, LCD5110_display* lcd_conf);
void LCD5110_clear_str(int x, int y, int len, int color, LCD5110_display* lcd_conf);
void LCD5110_wclear_str(int x, int y, int len, int color,
		 LCD5110_canvas_t* win, LCD5110_display* lcd_conf);

void LCD5110_wset_cursor(int x, int y, LCD5110_canvas_t* win, LCD5110_display* lcd_conf);
point_t LCD5110_wget_cursor(LCD5110_canvas_t* win, LCD5110_display* lcd_conf);

// Regarding inline -- C also lcd5110.c.
inline void LCD5110_set_cursor(int x, int y, LCD5110_display* lcd_conf)
{
	LCD5110_wset_cursor(x, y, &lcd_conf->def_scr, lcd_conf);
}
inline point_t LCD5110_get_cursor(LCD5110_display* lcd_conf)
{
	return LCD5110_wget_cursor(&lcd_conf->def_scr, lcd_conf);
}

inline void LCD5110_clear_scr(LCD5110_display* lcd_conf){
	LCD5110_clrscr(&lcd_conf->hw_conf);
	LCD5110_set_cursor(0, 0, lcd_conf);
}
inline void LCD5110_clear_win(LCD5110_canvas_t* win, LCD5110_display* lcd_conf){
	LCD5110_wrect_fill(&win->frame, WHITE, win, lcd_conf);
	LCD5110_wset_cursor(0, 0, win, lcd_conf);
}
inline void LCD5110_fill_scr(LCD5110_display* lcd_conf){
	LCD5110_fillscr(&lcd_conf->hw_conf);
}
inline void LCD5110_fill_win(LCD5110_canvas_t* win, LCD5110_display* lcd_conf){
	LCD5110_wrect_fill(&win->frame, BLACK, win, lcd_conf);
}


void LCD5110_wline(int x1, int y1, int x2, int y2, int color, LCD5110_canvas_t* win, LCD5110_display* lcd_conf);
inline void LCD5110_line(int x1, int y1, int x2, int y2, int color, LCD5110_display* lcd_conf){
	LCD5110_wline(x1, y1, x2, y2, color, &lcd_conf->def_scr, lcd_conf);
}

void LCD5110_wendl(LCD5110_canvas_t* win, LCD5110_display* lcd_conf);
inline void LCD5110_endl(LCD5110_display* lcd_conf) {
	LCD5110_wendl(&lcd_conf->def_scr, lcd_conf);
}

void LCD5110_wprint(const char* str, int color,
						LCD5110_canvas_t* win, LCD5110_display* lcd_conf);
int LCD5110_wprintf( LCD5110_display* lcd_conf, int color, LCD5110_canvas_t* win, char *fmt, ...);

inline void LCD5110_print(const char* str, int color, LCD5110_display* lcd_conf){
	LCD5110_wprint(str, color, &lcd_conf->def_scr, lcd_conf);
}
//! TODO: якось елегантн≥ше це зробити -- поки прост≥ше продублювати.
int LCD5110_printf( LCD5110_display* lcd_conf, int color, char *fmt, ...);


#endif
