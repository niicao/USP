all: item.o abb.o main.o
	gcc item.o abb.o main.o -o abb -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

abb.o:
	gcc -c ABB.c -o abb.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o abb

run:
	./abb

alo:
	./abb < 1.in