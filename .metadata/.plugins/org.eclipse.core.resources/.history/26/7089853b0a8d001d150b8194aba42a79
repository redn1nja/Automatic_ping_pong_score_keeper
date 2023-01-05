#ifndef __i2c_H
#define __i2c_H

#include "stm32f4xx.h"                  // Device header

#include <stdint.h>
void i2c_init(void);
char i2c_readByte(char saddr,char maddr,char *data);
void i2c_bus_scan(void);
void i2c_write_byte(char saddr,char maddr, char *data);
void i2c_ReadMulti(char saddr,char maddr, int n, char* data);
void i2c_WriteMulti(char saddr,char maddr,char *buffer, uint8_t length);
void lcd_write_i2c(char saddr,uint8_t *buffer, uint8_t length);
#endif

