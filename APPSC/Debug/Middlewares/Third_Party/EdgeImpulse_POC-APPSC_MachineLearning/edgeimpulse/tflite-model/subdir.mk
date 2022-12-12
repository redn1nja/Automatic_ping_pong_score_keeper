################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/trained_model_compiled.cpp 

OBJS += \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/trained_model_compiled.o 

CPP_DEPS += \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/trained_model_compiled.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/%.o Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/%.su: ../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/%.cpp Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/ -I"C:/ostap/APPSC/Core" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-tflite-2d-model

clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-tflite-2d-model:
	-$(RM) ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/trained_model_compiled.d ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/trained_model_compiled.o ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/tflite-model/trained_model_compiled.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-tflite-2d-model

