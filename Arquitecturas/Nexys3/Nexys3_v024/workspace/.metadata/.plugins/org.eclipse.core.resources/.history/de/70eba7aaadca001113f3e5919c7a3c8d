################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/platform.c \
../src/vitiram.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/platform.o \
./src/vitiram.o 

C_DEPS += \
./src/platform.d \
./src/vitiram.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O3 -c -fmessage-length=0 -D __XMK__ -I../../xilkernel_bsp_0/microblaze_0/include -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-div -mcpu=v8.20.a -mno-xl-soft-mul -mxl-multiply-high -mhard-float -mxl-float-convert -mxl-float-sqrt -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


