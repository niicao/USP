#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "lista.h"




int busca_rec(LISTA *lista, int chave){
    int contador = 0;

    NO* buscador;
    buscador = lista->inicio;
    //loop para achar itens e marcá-los
    while(lista->fim->proximo != buscador){
        if(item_get_chave(buscador->item) == chave){
            buscador->item = item_criar(-1);
            return busca_rec(lista, chave);
        }

        buscador = buscador->proximo;
    }

    buscador = lista->inicio;
    //loop para contagem dos itens e restauração dos itens marcados
    //a restauracao ocorre para nao interferir em outras buscas
    while(lista->fim->proximo != buscador){
        if(item_get_chave(buscador->item) == -1){
            contador++;
            buscador->item = item_criar(chave);
        }
        buscador = buscador->proximo;
    }
    return contador;
}