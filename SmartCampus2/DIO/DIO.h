/*
 * DIO.h
 *
 *  Created on: Jul 24, 2023
 *      Author: abdel
 */
#include "DIO_Types.h"
#ifndef REPO_MCAL_DIO_DIO_H_
#define REPO_MCAL_DIO_DIO_H_
/*----------------------------------------------------------------*/

void DIO_SetPortDirection(DIO_PORTID port_ID ,DIO_DIRECTION direction);
void DIO_SetPortValue(DIO_PORTID port_ID ,unsigned char value);
void DIO_SetPinDirection(DIO_PORTID port_ID ,DIO_PINID Pin_ID,DIO_DIRECTION direction);
void DIO_SetPinValue(DIO_PORTID port_ID ,DIO_PINID Pin_ID,DIO_VALUE value);
DIO_VALUE DIO_GetPinvalue(DIO_PORTID port_ID ,DIO_PINID Pin_ID);

#endif /* REPO_MCAL_DIO_DIO_H_ */
