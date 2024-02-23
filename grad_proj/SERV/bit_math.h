/*
 * bit_math.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */

#ifndef SERV_BIT_MATH_H_
#define SERV_BIT_MATH_H_

#define CLR_BIT(reg,bit)      reg &= ~ (1 << bit)
#define SET_BIT(reg,bit)      reg |=   (1 << bit)
#define TOGGLE_BIT(reg,bit)   reg ^=   (1 << bit)
#define GET_BIT(reg,bit)      ((reg >> bit) & 1 )

#endif /* SERV_BIT_MATH_H_ */
