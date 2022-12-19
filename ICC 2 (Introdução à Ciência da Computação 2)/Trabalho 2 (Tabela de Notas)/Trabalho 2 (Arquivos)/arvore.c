#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

typedef struct node node;

struct node
{
    char aluno[50]; //Nome
    int* vetor_notas; //ponteiro que armazena as notas
    node* esquerda; //ponteiro para os filhos
    node* direita;
    int desempate; //numero que armazena a nota responsavel pelo desempate
    float media; 
};


void freetree(node** arvore, int tamanho, int num_notas){
    free(*arvore);
}

void free_notas(node* arvore, int tamanho, int num_notas){
    for(int i = 1; i < tamanho; i++){
        free(arvore->vetor_notas);
    }
}

node* criar_arvore(int num_alunos, int num_notas, int* tamanho){
    node* arvore;
    while(num_alunos > *tamanho){
        *tamanho = *tamanho*2; //define o tamanho total da arvore (vai até a primeira potencia de 2 maior que o num de elementos)
    }
    *tamanho = *tamanho*2; //torna o tamanho 2k, onde k é a primeira potencia de 2 maior q num de elementos

    arvore = malloc((*tamanho)*sizeof(node));
    assert(arvore != NULL);



    for(int i = 1; i < *tamanho; i++){ // o for loop começa em 1, evitando o indice 0, como recomendado
        arvore[i].vetor_notas = calloc(num_notas, sizeof(int));
        arvore[i].media = -1;
        arvore[i].direita = NULL;
        arvore[i].esquerda = NULL;
    }


    return arvore;
}

bool ler_dados(node* arvore, int num_notas, int num_alunos, int tamanho){
    int contador = num_alunos;
    int auxiliar_media = 0;

    for(int i = 0; i < tamanho-contador; i++){
        arvore[i].media = -1; //incializa todas as medias como -1
    }

    while(contador > 0){
        scanf("%s", arvore[tamanho - contador].aluno);
        //tamanho - contador faz com que apenas as folhas sejam preenchidas (os ultimos k elementos do vetor)

        for(int i = 0; i < num_notas; i++){
            scanf("%d", &arvore[tamanho - contador].vetor_notas[i]);

            auxiliar_media = arvore[tamanho - contador].vetor_notas[i] + auxiliar_media; //realiza a soma das medias
        }

        arvore[tamanho - contador].media = (float)auxiliar_media/num_notas; //divide a soma total pelo numero de notas

        auxiliar_media = 0;        
        contador--; 
    }



    return true;
}

node compare(node* one, node* two, int num_notas){
    //essa funcao é responsavel por comparar os pares e retornar o elemento com maior media, de tal forma que o elemento retornado será o pai daquele par

    if((*one).media > (*two).media){
        return *one;
    }

    else if((*two).media > (*one).media){
        return *two;
    }


    else if((*one).media == -1 && (*two).media == -1){
        return *two;
    }

    else{ //caso as medias sejam iguais
        for(int i = 0; i < num_notas; i++){
            if((*one).vetor_notas[i] > (*two).vetor_notas[i]){
                if(one->desempate < i+1)    //esse if só será ativado caso o numero da nota de desempate seja maior que a anterior
                    one->desempate = i+1;   //caso X desempate com Y pela nota 2 e depois com Z pela nota 1, esse if garante que a nota 2 permanecerá
                return *one;                //pois Y é maior que Z, mesmo que tenha sido eliminado primeiro
            }


            else if((*two).vetor_notas[i] > (*one).vetor_notas[i]){
                if(two->desempate < i+1)
                    two->desempate = i+1;
                return *two;
            }
        }
    }
}


node* compareptr(node* one, node* two, int num_notas){ //esta funcao é parecida com a acima, porem ela é responsavel pela comparacao de cima para baixo
                                                       //de forma a achar a folha que tem o mesmo valor da raiz e substituir por -1
    if((*one).media > (*two).media && (*one).media != -1 && (*two).media != -1){
        return one;
    }

    else if((*two).media > (*one).media  && (*one).media != -1 && (*two).media != -1){
        return two;
    }

    else if((*one).media > (*two).media)
        return one;

    else if((*two).media > (*one).media)
        return two;


    else{
        for(int i = 0; i < num_notas; i++){
            if((*one).vetor_notas[i] > (*two).vetor_notas[i]){
                return one;
            }


            else if((*two).vetor_notas[i] > (*one).vetor_notas[i]){
                return two;
            }
        }
    }
}

bool allocate_students(node* arvore, int tamanho, int num_notas){//funcao responsavel por preencher o resto da arvore, apos as folhas terem sido alocadas
                                                                 //pela funcao ler_dados
    for(int i = tamanho-2; i >= 2; i = i-2){
        arvore[i/2] = compare(&arvore[i], &arvore[i+1], num_notas);
        arvore[i/2].esquerda = &arvore[i];
        arvore[i/2].direita = &arvore[i+1];
    }

    return true;
}

bool torneioGeralSort(node* arvore, int tamanho, int num_notas, int aux_posicao, int num_alunos){
    node* auxiliar = &arvore[1]; //variavel que percorre os nodes até chegar na folha
    allocate_students(arvore, tamanho, num_notas);

    if(aux_posicao == 1){
        printf("Maior media: %.3f\n", arvore[1].media);
    }

    if(arvore[1].media != -1){
        printf("%d. %s", aux_posicao, arvore[1].aluno);
        if(arvore[1].desempate > 0){
            printf(" - desempate: nota %d\n", arvore[1].desempate);
        }
        else if(aux_posicao != num_alunos){
            printf(" - media\n");
        }

        else{
            printf("\n");
        }

        while(auxiliar->direita != NULL || auxiliar->esquerda != NULL){//auxiliar vai descendo até chegar à folha (onde os ponteiros sao nulos) que está na raiz 
            auxiliar = compareptr(auxiliar->direita, auxiliar->esquerda, num_notas);
        }

        auxiliar->media = -1;


    
        return torneioGeralSort(arvore, tamanho, num_notas, aux_posicao+1, num_alunos);
    }
    else{ //caso a raiz tenha -1 na media, significa que todos os itens ja foram ordenados, retornando true e encerrando a funcao
        return true;
    }
}



