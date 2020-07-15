################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv6/tools/compiler/c5500_4.4.1

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./Auriculares.obj" \
"./BassBoost.obj" \
"./BassTreble.obj" \
"./Clasica.obj" \
"./Dance.obj" \
"./Llano.obj" \
"./PLL.obj" \
"./Pop.obj" \
"./Rock.obj" \
"./Techno.obj" \
"./Treble.obj" \
"./Vivo.obj" \
"./aic3204.obj" \
"./aic3204_init.obj" \
"./bargraph5515.obj" \
"./main.obj" \
"./oled5515.obj" \
"./pushbuttons5515.obj" \
"./stereo.obj" \
"./usbstk5505.obj" \
"./usbstk5505_gpio.obj" \
"./usbstk5505_i2c.obj" \
"./usbstk5505_led.obj" \
"./usbstk5515.obj" \
"./usbstk5515_gpio.obj" \
"./usbstk5515_i2c.obj" \
"./usbstk5515_led.obj" \
"../55xdsph.lib" \
"../CSLc55x5h.lib" \
"../lnkx.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
EcualizaFIR.out \

EXE_OUTPUTS__QUOTED += \
"EcualizaFIR.out" \

BIN_OUTPUTS += \
EcualizaFIR.hex \

BIN_OUTPUTS__QUOTED += \
"EcualizaFIR.hex" \


# All Target
all: EcualizaFIR.out

# Tool invocations
EcualizaFIR.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C5500 Linker'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/cl55" -v5515 --memory_model=huge -g --define=c5515 --display_error_number --diag_warning=225 --ptrdiff_size=32 -z -m"EcualizaFIR.map" --stack_size=0x200 --heap_size=0x400 -i"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/lib" -i"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/include" --reread_libs --display_error_number --warn_sections --xml_link_info="EcualizaFIR_linkInfo.xml" --rom_model --sys_stacksize=0x200 -o "EcualizaFIR.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

EcualizaFIR.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C5500 Hex Utility'
	"C:/ti/ccsv6/tools/compiler/c5500_4.4.1/bin/hex55"  -o "EcualizaFIR.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "Auriculares.d" "BassBoost.d" "BassTreble.d" "Clasica.d" "Dance.d" "Llano.d" "PLL.d" "Pop.d" "Rock.d" "Techno.d" "Treble.d" "Vivo.d" "aic3204.d" "aic3204_init.d" "bargraph5515.d" "main.d" "oled5515.d" "pushbuttons5515.d" "stereo.d" "usbstk5505.d" "usbstk5505_gpio.d" "usbstk5505_i2c.d" "usbstk5505_led.d" "usbstk5515.d" "usbstk5515_gpio.d" "usbstk5515_i2c.d" "usbstk5515_led.d" 
	-$(RM) "Auriculares.obj" "BassBoost.obj" "BassTreble.obj" "Clasica.obj" "Dance.obj" "Llano.obj" "PLL.obj" "Pop.obj" "Rock.obj" "Techno.obj" "Treble.obj" "Vivo.obj" "aic3204.obj" "aic3204_init.obj" "bargraph5515.obj" "main.obj" "oled5515.obj" "pushbuttons5515.obj" "stereo.obj" "usbstk5505.obj" "usbstk5505_gpio.obj" "usbstk5505_i2c.obj" "usbstk5505_led.obj" "usbstk5515.obj" "usbstk5515_gpio.obj" "usbstk5515_i2c.obj" "usbstk5515_led.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

