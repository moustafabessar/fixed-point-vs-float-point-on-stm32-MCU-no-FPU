/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "main.h"


void TIMER6_Init(void);
void float_point_math_calculation(float num_arr[], uint8_t length);
void fixed_point_math_calculation(float num_arr[], uint8_t length);
void record_time_start(void);
void record_time_stop_and_measure_elapsed(void);
void Error_handler(void);
TIM_HandleTypeDef htimer6;

int main(void)
{
	HAL_Init();
	TIMER6_Init();

	float float_numbers [100];
	//filling array with dummy float number
	for(int i = 0 ; i < 100 ; i++)
		float_numbers[i] = 2.75;

	//float point operation
	fixed_point_math_calculation(float_numbers, 100);
	//fixed point operation
	float_point_math_calculation(float_numbers, 100);

  while (1);

  return 0;
}

//Initializing timer6
void TIMER6_Init(void)
{
	htimer6.Instance = TIM6;
	htimer6.Init.Prescaler = 24;		//prescaler
	htimer6.Init.Period = 65535-1; 		//period value loaded into ARR
	if( HAL_TIM_Base_Init(&htimer6) != HAL_OK )
	{
		Error_handler();
	}
}

void float_point_math_calculation(float num_arr[], uint8_t length)
{
	//start timer
	record_time_start();
	float sum = 0, average = 0;
	for(uint8_t i = 0; i < length; i++ )
	{
		sum += num_arr[i];
	}
	average = sum/length;

	//stop timer and measure time in us
	record_time_stop_and_measure_elapsed();
	printf("%f\n",average );

}

void fixed_point_math_calculation(float num_arr[], uint8_t length)
{
	//start timer
	record_time_start();
	uint32_t sum = 0, average = 0;
	for(uint8_t i = 0; i < length; i++ )
	{
		sum += FLOAT_TO_FIXP(num_arr[i]);
	}
	average = sum/length;
	uint32_t intergral_part = (uint32_t)FIXP_INT_PART(average);
	uint32_t decimal_part = (uint32_t)(100 * FIXP_DEC_PART(average) >>FP_SHIFT);

	//stop timer and measure time in us
	record_time_stop_and_measure_elapsed();
	printf("%d.%d\n", intergral_part, decimal_part);
}

void record_time_start(void)
{
	HAL_TIM_Base_Start(&htimer6);
}
void record_time_stop_and_measure_elapsed(void)
{
	printf("%f us\n",( ( htimer6.Instance->CNT) * TIME_PERIOD_OF_CNT_CLK) );
	HAL_TIM_Base_Stop(&htimer6);
}

void Error_handler(void)
{
	while(1);
}
