#include <stdio.h>
#include <stdlib.h>

void calculo(int moedas[6], int* valor){
    moedas[0] = *valor/(100);
    moedas[1] = (*valor % 100)/50;
    moedas[2] = ((*valor % 100)%50)/25;
    moedas[3] = (((*valor % 100)%50)%25)/10;
    moedas[4] = ((((*valor % 100)%50)%25)%10)/5;
    moedas[5] = ((((*valor % 100)%50)%25)%10)%5/1;
}

int main(){
    int quantia[6];
    int *total;
    int moedinhas;
    scanf(" %d", &moedinhas);
    total = &moedinhas;

    calculo(quantia, total);
    printf("O valor consiste em %d moedas de 1 real\n", quantia[0]);
    printf("O valor consiste em %d moedas de 50 centavos\n", quantia[1]);
    printf("O valor consiste em %d moedas de 25 centavos\n", quantia[2]);
    printf("O valor consiste em %d moedas de 10 centavos\n", quantia[3]);
    printf("O valor consiste em %d moedas de 5 centavos\n", quantia[4]);
    printf("O valor consiste em %d moedas de 1 centavo\n", quantia[5]);
    return 0;

}