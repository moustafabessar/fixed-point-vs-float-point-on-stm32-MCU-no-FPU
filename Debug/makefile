################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
fixed_point.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
fixed_point.list \

OBJCOPY_BIN += \
fixed_point.bin \


# All Target
all: fixed_point.elf secondary-outputs

# Tool invocations
fixed_point.elf: $(OBJS) $(USER_OBJS) C:\Users\Nvidia\Documents\MCU1\ Course\MCU2\My_workspace\MasteringMCU2_WS\fixed_point\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "fixed_point.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\Nvidia\Documents\MCU1 Course\MCU2\My_workspace\MasteringMCU2_WS\fixed_point\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="fixed_point.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -u _printf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

fixed_point.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "fixed_point.list"
	@echo 'Finished building: $@'
	@echo ' '

fixed_point.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "fixed_point.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
