################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ThreeParty/FatFS/diskio.c \
../Middlewares/ThreeParty/FatFS/ff.c \
../Middlewares/ThreeParty/FatFS/main.c 

OBJS += \
./Middlewares/ThreeParty/FatFS/diskio.o \
./Middlewares/ThreeParty/FatFS/ff.o \
./Middlewares/ThreeParty/FatFS/main.o 

C_DEPS += \
./Middlewares/ThreeParty/FatFS/diskio.d \
./Middlewares/ThreeParty/FatFS/ff.d \
./Middlewares/ThreeParty/FatFS/main.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ThreeParty/FatFS/diskio.o: ../Middlewares/ThreeParty/FatFS/diskio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ThreeParty/FatFS/diskio.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThreeParty/FatFS/ff.o: ../Middlewares/ThreeParty/FatFS/ff.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ThreeParty/FatFS/ff.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/ThreeParty/FatFS/main.o: ../Middlewares/ThreeParty/FatFS/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Include -I"D:/GitHub/ART-PI-TEMPLATES/BSP/TIM_CLOCK" -I"D:/GitHub/ART-PI-TEMPLATES/BSP/SPI_FLASH" -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/STM32H7xx_HAL_Driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Middlewares/ThreeParty/FatFS/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

