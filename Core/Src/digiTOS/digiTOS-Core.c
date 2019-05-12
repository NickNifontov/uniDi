/*
 * digiTOS-Core.c
 *
 *  Created on: 5 ��� 2019 �.
 *      Author: Nick Nifontov
 */

#include "digiTOS-Core.h"
#include "digiTOS-DAC_Sinus.h"

volatile uint32_t UseSoftStart=0;
volatile uint32_t BlockGenerator=1;
volatile uint32_t IsGenerator=0;
volatile uint32_t IsSinus=0;

volatile uint16_t ADC_Data[ADC_ChannelCnt]; // ADC DMA's collected data
volatile uint32_t ADC_Cnt=0;  // count of collected data to calculate average

volatile uint32_t adcOC_V;
volatile uint32_t adcOC_I;
volatile uint32_t adcKlapan;
volatile uint32_t adcPolka;
volatile uint32_t adcWienZero;

volatile uint32_t adcWienZero_Avg;

volatile uint8_t CurrentMargin=SINUS_MARGIN;



void ResetADC_Buff() {
	for (int i=0;i<ADC_ChannelCnt;i++) {
		ADC_Data[i]=0;
	}
	//ADC_Cnt=0;
}

void CalcAvg() {
	if (ADC_Cnt==0) {
		adcWienZero_Avg=SINUS_MARGIN;
	}
	adcWienZero_Avg=(adcWienZero/ADC_Cnt);
	//
	ADC_Cnt=0;
	adcWienZero=0;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc1)
{
	/*adcOC_V=adcOC_V+ADC_Data[0];
	adcOC_I=adcOC_I+ADC_Data[2];
	adcKlapan=adcKlapan+ADC_Data[3];
	adcPolka=adcPolka+ADC_Data[4];
	adcWienZero=adcWienZero+ADC_Data[5];*/
	//
		adcOC_V=ADC_Data[0];
		adcOC_I=ADC_Data[1];
		adcKlapan=ADC_Data[2];
		adcPolka=ADC_Data[3];
		adcWienZero=adcWienZero+ADC_Data[4];
		//adcWienZero=10;

	//
	ADC_Cnt++;
	//
	ResetADC_Buff();
	//StartADC();
}



void StartADC(){
	//HAL_ADC_Start_IT(&hadc);
	//ADC->CCR |= ADC_CCR_TSEN | ADC_CCR_VREFEN;
	HAL_ADC_Start_DMA(&hadc,(uint32_t*) &ADC_Data,ADC_ChannelCnt);
}

void On_LEDs() {
	HAL_GPIO_WritePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin,GPIO_PIN_SET); // LED On
    HAL_GPIO_WritePin(POLKA_LED_GPIO_Port, POLKA_LED_Pin,GPIO_PIN_SET); // LED On
}

void Off_LEDs() {
	HAL_GPIO_WritePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin,GPIO_PIN_RESET); // LED Off
    HAL_GPIO_WritePin(POLKA_LED_GPIO_Port, POLKA_LED_Pin,GPIO_PIN_RESET); // LED Off
}

void BlinkLEDs(uint8_t _cnt, uint8_t _Delay) {
	uint8_t _i=0;
	Off_LEDs();
	while (_i<_cnt) {
		HAL_GPIO_TogglePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin);
		HAL_GPIO_TogglePin(POLKA_LED_GPIO_Port, POLKA_LED_Pin);
		HAL_Delay(_Delay);
		_i++;
	}
	Off_LEDs();
}

void Check50Hz() {
	if((BlockGenerator==0) && (IsGenerator==1)) {
		if (TIM1->CNT==1000) {
						CalcAvg();
						CurrentMargin=adcWienZero_Avg/41;
						if (CurrentMargin<SINUS_MARGIN) {
							CurrentMargin=SINUS_MARGIN;
						}
		}
		if (((TIM1->CNT==1000) || (TIM1->CNT==0)) || ((sin_step>100) && (TIM1->CNT<10))) {
			sin_step=0;
			//
			HAL_GPIO_TogglePin(BOARD_LED_GPIO_Port, BOARD_LED_Pin); // All is OK, blink
			return;
		}
	}

	if((BlockGenerator==0) && (IsGenerator==0)) {
		TIM1->CCR3=0;
		TIM1->CNT=0;
		PWM_50Hz_ON();
		DAC_SINUS_ON();
		return;
	}

	if((BlockGenerator==1) && (IsGenerator==1)) {
		TIM1->CCR3=0;
		TIM1->CNT=0;
		PWM_50Hz_OFF();
		DAC_SINUS_OFF();
		return;
	}
}

void EnableDebugMode() {
				__HAL_RCC_DBGMCU_CLK_ENABLE();
			    DBGMCU->APB1FZ |= DBGMCU_APB1_FZ_DBG_WWDG_STOP;
			    DBGMCU->APB2FZ = 0xFFFFFFFF;
			    DBGMCU->APB1FZ = 0xFFFFFFFF;
			    DBGMCU->CR |=DBGMCU_CR_DBG_STOP;
			    __HAL_DBGMCU_FREEZE_IWDG();
}

