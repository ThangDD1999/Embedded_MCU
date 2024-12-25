output/main.o:src/main.c
	gcc -c -I./include src/main.c -o output/main.o
output/sum.o:src/sum.c
	gcc -c -I./include src/sum.c -o output/sum.o
build:output/main.o output/sum.o
	gcc output/main.o output/sum.o -o output/main.exe
run:
	output/main.exe

clean:
	rm output/*
