/************************************************************
 * Author:			MAHAMMAD HESHMAT ABD EL RAHEEM      *
 * Creation Data:	      2 May, 2024                         *
 * Version:			v1.0                                *
 * Compiler:		GNU ARM-GCC                         *
 * Controller:		STM32F401CCU6                       *
 * Layer:			MCAL                                *
 ***********************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/******( For: Copy_u8InterruptState )*****/
#define     MNVIC_INT_DISABLE       0
#define     MNVIC_INT_ENABLE        1
/*****************************************/
/******( For: Copy_u8PeripheralID )*****/
#define     NVIC_EXTI0_ID           6
#define     NVIC_EXTI1_ID           7
#define     NVIC_EXTI2_ID           8
#define     NVIC_EXTI3_ID           9
#define     NVIC_EXTI4_ID           10
//#define     NVIC_EXTI5_ID        19
//#define     NVIC_EXTI6_ID        20
//#define     NVIC_EXTI7_ID        21
//#define     NVIC_EXTI8_ID        22
#define     NVIC_EXTI9_5_ID        23
#define     NVIC_EXTI15_10_ID       40
#define     NVIC_EXTI16_ID          1
#define     NVIC_EXTI17_ID          41
#define     NVIC_EXTI18_ID          42
#define     NVIC_EXTI21_ID          2
#define     NVIC_EXTI22_ID          3

#define     NVIC_TIM1_BRK_ID        24
#define     NVIC_TIM1_CC_ID         27
#define     NVIC_TIM1_UP_ID         25
#define     NVIC_TIM1_TRG_COM_ID    26
#define     NVIC_TIM2_ID            28
#define     NVIC_TIM3_ID            29
#define     NVIC_TIM4_ID            30
#define     NVIC_TIM5_ID            50
#define     NVIC_TIM9_ID            24
#define     NVIC_TIM10_ID           25
#define     NVIC_TIM11_ID           26

#define     NVIC_I2C1_EV_ID         31
#define     NVIC_I2C1_ER_ID         32
#define     NVIC_I2C2_EV_ID         33
#define     NVIC_I2C2_ER_ID         34
#define     NVIC_I2C3_EV_ID         72
#define     NVIC_I2C3_ER_ID         73

#define     NVIC_SPI1_ID            35
#define     NVIC_SPI2_ID            36
#define     NVIC_SPI3_ID            51
#define     NVIC_SPI4_ID            84

#define     NVIC_USART1_ID          37
#define     NVIC_USART2_ID          38
#define     NVIC_USART6_ID          71

#define     NVIC_DMA1_Stream0_ID    11
#define     NVIC_DMA1_Stream1_ID    12
#define     NVIC_DMA1_Stream2_ID    13
#define     NVIC_DMA1_Stream3_ID    14
#define     NVIC_DMA1_Stream4_ID    15
#define     NVIC_DMA1_Stream5_ID    16
#define     NVIC_DMA1_Stream6_ID    17
#define     NVIC_DMA1_Stream7_ID    47

#define     NVIC_DMA2_Stream0_ID    56
#define     NVIC_DMA2_Stream1_ID    57
#define     NVIC_DMA2_Stream2_ID    58
#define     NVIC_DMA2_Stream3_ID    59
#define     NVIC_DMA2_Stream4_ID    60
#define     NVIC_DMA2_Stream5_ID    68
#define     NVIC_DMA2_Stream6_ID    69
#define     NVIC_DMA2_Stream7_ID    70

#define     NVIC_OTG_FS_ID          67
#define     NVIC_OTG_FS_WKUP_ID     42
#define     NVIC_RTC_WKUP_ID        3
#define     NVIC_RTC_Alarm_ID       41
#define     NVIC_SDIO_ID            49
#define     NVIC_WWDG_ID            0
#define     NVIC_PVD_ID             1
#define     NVIC_TAMP_STAMP_ID      2
#define     NVIC_FPU_ID             81
#define     NVIC_FLASH_ID           4
#define     NVIC_RCC_ID             5
#define     NVIC_ADC_ID             18
/*****************************************/

void MNVIC_voidInit(void);
void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID);
void MNVIC_voidDisablePeripheralInterrup(u8 Copy_u8PeripheralID);
void MNVIC_voidPeripheralInterruptControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptState);
void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);

#endif