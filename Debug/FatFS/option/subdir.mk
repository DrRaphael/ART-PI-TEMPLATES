################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FatFS/option/cc936.c \
../FatFS/option/syscall.c 

OBJS += \
./FatFS/option/cc936.o \
./FatFS/option/syscall.o 

C_DEPS += \
./FatFS/option/cc936.d \
./FatFS/option/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
FatFS/option/cc936.o: ../FatFS/option/cc936.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I"D:/GitHub/ART-PI-TEMPLATES/FatFS" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FatFS/option/cc936.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
FatFS/option/syscall.o: ../FatFS/option/syscall.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I"D:/GitHub/ART-PI-TEMPLATES/FatFS" -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"FatFS/option/syscall.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

