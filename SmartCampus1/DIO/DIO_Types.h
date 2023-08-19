/*
 * DIO_Types.h
 *
 *  Created on: Jul 28, 2023
 *      Author: abdel
 */

#ifndef MCAL_DIO_DIO_TYPES_H_
#define MCAL_DIO_DIO_TYPES_H_

 typedef unsigned char u8_t;

typedef enum {
	 input,  // 0
	 output    // 1
 }DIO_DIRECTION;

 typedef enum {
 	 LOW,  // 0
 	 HIGH    // 1
  }DIO_VALUE;

 typedef enum {
	 portA,
	 portB,
	 portC,
	 portD
 }DIO_PORTID;

 typedef enum {
	 pin0,
	 pin1,
	 pin2,
	 pin3,
	 pin4,
	 pin5,
	 pin6,
	 pin7
  }DIO_PINID;

#endif /* MCAL_DIO_DIO_TYPES_H_ */
