#include <stdio.h>

int main()
{
    int cem=0, cinq=0, vint=0, dez=0, cinco=0, dois=0, um=0, saldo;
    scanf("%d", &saldo);
    if(saldo >= 100){
        cem = saldo/100;
        saldo = saldo%100;
    }
    if(saldo >= 50){
        cinq = saldo/50;
        saldo = saldo%50;
    }
    if(saldo >= 20){
        vint = saldo/20;
        saldo = saldo%20;
    }
    if(saldo >= 10){
        dez = saldo/10;
        saldo = saldo%10;
    }
    if(saldo >= 5){
        cinco = saldo/5;
        saldo = saldo%5;
    }
    if(saldo >= 2){
        dois = saldo/2;
        saldo = saldo%2;
    }
    if(saldo <= 1){
        um = saldo;
    }
    printf("%d nota(s) de 100, %d nota(s) de 50, %d nota(s) de 20, %d nota(s) de 10, %d nota(s) de 5, %d nota(s) de 2 e %d moeda(s) de 1.", cem, cinq, vint, dez, cinco, dois, um);
    return 0;
}
