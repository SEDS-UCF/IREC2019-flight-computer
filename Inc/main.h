/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
#define RF_RST_Pin GPIO_PIN_3
#define RF_RST_GPIO_Port GPIOE
#define RF_CS_Pin GPIO_PIN_4
#define RF_CS_GPIO_Port GPIOE
#define RF_GP0_Pin GPIO_PIN_13
#define RF_GP0_GPIO_Port GPIOC
#define IMU1_CS_Pin GPIO_PIN_4
#define IMU1_CS_GPIO_Port GPIOA
#define IMU2_CS_Pin GPIO_PIN_4
#define IMU2_CS_GPIO_Port GPIOC
#define IMU3_CS_Pin GPIO_PIN_5
#define IMU3_CS_GPIO_Port GPIOC
#define IMU4_CS_Pin GPIO_PIN_0
#define IMU4_CS_GPIO_Port GPIOB
#define LVL_SHFT_nEN_Pin GPIO_PIN_1
#define LVL_SHFT_nEN_GPIO_Port GPIOB
#define PDB_GPIO0_Pin GPIO_PIN_8
#define PDB_GPIO0_GPIO_Port GPIOE
#define PDB_GPIO1_Pin GPIO_PIN_9
#define PDB_GPIO1_GPIO_Port GPIOE
#define PDB_GPIO2_Pin GPIO_PIN_10
#define PDB_GPIO2_GPIO_Port GPIOE
#define PDB_GPIO3_Pin GPIO_PIN_11
#define PDB_GPIO3_GPIO_Port GPIOE
#define PDB_GPIO4_Pin GPIO_PIN_12
#define PDB_GPIO4_GPIO_Port GPIOE
#define PDB_GPIO5_Pin GPIO_PIN_13
#define PDB_GPIO5_GPIO_Port GPIOE
#define PDB_GPIO6_Pin GPIO_PIN_14
#define PDB_GPIO6_GPIO_Port GPIOE
#define PDB_GPIO7_Pin GPIO_PIN_15
#define PDB_GPIO7_GPIO_Port GPIOE
#define PDB_GPIO8_Pin GPIO_PIN_10
#define PDB_GPIO8_GPIO_Port GPIOB
#define PDB_GPIO9_Pin GPIO_PIN_11
#define PDB_GPIO9_GPIO_Port GPIOB
#define BARO1_CS_Pin GPIO_PIN_12
#define BARO1_CS_GPIO_Port GPIOB
#define BARO2_CS_Pin GPIO_PIN_8
#define BARO2_CS_GPIO_Port GPIOD
#define RF_GP3_Pin GPIO_PIN_8
#define RF_GP3_GPIO_Port GPIOB
#define RF_GP2_Pin GPIO_PIN_9
#define RF_GP2_GPIO_Port GPIOB
#define RF_GP1_Pin GPIO_PIN_0
#define RF_GP1_GPIO_Port GPIOE
#define RF_IRQ_Pin GPIO_PIN_1
#define RF_IRQ_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
