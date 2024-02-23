/*
 * lcd_conf.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */

#ifndef HAL_LCD_LCD_CONF_H_
#define HAL_LCD_LCD_CONF_H_

#include "../../SERV/std_typ.h"

#define LCD_Dir    *((volatile uint8 *)0x37)	/* Define LCD data port direction */
#define LCD_Port   *((volatile uint8 *)0x38)	/* Define LCD data port */

#define RS 0				/* Define Register Select pin */
#define EN 1 				/* Define Enable signal pin */


#endif /* HAL_LCD_LCD_CONF_H_ */
