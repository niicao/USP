//Nicholas Yudi Kurita Ikai - 13671852
//Introdução a Ciência da Computação 2

#ifndef _VINHO_H
#define _VINHO_H

typedef struct Vinho vinho;

int read_categories(FILE* arquivo);

vinho* ler_lista(FILE* arquivo, vinho* lista, int* count);

#endif