/*
 * ADC_init.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */

#ifndef MCAL_ADC_ADC_INIT_H_
#define MCAL_ADC_ADC_INIT_H_

#include "../../SERV/std_typ.h"

#define ADPS1 1
#define ADPS2 2
#define ADIF 4
#define ADSC 6
#define ADEN 7

#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADMUX    *((volatile uint8 *)0x27)
#define ADCSRA   *((volatile uint8 *)0x26)
#define ADCH     *((volatile uint8 *)0x25)
#define ADCL     *((volatile uint8 *)0x24)

void ADC_Init();
int ADC_Read(int ADC_chanel);



#endif /* MCAL_ADC_ADC_INIT_H_ */
