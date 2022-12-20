#include <stdio.h>


#include "circulo.h"
int main(){
    PONTO *ponto;
    float x, y, raio;

    scanf("%f", &x); 
    scanf("%f", &y);

    ponto = ponto_criar(x, y);
    if(ponto_set(ponto, x, y) == true){
        ponto_print(ponto);
    }

    CIRCULO *c;
    PONTO *center;
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &raio);
    
    center = ponto_criar(x, y);
    c = circulo_criar(center, raio);

    if(circulo_set_ponto(c, center) == true && circulo_set_raio(c, raio) == true){
        circulo_print(c);
    }

    ponto_apagar(ponto);
    ponto_apagar(center);
    circulo_apagar(c);
    return 0;
}