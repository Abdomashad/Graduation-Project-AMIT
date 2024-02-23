/*
 * dio_prog.c
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */

#include "../../SERV/std_typ.h"
#include "../../SERV/bit_math.h"
#include "dio_reg.h"
#include "dio_init.h"


volatile uint8 *ARR_Dir[4]={DDRA_REG,DDRB_REG,DDRC_REG,DDRD_REG};
volatile uint8 *ARR_Port[4]={PORTA_REG,PORTB_REG,PORTC_REG,PORTD_REG};
volatile uint8 *ARR_Pin[4]={PINA_REG,PINB_REG,PINC_REG,PIND_REG};

void  DIO_vidSetPortDir(uint8 Copyu8PortNum,uint8 Copyu8Dir)
{
	*ARR_Dir[Copyu8PortNum]=Copyu8Dir;
}

void  DIO_vidSetPortVal(uint8 Copyu8PortNum,uint8 Copyu8Val)
{
	*ARR_Port[Copyu8PortNum]=Copyu8Val;
}

uint8 DIO_u8GetPortVal(uint8 Copyu8PortNum)
{
	return *ARR_Pin[Copyu8PortNum];
}

/*------ PORTA 0 -> 7 | PORTB 8 -> 15 | PORTC 16 -> 23 | PORTD 24 -> 31 ------*/

void DIO_vidSetPinDir(uint8 Copyu8PinNum,uint8 Copyu8Dir)
{
	switch (Copyu8Dir)
	{
	case INPUT_PIN  :CLR_BIT(*ARR_Dir[Copyu8PinNum / 8], Copyu8PinNum % 8);break;
	case OUTPUT_PIN :SET_BIT(*ARR_Dir[Copyu8PinNum / 8], Copyu8PinNum % 8);break;
	}
}

void DIO_vidSetPinVal(uint8 Copyu8PinNum,uint8 Copyu8Val)
{
	switch (Copyu8Val)
	{
	case LOW_PIN   :CLR_BIT   (*ARR_Port[Copyu8PinNum / 8], Copyu8PinNum % 8);break;
	case HIGH_PIN  :SET_BIT   (*ARR_Port[Copyu8PinNum / 8], Copyu8PinNum % 8);break;
	case TOGGLE_PIN:TOGGLE_BIT(*ARR_Port[Copyu8PinNum / 8], Copyu8PinNum % 8);break;
	}
}

void DIO_SetPinsDir(uint8 * u8PinsNum,uint8 Copyu8Size, uint8 Copyu8Dir)
{
	uint8 i;
	for(i=0; i<Copyu8Size ; i++)
	{
		if(Copyu8Dir == INPUT_PIN)
		{
			CLR_BIT(*ARR_Dir[u8PinsNum[i] / 8], u8PinsNum[i] % 8);
		}
		else
		{
			SET_BIT(*ARR_Dir[u8PinsNum[i] / 8], u8PinsNum[i] % 8);
		}
	}
}

uint8 DIO_u8GetPinVal(uint8 Copyu8PinNum)
{
	return GET_BIT(*ARR_Pin[Copyu8PinNum / 8], Copyu8PinNum % 8);
}
