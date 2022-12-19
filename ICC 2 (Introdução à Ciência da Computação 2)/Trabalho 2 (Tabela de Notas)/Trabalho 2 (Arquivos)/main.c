//Nicholas Yudi Kurita Ikai - 13671852 - Introdução a Ciencia da Computação 2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "arvore.h"


typedef struct node node;

struct node
{
    char aluno[50];
    int* vetor_notas;
    node* esquerda;
    node* direita;
    int desempate;
    float media;
};

int main(){
    int num_alunos, num_notas;
    int tamanho = 2;
    node* arvore;
    int ranking = 1; //variavel que printa as colocacoes de cada aluno

    scanf("%d %d", &num_alunos, &num_notas);

    arvore = criar_arvore(num_alunos, num_notas, &tamanho);

    ler_dados(arvore, num_notas, num_alunos, tamanho);

    allocate_students(arvore, tamanho, num_notas);


    torneioGeralSort(arvore, tamanho, num_notas, ranking, num_alunos);

    free_notas(arvore, tamanho, num_notas);

    freetree(&arvore, tamanho, num_notas);

    return 0;
}
