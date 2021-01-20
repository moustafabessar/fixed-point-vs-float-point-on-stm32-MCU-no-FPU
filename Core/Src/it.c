/*
 * it.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Nvidia
 */
#include "main.h"

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
