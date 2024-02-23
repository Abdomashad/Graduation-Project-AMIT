/*
 * lcd_prog.c
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */

#include "../../SERV/std_typ.h"
#include "lcd_conf.h"
#include "lcd_init.h"
#include <stdio.h>
#include "util/delay.h"


void LCD_Com( unsigned char com )
{
	LCD_Port = (LCD_Port & 0x0F); 					// keep 4 lsb
	LCD_Port = LCD_Port | (com & 0xF0); 			// send upper
	LCD_Port &= ~ (1<<RS);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F);					// keep 4 lsb
	LCD_Port = LCD_Port | (com << 4);  				// send lower
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F);
	LCD_Port = LCD_Port | (data & 0xF0);		//send upper
	LCD_Port |= (1<<RS);
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F);
	LCD_Port = LCD_Port | (data << 4);			// send lower
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_Init (void)
{
	LCD_Dir = 0xFF;			//LCD port output
	_delay_ms(20);			//LCD Power ON delay always >15ms

	LCD_Com(0x02);			   //send for 4 bit initialization of LCD
	LCD_Com(0x28);              //2 line, 5*7 matrix in 4-bit mode
	LCD_Com(0x0c);              //Display on cursor off
	LCD_Com(0x06);              //Increment cursor (shift cursor to right)
	LCD_Com(0x01);              //Clear display screen
	_delay_ms(2);
}

void LCD_String (char *str)		// print string
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Char (str[i]);
	}
}

void LCD_Clear()
{
	LCD_Com (0x01);		//Clear
	_delay_ms(2);
	LCD_Com (0x80);		//return cursor
}

void LCD_second_line()
{
	LCD_Com(0xC0);
}

