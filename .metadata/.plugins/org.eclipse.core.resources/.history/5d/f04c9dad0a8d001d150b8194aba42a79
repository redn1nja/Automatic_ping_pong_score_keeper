#include "uart.h"

void USART2_Init(void){
RCC->APB1ENR|=RCC_APB1ENR_USART2EN;
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
GPIOA->AFR[0]=0x0700;
GPIOA->MODER|=(1<<5);//set bit5
GPIOA->MODER&=~(1<<4);//reset bit4
USART2->BRR  = 0x008B;    //115200 @16MHz
USART2->CR1  |=0x2008; // enable tx

}

void USART_write(int ch){
while(!(USART2->SR&0x0080)){
}
USART2->DR=(ch);
	
}

void UART_Write_String(char *p)
	{
	while(*p!='\0')
{
USART_write(*p);
p++;
}
}
	
