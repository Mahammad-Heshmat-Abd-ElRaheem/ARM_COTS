/****************************************************************************
 * Author:				MAHAMMAD HESHMAT ABD EL RAHEEM						*
 * Creation Data:		5 May, 2024										    *
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

// 0x40013C00
typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define     EXTI                     ((volatile EXTI_t *)0x40013C00)

#define     SYSCFG_EXTICR1          *((volatile u32 *)(0x40013800+0x08))
#define     SYSCFG_EXTICR2          *((volatile u32 *)(0x40013800+0x0C))
#define     SYSCFG_EXTICR3          *((volatile u32 *)(0x40013800+0x10))
#define     SYSCFG_EXTICR4          *((volatile u32 *)(0x40013800+0x14))


#endif