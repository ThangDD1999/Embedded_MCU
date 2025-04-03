GCC_DIR := C:/GNU_Arm_Embedded_Toolchain/10_2021_10/
CC=$(GCC_DIR)/bin/arm-none-eabi-gcc.exe
LD_FILE := Linker/STM32F103C8TX_FLASH.ld


MODULE := GPIO
PATH_OUTPUT = ./Output

# Include files
INC_DIRS += 	Driver/$(MODULE)/inc \
				User/inc
INC_FILES = $(foreach var,$(INC_DIRS), $(wildcard $(var)/*))

# Source files
SRC_DIRS +=		Driver/$(MODULE)/src \
				User/src \
				Startup
				
SRC_FILES = $(foreach var,$(SRC_DIRS), $(wildcard $(var)/*.c))

# CC Opt for INC_DIRS
INC_DIRS_OPT =$(foreach var, $(INC_DIRS), -I$(var))

# Object Files
OBJ_FILES := $(notdir $(SRC_FILES))
OBJ_FILES := $(subst .c,.o,$(OBJ_FILES))
PATH_OJBS := $(foreach var,$(OBJ_FILES), $(PATH_OUTPUT)/$(var))

CHIP=cortex-m3

CCFLAGS = -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 -g $(INC_DIRS_OPT)
LDFLAGS = -nostdlib -T $(LD_FILE) -Wl,-Map=$(PATH_OUTPUT)/$(MODULE).map

vpath %.c $(SRC_DIRS)

all: $(PATH_OUTPUT)/$(MODULE).hex

%.o:%.c
	$(CC) $(CCFLAGS) -o $(PATH_OUTPUT)/$@ $^

$(PATH_OUTPUT)/$(MODULE).elf: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $(PATH_OJBS)

$(PATH_OUTPUT)/$(MODULE).hex: $(PATH_OUTPUT)/$(MODULE).elf
	$(GCC_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "$^" "$@"

run:
	./Tools/ST-LINK_Utility/ST-LINK_CLI.exe -ME
	./Tools/ST-LINK_Utility/ST-LINK_CLI.exe -p "$(PATH_OUTPUT)/$(MODULE).hex" 0x08000000
	./Tools/ST-LINK_Utility/ST-LINK_CLI.exe -rst

clean:
	@rm -rf $(PATH_OUTPUT)/*
	@echo "Clear all output file!"

print-%:
	@echo $($(subst print-,,$@))
