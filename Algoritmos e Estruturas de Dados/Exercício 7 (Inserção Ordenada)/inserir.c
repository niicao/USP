#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
bool lista_inserir(LISTA* lista, ITEM* item){
    int auxiliar;
    if(lista_cheia(lista)){
        return false;
    }

    else if(lista_vazia(lista)){
        lista->lista[lista->inicio] = item;
        lista->fim++;
        return true;
    }

    else{
        for (int i = lista->inicio; i < lista->fim; i++){
            if(item_get_chave(item) < item_get_chave(lista->lista[i])){
                auxiliar = i;
                break;
                printf("auxiliar: %d\n", auxiliar);
            }
            else if(i == lista->fim - 1){
                lista->lista[lista->fim] = item;
                lista->fim++;
                return true;
            }
        }

        for(int j = lista->fim; j >= auxiliar; j--){
            lista->lista[j+1] = lista->lista[j];
        }
        lista->lista[auxiliar] = item;
        lista->fim++;
        return true;
    }
}