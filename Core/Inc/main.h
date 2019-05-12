/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define OSC32_IN_Pin GPIO_PIN_14
#define OSC32_IN_GPIO_Port GPIOC
#define RX1_Pin GPIO_PIN_15
#define RX1_GPIO_Port GPIOA
#define CLK_Pin GPIO_PIN_14
#define CLK_GPIO_Port GPIOA
#define DIO_Pin GPIO_PIN_13
#define DIO_GPIO_Port GPIOA
#define OSC32_OUT_Pin GPIO_PIN_15
#define OSC32_OUT_GPIO_Port GPIOC
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOF
#define CH1_Pin GPIO_PIN_10
#define CH1_GPIO_Port GPIOA
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOF
#define POLKA_LED_Pin GPIO_PIN_9
#define POLKA_LED_GPIO_Port GPIOC
#define BOARD_LED_Pin GPIO_PIN_8
#define BOARD_LED_GPIO_Port GPIOC
#define TX1_Pin GPIO_PIN_2
#define TX1_GPIO_Port GPIOA
#define POLKA_Pin GPIO_PIN_5
#define POLKA_GPIO_Port GPIOA
#define CH2_Pin GPIO_PIN_15
#define CH2_GPIO_Port GPIOB
#define BLOCK_PU_Pin GPIO_PIN_0
#define BLOCK_PU_GPIO_Port GPIOA
#define BLOCK_PU_EXTI_IRQn EXTI0_1_IRQn
#define OC_I_Pin GPIO_PIN_3
#define OC_I_GPIO_Port GPIOA
#define KLAPAN_Pin GPIO_PIN_6
#define KLAPAN_GPIO_Port GPIOA
#define OC_V_Pin GPIO_PIN_1
#define OC_V_GPIO_Port GPIOA
#define WIEN_Pin GPIO_PIN_4
#define WIEN_GPIO_Port GPIOA
#define ZERO_WIEN_Pin GPIO_PIN_7
#define ZERO_WIEN_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
