################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/linpack.c \
../src/platform.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/linpack.o \
./src/platform.o 

C_DEPS += \
./src/linpack.d \
./src/platform.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -DSP -Wall -O3 -c -fmessage-length=0 -D __XMK__ -I../../xilkernel_bsp_0/microblaze_0/include -mcpu=v8.20.a -mxl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


