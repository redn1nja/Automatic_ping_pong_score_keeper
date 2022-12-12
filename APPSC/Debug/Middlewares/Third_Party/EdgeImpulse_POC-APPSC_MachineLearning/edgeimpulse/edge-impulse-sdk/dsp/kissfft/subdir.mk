################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fft.cpp \
../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fftr.cpp 

OBJS += \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fft.o \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fftr.o 

CPP_DEPS += \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fft.d \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fftr.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/%.o Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/%.su: ../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/%.cpp Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/ -I"C:/ostap/APPSC/Core" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-dsp-2f-kissfft

clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-dsp-2f-kissfft:
	-$(RM) ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fft.d ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fft.o ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fft.su ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fftr.d ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fftr.o ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/dsp/kissfft/kiss_fftr.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-dsp-2f-kissfft

