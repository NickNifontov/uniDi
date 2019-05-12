################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/digiTOS/digiTOS-50Hz.c \
../Core/Src/digiTOS/digiTOS-Core.c \
../Core/Src/digiTOS/digiTOS-DAC_Sinus.c \
../Core/Src/digiTOS/digiTOS-IWDG.c 

OBJS += \
./Core/Src/digiTOS/digiTOS-50Hz.o \
./Core/Src/digiTOS/digiTOS-Core.o \
./Core/Src/digiTOS/digiTOS-DAC_Sinus.o \
./Core/Src/digiTOS/digiTOS-IWDG.o 

C_DEPS += \
./Core/Src/digiTOS/digiTOS-50Hz.d \
./Core/Src/digiTOS/digiTOS-Core.d \
./Core/Src/digiTOS/digiTOS-DAC_Sinus.d \
./Core/Src/digiTOS/digiTOS-IWDG.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/digiTOS/digiTOS-50Hz.o: ../Core/Src/digiTOS/digiTOS-50Hz.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/digiTOS/digiTOS-50Hz.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/digiTOS/digiTOS-Core.o: ../Core/Src/digiTOS/digiTOS-Core.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/digiTOS/digiTOS-Core.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/digiTOS/digiTOS-DAC_Sinus.o: ../Core/Src/digiTOS/digiTOS-DAC_Sinus.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/digiTOS/digiTOS-DAC_Sinus.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/digiTOS/digiTOS-IWDG.o: ../Core/Src/digiTOS/digiTOS-IWDG.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F051x8 -DDEBUG -c -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/digiTOS/digiTOS-IWDG.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

