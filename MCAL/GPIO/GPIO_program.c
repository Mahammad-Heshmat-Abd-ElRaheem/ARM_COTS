/****************************************************************************
 * Author:				MAHAMMAD HESHMAT									*
 * Creation Data:		24 April, 2024										*
 * Version:				v1.0												*
 * Compiler:			GNU ARM-GCC											*
 * Controller:			STM32F401CCU6										*
 * Layer:				MCAL												*
 ****************************************************************************/
 
 //Liberary Inclusion
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

//Lower Layers Inclusion

//Self Layers Inclusion

//Self Files Inclusion
#include "../include/GPIO_interface.h"
#include "../include/GPIO_private.h"
#include "../include/GPIO_config.h"
 
extern u8 value;

void MGPIO_VoidInit(void)
{
	//TO RESET MODER REGISTER
	GPIOA_MODER = 0x0C000000;
	GPIOB_MODER = 0x00000280;
	GPIOC_MODER = 0x00000000;
	GPIOD_MODER = 0x00000000;
	GPIOE_MODER = 0x00000000;
	GPIOH_MODER = 0x00000000;
	//TO RESET OTYPER REGISTER
	GPIOA_OTYPER = 0x00000000;
	GPIOB_OTYPER = 0x00000000;
	GPIOC_OTYPER = 0x00000000;
	GPIOD_OTYPER = 0x00000000;
	GPIOE_OTYPER = 0x00000000;
	GPIOH_OTYPER = 0x00000000;
	//TO RESET OSPEEDR REGISTER
	GPIOA_OSPEEDR = 0x0C000000;
	GPIOB_OSPEEDR = 0x000000C0;
	GPIOC_OSPEEDR = 0x00000000;
	GPIOD_OSPEEDR = 0x00000000;
	GPIOE_OSPEEDR = 0x00000000;
	GPIOH_OSPEEDR = 0x00000000;	
	//TO RESET PUPDR REGISTER
	GPIOA_PUPDR = 0x64000000;
	GPIOB_PUPDR = 0x00000100;
	GPIOC_PUPDR = 0x00000000;
	GPIOD_PUPDR = 0x00000000;
	GPIOE_PUPDR = 0x00000000;
	GPIOH_PUPDR = 0x00000000;
	//IDR REGISTER => READ ONLY
	//TO RESET ODR REGISTER
	GPIOA_ODR = 0x00000000;
	GPIOB_ODR = 0x00000000;
	GPIOC_ODR = 0x00000000;
	GPIOD_ODR = 0x00000000;
	GPIOE_ODR = 0x00000000;
	GPIOH_ODR = 0x00000000;
	//TO RESET BSRR REGISTER
	GPIOA_BSRR = 0x00000000;
	GPIOB_BSRR = 0x00000000;
	GPIOC_BSRR = 0x00000000;
	GPIOD_BSRR = 0x00000000;
	GPIOE_BSRR = 0x00000000;
	GPIOH_BSRR = 0x00000000;
}
void MGPIO_VoidSetPin_Mode( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode )
{
	switch(copy_u8Port)
	{
		case PORTA:
					GPIOA_MODER &= ~(MODER_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOA_MODER |= (copy_u8Mode << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTB:
					GPIOB_MODER &= ~(MODER_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOB_MODER |= (copy_u8Mode << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTC:
					GPIOC_MODER &= ~(MODER_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOC_MODER |= (copy_u8Mode << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTD:
					GPIOD_MODER &= ~(MODER_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOD_MODER |= (copy_u8Mode << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTE:
					GPIOE_MODER &= ~(MODER_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOE_MODER |= (copy_u8Mode << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTH:
					GPIOH_MODER &= ~(MODER_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOH_MODER |= (copy_u8Mode << (copy_u8Pin * PIN_OFFSET));
		break;
		
		default:	//error
		break;
	}
}

void MGPIO_VoidSetPin_OutputMode( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8OutputMode )
{
	switch(copy_u8Port)
	{
		case PORTA:
					GPIOA_OTYPER &= ~(OTYPER_MASK << copy_u8Pin);
					GPIOA_OTYPER |= (copy_u8OutputMode << copy_u8Pin);
		break;      
		
		case PORTB:
					GPIOB_OTYPER &= ~(OTYPER_MASK << copy_u8Pin);
					GPIOB_OTYPER |= (copy_u8OutputMode << copy_u8Pin);
		break;
		
		case PORTC:
					GPIOC_OTYPER &= ~(OTYPER_MASK << copy_u8Pin);
					GPIOC_OTYPER |= (copy_u8OutputMode << copy_u8Pin);
		break;
		
		case PORTD:
					GPIOD_OTYPER &= ~(OTYPER_MASK << copy_u8Pin);
					GPIOD_OTYPER |= (copy_u8OutputMode << copy_u8Pin);
		break;
		
		case PORTE:
					GPIOE_OTYPER &= ~(OTYPER_MASK << copy_u8Pin);
					GPIOE_OTYPER |= (copy_u8OutputMode << copy_u8Pin);
		break;
		
		case PORTH:
					GPIOH_OTYPER &= ~(OTYPER_MASK << copy_u8Pin);
					GPIOH_OTYPER |= (copy_u8OutputMode << copy_u8Pin);
		break;
		default:	//error
		break;
	}
}

void MGPIO_VoidSetPin_OutputSpeed( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Speed )
{
	switch(copy_u8Port)
	{
		case PORTA:
					GPIOA_OSPEEDR &= ~(OSPEEDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOA_OSPEEDR |= (copy_u8Speed << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTB:
					GPIOB_OSPEEDR &= ~(OSPEEDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOB_OSPEEDR |= (copy_u8Speed << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTC:
					GPIOC_OSPEEDR &= ~(OSPEEDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOC_OSPEEDR |= (copy_u8Speed << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTD:
					GPIOD_OSPEEDR &= ~(OSPEEDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOD_OSPEEDR |= (copy_u8Speed << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTE:
					GPIOE_OSPEEDR &= ~(OSPEEDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOE_OSPEEDR |= (copy_u8Speed << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTH:
					GPIOH_OSPEEDR &= ~(OSPEEDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOH_OSPEEDR |= (copy_u8Speed << (copy_u8Pin * PIN_OFFSET));
		break;
		
		default:	//error
		break;
	}
}

void MGPIO_VoidSetPin_Value( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value )
{
	switch(copy_u8Port)
	{
		case PORTA:
					GPIOA_ODR &= ~(ODR_MASK << copy_u8Pin);
					GPIOA_ODR |= (copy_u8Value << copy_u8Pin);
		break;      
		
		case PORTB:
					GPIOB_ODR &= ~(ODR_MASK << copy_u8Pin);
					GPIOB_ODR |= (copy_u8Value << copy_u8Pin);
		break;
		
		case PORTC:
					GPIOC_ODR &= ~(ODR_MASK << copy_u8Pin);
					GPIOC_ODR |= (copy_u8Value << copy_u8Pin);
		break;
		
		case PORTD:
					GPIOD_ODR &= ~(ODR_MASK << copy_u8Pin);
					GPIOD_ODR |= (copy_u8Value << copy_u8Pin);
		break;
		
		case PORTE:
					GPIOE_ODR &= ~(ODR_MASK << copy_u8Pin);
					GPIOE_ODR |= (copy_u8Value << copy_u8Pin);
		break;
		
		case PORTH:
					GPIOH_ODR &= ~(ODR_MASK << copy_u8Pin);
					GPIOH_ODR |= (copy_u8Value << copy_u8Pin);
		break;
		default:	//error
		break;
	}
}

void MGPIO_VoidSetPin_PUPD( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8State )
{
	switch(copy_u8Port)
	{
		case PORTA:
					GPIOA_PUPDR &= ~(PUPDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOA_PUPDR |= (copy_u8State << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTB:
					GPIOB_PUPDR &= ~(PUPDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOB_PUPDR |= (copy_u8State << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTC:
					GPIOC_PUPDR &= ~(PUPDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOC_PUPDR |= (copy_u8State << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTD:
					GPIOD_PUPDR &= ~(PUPDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOD_PUPDR |= (copy_u8State << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTE:
					GPIOE_PUPDR &= ~(PUPDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOE_PUPDR |= (copy_u8State << (copy_u8Pin * PIN_OFFSET));
		break;
		
		case PORTH:
					GPIOH_PUPDR &= ~(PUPDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOH_PUPDR |= (copy_u8State << (copy_u8Pin * PIN_OFFSET));
		break;
		
		default:	//error
		break;
	}
}

u8 MGPIO_u8GetPinValue( u8 copy_u8Port , u8 copy_u8Pin )
{
	switch(copy_u8Port)
	{
		case PORTA:	value= GET_BIT(GPIOA_IDR,copy_u8Pin);
		break;      
		
		case PORTB:	value= GET_BIT(GPIOB_IDR,copy_u8Pin);
		break;
		
		case PORTC:	value= GET_BIT(GPIOC_IDR,copy_u8Pin);
		break;
		
		case PORTD:	value= GET_BIT(GPIOD_IDR,copy_u8Pin);	
		break;
		
		case PORTE:	value= GET_BIT(GPIOE_IDR,copy_u8Pin);
		break;
		
		case PORTH:	value= GET_BIT(GPIOH_IDR,copy_u8Pin);
		break;
		
		default:	//error
		break;
	}
	return value ;
}
 
void MGPIO_VoidSetPin_OPPVHS( u8 copy_u8Port , u8 copy_u8Pin )
{
	switch(copy_u8Port)
	{
		case PORTA:
					GPIOA_MODER &= ~(MODER_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOA_MODER |= (0b01 << (copy_u8Pin * PIN_OFFSET));
		break;
		case PORTB:
					GPIOB_MODER &= ~(MODER_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOB_MODER |= (0b01 << (copy_u8Pin * PIN_OFFSET));
		break;
		case PORTC:
					GPIOC_MODER &= ~(MODER_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOC_MODER |= (0b01 << (copy_u8Pin * PIN_OFFSET));
		break;
		default:	//error
		break;
	}
	switch(copy_u8Port)
	{
		case PORTA:
					GPIOA_OTYPER &= ~(OTYPER_MASK << copy_u8Pin);
					GPIOA_OTYPER |= (0b0 << copy_u8Pin);
		break;      
		case PORTB:
					GPIOB_OTYPER &= ~(OTYPER_MASK << copy_u8Pin);
					GPIOB_OTYPER |= (0b0 << copy_u8Pin);
		break;
		case PORTC:
					GPIOC_OTYPER &= ~(OTYPER_MASK << copy_u8Pin);
					GPIOC_OTYPER |= (0b0 << copy_u8Pin);
		break;
		default:	//error
		break;
	}
	switch(copy_u8Port)
	{
		case PORTA:
					GPIOA_OSPEEDR &= ~(OSPEEDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOA_OSPEEDR |= (0b11 << (copy_u8Pin * PIN_OFFSET));
		break;
		case PORTB:
					GPIOB_OSPEEDR &= ~(OSPEEDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOB_OSPEEDR |= (0b11 << (copy_u8Pin * PIN_OFFSET));
		break;
		case PORTC:
					GPIOC_OSPEEDR &= ~(OSPEEDR_MASK << (copy_u8Pin * PIN_OFFSET));
					GPIOC_OSPEEDR |= (0b11 << (copy_u8Pin * PIN_OFFSET));
		break;
		default:	//error
		break;
	}
}
 
 
 
 
 