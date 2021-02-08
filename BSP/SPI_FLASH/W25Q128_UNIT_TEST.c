/*
 * FileNameW25Q128_UNIT_TEST.c
 * Data:Feb 8, 2021
 * Author:Mr Raphael
 */

#if 1

#include "W25Q128_UNIT_TEST.h"

//uint8_t SPI_Flash_ReadByte(uint32_t ADDR);
//SPI_FLASH_StatusTypedef SPI_FLASH_ReadBusy(void);
//SPI_FLASH_StatusTypedef SPI_FLASH_WriteEnable(void);
//SPI_FLASH_StatusTypedef SPI_FLASH_WriteDisable(void);
//SPI_FLASH_StatusTypedef SPI_FLASH_WriteByte(uint32_t ADDR, uint8_t Data);
//SPI_FLASH_StatusTypedef SPI_FLASH_SectorErase(uint32_t ADDR)
//SPI_FLASH_StatusTypedef SPI_FLASH_ChipErase(void);

void W25Q128_Test(void)
{
	printf("*******W25Q128单元测试*******\n");
	HAL_Delay(1000);
	printf("测试开始...\n");
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
	uint32_t temp;
	temp = SPI_FLASH_READ_JEDECID();
	printf("JEDECID = 0x%X\n", temp);
	LED_RB_TOG();
	printf("开始读测验...\n");
	htim5.Instance->CNT = 0x00;
	HAL_TIM_Base_Start(&htim5);
	for (uint32_t i = 0; i < SPI_FLASH_SIZE; i++)
	{
		if (i % SectorSize == 0)
		{
			LED_RB_TOG();
		}
		SPI_Flash_ReadByte(i);
	}
	HAL_TIM_Base_Stop(&htim5);
	printf("读测试结束，耗时： %d ms\n", htim5.Instance->CNT / 1000);
	LED_B_ON();
	LED_R_OFF();
	HAL_Delay(1000);
	printf("开始写测试....\n");
	htim5.Instance->CNT = 0x00;
	HAL_TIM_Base_Start(&htim5);
	for (uint32_t i = 0; i < SPI_FLASH_SIZE; i++)
	{
		if (i % SectorSize == 0)
		{
			LED_B_TOG();
		}
		SPI_FLASH_WriteByte(i, i);
	}
	HAL_TIM_Base_Stop(&htim5);
	printf("写测试结束，耗时： %d ms\n", htim5.Instance->CNT / 1000);
	LED_B_ON();
	LED_R_OFF();
	HAL_Delay(1000);
	printf("开始校验....\n");
	htim5.Instance->CNT = 0x00;
	HAL_TIM_Base_Start(&htim5);
	for (uint32_t i = 0; i < SPI_FLASH_SIZE; i++)
	{
		if (i % SectorSize == 0)
		{
			LED_R_TOG();
		}
		if (SPI_Flash_ReadByte(i) == (uint8_t) i)
		{
			LED_B_ON();
		}
		else
		{
			LED_B_OFF();
			printf("地址[0x%X]校验错误！！\n", i);
			HAL_Delay(1000);
		}
	}
	HAL_TIM_Base_Stop(&htim5);
	printf("校验测试结束，耗时： %d ms\n", htim5.Instance->CNT / 1000);
	LED_B_ON();
	LED_R_OFF();
	HAL_Delay(1000);
	printf("开始扇区擦除....\n");
	htim5.Instance->CNT = 0x00;
	HAL_TIM_Base_Start(&htim5);
	for (uint32_t i = 0; i < SPI_FLASH_SIZE; i++)
	{
		if (i % SectorSize == 0)
		{
			LED_R_TOG();
			SPI_FLASH_SectorErase(i);
		}
	}
	HAL_TIM_Base_Stop(&htim5);
	printf("扇区擦除结束，耗时： %d ms\n", htim5.Instance->CNT / 1000);
	LED_B_ON();
	LED_R_OFF();
	HAL_Delay(1000);
	printf("开始二次校验....\n");
	htim5.Instance->CNT = 0x00;
	HAL_TIM_Base_Start(&htim5);
	for (uint32_t i = 0; i < SPI_FLASH_SIZE; i++)
	{
		if (i % SectorSize == 0)
		{
			LED_R_TOG();
		}
		if (SPI_Flash_ReadByte(i) == 0xFF)
		{
			LED_B_ON();
		}
		else
		{
			LED_B_OFF();
			printf("地址[0x%X] = 0x%X校验错误！！\n", i,SPI_Flash_ReadByte(i));
		}
	}
	HAL_TIM_Base_Stop(&htim5);
	printf("二次校验测试结束，耗时： %d ms\n", htim5.Instance->CNT / 1000);
	LED_B_ON();
	LED_R_OFF();
	printf("测试结束\n");

}

#endif
