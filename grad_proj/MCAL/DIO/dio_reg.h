/*
 * dio_reg.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */

#ifndef MCAL_DIO_DIO_REG_H_
#define MCAL_DIO_DIO_REG_H_

#include "../../SERV/std_typ.h"

#define DDRA_REG       ( (volatile uint8 *)   0x3A)
#define DDRB_REG       ( (volatile uint8 *)   0x37)
#define DDRC_REG       ( (volatile uint8 *)   0x34)
#define DDRD_REG       ( (volatile uint8 *)   0x31)

#define PORTA_REG      ( (volatile uint8 *)   0x3B)
#define PORTB_REG      ( (volatile uint8 *)   0x38)
#define PORTC_REG      ( (volatile uint8 *)   0x35)
#define PORTD_REG      ( (volatile uint8 *)   0x32)

#define PINA_REG       ( (volatile uint8 *)   0x39)
#define PINB_REG       ( (volatile uint8 *)   0x36)
#define PINC_REG       ( (volatile uint8 *)   0x33)
#define PIND_REG       ( (volatile uint8 *)   0x30)

#endif /* MCAL_DIO_DIO_REG_H_ */
