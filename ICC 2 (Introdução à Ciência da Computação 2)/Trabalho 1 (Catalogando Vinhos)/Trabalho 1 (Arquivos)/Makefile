all: vinho.o main.o ordenate.o
	gcc -g main.o vinho.o ordenate.o -o main -std=c99 -Wall -lm

ordenate.o:
	gcc -c ordenate.c -o ordenate.o

vinho.o:
	gcc -c vinho.c -o vinho.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm vinho.o main.o ordenate.o ./main

run:
	./main
