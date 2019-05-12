/*
 * digiTOS-Core.c
 *
 *  Created on: 5 ��� 2019 �.
 *      Author: Nick Nifontov
 */

#ifndef SRC_DIGITOS_DIGITOS_CORE_C_
#define SRC_DIGITOS_DIGITOS_CORE_C_

#include "stm32f0xx_hal.h"
#include "adc.h"

extern volatile uint32_t UseSoftStart;
extern volatile uint32_t BlockGenerator;
extern volatile uint32_t IsGenerator;
extern volatile uint32_t IsSinus;

#define ADC_ChannelCnt 5
extern volatile uint16_t ADC_Data[ADC_ChannelCnt]; // ADC DMA's collected data
extern volatile uint32_t ADC_Cnt;

extern volatile uint32_t adcOC_V;
extern volatile uint32_t adcOC_I;
extern volatile uint32_t adcKlapan;
extern volatile uint32_t adcPolka;
extern volatile uint32_t adcWienZero;

extern volatile uint32_t adcWienZero_Avg;

extern volatile uint8_t CurrentMargin;




void StartADC();
void CalcAvg();

void EnableDebugMode();
void Check50Hz();

void On_LEDs();

void Off_LEDs();

void BlinkLEDs(uint8_t _cnt, uint8_t _Delay);

#endif /* SRC_DIGITOS_DIGITOS_CORE_C_ */
