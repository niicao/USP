#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ponto.h"

struct circulo_{
    PONTO *centro;
    float r;
};

typedef struct circulo_ CIRCULO;

CIRCULO *circulo_criar (PONTO *p, float raio){
    CIRCULO *c = malloc(sizeof(CIRCULO));
    if(c == NULL){
        printf("Erro de alocacao");
        exit(-1);
    }
    c->centro = p;
    assert(c->centro != NULL);
    c->r = raio;

    return c;
    free(c);

}

float circulo_get_raio (CIRCULO *c){
    return c->r;
}

PONTO *circulo_get_ponto(CIRCULO *c){
    return c->centro;
}

bool circulo_set_ponto(CIRCULO *c, PONTO *p){
    if(c != NULL){
        return true;
    }
    else{
        printf("Ponteiro nulo\n");
        return false;
    }

}

bool circulo_set_raio(CIRCULO *c, float raio){
    if(c != NULL){
        c->r = raio;
        return true;
    }
    else{
        printf("Ponteiro nulo\n");
        return false;
    }
}

void circulo_apagar(CIRCULO **c){
    free(*c);
}

void circulo_print(CIRCULO *c){
    printf("Circulo: Centro (%.1f, %.1f), Raio = %.1f \n", ponto_get_x(circulo_get_ponto(c)), ponto_get_y(circulo_get_ponto(c)), circulo_get_raio(c));
}