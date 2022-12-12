################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_ansi.c \
../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_opt.c 

C_DEPS += \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_ansi.d \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_opt.d 

OBJS += \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_ansi.o \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_opt.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/%.o Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/%.su: ../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/%.c Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/ -I"C:/ostap/APPSC/Core" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-porting-2f-espressif-2f-ESP-2d-NN-2f-src-2f-softmax

clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-porting-2f-espressif-2f-ESP-2d-NN-2f-src-2f-softmax:
	-$(RM) ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_ansi.d ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_ansi.o ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_ansi.su ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_opt.d ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_opt.o ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/porting/espressif/ESP-NN/src/softmax/esp_nn_softmax_opt.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-porting-2f-espressif-2f-ESP-2d-NN-2f-src-2f-softmax

