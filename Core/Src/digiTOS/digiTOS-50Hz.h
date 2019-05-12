/*
 * digiTOS-50Hz.h
 *
 *  Created on: 5 ��� 2019 �.
 *      Author: Nick Nifontov
 */

#ifndef SRC_DIGITOS_DIGITOS_50HZ_H_
#define SRC_DIGITOS_DIGITOS_50HZ_H_

#include "stm32f0xx_hal.h"
#include "stm32f051x8.h"
#include "digiTOS-Core.h"


////////////////////// DEAD TIME - BEGIN //////////////////////
//void Set50HzDeadTimeNS(void);
uint32_t SetDeadTime();

void Set50Hz();

void Set505Hz();
////////////////////// DEAD TIME - END //////////////////////



////////////////////// SIGNAL INVERSE - BEGIN //////////////////////
//void SetNormalSignal(void);
//void SetInverseSignal(void);
////////////////////// SIGNAL INVERSEE - END //////////////////////


////////////////////// IDLE STATE - BEGIN //////////////////////
//void Idle_SET(void);
//void Idle_RESET(void);
////////////////////// IDLE STAT - END //////////////////////


////////////////////// INIT GENERATOR 50Hz - BEGIN //////////////////////
//void PWM_50Hz_Init (void);
////////////////////// INIT GENERATOR 50Hz - END //////////////////////


////////////////////// CONTROL 50Hz - BEGIN //////////////////////
//void PWM_50Hz_OUTEN(void);
//void PWM_50Hz_OUTDIS(void);
//void PWM_50Hz_START(void);
//void PWM_50Hz_STOP(void);
void PWM_50Hz_ON(void);
void PWM_50Hz_OFF(void);
////////////////////// CONTROL 50Hz - END //////////////////////


#endif /* SRC_DIGITOS_DIGITOS_50HZ_H_ */
