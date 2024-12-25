all:
	gcc -E main.c -o main.i
	gcc -S main.i -o main.s
	as main.s -o main.o
	gcc -E sum.c -o sum.i
	gcc -S sum.i -o sum.s
	as sum.s -o sum.o
	gcc -v -o main main.o sum.o
run:
	main.exe