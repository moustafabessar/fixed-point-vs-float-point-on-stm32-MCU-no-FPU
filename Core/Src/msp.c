/*
 * msp.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Nvidia
 */
#include "main.h"

void HAL_MspInit(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_MspInit could be implemented in the user file
   */
	//1. setup priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= 0x7 << 16; //usg fault mem fault bus fault system exception

	//3. configure the priority for the system exception
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htimer)
{
	//1. enable the clock for the TIM6 peripheral
	__HAL_RCC_TIM6_CLK_ENABLE();

	//2. enable the IRQ of TIM6
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

	//3. setup periority for TIM6_DAC_IRQn
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 15, 0);
}
