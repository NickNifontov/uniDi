/*
 * digiTOS-Core.c
 *
 *  Created on: 5 ��� 2019 �.
 *      Author: Nick Nifontov
 */

#ifndef SRC_DIGITOS_DIGITOS_CORE_C_
#define SRC_DIGITOS_DIGITOS_CORE_C_

#include "stm32f0xx_hal.h"

extern volatile uint32_t UseSoftStart;
extern volatile uint32_t BlockGenerator;
extern volatile uint32_t IsGenerator;
extern volatile uint32_t IsSinus;

void EnableDebugMode();
void Check50Hz();

void On_LEDs();

void Off_LEDs();

void BlinkLEDs(uint8_t _cnt, uint8_t _Delay);

#endif /* SRC_DIGITOS_DIGITOS_CORE_C_ */
