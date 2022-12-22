#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "lista.h"


bool lista_inverter(LISTA** lista){

    if((*lista)->inicio != NULL){
        NO* prevNode = (*lista)->inicio;
        NO* curNode = (*lista)->inicio->proximo;
        (*lista)->inicio = (*lista)->inicio->proximo;
        prevNode->proximo = NULL;

        while((*lista)->inicio != NULL){
            (*lista)->inicio = (*lista)->inicio->proximo;
            curNode->proximo = prevNode;
            prevNode = curNode;
            curNode = (*lista)->inicio;
        }
        (*lista)->inicio = prevNode;
        return true;
    }






    return true;

}