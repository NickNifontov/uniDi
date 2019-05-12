/*
 * digiTOS-50Hz.c
 *
 *  Created on: 5 ��� 2019 �.
 *      Author: Nick Nifontov
 */

#include "digiTOS-50Hz.h"
#include "digiTOS-DAC_Sinus.h"
#include "tim.h"

////////////////////// DEAD TIME - BEGIN //////////////////////
//const int FOSC=48; // 48000 Hz
//const long FTICK=10000; // 1 per 48000 Hz
//#define MIN_DEADTIME (unsigned long) (FTICK/FOSC);
//#define MAX_DEADTIME (unsigned long) (255*MIN_DEADTIME);

//#define DeadTime1X 					1 // Dead time base value 1/Fosc=1/48000=20.8ns
//#define DeadTime2X 					1 //41,6ns
//#define DeadTime4X					1 //83,2ns
//#define DeadTime8X 					1 //166,4ns
//#define DeadTime16X 				1 //332,8ns
//#define DeadTime32X 				1 //665,6ns
//#define DeadTime64X 				1 //1331,2ns
//#define DeadTime128X 				1 //2662,4ns

void Set50Hz() {
	TIM1->PSC=479-1;
}

void Set505Hz() {
	TIM1->PSC=475-1;
}

uint32_t SetDeadTime() {
	uint32_t _DeadTime=0;

	//_DeadTime  |= TIM_BDTR_DTG_7;//128x //2662,4ns
	_DeadTime  |= TIM_BDTR_DTG_6;//64x //1331,2ns
	_DeadTime  |= TIM_BDTR_DTG_5;//32x //665,6ns
	_DeadTime  |= TIM_BDTR_DTG_4;//16x //332,8ns
	_DeadTime  |= TIM_BDTR_DTG_3;//8x //166,4ns
	_DeadTime  |= TIM_BDTR_DTG_2;//4x //83,2ns
	_DeadTime  |= TIM_BDTR_DTG_1;//2x  //41,6ns
	_DeadTime  |= TIM_BDTR_DTG_0;//1x // Dead time base value 1/Fosc=1/48000=20.8ns

	return _DeadTime;
}

/*void Set50HzDeadTimeNS(void) {

		// Tdts = Tck_int //
	    TIM1->CR1 &= ~TIM_CR1_CKD;
	    TIM1->BDTR &= ~TIM_BDTR_DTG;

	    //TIM1->BDTR  |= TIM_BDTR_DTG_7;//128x //2662,4ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_6;//64x //1331,2ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_5;//32x //665,6ns
	    //TIM1->BDTR  |= TIM_BDTR_DTG_4;//16x //332,8ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_3;//8x //166,4ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_2;//4x //83,2ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_1;//2x  //41,6ns
	    TIM1->BDTR  |= TIM_BDTR_DTG_0;//1x // Dead time base value 1/Fosc=1/48000=20.8ns
}*/
////////////////////// DEAD TIME - END //////////////////////


////////////////////// SIGNAL INVERSE - BEGIN //////////////////////
/*void SetNormalSignal(void) {
		TIM1->CCER |= TIM_CCER_CC3NP; // active high level: 0 - high, 1 - low
		TIM1->CCER |= TIM_CCER_CC3P; // active high level: 0 - high, 1 - low
}

void SetInverseSignal(void) {
		TIM1->CCER &= ~TIM_CCER_CC3NP; // active high level: 0 - high, 1 - low
		TIM1->CCER &= ~TIM_CCER_CC3P; // active high level: 0 - high, 1 - low
}*/
////////////////////// SIGNAL INVERSE - END //////////////////////

////////////////////// IDLE STATE - BEGIN //////////////////////
/*void Idle_SET(void) {
	    // output idle state HIGHT //
		TIM1->CR2 |= TIM_CR2_OIS3;
		TIM1->CR2 |= TIM_CR2_OIS3N;
}

void Idle_RESET(void) {
	    // output idle state LOW //
		TIM1->CR2 &= ~TIM_CR2_OIS3;
		TIM1->CR2 &= ~TIM_CR2_OIS3N;
}*/
////////////////////// IDLE STAT - END //////////////////////


