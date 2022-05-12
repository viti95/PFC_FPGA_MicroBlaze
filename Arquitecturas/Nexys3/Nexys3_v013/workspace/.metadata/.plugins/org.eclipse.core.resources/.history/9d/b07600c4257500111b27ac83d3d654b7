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
dhrystone_2.1.elf.size \

ELFCHECK += \
dhrystone_2.1.elf.elfcheck \


# All Target
all: dhrystone_2.1.elf secondary-outputs

# Tool invocations
dhrystone_2.1.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo Building target: $@
	@echo Invoking: MicroBlaze gcc linker
	mb-gcc -Wl,-T -Wl,../src/lscript.ld -L../../xilkernel_bsp_0/microblaze_0/lib -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-div -mcpu=v8.20.a -mno-xl-soft-mul -mxl-multiply-high -mhard-float -mxl-float-convert -mxl-float-sqrt -o"dhrystone_2.1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo Finished building target: $@
	@echo ' '

dhrystone_2.1.elf.size: dhrystone_2.1.elf
	@echo Invoking: MicroBlaze Print Size
	mb-size dhrystone_2.1.elf  |tee "dhrystone_2.1.elf.size"
	@echo Finished building: $@
	@echo ' '

dhrystone_2.1.elf.elfcheck: dhrystone_2.1.elf
	@echo Invoking: Xilinx ELF Check
	elfcheck dhrystone_2.1.elf -hw ../../Nexys3_v013_hw_platform/system.xml -pe microblaze_0  |tee "dhrystone_2.1.elf.elfcheck"
	@echo Finished building: $@
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) dhrystone_2.1.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
