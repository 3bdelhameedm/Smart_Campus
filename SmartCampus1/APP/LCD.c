/*
 * LCD.c
 *
 *  Created on: Aug 2, 2023
 *      Author: abdel
 */
#include "../DIO/DIO.h"
#include <util/delay.h>
void LCD(void){

	DIO_SetPortDirection(portA,output);
	DIO_SetPinDirection(portB,pin0,output);
	DIO_SetPinDirection(portB,pin1,output);
	DIO_SetPinDirection(portB,pin2,output);
    LCD_Initialize();
//    char coursname[]=" Computer";
//    char coursname1[]=" Organization";
//    LCD_SET_COURSER(0,3);
//    LCD_SENDSTR(coursname);
//    LCD_SET_COURSER(1,1);
//    LCD_SENDSTR(coursname1);
//    _delay_ms(700);
//    LCD_SENDCOMMAND(0x01);
//    LCD_SENDSTR(" CODE:CEE224 ");
//    _delay_ms(700);
//    LCD_SENDCOMMAND(0x01);
    LCD_SENDSTR("   RFID Based    ");
    _delay_ms(700);
    LCD_SENDCOMMAND(0x01);
    LCD_SENDSTR("   Attendance ");
    LCD_SET_COURSER(1,4);
    LCD_SENDSTR(" System");

    _delay_ms(700);

    LCD_SENDCOMMAND(0x01);
    LCD_SENDSTR(" Place your card:");
    LCD_SET_COURSER(1,0);

}
