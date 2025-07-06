/****************************************************************************
 * Author:				MAHAMMAD HESHMAT ABD EL RAHEEM		    *
 * Creation Data:		      5 May, 2024						    *
 * Version:				v1.0							    *
 * Compiler:			GNU ARM-GCC						    *
 * Controller:			STM32F401CCU6					    *
 * Layer:				MCAL							    *
 ****************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*****( for: Copy_tInterrupLine )*******/
#define     MEXTI_EXTI0      0
#define     MEXTI_EXTI1      1
#define     MEXTI_EXTI2      2
#define     MEXTI_EXTI3      3
#define     MEXTI_EXTI4      4
#define     MEXTI_EXTI5      5
#define     MEXTI_EXTI6      6
#define     MEXTI_EXTI7      7
#define     MEXTI_EXTI8      8
#define     MEXTI_EXTI9      9
#define     MEXTI_EXTI10     10
#define     MEXTI_EXTI11     11
#define     MEXTI_EXTI12     12
#define     MEXTI_EXTI13     13
#define     MEXTI_EXTI14     14
#define     MEXTI_EXTI15     15
/**************************************/
/*****( for: Copy_tSenseSignal )****/
#define    MEXTI_RISING      0
#define    MEXTI_FALLING     1
#define    MEXTI_ONCHANGE    2
/***********************************/

void MEXTI_voidInit(void);
void MEXTI_voidEnableInterrupt(u8 Copy_tInterrupLine);
void MEXTI_voidDisableInterrupt(u8 Copy_tInterrupLine);
void MEXTI_voidChangeSenseMode(u8 Copy_tInterrupLine, u8 Copy_tSenseSignal);
void MEXTI_voidSetCallBack(u8 Copy_tInterrupLine, void (*pCallBackFunction)(void));

#endif