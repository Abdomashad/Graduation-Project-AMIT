/*
 * ADC_prog.c
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */
#include "../../SERV/std_typ.h"
#include "../../SERV/bit_math.h"
#include "../../MCAL/DIO/dio_init.h"

#include "ADC_init.h"
#include <stdio.h>
#include "util/delay.h"

void ADC_Init()
{
	DIO_vidSetPortDir(PORTA,INPUT_PORT);	/* Make ADC port as input */


	CLR_BIT(ADMUX,REFS1);		/* Vref: Avcc, ADC channel: 0 */
	SET_BIT(ADMUX,REFS0);

	SET_BIT(ADCSRA,ADEN);		/* Enable ADC */


	CLR_BIT(ADMUX,ADLAR);			/* set Lower bits to store in ADCL */


//	SET_BIT(ADCSRA,ADPS1);		/* for/64 */
//	SET_BIT(ADCSRA,ADPS2);

	SET_BIT(ADCSRA,ADPS2);		/* for/16 */


}

int ADC_Read(int ADC_chanel)
{
	uint16 adc_value = 0;				// 0 for summing

	ADMUX = ((ADMUX)&0xE0) |ADC_chanel; // Choose bit to read from while not changing ref voltage


	SET_BIT(ADCSRA,ADSC); // Start conversion


	while(GET_BIT(ADCSRA,ADIF)==0);// wait for conversion to complete

	//_delay_us(10);

	adc_value = (uint16)(ADCL) +(uint16)(ADCH)*256; //add higher and lower bits

	return adc_value;
}
