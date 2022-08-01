#include <stdio.h>
#include <stdlib.h>

int** multiplicacao(int **matriz, int altura, int largura){

    
    int **resultado;
    int auxiliar = 0;

    resultado = malloc(altura*sizeof(int*));
    if(resultado == NULL){
        printf("erro de alocacao");
        exit(1);
    }

    for(int i = 0; i < altura; i++){
        resultado[i] = malloc(altura*sizeof(int));
        if(resultado[i] == NULL){
            printf("erro de alocacao");
            for(int j = 0; j < i; j++){
                free(resultado[j]);

            }
            free(resultado);
        }
    }
    //calculando as multiplicacoes dos elementos pelos elementos da transposta
    while(auxiliar < altura){
        for(int i = 0; i < altura; i++){
            for(int j = 0; j < largura; j++){
                resultado[auxiliar][i] += matriz[auxiliar][j]*matriz[i][j];
            }
        }
        auxiliar++;
    }


    return resultado;

}

int main(){
    int altura, largura;
    int **matriz;
    int **resultado;

    scanf("%d %d", &altura, &largura);
    //alocando a matriz
    matriz = (int**)malloc(altura*sizeof(int*));
    
    if(matriz == NULL){
        printf("Erro de alocacao");
        exit(1);
    }

    for(int i = 0; i < altura; i++){
        matriz[i] = (int*) malloc(largura*sizeof(int));
        if(matriz[i] == NULL){
            printf("Erro de alocacao");
            for(int j = 0; j < i; j++){
                free(matriz[j]);        
            }
            free(matriz);
        }
    }
    //alocando a matriz dos resultados
    resultado = malloc(altura*sizeof(int*));

    if(resultado == NULL){
        printf("erro de alocacao");
        exit(1);
    }

    for(int i = 0; i < altura; i++){
        resultado[i] = malloc(altura*sizeof(int));
        if(resultado[i] == NULL){
            printf("erro de alocacao");
            for(int j = 0; j < i; j++){
                free(resultado[j]);

            }
            free(resultado);        }
    }

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    resultado = multiplicacao(matriz, altura, largura);

    printf("%d %d ", altura, altura);

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < altura; j++){
            printf("%d ", resultado[i][j]);
        }
    }
    
    return 0;
}