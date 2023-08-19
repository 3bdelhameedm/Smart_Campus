/*
 * LCD.c
 *
 *  Created on: Aug 2, 2023
 *      Author: abdel
 */
#include "../DIO/DIO.h"
#include <util/delay.h>
void LCD2(void){

	DIO_SetPortDirection(portB,output);
	DIO_SetPinDirection(portA,pin7,output);
	DIO_SetPinDirection(portA,pin6,output);
	DIO_SetPinDirection(portA,pin5,output);
    LCD_Initialize();
    char coursname[]=" Computer";
    char coursname1[]=" Organization";
    LCD_SET_COURSER(0,3);
    LCD_SENDSTR(coursname);
    LCD_SET_COURSER(1,1);
    LCD_SENDSTR(coursname1);
    _delay_ms(1000);
    LCD_SENDCOMMAND(0x01);
    LCD_SENDSTR(" CODE:CEE224 ");
    _delay_ms(1000);

}
