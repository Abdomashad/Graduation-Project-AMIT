/*
 * main.c
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */

#include "../SERV/std_typ.h"
#include "../SERV/bit_math.h"
#include "../MCAL/DIO/dio_init.h"
#include "../MCAL/ADC/ADC_init.h"
#include "../HAL/LCD/lcd_init.h"
#include <util/delay.h>



int main()
{
	uint16 pinky = 0;
	uint16 ring = 0;
	uint16 middle = 0;
	uint16 pointer = 0;
	uint16 thumb = 0;

	uint16 pinkyval = 0;
	uint16 ringval = 0;
	uint16 middleval = 0;
	uint16 pointerval = 0;
	uint16 thumbval = 0;
	uint16 total = 0;

	DIO_vidSetPinDir(16,OUTPUT_PIN);		//5v for glove
	DIO_vidSetPinVal(16,HIGH_PIN);			//5v for glove

	DIO_vidSetPinDir(25,OUTPUT_PIN);		//5v for lcd
	DIO_vidSetPinVal(25,HIGH_PIN);			//5v for lcd


	ADC_Init();			// Initialization of ADC

	LCD_Init();			// Initialization of LCD


	while(1)
	{

	pinky= ADC_Read(0);
	ring= ADC_Read(4);
	middle= ADC_Read(5);
	pointer= ADC_Read(6);
	thumb= ADC_Read(7);

	if(pinky>675)
	{
		pinkyval = 1;
	}
	else
	{
		pinkyval = 0;
	}

	if(ring>850)
	{
		ringval = 2;
	}
	else
	{
		ringval = 0;
	}

	if(middle>700)
	{
		middleval = 4;
	}
	else
	{
		middleval = 0;
	}

	if(pointer>750)
	{
		pointerval = 8;
	}
	else
	{
		pointerval = 0;
	}

	if(thumb>650)
	{
		thumbval = 16;
	}
	else
	{
		thumbval = 0;
	}

	total = pinkyval + ringval + middleval + pointerval + thumbval;

	switch(total)	//determine position of fingers
	    {
	    case 9:
	    	LCD_Clear();
	    	LCD_String("That's Awesome");
	    	_delay_ms(2000);
	    break;

	    case 25:
	    	LCD_Clear();
	    	LCD_String("I Love You");
	    	_delay_ms(2000);
	    break;

	    case 29:
	        LCD_Clear();
	        LCD_String("I really");
	        LCD_second_line();
	        LCD_String("Love you");
	    	_delay_ms(2000);
	    break;

	    case 12:
	        LCD_Clear();
	        LCD_String("I got my eyes");
	        LCD_second_line();
	        LCD_String("on you.");
	    	_delay_ms(2000);
	    break;

	    case 8:
	        LCD_Clear();
	        LCD_String("HEY, YOU!");
	    	_delay_ms(2000);
	    break;

	    case 16:
	        LCD_Clear();
	        LCD_String("Good Work");
	    	_delay_ms(2000);
	    break;

	    case 27:
	        LCD_Clear();
	        LCD_String("I wish you a");
	        LCD_second_line();
	        LCD_String("happy life");
	    	_delay_ms(2000);
	    break;

	    default:
	    break;

	    }
	}

	return 0;
}

