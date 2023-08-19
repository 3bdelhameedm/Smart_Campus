///*
// * main.c
// *
// *  Created on: Aug 1, 2023
// *      Author: abdel
// */
//
//#include "LIB/BIT_MATH.h"
//#include <util/delay.h>
//#include <avr/io.h>
//#include <avr/interrupt.h>
//#include "DIO/DIO.h"

#include "DIO/DIO.h"
#include "LIB/BIT_MATH.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>
void UART_sendchar(char data);
unsigned char UART_GETChar(void);
void UART_Transmit(unsigned char data);
void UART_sendstring(char *ptr);
unsigned char UART_Recieve(void);
char ass [10]={0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int count1=0,count2=0,count3=0;
unsigned int i;
unsigned char value[10];
char rfid[13],inc,inc2 ,inc3,inc4;
unsigned char value1[]={"123456789012"};            //Unique ID
unsigned char value2[]={"51005D6899FD"};
unsigned char value3[]={"52655D5799AC"};
#define LCD_clear LCD_SendCommand(0b00000001);
char result[10];
int segm=0;
int main(void)

{
	        UCSRB=0x18;
		   	UCSRC=0x86;
		   	UBRRL=51;
		   	UBRRH=0;

	DIO_SetPortDirection(portC,output);
	PORTC |= (1<PC7);                       //enable PC7 internal pullup
	DIO_SetPinDirection(portB,pin3,output);	//make PB3 pin an output for LED
	DIO_SetPinDirection(portB,pin4,output);	//make PB4 pin an output for LED
	DIO_SetPinDirection(portB,pin5,output);
    DIO_SetPinDirection(portD,pin7,input);
    LCD();
    DIO_SetPinDirection(portD,pin2,input);
    DIO_SetPinDirection(portD,pin0,output);
    DIO_SetPinDirection(portD,pin1,output);
    DIO_SetPinDirection(portD,pin4,output);
    DIO_SetPinDirection(portD,pin5,output);

    SET_BIT(MCUCR,1);
    CLR_BIT(MCUCR,0);
    SET_BIT(GICR,6);
    SET_BIT(SREG,7);

    while(1)
    {

        for(i=0;i<12;i++)
         {
        	  rfid[i]=UART_Recieve();
//        	   UART_Transmit(rfid[i]);

          }

         if(strncmp(rfid,value1,12)==0 && inc2!="\n")
               {
          	    	LCD_SENDCOMMAND(0x01);
                   	LCD_SET_COURSER(0,1);
                   	LCD_SENDSTR(" Attendance");
                   	LCD_SET_COURSER(1,1);
                   	LCD_SENDSTR(" Registered");
                   	DIO_SetPinValue(portB,pin4,1);
                   	_delay_ms(300);
                   	DIO_SetPinValue(portB,pin4,0);
          	    	LCD_SENDCOMMAND(0x01);
                    LCD_SENDSTR(" Place your card:");
                    inc="\o";
                    inc2="\n";
                   	UART_sendstring(" Abdelhameed Elkhadrgy ... Attendance Registered\n");

                    _delay_ms(200);


}
         if(strncmp(rfid,value2,12)==0&& inc3!="\n")
             {
            	LCD_SENDCOMMAND(0x01);
            	LCD_SET_COURSER(0,1);
            	LCD_SENDSTR(" Attendance");
              	LCD_SET_COURSER(1,1);
              	LCD_SENDSTR(" Registered");
               	DIO_SetPinValue(portB,pin4,1);
              	_delay_ms(300);
               	DIO_SetPinValue(portB,pin4,0);
      	    	LCD_SENDCOMMAND(0x01);
                LCD_SENDSTR(" Place your card:");
              	inc="\o";
                inc3="\n";
               	UART_sendstring(" Omar ... Attendance Registered \n");

                _delay_ms(200);

              }
          if(strncmp(rfid,value3,12)==0&& inc4!="\n")
                          {
                         	LCD_SENDCOMMAND(0x01);
                         	LCD_SET_COURSER(0,1);
                         	LCD_SENDSTR(" Attendance");
                           	LCD_SET_COURSER(1,1);
                           	LCD_SENDSTR(" Registered");
                           	DIO_SetPinValue(portB,pin4,1);
                            _delay_ms(300);
                         	DIO_SetPinValue(portB,pin4,0);
                  	    	LCD_SENDCOMMAND(0x01);
                            LCD_SENDSTR(" Place your card:");
                           	LCD_SET_COURSER(1,1);
                           	inc="\o";
                            inc4="\n";
                           	UART_sendstring(" shady ... Attendance Registered\n");

                            _delay_ms(200);

                           }
//         else if ((strncmp(rfid,value3,12)!=0)||(strncmp(rfid,value2,12)!=0)||(strncmp(rfid,value1,12)!=0) ){
//          	LCD_SENDCOMMAND(0x01);
//            LCD_SENDSTR(" Invalid card");
//        	DIO_SetPinValue(portB,pin5,1);
//            _delay_ms(300);
//            DIO_SetPinValue(portB,pin5,0);
//         	LCD_SENDCOMMAND(0x01);
//            LCD_SENDSTR(" Place your card:");
//          	LCD_SET_COURSER(1,1);
//         }

       if (inc=="\o"){
	           PORTC=ass[segm];
	           segm++;
inc=' ';
}





              }



              }

//ISR(INT0_vect){
//	                PORTD |= (1<<PD4);
//					PORTD |= (1<<PD5);
//	                _delay_ms(1000);
//
//
//}



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
