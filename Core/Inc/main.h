/*
 * main.h
 *
 *  Created on: Sep 15, 2020
 *      Author: Nvidia
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdint.h>

#define TIME_PERIOD_OF_CNT_CLK	(1.5625/1000000)

#define FP_SHIFT 16 // shifts to produce a fixed-point number
#define FP_SCALE 65536 // scaling factor
typedef int FIXPOINT;

#define INT_TO_FIXP(n) ((FIXPOINT)((n << FP_SHIFT)))
#define FLOAT_TO_FIXP(n) ((FIXPOINT)((float)n * FP_SCALE))
#define FIXP_INT_PART(n) (n >> 16)
#define FIXP_DEC_PART(n) (n & 0x0000ffff)

#endif /* INC_MAIN_H_ */
