PROJECT_NAME := sum
SRC_DIR := D:/My_Work_Space/STM32/Hello/src
OBJ_FILES = output/main.o
OBJ_FILES += output/$(PROJECT_NAME).o

output/main.o:src/main.c
	@gcc -c -I./include src/main.c -o output/main.o
output/$(PROJECT_NAME).o:src/$(PROJECT_NAME).c
	@gcc -c -I./include src/$(PROJECT_NAME).c -o output/$(PROJECT_NAME).o

.PHONY: build
build:$(OBJ_FILES)
	@gcc $(OBJ_FILES) -o output/main.exe
	@echo "Build Done!"
	@echo $(OBJ_FILES)
.PHONY: run
run:
	output/main.exe

clean:
	@rm output/*
	@echo "Clear all output file!"

print-%:
	@echo $($(subst print-,,$@))