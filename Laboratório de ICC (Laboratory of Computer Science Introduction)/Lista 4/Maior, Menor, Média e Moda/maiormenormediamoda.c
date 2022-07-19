#include <stdio.h>
#include <stdlib.h>

void maior(int array[10], int *maior){
    for(int i = 0; i < 10; i++){
        if(i == 0){
            *maior = array[i];
        }
        else if(*maior < array[i]){
            *maior = array[i];
        }
    }
}

void menor(int array[10], int *menor){
    for(int i = 0; i < 10; i++){
        if(i == 0){
            *menor = array[i];
        }
        else if(*menor > array[i]){
            *menor = array[i];
        }
    }
    return;
}

void media(int array[10], float *media){
    float aux_soma = 0;
    for(int i = 0; i < 10; i++){
        aux_soma += array[i];
    }
    *media = aux_soma/10;
    
}

void moda(int array[10], int *moda){
    int counter;
    int mostfrequent;
    for(int i = 0; i < 10; i++){
        counter = 1;
        for(int j = 0; j < 10; j++){
            if(array[j] == array[i]){
                counter++;
            }
        }
        if(i == 0 || counter > mostfrequent){
            mostfrequent = counter;
            *moda = array[i];
        }
    }
}

int main(){
    int array[10];
    int *higher, *lower, *fashion;
    float *average;
    int MaiorValor, MenorValor, Mooda;
    float MediaTotal;

    higher = &MaiorValor;
    lower = &MenorValor;
    fashion = &Mooda;
    average = &MediaTotal;

    for(int i = 0; i < 10; i++){
        scanf(" %d", &array[i]);
    }

    maior(array, higher);
    menor(array, lower);
    moda(array, fashion);
    media(array, average);

    printf("%d %d %.2f %d", *higher, *lower, *average, *fashion);
    
    return 0;
}