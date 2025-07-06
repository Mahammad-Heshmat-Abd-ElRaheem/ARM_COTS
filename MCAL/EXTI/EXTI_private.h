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

#define     EXTI0      0
#define     EXTI1      1
#define     EXTI2      2
#define     EXTI3      3
#define     EXTI4      4
#define     EXTI5      5
#define     EXTI6      6
#define     EXTI7      7
#define     EXTI8      8
#define     EXTI9      9
#define     EXTI10     10
#define     EXTI11     11
#define     EXTI12     12
#define     EXTI13     13
#define     EXTI14     14
#define     EXTI15     15

#define     MEXTI_DISABLE   0
#define     MEXTI_ENABLE    1
#define     MEXTI_PINAx     20
#define     MEXTI_PINBX     21
#define     MEXTI_PINCx     22

#define     SYSCFG_EXTICR_MASK      0b1111
#define     SET_PINBx               0b0001
#define     SET_PINCx               0b0010

#define     EXTI_0_OFFSET        0
#define     EXTI_4_OFFSET        0
#define     EXTI_8_OFFSET        0
#define     EXTI_12_OFFSET       0
#define     EXTI_1_OFFSET        4
#define     EXTI_5_OFFSET        4
#define     EXTI_9_OFFSET        4
#define     EXTI_13_OFFSET       4
#define     EXTI_2_OFFSET        8
#define     EXTI_6_OFFSET        8
#define     EXTI_10_OFFSET       8
#define     EXTI_14_OFFSET       8
#define     EXTI_3_OFFSET        12
#define     EXTI_7_OFFSET        12
#define     EXTI_11_OFFSET       12
#define     EXTI_15_OFFSET       12


#endif