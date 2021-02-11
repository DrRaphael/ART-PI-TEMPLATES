/*
 * FileNameW25Q128.c
 * Data:Feb 5, 2021
 * Author:Mr Raphael
 */
#include "W25Q128.h"
#if 1

uint8_t SPI_Flash_ReadByte(uint32_t ADDR)
{
	uint8_t temp[4];
	uint8_t *pData;
	pData = &temp[0];
	temp[0] = CMD_ReadData;
	temp[1] = (uint8_t) ((ADDR & 0xFF0000) >> 16);
	temp[2] = (uint8_t) ((ADDR & 0xFF00) >> 8);
	temp[3] = (uint8_t) (ADDR & 0xFF);
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&FLASH_SPI, pData, 4, 0xFF);
	HAL_SPI_Receive(&FLASH_SPI, pData, 1, 0xFF);
	SPI_Flash_Transmit_Stop();
	return temp[0];
}

uint8_t SPI_FLASH_Read_WriteStatusRegister(void)
{
	uint8_t Data = CMD_ReadStatusRegister;
	uint8_t *pData = &Data;
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&FLASH_SPI, pData, 1, 0xFF);
	HAL_SPI_Receive(&FLASH_SPI, pData, 1, 0xFF);
	SPI_Flash_Transmit_Stop();
	return Data;
}

SPI_FLASH_StatusTypedef SPI_FLASH_WriteEnable(void)
{
	uint8_t *pData;
	uint8_t Data = CMD_WriteEnable;
	pData = &Data;
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&FLASH_SPI, pData, 1, 0xFF);
	SPI_Flash_Transmit_Stop();
	return SPI_FLASH_OK;
}

SPI_FLASH_StatusTypedef SPI_FLASH_WriteDisable(void)
{
	uint8_t *pData;
	uint8_t Data = CMD_WriteDisable;
	pData = &Data;
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&FLASH_SPI, pData, 1, 0xFF);
	SPI_Flash_Transmit_Stop();
	return SPI_FLASH_OK;
}

SPI_FLASH_StatusTypedef SPI_FLASH_ReadBusy(void)
{
	uint8_t Data = CMD_ReadStatusRegister;
	uint8_t *pData = &Data;
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&FLASH_SPI, pData, 1, 0xFF);
	HAL_SPI_Receive(&FLASH_SPI, pData, 1, 0xFF);
	SPI_Flash_Transmit_Stop();
	if ((Data & 0x01))
	{
		return SPI_FLASH_BUSY;
	}
	return SPI_FLASH_OK;
}

SPI_FLASH_StatusTypedef SPI_FLASH_WriteByte(uint32_t ADDR, uint8_t Data)
{
	//todo 增加对存储器是否为擦除状态的判断
	uint8_t temp[5];
	uint8_t *pData;
	pData = &temp[0];
	SPI_FLASH_WriteEnable();
	temp[0] = CMD_PageProgram;
	temp[1] = (uint8_t) ((ADDR & 0xFF0000) >> 16);
	temp[2] = (uint8_t) ((ADDR & 0xFF00) >> 8);
	temp[3] = (uint8_t) (ADDR & 0xFF);
	temp[4] = Data;
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&hspi1, pData, 5, 0xFF);
	SPI_Flash_Transmit_Stop();
	while (SPI_FLASH_ReadBusy() == SPI_FLASH_BUSY)
		;
	return SPI_FLASH_OK;
}
SPI_FLASH_StatusTypedef SPI_FLASH_WriteBytes(uint32_t ADDR, uint8_t *pBuffer,
		uint16_t Size)
{
	uint8_t temp[4];
	uint8_t *pData;
	pData = &temp[0];
	if (Size > 0x100)
	{
		return SPI_FLASH_TOOLONGDATA;
	}
	SPI_FLASH_WriteEnable();
	temp[0] = CMD_PageProgram;
	temp[1] = (uint8_t) ((ADDR & 0xFF0000) >> 16);
	temp[2] = (uint8_t) ((ADDR & 0xFF00) >> 8);
	temp[3] = (uint8_t) (ADDR & 0xFF);
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&hspi1, pData, 4, 0xFF);
	HAL_SPI_Transmit(&FLASH_SPI, pBuffer, Size, 0xFFFF0);
	SPI_Flash_Transmit_Stop();
	while (SPI_FLASH_ReadBusy() == SPI_FLASH_BUSY)
		;
	return SPI_FLASH_OK;
}

SPI_FLASH_StatusTypedef SPI_FLASH_SectorErase(uint32_t ADDR)
{
	uint8_t temp[4];
	uint8_t *pData = &temp[0];
	ADDR = ADDR / SectorSize * SectorSize;
	temp[0] = CMD_SectorErase;
	temp[1] = (uint8_t) ((ADDR & 0xFF0000) >> 16);
	temp[2] = (uint8_t) ((ADDR & 0xFF00) >> 8);
	temp[3] = (uint8_t) (ADDR & 0xFF);
	SPI_FLASH_WriteEnable();
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&FLASH_SPI, pData, 4, 0xFF);
	SPI_Flash_Transmit_Stop();
	SPI_FLASH_WriteEnable();
	while (SPI_FLASH_ReadBusy())
		;

	return SPI_FLASH_OK;
}

SPI_FLASH_StatusTypedef SPI_FLASH_ChipErase(void)
{
	uint8_t Data = CMD_ChipErase;
	uint8_t *pData = &Data;
	SPI_FLASH_WriteEnable();
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&FLASH_SPI, pData, 1, 0xFF);
	while (SPI_FLASH_ReadBusy())
		;
	SPI_Flash_Transmit_Stop();
	SPI_FLASH_WriteEnable();
	for (uint8_t i = 0; i < 0xFF; i++)
	{
		if (!(SPI_Flash_ReadByte(i) == 0xFF))
		{
			return SPI_FLASH_ERROR;
		}
	}
	return SPI_FLASH_OK;
}

uint32_t SPI_FLASH_READ_JEDECID(void)
{
	uint8_t Data[3];
	uint8_t *pData = &Data[0];
	Data[0] = CMD_JEDECID;
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&FLASH_SPI, pData, 1, 0xFF);
	HAL_SPI_Receive(&FLASH_SPI, pData, 3, 0xFF);
	SPI_Flash_Transmit_Stop();
	return (Data[0] << 16 | Data[1] << 8 | Data[2]);
}

SPI_FLASH_StatusTypedef SPI_FLASH_ReadBytes(uint32_t ADDR, uint32_t size,
		uint8_t *pBuffer)
{
	uint8_t temp[4];
	uint8_t *pData;
	pData = &temp[0];
	temp[0] = CMD_ReadData;
	temp[1] = (uint8_t) ((ADDR & 0xFF0000) >> 16);
	temp[2] = (uint8_t) ((ADDR & 0xFF00) >> 8);
	temp[3] = (uint8_t) (ADDR & 0xFF);
	SPI_Flash_Transmit_Start();
	HAL_SPI_Transmit(&FLASH_SPI, pData, 4, 0xFF);
	HAL_SPI_Receive(&FLASH_SPI, pBuffer, size, 0xFFFF);
	SPI_Flash_Transmit_Stop();
	return SPI_FLASH_OK;
}
#endif
