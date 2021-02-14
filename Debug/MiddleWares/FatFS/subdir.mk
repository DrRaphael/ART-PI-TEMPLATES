################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MiddleWares/FatFS/diskio.c \
../MiddleWares/FatFS/ff.c 

OBJS += \
./MiddleWares/FatFS/diskio.o \
./MiddleWares/FatFS/ff.o 

C_DEPS += \
./MiddleWares/FatFS/diskio.d \
./MiddleWares/FatFS/ff.d 


# Each subdirectory must supply rules for building sources it contributes
MiddleWares/FatFS/diskio.o: ../MiddleWares/FatFS/diskio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MiddleWares/FatFS/diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
MiddleWares/FatFS/ff.o: ../MiddleWares/FatFS/ff.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MiddleWares/FatFS/ff.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

