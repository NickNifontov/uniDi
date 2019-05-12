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
	}
	Off_LEDs();
}

void Check50Hz() {
	if((BlockGenerator==0) && (IsGenerator==1)) {
		if (((TIM1->CNT==1000) || (TIM1->CNT==0)) || ((sin_step>100) && (TIM1->CNT<10))) {
			sin_step=0;
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

