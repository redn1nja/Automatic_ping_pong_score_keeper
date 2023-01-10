################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/gpio.c \
../Core/Src/i2c.c \
../Core/Src/i2c_config.c \
../Core/Src/i2c_lcd.c \
../Core/Src/lcd5110.c \
../Core/Src/lcd5110_hal.c \
../Core/Src/lcd5110_ll.c \
../Core/Src/main.c \
../Core/Src/spi.c \
../Core/Src/stm32f3xx_hal_msp.c \
../Core/Src/stm32f3xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f3xx.c \
../Core/Src/tim.c \
../Core/Src/usb.c 

OBJS += \
./Core/Src/gpio.o \
./Core/Src/i2c.o \
./Core/Src/i2c_config.o \
./Core/Src/i2c_lcd.o \
./Core/Src/lcd5110.o \
./Core/Src/lcd5110_hal.o \
./Core/Src/lcd5110_ll.o \
./Core/Src/main.o \
./Core/Src/spi.o \
./Core/Src/stm32f3xx_hal_msp.o \
./Core/Src/stm32f3xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f3xx.o \
./Core/Src/tim.o \
./Core/Src/usb.o 

C_DEPS += \
./Core/Src/gpio.d \
./Core/Src/i2c.d \
./Core/Src/i2c_config.d \
./Core/Src/i2c_lcd.d \
./Core/Src/lcd5110.d \
./Core/Src/lcd5110_hal.d \
./Core/Src/lcd5110_ll.d \
./Core/Src/main.d \
./Core/Src/spi.d \
./Core/Src/stm32f3xx_hal_msp.d \
./Core/Src/stm32f3xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f3xx.d \
./Core/Src/tim.d \
./Core/Src/usb.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/i2c.d ./Core/Src/i2c.o ./Core/Src/i2c.su ./Core/Src/i2c_config.d ./Core/Src/i2c_config.o ./Core/Src/i2c_config.su ./Core/Src/i2c_lcd.d ./Core/Src/i2c_lcd.o ./Core/Src/i2c_lcd.su ./Core/Src/lcd5110.d ./Core/Src/lcd5110.o ./Core/Src/lcd5110.su ./Core/Src/lcd5110_hal.d ./Core/Src/lcd5110_hal.o ./Core/Src/lcd5110_hal.su ./Core/Src/lcd5110_ll.d ./Core/Src/lcd5110_ll.o ./Core/Src/lcd5110_ll.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/spi.d ./Core/Src/spi.o ./Core/Src/spi.su ./Core/Src/stm32f3xx_hal_msp.d ./Core/Src/stm32f3xx_hal_msp.o ./Core/Src/stm32f3xx_hal_msp.su ./Core/Src/stm32f3xx_it.d ./Core/Src/stm32f3xx_it.o ./Core/Src/stm32f3xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f3xx.d ./Core/Src/system_stm32f3xx.o ./Core/Src/system_stm32f3xx.su ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su ./Core/Src/usb.d ./Core/Src/usb.o ./Core/Src/usb.su

.PHONY: clean-Core-2f-Src

