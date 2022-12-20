#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ponto.h"

PONTO *ponto_criar(float x, float y){
    PONTO *ponto_criado;

    ponto_criado = malloc(sizeof(PONTO));

    if(ponto_criado == NULL){
        printf("Erro de alocação\n");
        return NULL;
    }

    ponto_criado->coordX = x;
    ponto_criado->coordY = y;
    return ponto_criado;
    free(ponto_criado);
}

void ponto_apagar(PONTO *p){
    if(p == NULL){
        printf("Memoria nao alocada \n");
        exit (-1);
    }
    free(p);
}

bool ponto_set(PONTO *p, float x, float y){
    if(p->coordX == x && p->coordY == y && p != NULL){
        return true;
    }
    else{
        printf("Ponteiro nao foi setado\n");
        return false;
    }
}

float ponto_get_x (PONTO *p){
    if(p == NULL){
        printf("Ponteiro nulo\n");
    }
    return p -> coordX;
}

float ponto_get_y(PONTO *p){
    if(p == NULL){
        printf("Ponteiro nulo\n");
    }
    return p -> coordY;
}

void ponto_print(PONTO *p){
    printf("Ponto: (%.1f, %.1f)\n", ponto_get_x(p), ponto_get_y(p));
}