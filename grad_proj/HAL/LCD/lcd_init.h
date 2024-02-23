/*
 * lcd_init.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Dell
 */

#ifndef HAL_LCD_LCD_INIT_H_
#define HAL_LCD_LCD_INIT_H_

void LCD_Com( unsigned char cmnd );
void LCD_Char( unsigned char data );
void LCD_Init (void);
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Clear();
void LCD_second_line();

#endif /* HAL_LCD_LCD_INIT_H_ */
