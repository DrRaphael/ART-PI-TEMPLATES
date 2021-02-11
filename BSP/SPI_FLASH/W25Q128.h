/*
 * W25Q128.h
 *
 *  Created on: Feb 5, 2021
 *      Author: Raphael
 */

#ifndef SPI_FLASH_W25Q128_H_
#define SPI_FLASH_W25Q128_H_
#if 1
#include "main.h"
#include "spi.h"
#include "stdio.h"
#define SPI_Flash_Transmit_Start()		HAL_GPIO_WritePin(SPI_FLASH_EN_GPIO_Port, SPI_FLASH_EN_Pin, GPIO_PIN_RESET);
#define SPI_Flash_Transmit_Stop()		HAL_GPIO_WritePin(SPI_FLASH_EN_GPIO_Port, SPI_FLASH_EN_Pin, GPIO_PIN_SET);
#define SPI_FLASH_SIZE 					16*1024*1024	//(bytes)
#define SPI_FLASH_ID					0xEF4018
/*
 *  此处使用SPI_DATA_BUF_SIZE参数来分配Buff的大小
 * */
#define SectorSize						4096

#define SPI_DATA_BUF_SIZE				256
//#define SPI_DATA_BUF_SIZE				512
//#define SPI_DATA_BUF_SIZE				1024
//#define SPI_DATA_BUF_SIZE				2*1024
//#define SPI_DATA_BUF_SIZE				4*1024
//#define SPI_DATA_BUF_SIZE				8*1024
//#define SPI_DATA_BUF_SIZE				16*1024

typedef enum
{
	CMD_WriteStatusRegister = 0x01,
	CMD_PageProgram = 0x02,
	CMD_ReadData = 0x03,
	CMD_WriteDisable = 0x04,
	CMD_ReadStatusRegister = 0x05,
	CMD_WriteEnable = 0x06,
	CMD_SectorErase = 0x20,
	CMD_Manufacturer = 0x90,
	CMD_JEDECID = 0x9F,
	CMD_ReleasePowerDown = 0xAB,
	CMD_PowerDown = 0xB9,
	CMD_ChipErase = 0xC7

} SPI_Flash_Control_CMD; //SPI Flash 控制命令枚举值

typedef enum
{
	VendorID = 0,
	FlashModelHigh = 1,
	FlashModelLow = 2,
	WriteStatusRegisterInfo = 3,
	WriteDisableInfo = 4,
	ReadStatusRegisterInfo = 5,
	PowerDownInfo = 6,
	FlashSize = 7
} SPIFlashInfoIndex;

typedef enum
{
	SPI_FLASH_OK = 0x00,
	SPI_FLASH_ERROR = 0x01,
	SPI_FLASH_Invalid_Instruction = 0x02,
	SPI_FLASH_Unexpect_ERR = 0x03,
	SPI_FLASH_BUSY = 0x04,
	SPI_FLASH_TOOLONGDATA = 0x05
} SPI_FLASH_StatusTypedef;

uint8_t SPIpDataBuffer[SPI_DATA_BUF_SIZE];
uint8_t SPIFlashInfo[10];

uint8_t SPI_Flash_ReadByte(uint32_t ADDR);
SPI_FLASH_StatusTypedef SPI_FLASH_ReadBusy(void);
SPI_FLASH_StatusTypedef SPI_FLASH_WriteEnable(void);
SPI_FLASH_StatusTypedef SPI_FLASH_WriteDisable(void);
SPI_FLASH_StatusTypedef SPI_FLASH_WriteByte(uint32_t ADDR, uint8_t Data);
SPI_FLASH_StatusTypedef SPI_FLASH_WriteBytes(uint32_t ADDR, uint8_t *pBuffer,
		uint16_t Size);
SPI_FLASH_StatusTypedef SPI_FLASH_SectorErase(uint32_t ADDR);
SPI_FLASH_StatusTypedef SPI_FLASH_ChipErase(void);
uint32_t SPI_FLASH_READ_JEDECID(void);
SPI_FLASH_StatusTypedef SPI_FLASH_ReadBytes(uint32_t ADDR, uint32_t size,
		uint8_t *pBuffer);
#endif
#endif /* SPI_FLASH_W25Q128_H_ */
