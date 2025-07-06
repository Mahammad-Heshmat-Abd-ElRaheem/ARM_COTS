/****************************************************************************
 * Author:				MAHAMMAD HESHMAT ABD EL RAHEEM						*
 * Creation Data:		5 May, 2024										    *
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/EXTI_interface.h"
#include "../include/EXTI_private.h"
#include "../include/EXTI_config.h"

// static void (*EXTI0_pNotificationFunction)(void) = NULLPTR;
// static void (*EXTI1_pNotificationFunction)(void) = NULLPTR;

// Array Of Pointers to Function
static void (*EXTI_pNotificationFunction[16])(void) = {NULLPTR};


// Task
void MEXTI_voidInit(void)
{
    #if MEXTI_EXTI_0_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI0);     //clearing event mask register
        SET_BIT(EXTI->IMR, EXTI0);
    #elif MEXTI_EXTI_0_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI0);
    #endif
    #if MEXTI_EXTI_1_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI1);     
        SET_BIT(EXTI->IMR, EXTI1);
    #elif MEXTI_EXTI_1_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI1);
    #endif
    #if MEXTI_EXTI_2_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI2);     
        SET_BIT(EXTI->IMR, EXTI2);
    #elif MEXTI_EXTI_2_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI2);
    #endif
    #if MEXTI_EXTI_3_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI3);     
        SET_BIT(EXTI->IMR, EXTI3);
    #elif MEXTI_EXTI_3_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI3);
    #endif
    #if MEXTI_EXTI_4_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI4);     
        SET_BIT(EXTI->IMR, EXTI4);
    #elif MEXTI_EXTI_4_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI4);
    #endif
    #if MEXTI_EXTI_5_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI5);     
        SET_BIT(EXTI->IMR, EXTI5);
    #elif MEXTI_EXTI_5_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI5);
    #endif
    #if MEXTI_EXTI_6_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI6);     
        SET_BIT(EXTI->IMR, EXTI6);
    #elif MEXTI_EXTI_6_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI6);
    #endif
    #if MEXTI_EXTI_7_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI7);     
        SET_BIT(EXTI->IMR, EXTI7);
    #elif MEXTI_EXTI_7_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI7);
    #endif
    #if MEXTI_EXTI_8_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI8);     
        SET_BIT(EXTI->IMR, EXTI8);
    #elif MEXTI_EXTI_8_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI8);
    #endif
    #if MEXTI_EXTI_9_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI9);     
        SET_BIT(EXTI->IMR, EXTI9);
    #elif MEXTI_EXTI_9_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI9);
    #endif
    #if MEXTI_EXTI_10_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI10);     
        SET_BIT(EXTI->IMR, EXTI10);
    #elif MEXTI_EXTI_10_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI10);
    #endif
    #if MEXTI_EXTI_11_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI11);     
        SET_BIT(EXTI->IMR, EXTI11);
    #elif MEXTI_EXTI_11_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI11);
    #endif
    #if MEXTI_EXTI_12_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI12);     
        SET_BIT(EXTI->IMR, EXTI12);
    #elif MEXTI_EXTI_12_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI12);
    #endif
    #if MEXTI_EXTI_13_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI13);     
        SET_BIT(EXTI->IMR, EXTI13);
    #elif MEXTI_EXTI_13_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI13);
    #endif
    #if MEXTI_EXTI_14_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI14);     
        SET_BIT(EXTI->IMR, EXTI14);
    #elif MEXTI_EXTI_14_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI14);
    #endif
    #if MEXTI_EXTI_15_EN == MEXTI_ENABLE
        CLR_BIT(EXTI->EMR, EXTI15);     
        SET_BIT(EXTI->IMR, EXTI15);
    #elif MEXTI_EXTI_15_EN == MEXTI_DISABLE
        CLR_BIT(EXTI->IMR, EXTI15);
    #endif
//now we should select our pins
    #if MEXTI_EXTI_0_PIN == MEXTI_PINAx
        SYSCFG_EXTICR1 &= (~(SYSCFG_EXTICR_MASK << EXTI_0_OFFSET ));
    #elif MEXTI_EXTI_0_PIN == MEXTI_PINBx
        SYSCFG_EXTICR1 &= (~(SYSCFG_EXTICR_MASK << EXTI_0_OFFSET ));
		SYSCFG_EXTICR1 |= (SET_PINBx << EXTI_0_OFFSET );
    #endif
    #if MEXTI_EXTI_1_PIN == MEXTI_PINAx
        SYSCFG_EXTICR1 &= (~(SYSCFG_EXTICR_MASK << EXTI_1_OFFSET ));
    #elif MEXTI_EXTI_1_PIN == MEXTI_PINBx
        SYSCFG_EXTICR1 &= (~(SYSCFG_EXTICR_MASK << EXTI_1_OFFSET ));
		SYSCFG_EXTICR1 |= (SET_PINBx << EXTI_1_OFFSET );
    #endif
    #if MEXTI_EXTI_2_PIN == MEXTI_PINAx
        SYSCFG_EXTICR1 &= (~(SYSCFG_EXTICR_MASK << EXTI_2_OFFSET ));
    #elif MEXTI_EXTI_2_PIN == MEXTI_PINBx
        SYSCFG_EXTICR1 &= (~(SYSCFG_EXTICR_MASK << EXTI_2_OFFSET ));
		SYSCFG_EXTICR1 |= (SET_PINBx << EXTI_2_OFFSET );
    #endif
    #if MEXTI_EXTI_3_PIN == MEXTI_PINAx
        SYSCFG_EXTICR1 &= (~(SYSCFG_EXTICR_MASK << EXTI_3_OFFSET ));
    #elif MEXTI_EXTI_3_PIN == MEXTI_PINBx
        SYSCFG_EXTICR1 &= (~(SYSCFG_EXTICR_MASK << EXTI_3_OFFSET ));
		SYSCFG_EXTICR1 |= (SET_PINBx << EXTI_3_OFFSET );
    #endif
    #if MEXTI_EXTI_4_PIN == MEXTI_PINAx
        SYSCFG_EXTICR2 &= (~(SYSCFG_EXTICR_MASK << EXTI_4_OFFSET ));
    #elif MEXTI_EXTI_4_PIN == MEXTI_PINBx
        SYSCFG_EXTICR2 &= (~(SYSCFG_EXTICR_MASK << EXTI_4_OFFSET ));
		SYSCFG_EXTICR2 |= (SET_PINBx << EXTI_4_OFFSET );
    #endif
    #if MEXTI_EXTI_5_PIN == MEXTI_PINAx
        SYSCFG_EXTICR2 &= (~(SYSCFG_EXTICR_MASK << EXTI_5_OFFSET ));
    #elif MEXTI_EXTI_5_PIN == MEXTI_PINBx
        SYSCFG_EXTICR2 &= (~(SYSCFG_EXTICR_MASK << EXTI_5_OFFSET ));
		SYSCFG_EXTICR2 |= (SET_PINBx << EXTI_5_OFFSET );
    #endif
    #if MEXTI_EXTI_6_PIN == MEXTI_PINAx
        SYSCFG_EXTICR2 &= (~(SYSCFG_EXTICR_MASK << EXTI_6_OFFSET ));
    #elif MEXTI_EXTI_6_PIN == MEXTI_PINBx
        SYSCFG_EXTICR2 &= (~(SYSCFG_EXTICR_MASK << EXTI_6_OFFSET ));
		SYSCFG_EXTICR2 |= (SET_PINBx << EXTI_6_OFFSET );
    #endif
    #if MEXTI_EXTI_7_PIN == MEXTI_PINAx
        SYSCFG_EXTICR2 &= (~(SYSCFG_EXTICR_MASK << EXTI_7_OFFSET ));
    #elif MEXTI_EXTI_7_PIN == MEXTI_PINBx
        SYSCFG_EXTICR2 &= (~(SYSCFG_EXTICR_MASK << EXTI_7_OFFSET ));
		SYSCFG_EXTICR2 |= (SET_PINBx << EXTI_7_OFFSET );
    #endif
    #if MEXTI_EXTI_8_PIN == MEXTI_PINAx
        SYSCFG_EXTICR3 &= (~(SYSCFG_EXTICR_MASK << EXTI_8_OFFSET ));
    #elif MEXTI_EXTI_8_PIN == MEXTI_PINBx
        SYSCFG_EXTICR3 &= (~(SYSCFG_EXTICR_MASK << EXTI_8_OFFSET ));
		SYSCFG_EXTICR3 |= (SET_PINBx << EXTI_8_OFFSET );
    #endif
    #if MEXTI_EXTI_9_PIN == MEXTI_PINAx
        SYSCFG_EXTICR3 &= (~(SYSCFG_EXTICR_MASK << EXTI_9_OFFSET ));
    #elif MEXTI_EXTI_9_PIN == MEXTI_PINBx
        SYSCFG_EXTICR3 &= (~(SYSCFG_EXTICR_MASK << EXTI_9_OFFSET ));
		SYSCFG_EXTICR3 |= (SET_PINBx << EXTI_9_OFFSET );
    #endif
    #if MEXTI_EXTI_10_PIN == MEXTI_PINAx
        SYSCFG_EXTICR3 &= (~(SYSCFG_EXTICR_MASK << EXTI_10_OFFSET ));
    #elif MEXTI_EXTI_10_PIN == MEXTI_PINBx
        SYSCFG_EXTICR3 &= (~(SYSCFG_EXTICR_MASK << EXTI_10_OFFSET ));
		SYSCFG_EXTICR3 |= (SET_PINBx << EXTI_10_OFFSET );
    #endif
    #if MEXTI_EXTI_11_PIN == MEXTI_PINAx
        SYSCFG_EXTICR3 &= (~(SYSCFG_EXTICR_MASK << EXTI_11_OFFSET ));
    #elif MEXTI_EXTI_11_PIN == MEXTI_PINBx
        SYSCFG_EXTICR3 &= (~(SYSCFG_EXTICR_MASK << EXTI_11_OFFSET ));
		SYSCFG_EXTICR3 |= (SET_PINBx << EXTI_11_OFFSET );
    #endif
    #if MEXTI_EXTI_12_PIN == MEXTI_PINAx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_12_OFFSET ));
    #elif MEXTI_EXTI_12_PIN == MEXTI_PINBx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_12_OFFSET ));
		SYSCFG_EXTICR4 |= (SET_PINBx << EXTI_12_OFFSET );
    #endif
    #if MEXTI_EXTI_13_PIN == MEXTI_PINAx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_13_OFFSET ));
    #elif MEXTI_EXTI_13_PIN == MEXTI_PINBx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_13_OFFSET ));
		SYSCFG_EXTICR4 |= (SET_PINBx << EXTI_13_OFFSET );
    #elif MEXTI_EXTI_13_PIN == MEXTI_PINCx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_13_OFFSET ));
		SYSCFG_EXTICR4 |= (SET_PINCx << EXTI_13_OFFSET );
    #endif
    #if MEXTI_EXTI_14_PIN == MEXTI_PINAx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_14_OFFSET ));
    #elif MEXTI_EXTI_14_PIN == MEXTI_PINBx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_14_OFFSET ));
		SYSCFG_EXTICR4 |= (SET_PINBx << EXTI_14_OFFSET );
    #elif MEXTI_EXTI_14_PIN == MEXTI_PINCx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_14_OFFSET ));
		SYSCFG_EXTICR4 |= (SET_PINCx << EXTI_14_OFFSET );
    #endif
    #if MEXTI_EXTI_15_PIN == MEXTI_PINAx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_15_OFFSET ));
    #elif MEXTI_EXTI_15_PIN == MEXTI_PINBx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_15_OFFSET ));
		SYSCFG_EXTICR4 |= (SET_PINBx << EXTI_15_OFFSET );
    #elif MEXTI_EXTI_15_PIN == MEXTI_PINCx
        SYSCFG_EXTICR4 &= (~(SYSCFG_EXTICR_MASK << EXTI_15_OFFSET ));
		SYSCFG_EXTICR4 |= (SET_PINCx << EXTI_15_OFFSET );
    #endif
//Now we select the type of signal
    #if MEXTI_EXTI_0_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI0);
        SET_BIT(EXTI->RTSR, EXTI0);
    #elif MEXTI_EXTI_0_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI0);
        SET_BIT(EXTI->FTSR, EXTI0);       
    #elif MEXTI_EXTI_0_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI0);
        SET_BIT(EXTI->FTSR, EXTI0);  
    #endif
    #if MEXTI_EXTI_1_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI1);
        SET_BIT(EXTI->RTSR, EXTI1);
    #elif MEXTI_EXTI_1_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI1);
        SET_BIT(EXTI->FTSR, EXTI1);       
    #elif MEXTI_EXTI_1_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI1);
        SET_BIT(EXTI->FTSR, EXTI1);  
    #endif
    #if MEXTI_EXTI_2_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI2);
        SET_BIT(EXTI->RTSR, EXTI2);
    #elif MEXTI_EXTI_2_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI2);
        SET_BIT(EXTI->FTSR, EXTI2);       
    #elif MEXTI_EXTI_2_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI2);
        SET_BIT(EXTI->FTSR, EXTI2);  
    #endif
    #if MEXTI_EXTI_3_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI3);
        SET_BIT(EXTI->RTSR, EXTI3);
    #elif MEXTI_EXTI_3_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI3);
        SET_BIT(EXTI->FTSR, EXTI3);       
    #elif MEXTI_EXTI_3_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI3);
        SET_BIT(EXTI->FTSR, EXTI3);  
    #endif
    #if MEXTI_EXTI_4_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI4);
        SET_BIT(EXTI->RTSR, EXTI4);
    #elif MEXTI_EXTI_4_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI4);
        SET_BIT(EXTI->FTSR, EXTI4);       
    #elif MEXTI_EXTI_4_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI4);
        SET_BIT(EXTI->FTSR, EXTI4);  
    #endif
    #if MEXTI_EXTI_5_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI5);
        SET_BIT(EXTI->RTSR, EXTI5);
    #elif MEXTI_EXTI_5_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI5);
        SET_BIT(EXTI->FTSR, EXTI5);       
    #elif MEXTI_EXTI_5_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI5);
        SET_BIT(EXTI->FTSR, EXTI5);  
    #endif
    #if MEXTI_EXTI_6_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI6);
        SET_BIT(EXTI->RTSR, EXTI6);
    #elif MEXTI_EXTI_6_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI6);
        SET_BIT(EXTI->FTSR, EXTI6);       
    #elif MEXTI_EXTI_6_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI6);
        SET_BIT(EXTI->FTSR, EXTI6);  
    #endif
    #if MEXTI_EXTI_7_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI7);
        SET_BIT(EXTI->RTSR, EXTI7);
    #elif MEXTI_EXTI_7_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI7);
        SET_BIT(EXTI->FTSR, EXTI7);       
    #elif MEXTI_EXTI_7_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI7);
        SET_BIT(EXTI->FTSR, EXTI7);  
    #endif
    #if MEXTI_EXTI_8_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI8);
        SET_BIT(EXTI->RTSR, EXTI8);
    #elif MEXTI_EXTI_8_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI8);
        SET_BIT(EXTI->FTSR, EXTI8);       
    #elif MEXTI_EXTI_8_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI8);
        SET_BIT(EXTI->FTSR, EXTI8);  
    #endif
    #if MEXTI_EXTI_9_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI9);
        SET_BIT(EXTI->RTSR, EXTI9);
    #elif MEXTI_EXTI_9_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI9);
        SET_BIT(EXTI->FTSR, EXTI9);       
    #elif MEXTI_EXTI_9_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI9);
        SET_BIT(EXTI->FTSR, EXTI9);  
    #endif
    #if MEXTI_EXTI_10_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI10);
        SET_BIT(EXTI->RTSR, EXTI10);
    #elif MEXTI_EXTI_10_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI10);
        SET_BIT(EXTI->FTSR, EXTI10);       
    #elif MEXTI_EXTI_10_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI10);
        SET_BIT(EXTI->FTSR, EXTI10);  
    #endif
    #if MEXTI_EXTI_11_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI11);
        SET_BIT(EXTI->RTSR, EXTI11);
    #elif MEXTI_EXTI_11_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI11);
        SET_BIT(EXTI->FTSR, EXTI11);       
    #elif MEXTI_EXTI_11_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI11);
        SET_BIT(EXTI->FTSR, EXTI11);  
    #endif
    #if MEXTI_EXTI_12_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI12);
        SET_BIT(EXTI->RTSR, EXTI12);
    #elif MEXTI_EXTI_12_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI12);
        SET_BIT(EXTI->FTSR, EXTI12);       
    #elif MEXTI_EXTI_12_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI12);
        SET_BIT(EXTI->FTSR, EXTI12);  
    #endif
    #if MEXTI_EXTI_13_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI13);
        SET_BIT(EXTI->RTSR, EXTI13);
    #elif MEXTI_EXTI_13_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI13);
        SET_BIT(EXTI->FTSR, EXTI13);       
    #elif MEXTI_EXTI_13_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI13);
        SET_BIT(EXTI->FTSR, EXTI13);  
    #endif
    #if MEXTI_EXTI_14_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI14);
        SET_BIT(EXTI->RTSR, EXTI14);
    #elif MEXTI_EXTI_14_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI14);
        SET_BIT(EXTI->FTSR, EXTI14);       
    #elif MEXTI_EXTI_14_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI14);
        SET_BIT(EXTI->FTSR, EXTI14);  
    #endif
    #if MEXTI_EXTI_15_ST == RISING_EDGE
        CLR_BIT(EXTI->FTSR, EXTI15);
        SET_BIT(EXTI->RTSR, EXTI15);
    #elif MEXTI_EXTI_15_ST == FALLING_EDGE
        CLR_BIT(EXTI->RTSR, EXTI15);
        SET_BIT(EXTI->FTSR, EXTI15);       
    #elif MEXTI_EXTI_15_ST == ON_CHANGE
        SET_BIT(EXTI->RTSR, EXTI15);
        SET_BIT(EXTI->FTSR, EXTI15);  
    #endif
}

void MEXTI_voidEnableInterrupt(u8 Copy_tInterrupLine)
{
    SET_BIT(EXTI->IMR, Copy_tInterrupLine);
}

void MEXTI_voidDisableInterrupt(u8 Copy_tInterrupLine)
{
    CLR_BIT(EXTI->IMR, Copy_tInterrupLine);
}

void MEXTI_voidChangeSenseMode(u8 Copy_tInterrupLine, u8 Copy_tSenseSignal)
{
    switch(Copy_tSenseSignal)
    {
        case MEXTI_RISING:
            CLR_BIT(EXTI->FTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
        break;

        case MEXTI_FALLING:
            CLR_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        case MEXTI_ONCHANGE:
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        default:
        break;
    }
}

void MEXTI_voidSetCallBack(u8 Copy_tInterrupLine, void (*pCallBackFunction)(void))
{
    switch(Copy_tInterrupLine)
    {
        case EXTI0:
            // EXTI0_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI1:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI2:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI3:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI4:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI5:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI6:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI7:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI8:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI9:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI10:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI11:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI12:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI13:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI14:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case EXTI15:
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
    }
}

// ISR For EXTI0
void EXTI0_IRQHandler(void)
{
    // if(EXTI0_pNotificationFunction != NULLPTR)
    if(EXTI_pNotificationFunction[EXTI0] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[EXTI0]();
    }
    else {  }
}

// ISR For EXTI1
void EXTI1_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI1] != NULLPTR) { EXTI_pNotificationFunction[EXTI1](); }
    else {  }
}
// ISR For EXTI2
void EXTI2_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI2] != NULLPTR) { EXTI_pNotificationFunction[EXTI2](); }
    else {  }
}
// ISR For EXTI3
void EXTI3_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI3] != NULLPTR) { EXTI_pNotificationFunction[EXTI3](); }
    else {  }
}
// ISR For EXTI4
void EXTI4_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI4] != NULLPTR) { EXTI_pNotificationFunction[EXTI4](); }
    else {  }
}
// ISR For EXTI5
void EXTI9_5_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI5] != NULLPTR) { EXTI_pNotificationFunction[EXTI5](); }
    else {  }
}
// ISR For EXTI10
void EXTI10_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI10] != NULLPTR) { EXTI_pNotificationFunction[EXTI10](); }
    else {  }
}
// ISR For EXTI11
void EXTI11_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI11] != NULLPTR) { EXTI_pNotificationFunction[EXTI11](); }
    else {  }
}
// ISR For EXTI12
void EXTI12_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI12] != NULLPTR) { EXTI_pNotificationFunction[EXTI12](); }
    else {  }
}
// ISR For EXTI13
void EXTI13_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI13] != NULLPTR) { EXTI_pNotificationFunction[EXTI13](); }
    else {  }
}
// ISR For EXTI14
void EXTI14_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI14] != NULLPTR) { EXTI_pNotificationFunction[EXTI14](); }
    else {  }
}
// ISR For EXTI15
void EXTI15_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[EXTI15] != NULLPTR) { EXTI_pNotificationFunction[EXTI15](); }
    else {  }
}