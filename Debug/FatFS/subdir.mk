################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FatFS/diskio.c \
../FatFS/ff.c 

OBJS += \
./FatFS/diskio.o \
./FatFS/ff.o 

C_DEPS += \
./FatFS/diskio.d \
./FatFS/ff.d 


# Each subdirectory must supply rules for building sources it contributes
FatFS/diskio.o: ../FatFS/diskio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I"D:/GitHub/ART-PI-TEMPLATES/FatFS" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FatFS/diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
FatFS/ff.o: ../FatFS/ff.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I"D:/GitHub/ART-PI-TEMPLATES/FatFS" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FatFS/ff.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

