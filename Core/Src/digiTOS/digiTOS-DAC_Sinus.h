/*
 * digiTOS-DAC_Sinus.h
 *
 *  Created on: 5 ��� 2019 �.
 *      Author: Nick Nifontov
 */

#ifndef SRC_DIGITOS_DIGITOS_DAC_SINUS_H_
#define SRC_DIGITOS_DIGITOS_DAC_SINUS_H_

#include "stm32f0xx_hal.h"
#include "digiTOS-50Hz.h"
#include "stm32f051x8.h"
#include "tim.h"
#include "dac.h"

#define SINUS_MARGIN 2
#define SinRes 480

extern volatile uint16_t sin_data[SinRes];

extern volatile uint16_t sin_step;

void DAC_SINUS_INIT();
void DAC_SINUS_ON();
void DAC_SINUS_OFF();
void Set_DAC_SINUS_ZERO();
uint16_t GetSinus();


#endif /* SRC_DIGITOS_DIGITOS_DAC_SINUS_H_ */
