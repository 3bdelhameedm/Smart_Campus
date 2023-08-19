/*
 * main.c
 *
 *  Created on: Aug 5, 2023
 *      Author: abdel
 */
#include "DIO/DIO.h"
#include <util/delay.h>
#include <avr/io.h>
#include "LCD/LCD.h"
#include "LIB/BIT_MATH.h"
#include "LCD/def.h"
void ADC_Init();
//unsigned char UART_Recieve(void);


int main (){

	DIO_SetPinDirection(portD,pin0,input);
	DIO_SetPinDirection(portD,pin7,input);
	DIO_SetPinDirection(portD,pin3,output);
	DIO_SetPinDirection(portD,pin4,output);
	DIO_SetPinDirection(portD,pin5,output);
	DIO_SetPinDirection(portD,pin6,output);
	DIO_SetPinDirection(portD,pin2,input);
	DIO_SetPortDirection(portC,output);
	DIO_SetPinDirection(portA,pin0,input);
	DIO_SetPinDirection(portA,pin7,input);


//LCD2();

		ADC_Init();

while (1){

	             ADCSRA |= (1 << ADSC);	// Start Conversion

				 while( (1<<ADIF)==1);		// check if data has been sent


		        if (ADCH >= 45)

		         {

		        	 DIO_SetPinValue(portC,pin0,1);
		        	 DIO_SetPinValue(portC,pin1,1);
		     		_delay_ms(15);
		     		DIO_SetPinValue(portC,pin1,0);
		     		_delay_ms(15);
		     		DIO_SetPinValue(portC,pin1,1);


		         }

	 if(PIND & (1<<PD7))
	 {
					PORTD |= (1<<PD3);
					PORTD |= (1<<PD5);
					PORTD |= (1<<PD6);
					 if (ADCH>=25)
							{
							  PORTD|= (1<<PD4);
							}
					 if (ADCH<25){
					 	    PORTD &= ~(1<<PD4);
					 		         }
				}
		 else{
					PORTD &= ~(1<<PD3);
				    PORTD &= ~(1<<PD5);
				    PORTD &= ~(1<<PD6);
		 }
	if (PIND & (1<<PD2))
	{
		DIO_SetPinValue(portC,pin0,0);
		DIO_SetPinValue(portC,pin1,0);

	}
	else
	{
		DIO_SetPinValue(portC,pin0,1);
		DIO_SetPinValue(portC,pin1,1);
		_delay_ms(15);
		DIO_SetPinValue(portC,pin1,0);
       	_delay_ms(15);
       	DIO_SetPinValue(portC,pin1,1);
	}

	if (PIND & (1<<PD0)){

		DIO_SetPinValue(portC,pin3,0);
		DIO_SetPinValue(portC,pin4,0);
		DIO_SetPinValue(portC,pin5,0);
		DIO_SetPinValue(portC,pin6,0);
	}
	else {
		DIO_SetPinValue(portC,pin3,1);
		DIO_SetPinValue(portC,pin4,1);
		DIO_SetPinValue(portC,pin5,1);
		DIO_SetPinValue(portC,pin6,1);
	}

//	unsigned char rec=UART_Recieve();
//	switch (rec){
//	case 'EM':
//	DIO_SetPinValue(portC,pin0,1);
//	DIO_SetPinValue(portC,pin1,1);
//	_delay_ms(15);
//	DIO_SetPinValue(portC,pin1,0);
//   	_delay_ms(15);
//   	DIO_SetPinValue(portC,pin1,1);
//   	break;
//
//	case 'STAD':
//	DIO_SetPinValue(portC,pin3,1);
//	DIO_SetPinValue(portC,pin4,1);
//	DIO_SetPinValue(portC,pin5,1);
//	DIO_SetPinValue(portC,pin6,1);
//	break;
//	case 'HALL':
//	PORTD |= (1<<PD3);
//	PORTD |= (1<<PD5);
//	PORTD |= (1<<PD6);
//	break;





	}

	 }






void ADC_Init()
{
	ADMUX |=(1<<REFS0)|(1<<REFS1);   // Refernce Voltage is 2.5
	ADCSRA |= (1 << ADEN);			// Enable ADC
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1<<ADPS2);	// 128 Divition
	ADMUX |= (1 << ADLAR);			//Adjust ADC Results

}


void UART_sendchar(char data){
	while(!(UCSRA & (1<<UDRE)));
	UDR=data;



}
unsigned char UART_GETChar(void){
	unsigned char Result;
	while((UCSRA&0x80)==0x00);
	Result=UDR;


}
void UART_sendstring(char *ptr){
	int counter=0;
	while(1){
		if(ptr[counter]=='\0'){
			break;
		}
		UART_sendchar(ptr[counter]);
		counter++;

	}}
void UART_Transmit(unsigned char data)
{
while(!(UCSRA&(1<<UDRE)));
 UDR=data;

}
unsigned char UART_Recieve(void){
	while(!(UCSRA&(1<<RXC)));
	return UDR;

}
