/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2016        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "diskio.h"		/* FatFs lower layer API */
//#include "usbdisk.h"	/* Example: Header file of existing USB MSD control module */
//#include "atadrive.h"	/* Example: Header file of existing ATA harddisk control module */
//#include "sdcard.h"		/* Example: Header file of existing MMC/SDC contorl module */
#include "W25Q128.h"

/* Definitions of physical drive number for each drive */
#define ATA				0	/* Example: Map ATA harddisk to physical drive 0 */
#define MMC				1	/* Example: Map MMC/SD card to physical drive 1 */
#define USB				2	/* Example: Map USB MSD to physical drive 2 */
#define SPI_FLASH	 	3

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status(BYTE pdrv /* Physical drive nmuber to identify the drive */
)
{
	DSTATUS status = STA_NOINIT;
	switch (pdrv)
	{
		case ATA:
			break;
		case MMC:
			break;
		case USB:
			break;
		case SPI_FLASH:
			if (SPI_FLASH_ID == SPI_FLASH_READ_JEDECID())
			{
				status &= ~STA_NOINIT;
			} else
			{
				status = STA_NOINIT;
			}
		default:
			break;
	}
	return status;
}

/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize(BYTE pdrv /* Physical drive nmuber to identify the drive */
)
{
	DSTATUS status = STA_NOINIT;
	switch (pdrv)
	{
		case ATA:
			break;
		case MMC:
			break;
		case USB:
			break;
		case SPI_FLASH:
			if (SPI_FLASH_ID == SPI_FLASH_READ_JEDECID())
			{
				status &= ~STA_NOINIT;
			} else
			{
				status = STA_NOINIT;
			}
		default:
			break;
	}
	return status;
}

/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read(BYTE pdrv, /* Physical drive nmuber to identify the drive */
BYTE *buff, /* Data buffer to store read data */
DWORD sector, /* Sector address in LBA */
UINT count /* Number of sectors to read */
)
{
	DRESULT res = RES_PARERR;
	switch (pdrv)
	{
		case ATA:
			break;
		case MMC:
			break;
		case USB:
			break;
		case SPI_FLASH:
		{
			if (SPI_FLASH_ReadBytes(sector << 12, count << 12, buff)
					== SPI_FLASH_OK)
			{
				res = RES_OK;
			} else
			{
				res = RES_ERROR;
			}

		}
	}

	return res;
}

/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

DRESULT disk_write(BYTE pdrv, /* Physical drive nmuber to identify the drive */
const BYTE *buff, /* Data to be written */
DWORD sector, /* Sector address in LBA */
UINT count /* Number of sectors to write */
)
{

	return 0;
}

/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl(BYTE pdrv, /* Physical drive nmuber (0..) */
BYTE cmd, /* Control code */
void *buff /* Buffer to send/receive control data */
)
{
	DRESULT res;

	return RES_PARERR;
}

