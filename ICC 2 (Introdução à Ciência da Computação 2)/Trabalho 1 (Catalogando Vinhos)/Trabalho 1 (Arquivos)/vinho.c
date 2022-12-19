//Nicholas Yudi Kurita Ikai - 13671852
//Introdução a Ciência da Computação 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vinho
{
    int id;
    double citric_acid, residual_sugar;
    double density, pH, alcohol;
};

typedef struct Vinho vinho;

//funcao encarregada de ler as categorias no cabeçalho (comeco do arquivo)
int read_categories(FILE* arquivo){
    int i = -1;
    char* first_line;

    first_line = malloc(sizeof(char));
    if(first_line == NULL){
        printf("erro de alocacao\n");
        free(first_line);
    }

    do{

        i++;
        fscanf(arquivo, "%c", &first_line[i]);
        first_line = realloc(first_line, (i+2)*sizeof(char));
        //do jeito que esta sendo lido, deve ser somado + 2 para que o realloc nao execute com o mesmo tamanho.
    }while(first_line[i] != '0');

    free(first_line);
    return sizeof(first_line) - 1;
    //o -1 desconsidera o zero que define a parada do while, ou seja, a funcao lê até o primeiro numero (ID == 0)
    //mas retorna apenas o tamanho do cabecalho
    
}

vinho* ler_lista(FILE* arquivo, vinho* lista, int* count){
    int contador = 0;
    lista = malloc(sizeof(vinho));

    while(!feof(arquivo)){
        fscanf(arquivo, "%d,%lf,%lf,%lf,%lf,%lf", &lista[contador].id, &lista[contador].citric_acid, &lista[contador].residual_sugar, &lista[contador].density, &lista[contador].pH, &lista[contador].alcohol);
        contador++;
        lista = realloc(lista, (contador+1)*sizeof(vinho));
    }

    *count = contador; //desconsiderar o zero
    //a var count retorna o ultimo ID da lista, ou seja, o tamanho da lista contando a partir do zero, portanto deve ser subtraido uma unidade
    return lista;
}
