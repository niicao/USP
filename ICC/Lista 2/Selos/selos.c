#include <stdio.h>

int main()
{
    int saldo, cinc=0, tres=0, aux1=0;
    scanf("%d", &saldo);
    
    cinc = saldo/5;
    tres = (saldo%5)/3;
    aux1 = (saldo%5)%3;
    if(aux1 == 1){
        cinc = cinc - 1;
        tres = tres + 2;
    }
    else if(aux1 == 2){
        cinc = cinc - 2;
        tres = tres + 4;
    }
    
    if(saldo < 8){
        cinc = 0;
        tres = 0;
    }
    printf("Quantidade de selos de 5: %d\nQuantidade de selos de 3: %d", cinc, tres);
    return 0;
    
}