////////////////////// INIT GENERATOR 50Hz - BEGIN //////////////////////
/*void PWM_50Hz_Init (void) {
	//RCC->APB2ENR |= RCC_APB2ENR_TIM16EN; // enable clock for TIM1
	//RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // enable clock for port A
	//RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // enable clock for port B
	//RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; // enable clock for alternative gpio


	//GPIOA->CRH 	&= ~GPIO_CRH_CNF10; // setting out alternative push-pull for PWM
	//GPIOA->CRH 	|= GPIO_CRH_CNF10_1;

	//GPIOA->CRH	&= ~GPIO_CRH_MODE10;
	//GPIOA->CRH	|= GPIO_CRH_MODE10; // gpio speed 50 MHz


	//GPIOB->CRH 	&= ~GPIO_CRH_CNF15; // setting complementary for CH3N
	//GPIOB->CRH 	|= GPIO_CRH_CNF15_1;

	//GPIOB->CRH	&= ~GPIO_CRH_MODE15;
	//GPIOB->CRH	|= GPIO_CRH_MODE15; // gpio speed 50 MHz


	TIM1->PSC = 960-1; // div for clock: F = SYSCLK / [PSC + 1]
	TIM1->ARR = 1000; // count to 1000
	TIM1->CCR3 = 500; // duty cycle 50%
	TIM1->CR1 &= ~TIM_CR1_DIR; // count up: 0 - up, 1 - down
    TIM1->CR1 &= ~TIM_CR1_CMS; // aligned on the front signal

    TIM1->CCMR2 &= ~TIM_CCMR2_OC3M;
    TIM1->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1; // positiv PWM

	TIM1->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3NE; // enable PWM complementary out

	SetInverseSignal();//SetNormalSignal(); // NORMAL or INVERSE
	//Idle_RESET();//
	Idle_SET(); // se idle state

	Set50HzDeadTimeNS(); // 1976 ns

	//ch50HZ_OUTEN(); // OUTPUT ENABLE
	//ch50HZ_START(); // start CNT

}*/
////////////////////// INIT GENERATOR 50Hz - END //////////////////////


////////////////////// CONTROL 50Hz - BEGIN //////////////////////
/*void PWM_50Hz_START(void)
{
	//TIM1->CNT = 0;
	TIM1->CCR3=500;
		TIM1->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3NE; // enable PWM complementary out

		SetInverseSignal(); // NORMAL or INVERSE
		//Idle_RESET();//

		Idle_SET(); // se idle state

		Set50HzDeadTimeNS(); // 1976 ns

	TIM1->DIER |= TIM_DIER_UIE;
	TIM1->CR1 |= TIM_CR1_CEN;
}




void PWM_50Hz_STOP(void)
{
	TIM1->SR&=~TIM_SR_UIF; // clear update flag

	TIM1->DIER &= ~TIM_DIER_UIE; // stop interrupt
	TIM1->CR1 &= (uint16_t)~TIM_CR1_CEN; // stop cnt

	//TIM1->CR1 &= ~TIM_CR1_CKD; // off dead time
	//TIM1->BDTR &= ~TIM_BDTR_DTG;

	//TIM1->CR2 |= TIM_CR2_OIS3N; // revert level
	//TIM1->CR2 &= ~TIM_CR2_OIS3;

	//TIM1->CCER |= TIM_CCER_CC3P; // active high level: 0 - high, 1 - low
	//TIM1->CCER &= ~TIM_CCER_CC3NP; // active high level: 0 - high, 1 - low

	TIM1->CCER |= TIM_CCER_CC3NP; // active high level: 0 - high, 1 - low
	TIM1->CCER &= ~TIM_CCER_CC3P; // active high level: 0 - high, 1 - low

	TIM1->CCR3=0;


}

void PWM_50Hz_OUTEN(void)
{
	TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_AOE; // enable generation output
	//HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
}

void PWM_50Hz_OUTDIS(void)
{
    TIM1->BDTR &= ~TIM_BDTR_MOE;
    TIM1->BDTR &= ~TIM_BDTR_AOE;
    //HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_3);
}
*/


void PWM_50Hz_ON(void){
	//PWM_50Hz_OUTEN(); // OUTPUT ENABLE
	//PWM_50Hz_START(); // start CNT
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_Base_Start_IT(&htim1);
	HAL_TIM_OC_Start(&htim1, TIM_CHANNEL_3);
	HAL_TIMEx_OCN_Start(&htim1, TIM_CHANNEL_3);

	IsGenerator=1;
}

void PWM_50Hz_OFF(void){
	//PWM_50Hz_OUTDIS(); // OUTPUT ENABLE
	//PWM_50Hz_STOP(); // stop CNT
	HAL_TIM_Base_Stop(&htim1);
	HAL_TIM_Base_Stop_IT(&htim1);
	HAL_TIM_OC_Stop(&htim1, TIM_CHANNEL_3);
	HAL_TIMEx_OCN_Stop(&htim1, TIM_CHANNEL_3);

	IsGenerator=0;
}
////////////////////// CONTROL 50Hz - END //////////////////////
