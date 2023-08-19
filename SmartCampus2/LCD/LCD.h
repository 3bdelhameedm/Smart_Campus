/*
 * LED.h
 *
 *  Created on: Jul 24, 2023
 *      Author: abdel
 */

#ifndef REPO_HAL_LED_LED_H_
#define Lcd_clear     LCD_SENDCOMMAND(0b00000001);

void LCD_SENDCOMMAND(char command);

void LCD_SENDDATA(char data);

void LCD_SENDSTR(char *PTR);

void LCD_SET_COURSER(unsigned char X_POSITION,unsigned char Y_POSITION);
void  LCD_Initialize(void);
#endif /* REPO_HAL_LED_LED_H_ */

