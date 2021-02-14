################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ThreeParty/FatFS/option/cc936.c \
../Middlewares/ThreeParty/FatFS/option/syscall.c \
../Middlewares/ThreeParty/FatFS/option/unicode.c 

OBJS += \
./Middlewares/ThreeParty/FatFS/option/cc936.o \
./Middlewares/ThreeParty/FatFS/option/syscall.o \
./Middlewares/ThreeParty/FatFS/option/unicode.o 

C_DEPS += \
./Middlewares/ThreeParty/FatFS/option/cc936.d \
./Middlewares/ThreeParty/FatFS/option/syscall.d \
./Middlewares/ThreeParty/FatFS/option/unicode.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ThreeParty/FatFS/option/cc936.o: ../Middlewares/ThreeParty/FatFS/option/cc936.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/Middlewares" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ThreeParty/FatFS/option/cc936.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThreeParty/FatFS/option/syscall.o: ../Middlewares/ThreeParty/FatFS/option/syscall.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/Middlewares" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ThreeParty/FatFS/option/syscall.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThreeParty/FatFS/option/unicode.o: ../Middlewares/ThreeParty/FatFS/option/unicode.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/Middlewares" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ThreeParty/FatFS/option/unicode.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

