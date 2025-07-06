/****************************************************************************
 * Author:				MAHAMMAD HESHMAT ABD EL RAHEEM		    *
 * Creation Data:		      5 May, 2024						    *
 * Version:				v1.0							    *
 * Compiler:			GNU ARM-GCC						    *
 * Controller:			STM32F401CCU6					    *
 * Layer:				MCAL							    *
 ****************************************************************************/
#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

/* Please Enable which EXTI you will use : 
Options: MEXTI_ENABLE
         MEXTI_DISABLE
*/
#define     MEXTI_EXTI_0_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_1_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_2_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_3_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_4_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_5_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_6_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_7_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_8_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_9_EN      MEXTI_DISABLE
#define     MEXTI_EXTI_10_EN     MEXTI_DISABLE
#define     MEXTI_EXTI_11_EN     MEXTI_DISABLE
#define     MEXTI_EXTI_12_EN     MEXTI_DISABLE
#define     MEXTI_EXTI_13_EN     MEXTI_DISABLE
#define     MEXTI_EXTI_14_EN     MEXTI_DISABLE
#define     MEXTI_EXTI_15_EN     MEXTI_DISABLE
/***************************************************/

/* Please selec your Pins
Options:    MEXTI_PINAx
            MEXTI_PINBX
            MEXTI_PINCx
*/
#define     MEXTI_EXTI_0_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_1_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_2_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_3_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_4_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_5_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_6_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_7_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_8_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_9_PIN      MEXTI_PINAx
#define     MEXTI_EXTI_10_PIN     MEXTI_PINAx
#define     MEXTI_EXTI_11_PIN     MEXTI_PINAx
#define     MEXTI_EXTI_12_PIN     MEXTI_PINAx
#define     MEXTI_EXTI_13_PIN     MEXTI_PINAx
#define     MEXTI_EXTI_14_PIN     MEXTI_PINAx
#define     MEXTI_EXTI_15_PIN     MEXTI_PINAx
/********************************************************/
/* Please selec your type of signal
Options:    RISING_EDGE
            FALLING_EDGE
            ON_CHANGE
*/
#define     MEXTI_EXTI_0_ST      RISING_EDGE
#define     MEXTI_EXTI_1_ST      RISING_EDGE
#define     MEXTI_EXTI_2_ST      RISING_EDGE
#define     MEXTI_EXTI_3_ST      RISING_EDGE
#define     MEXTI_EXTI_4_ST      RISING_EDGE
#define     MEXTI_EXTI_5_ST      RISING_EDGE
#define     MEXTI_EXTI_6_ST      RISING_EDGE
#define     MEXTI_EXTI_7_ST      RISING_EDGE
#define     MEXTI_EXTI_8_ST      RISING_EDGE
#define     MEXTI_EXTI_9_ST      RISING_EDGE
#define     MEXTI_EXTI_10_ST     RISING_EDGE
#define     MEXTI_EXTI_11_ST     RISING_EDGE
#define     MEXTI_EXTI_12_ST     RISING_EDGE
#define     MEXTI_EXTI_13_ST     RISING_EDGE
#define     MEXTI_EXTI_14_ST     RISING_EDGE
#define     MEXTI_EXTI_15_ST     RISING_EDGE
/********************************************************/




#endif