/*
 * W25Q128_UNIT_TEST.h
 *
 *  Created on: Feb 8, 2021
 *      Author: Raphael
 */

#ifndef SPI_FLASH_W25Q128_UNIT_TEST_H_
#define SPI_FLASH_W25Q128_UNIT_TEST_H_

#if 1	//W25Q128单元测试，默认失能
#include "main.h"
#include "stdio.h"
#include "W25Q128.h"
#include "gpio.h"
#include "tim.h"

#define LED_R_ON()				HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
#define LED_B_ON()				HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);
#define LED_R_TOG()				HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
#define LED_B_TOG()				HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
#define LED_R_OFF()				HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
#define LED_B_OFF()				HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET);
#define LED_RB_ON()				LED_B_ON();LED_R_ON();
#define LED_RB_OFF()			LED_B_OFF();LED_R_OFF();
#define LED_RB_TOG()			LED_R_TOG();LED_B_TOG();

void W25Q128_Test(void);

#endif
#endif /* SPI_FLASH_W25Q128_UNIT_TEST_H_ */
