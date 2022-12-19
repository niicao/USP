all: arvore.o main.o
	gcc arvore.o main.o -o arvore -std=c99 -Wall

arvore.o:
	gcc -c arvore.c -o arvore.o

main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o arvore

run:
	./arvore