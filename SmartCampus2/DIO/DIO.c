/*
 * DIO.c
 *
 *  Created on: Jul 24, 2023
 *      Author: abdel
 */
#include "../LIB/BIT_MATH.h"
#include "DIO_Types.h"
#include "DIO_REG.h"

void DIO_SetPortDirection(DIO_PORTID port_ID ,DIO_DIRECTION direction)
{

if (output==direction){
	switch(port_ID){

	case portA: DDRA_REG = 0xFF; break;
	case portB: DDRB_REG = 0xFF; break;
	case portC: DDRC_REG = 0xFF; break;
	case portD: DDRD_REG = 0xFF; break;
	}
	}
	else if (input==direction){
		switch(port_ID){

	case portA: DDRA_REG = 0x00; break;
	case portB: DDRB_REG = 0x00; break;
	case portC: DDRC_REG = 0x00; break;
	case portD: DDRD_REG = 0x00; break;

	}

    }

}
void DIO_SetPortValue(DIO_PORTID port_ID ,unsigned char value){

	switch(port_ID){

		case portA: PORTA_REG = value; break;
		case portB: PORTB_REG = value; break;
		case portC: PORTC_REG = value; break;
		case portD: PORTD_REG = value; break;
		}

}
void DIO_SetPinDirection(DIO_PORTID port_ID ,DIO_PINID Pin,DIO_DIRECTION direction){

	if(port_ID<=portD && Pin<=pin7) {
		if(output==direction) {

		switch(port_ID){

		    case portA: SET_BIT(DDRA_REG,Pin); break;
		    case portB: SET_BIT(DDRB_REG,Pin); break;
		    case portC: SET_BIT(DDRC_REG,Pin); break;
		    case portD: SET_BIT(DDRD_REG,Pin); break;
				}

		}
		else if (input==direction){

			switch(port_ID){

			case portA: CLR_BIT(DDRA_REG,Pin); break;
			case portB: CLR_BIT(DDRB_REG,Pin); break;
			case portC: CLR_BIT(DDRC_REG,Pin); break;
			case portD: CLR_BIT(DDRD_REG,Pin); break;
							}
    }
    }
    }
void DIO_SetPinValue(DIO_PORTID port_ID ,DIO_PINID Pin_ID,DIO_VALUE value)
{
	if(port_ID<=portD && Pin_ID<=pin7) {
			if(HIGH==value) {

			switch(port_ID){

		 case portA: SET_BIT(PORTA_REG,Pin_ID); break;
		 case portB: SET_BIT(PORTB_REG,Pin_ID); break;
		 case portC: SET_BIT(PORTC_REG,Pin_ID); break;
		 case portD: SET_BIT(PORTD_REG,Pin_ID); break;

	}
	}
			else if (LOW==value){

				switch(port_ID){

		 case portA: CLR_BIT(PORTA_REG,Pin_ID); break;
		 case portB: CLR_BIT(PORTB_REG,Pin_ID); break;
		 case portC: CLR_BIT(PORTC_REG,Pin_ID); break;
		 case portD: CLR_BIT(PORTD_REG,Pin_ID); break;

	}
	}
	}
    }
DIO_VALUE DIO_GetPinvalue(DIO_PORTID port_ID ,DIO_PINID Pin_ID)
{
	DIO_VALUE Pinvalue ;
	if(port_ID<=portD && Pin_ID<=pin7) {

				switch(port_ID){

			 case portA: Pinvalue=GET_BIT(PORTA_REG,Pin_ID); break;
			 case portB: Pinvalue=GET_BIT(PORTB_REG,Pin_ID); break;
			 case portC:Pinvalue= GET_BIT(PORTC_REG,Pin_ID); break;
			 case portD: Pinvalue=GET_BIT(PORTD_REG,Pin_ID); break;

	}
	}

	return Pinvalue;
    }

