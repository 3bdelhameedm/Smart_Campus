/*
 * BIT_MATH.h
 *
 *  Created on: Jul 29, 2023
 *      Author: abdel
 */

#ifndef MCAL_DIO_BIT_MATH_H_
#define MCAL_DIO_BIT_MATH_H_

#define SET_BIT(REG,BITNO)          REG|=(1<<BITNO)
#define CLR_BIT(REG,BITNO)          REG&=(~(1<<BITNO))
#define  TOG_BIT(REG,BITNO)         REG^=(1<<BITNO)                                            //tog xor
#define  GET_BIT(REG,BITNO)         ((REG>>BITNO)&1)

#endif /* MCAL_DIO_BIT_MATH_H_ */
