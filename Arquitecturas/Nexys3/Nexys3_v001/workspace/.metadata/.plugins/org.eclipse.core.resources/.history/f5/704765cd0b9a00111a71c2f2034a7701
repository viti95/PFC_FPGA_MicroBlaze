################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
calibrator.elf.size \

ELFCHECK += \
calibrator.elf.elfcheck \


# All Target
all: calibrator.elf secondary-outputs

# Tool invocations
calibrator.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo Building target: $@
	@echo Invoking: MicroBlaze gcc linker
	mb-gcc -Wl,-T -Wl,../src/lscript.ld -L../../xilkernel_bsp_0/microblaze_0/lib -mcpu=v8.20.a -mxl-soft-mul -o"calibrator.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo Finished building target: $@
	@echo ' '

calibrator.elf.size: calibrator.elf
	@echo Invoking: MicroBlaze Print Size
	mb-size calibrator.elf  |tee "calibrator.elf.size"
	@echo Finished building: $@
	@echo ' '

calibrator.elf.elfcheck: calibrator.elf
	@echo Invoking: Xilinx ELF Check
	elfcheck calibrator.elf -hw ../../Nexys3_v001_hw_platform/system.xml -pe microblaze_0  |tee "calibrator.elf.elfcheck"
	@echo Finished building: $@
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) calibrator.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
