/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define Encoder_Z_Pin GPIO_PIN_13
#define Encoder_Z_GPIO_Port GPIOC
#define Encoder_Z_EXTI_IRQn EXTI15_10_IRQn
#define KEY_UP_Pin GPIO_PIN_0
#define KEY_UP_GPIO_Port GPIOC
#define KEY_DOWN_Pin GPIO_PIN_1
#define KEY_DOWN_GPIO_Port GPIOC
#define SPE_Pin GPIO_PIN_3
#define SPE_GPIO_Port GPIOA
#define ADC_U_Pin GPIO_PIN_4
#define ADC_U_GPIO_Port GPIOA
#define ADC_V_Pin GPIO_PIN_5
#define ADC_V_GPIO_Port GPIOA
#define ADC_W_Pin GPIO_PIN_6
#define ADC_W_GPIO_Port GPIOA
#define U_L_Pin GPIO_PIN_7
#define U_L_GPIO_Port GPIOA
#define ADC_NTC_Pin GPIO_PIN_4
#define ADC_NTC_GPIO_Port GPIOC
#define ADC_Power_Pin GPIO_PIN_5
#define ADC_Power_GPIO_Port GPIOC
#define V_L_Pin GPIO_PIN_0
#define V_L_GPIO_Port GPIOB
#define W_L_Pin GPIO_PIN_1
#define W_L_GPIO_Port GPIOB
#define SPI2_CS_Pin GPIO_PIN_12
#define SPI2_CS_GPIO_Port GPIOB
#define Motor_Enable_Pin GPIO_PIN_6
#define Motor_Enable_GPIO_Port GPIOC
#define Fault_Pin GPIO_PIN_7
#define Fault_GPIO_Port GPIOC
#define SYS_LED_Pin GPIO_PIN_8
#define SYS_LED_GPIO_Port GPIOC
#define Fault_LED_Pin GPIO_PIN_9
#define Fault_LED_GPIO_Port GPIOC
#define U_H_Pin GPIO_PIN_8
#define U_H_GPIO_Port GPIOA
#define V_H_Pin GPIO_PIN_9
#define V_H_GPIO_Port GPIOA
#define W_H_Pin GPIO_PIN_10
#define W_H_GPIO_Port GPIOA
#define SPI3_CS_Pin GPIO_PIN_15
#define SPI3_CS_GPIO_Port GPIOA
#define Encoder_CS_Pin GPIO_PIN_2
#define Encoder_CS_GPIO_Port GPIOD
#define Encoder_A_Pin GPIO_PIN_6
#define Encoder_A_GPIO_Port GPIOB
#define Encoder_B_Pin GPIO_PIN_7
#define Encoder_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
