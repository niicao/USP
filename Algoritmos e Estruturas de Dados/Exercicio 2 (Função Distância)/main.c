/* 
 * File:   main.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "ponto.h"

/*
 * 
 */
int main(int argc, char** argv) {

    //declaraçoes
    PONTO *centro_circulo = ponto_criar();
    CIRCULO *c;
    float a, b, r;


    scanf(" %f %f %f", &a, &b, &r); //leitura do circulo 
    /*é interessante deixar um espaço antes da primeira leitura pois limpa o buffer*/


    ponto_set(centro_circulo, a, b);
    c = circulo_criar(centro_circulo, r);


    unsigned int n; //numero de pontos
    scanf(" %d", &n);


    PONTO *ponto_aux = ponto_criar();

    while (n--) {
        scanf(" %f %f", &a, &b);
        ponto_set(ponto_aux, a, b);

        //diferencia da (distancia do ponto com o centro do circulo) com o tamanho do raio
        float resultado = distancia(circulo_get_ponto(c), ponto_aux) - circulo_get_raio(c);

        if (resultado < 0)
            printf("dentro\n");
        else if (resultado > 0)
            printf("fora\n");
        else
            printf("no raio\n");

    }



    //sempre lembrar de desalocar a memoria que foi alocada
    ponto_apagar(&centro_circulo);
    ponto_apagar(&ponto_aux);
    circulo_apagar(&c);


    return (EXIT_SUCCESS);
}

