GCC_DIR := C:/GNU_Arm_Embedded_Toolchain/10_2021_10/
CC=$(GCC_DIR)/bin/arm-none-eabi-gcc.exe
LD_FILE := Linker/STM32F103C8TX_FLASH.ld
INC_DIR := 	Driver/GPIO/inc \
			Startup


CHIP=cortex-m4

CCFLAGS = -c -mcpu=$(CHIP) -mthumb -std=gnu11 -O0 -I$(INC_DIR)
LDFLAGS = -nostdlib -T $(LD_FILE) -Wl,-Map=Output/GPIO.map

build: Output/GPIO.hex

Output/main.o: User/src/main.c
	$(CC) $(CCFLAGS) -o Output/main.o User/src/main.c
Output/GPIO.o: Driver/GPIO/src/GPIO.c
	$(CC) $(CCFLAGS) -o Output/GPIO.o Driver/GPIO/src/GPIO.c
Output/Statup.o: Startup/stm32_startup.c
	$(CC) $(CCFLAGS) -o Output/Statup.o Startup/stm32_startup.c

Output/GPIO.elf: Output/main.o Output/GPIO.o Output/Statup.o
	$(CC) $(LDFLAGS) -o Output/GPIO.elf Output/main.o Output/GPIO.o Output/Statup.o

Output/GPIO.hex: Output/GPIO.elf
	$(GCC_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex "Output/GPIO.elf" "Output/GPIO.hex"

run:
	./Tools/ST-LINK_Utility/ST-LINK_CLI.exe -ME
	./Tools/ST-LINK_Utility/ST-LINK_CLI.exe -p "Output/GPIO.hex" 0x08000000
	./Tools/ST-LINK_Utility/ST-LINK_CLI.exe -rst

clean:
	@rm -rf Output/*
	@echo "Clear all output file!"
