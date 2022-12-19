#ifndef ARVORE_H
    #define ARVORE_H

    #include <stdbool.h>

    typedef struct node node;

    node* criar_arvore(int num_alunos, int num_notas, int* tamanho);

    void ler_dados(node* arvore, int num_notas, int num_alunos, int tamanho);

    bool allocate_students(node* arvore, int tamanho, int num_notas);

    node compare(node* one, node* two, int num_notas);

    int torneioGeralSort(node* arvore, int tamanho, int num_notas, int aux_posicao, int num_alunos);

    node* compareptr(node* one, node* two, int num_notas);

    void freetree(node** arvore, int tamanho, int num_notas);

    void free_notas(node* arvore, int tamanho, int num_notas);
#endif