################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MUART/subdir.mk
-include MCAL/MTIMER2/subdir.mk
-include MCAL/MTIMER1/subdir.mk
-include MCAL/MTIMER0/subdir.mk
-include MCAL/MSPI/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/HSTEPPER/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HKPD/subdir.mk
-include HAL/HCLCD/subdir.mk
-include HAL/HBUTTON/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SPI_DIRVER_PRO.lss \

FLASH_IMAGE += \
SPI_DIRVER_PRO.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SPI_DIRVER_PRO.elf secondary-outputs

# Tool invocations
SPI_DIRVER_PRO.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_DIRVER_PRO.map -mmcu=atmega32 -o "SPI_DIRVER_PRO.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_DIRVER_PRO.lss: SPI_DIRVER_PRO.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_DIRVER_PRO.elf  >"SPI_DIRVER_PRO.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_DIRVER_PRO.hex: SPI_DIRVER_PRO.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_DIRVER_PRO.elf  "SPI_DIRVER_PRO.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_DIRVER_PRO.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SPI_DIRVER_PRO.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_DIRVER_PRO.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
