/************************************************************
 * Author:			MAHAMMAD HESHMAT ABD EL RAHEEM      *
 * Creation Data:	      2 June, 2024                        *
 * Version:			v1.0                                *
 * Compiler:		GNU ARM-GCC                         *
 * Controller:		STM32F401CCU6                       *
 * Layer:			MCAL                                *
 ***********************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/DMA_interface.h"
#include "../include/DMA_private.h"
#include "../include/DMA_config.h"

void MDMA1_voidInit (void)
{
      
}
void MDMA1_VoidStartTransfer( u32 * Source_Address, u32 * Distenation_Address, u16 Block_Size )
{
      CLR_BIT(DMA1->Channel[0].SCR , 0);

      DMA1->Channel[0].SPAR = Source_Address ;
      DMA1->Channel[0].SM0AR = Distenation_Address ;
      DMA1->Channel[0].SNDTR = Block_Size; 

      SET_BIT(DMA1->Channel[0].SCR , 0);
}
