################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
aic3204.obj: ../aic3204.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/TexasInstruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="D:/TexasInstruments/ccsv4/tools/compiler/c5500/include" --include_path="D:/TexasInstruments/ccsv4/tools/compiler/c5500/../../../emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --include_path="D:/TexasInstruments/ccsv4/tools/compiler/c5500/../../../emulation/boards/ezdsp5535_v1/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="aic3204.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/TexasInstruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="D:/TexasInstruments/ccsv4/tools/compiler/c5500/include" --include_path="D:/TexasInstruments/ccsv4/tools/compiler/c5500/../../../emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --include_path="D:/TexasInstruments/ccsv4/tools/compiler/c5500/../../../emulation/boards/ezdsp5535_v1/include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


