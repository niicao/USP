#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"

typedef struct No NO; 
struct No{
    ITEM *item;
    NO *esq;
    NO *dir;
};

struct abb{ 
    NO *raiz;    
    int profundidade;
};

typedef struct abb ABB;

ABB *abb_criar (void){
    ABB* arvore;
    arvore = (ABB*) malloc(sizeof(ABB));

    arvore->raiz = NULL;
    arvore->profundidade = 0;

    return arvore;
}

bool abb_vazia(ABB *T){
    if(T->raiz == NULL){
        return true;
    }
    
    else{
        return false;
    }
}

bool abb_inserir (ABB *T, ITEM *item){
    NO* node = (NO*) malloc(sizeof(NO));
    node->item = item;
    node->esq = NULL;
    node->dir = NULL;
    NO* aux;
    int contador = 1;

    if(T->raiz == NULL){
        T->raiz = node;
        T->profundidade++;
        return true;
    }

    else{
        aux = T->raiz;
        while(aux != NULL){

            if(item_get_chave(item) > item_get_chave(aux->item)){

                if(aux->dir == NULL){
                    aux->dir = node;
                    T->profundidade++;
                    return true;
                }

                aux = aux->dir;
                contador++;
            }

            else if(item_get_chave(item) < item_get_chave(aux->item)){

                if(aux->esq == NULL){
                    T->profundidade++;
                    aux->esq = node;
                    return true;
                }

                aux = aux->esq;
                contador++;
            }

        }

    }
}

bool abb_remover(ABB *T, int chave){
    NO* aux = T->raiz;
    NO* found_element;
    NO* down_element;
    while(item_get_chave(aux->item) != chave && aux != NULL){
        if(chave > item_get_chave(aux->item)){
            aux = aux->dir;
        }
        else if(item_get_chave(aux->item) > chave){
            aux = aux->esq;
        }
    }
    if(aux == NULL){
        return NULL;
    }

    if(aux->dir != NULL && aux->esq == NULL){
        NO *temp = aux->dir;
        aux->item = aux->dir->item;
        free(aux->dir);
        aux->dir = NULL;
        return true;
    }

    else if(aux->esq != NULL && aux->dir == NULL){
        NO *temp = aux->esq;
        aux->item = aux->esq->item;
        free(aux->esq);
        aux->esq = NULL;
        
        return true;
    }

}

ITEM *abb_busca(ABB *T, int chave){
    NO* aux = T->raiz;
    
    if(chave == item_get_chave(aux->item)){
        return aux->item;
    }

    while(item_get_chave(aux->item) != chave){

        if(item_get_chave(aux->item) < chave){
            if(aux->dir == NULL){
                return NULL;
            }
            aux = aux->dir;
        }

        else if(item_get_chave(aux->item) > chave){
            if(aux->esq == NULL){
                return NULL;
            }
            aux = aux->esq;
        }

    }

    if(item_get_chave(aux->item) == chave){
        return aux->item;
    }
    else{
        return NULL;
    }
}



void abb_apagar (ABB **T){
    free(T);
}
