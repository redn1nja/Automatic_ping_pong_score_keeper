################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.c \
../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.c \
../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.c \
../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.c 

C_DEPS += \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.d \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.d \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.d \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.d 

OBJS += \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.o \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.o \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.o \
./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/%.o Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/%.su: ../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/%.c Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/ -I"C:/ostap/Automatic_ping_pong_score_keeper/APPSC/Core" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-CMSIS-2f-NN-2f-Source-2f-ConcatenationFunctions

clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-CMSIS-2f-NN-2f-Source-2f-ConcatenationFunctions:
	-$(RM) ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.d ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.o ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.su ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.d ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.o ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.su ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.d ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.o ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.su ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.d ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.o ./Middlewares/Third_Party/EdgeImpulse_POC-APPSC_MachineLearning/edgeimpulse/edge-impulse-sdk/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-EdgeImpulse_POC-2d-APPSC_MachineLearning-2f-edgeimpulse-2f-edge-2d-impulse-2d-sdk-2f-CMSIS-2f-NN-2f-Source-2f-ConcatenationFunctions

