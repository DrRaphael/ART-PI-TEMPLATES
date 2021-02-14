################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MiddleWares/FatFS/option/cc936.c \
../MiddleWares/FatFS/option/syscall.c \
../MiddleWares/FatFS/option/unicode.c 

OBJS += \
./MiddleWares/FatFS/option/cc936.o \
./MiddleWares/FatFS/option/syscall.o \
./MiddleWares/FatFS/option/unicode.o 

C_DEPS += \
./MiddleWares/FatFS/option/cc936.d \
./MiddleWares/FatFS/option/syscall.d \
./MiddleWares/FatFS/option/unicode.d 


# Each subdirectory must supply rules for building sources it contributes
MiddleWares/FatFS/option/cc936.o: ../MiddleWares/FatFS/option/cc936.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MiddleWares/FatFS/option/cc936.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
MiddleWares/FatFS/option/syscall.o: ../MiddleWares/FatFS/option/syscall.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MiddleWares/FatFS/option/syscall.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
MiddleWares/FatFS/option/unicode.o: ../MiddleWares/FatFS/option/unicode.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MiddleWares/FatFS/option/unicode.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

