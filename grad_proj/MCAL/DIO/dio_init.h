/*
 * dio_init.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */

#ifndef MCAL_DIO_DIO_INIT_H_
#define MCAL_DIO_DIO_INIT_H_

#define PORTA   (uint8)0
#define PORTB   (uint8)1
#define PORTC   (uint8)2
#define PORTD   (uint8)3

#define HIGH_PORT    (uint8)0xFF
#define LOW_PORT     (uint8)0x00

#define LOW_PIN      (uint8)0
#define HIGH_PIN     (uint8)1
#define TOGGLE_PIN   (uint8)2

typedef enum
{
PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,
PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,
PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,
PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7
}PIN_NUM;

#define INPUT_PORT       (uint8)0x00
#define OUTPUT_PORT      (uint8)0xFF

#define INPUT_PIN       (uint8)0
#define OUTPUT_PIN      (uint8)1
#define TOGGLE_PIN		(uint8)2

void  DIO_vidSetPortDir(uint8 Copyu8PortNum,uint8 Copyu8Dir);
void  DIO_vidSetPortVal(uint8 Copyu8PortNum,uint8 Copyu8Val);
uint8 DIO_u8GetPortVal(uint8 Copyu8PortNum);

void DIO_vidSetPinDir(uint8 Copyu8PinNum,uint8 Copyu8Dir);
void DIO_vidSetPinVal(uint8 Copyu8PinNum,uint8 Copyu8Val);
uint8 DIO_u8GetPinVal(uint8 Copyu8PinNum);

void DIO_SetPinsDir(uint8 * u8PinsNum,uint8 Copyu8Size, uint8 Copyu8Dir);

#endif /* MCAL_DIO_DIO_INIT_H_ */
