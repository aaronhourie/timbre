################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)
CG_TOOL_ROOT := D:/TexasInstruments/ccsv4/tools/compiler/c5500

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./main.obj" \
"./fraction.obj" \
"./aic3204.obj" \
-l"libc.a" \
-l"ezdsp5535bsl.lib" \
-l"rts55x.lib" \
-l"cslVC5505.lib" \
"../lnkx.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: timbre.out

dependents:
	-cd D:/TexasInstruments/ccsv4/emulation/boards/ezdsp5535_v1/lib/Debug && $(MAKE) all

# Tool invocations
timbre.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS) D:/TexasInstruments/ccsv4/emulation/boards/ezdsp5535_v1/lib/Debug/../ezdsp5535bsl.lib
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"D:/TexasInstruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --diag_warning=225 --ptrdiff_size=16 --memory_model=large -z -m"timbre.map" --warn_sections -i"D:/TexasInstruments/ccsv4/tools/compiler/c5500/lib" -i"D:/TexasInstruments/ccsv4/tools/compiler/c5500/include" -i"D:/TexasInstruments/ccsv4/tools/compiler/c5500/../../../emulation/boards/ezdsp5535_v1/lib" -i"D:/TexasInstruments/ccsv4/tools/compiler/c5500/../../../emulation/boards/ezdsp5535_v1/c55xx_csl/ccs_v4.0_examples/cslVC5505/Debug" --reread_libs --rom_model -o "timbre.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C5500_EXECUTABLE_OUTPUTS__QTD) "timbre.out"
	-$(RM) ".\aic3204.obj" ".\fraction.obj" ".\main.obj" 
	-$(RM) ".\aic3204.pp" ".\fraction.pp" ".\main.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
D:/TexasInstruments/ccsv4/emulation/boards/ezdsp5535_v1/lib/Debug/../ezdsp5535bsl.lib:

-include ../makefile.targets
