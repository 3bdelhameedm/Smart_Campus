/*
 * LED.c

 *
 *  Created on: Jul 24, 2023
 *      Author: abdel
 */

#include "../LCD/LCD.h"
#include "../DIO/DIO.h"
#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/BIT_MATH.h"
#include "../LCD/def.h"

void LCD_Initialize(void){
	    _delay_ms(1);
	    _delay_ms(50);
	    LCD_SENDCOMMAND(0b00111000); // fun set
	    _delay_ms(5);
	    LCD_SENDCOMMAND(0b00001111); // display on blank
	    _delay_ms(5);
	    LCD_SENDCOMMAND(0b00000001);
	    _delay_ms(15);
}

void LCD_SENDCOMMAND(char command){

	CLR_BIT(PORTB,RS);
	CLR_BIT(PORTB,RW);
    SET_BIT(PORTB,E);
	PORTA=command;
	CLR_BIT(PORTB,E);
    _delay_ms(1);
    SET_BIT(PORTB,E);
    _delay_ms(5);
    CLR_BIT(PORTB,E);


}
void LCD_SENDDATA(char data){

	SET_BIT(PORTB,RS);
    CLR_BIT(PORTB,RW);
    SET_BIT(PORTB,E);
	PORTA=data;
    CLR_BIT(PORTB,E);
    _delay_ms(1);
    SET_BIT(PORTB,E);
    _delay_ms(5);
//    CLEAR_BIT(PORTB,E);
}
void LCD_SENDSTR(char *PTR){
	int count=0;
while (1){

if(PTR[count]=='\0'){

	break;
}
	LCD_SENDDATA(PTR[count]);
	count++;

}

}

void LCD_SET_COURSER(unsigned char X_POSITION,unsigned char Y_POSITION)
{
	int ADD;
	if(X_POSITION==0){
		ADD=0X80;
	}
	else if (X_POSITION==1){
		ADD=0XC0;
	}
	if (Y_POSITION<16){

				ADD +=Y_POSITION;
	}
	LCD_SENDCOMMAND(ADD);


}
