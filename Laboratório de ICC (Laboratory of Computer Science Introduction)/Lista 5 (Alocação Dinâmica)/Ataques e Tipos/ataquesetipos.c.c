#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float** alocar_matriz(int M, int N){
    float** matriz;
    matriz = malloc(M*sizeof(float*));
    if(matriz == NULL){
        printf("Erro de alocacao");
        exit(1);
    }

    for(int i = 0; i < N; i++){
        matriz[i] = malloc(N*sizeof(float));
        if(matriz[i] == NULL){
            printf("erro de alocacao");
            for(int k = 0; k < i; k++){
                free(matriz[k]);
            }
            free(matriz);
        }
    }
    return matriz;
}

int main(){
    int M;
    float** matriz;
    int *ataques, *tipos;
    int auxiliar = 0;
    int inimigo;
    float maior_poder, poder;
    int id;

    scanf("%d", &M);
    matriz = alocar_matriz(M, M);
    ataques = malloc(sizeof(int));
    tipos = malloc(sizeof(int));
    if(ataques == NULL || tipos == NULL){
        printf("erro de realocacao");
        exit(1);
    }
    

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            scanf("%f", &matriz[i][j]);
        }
    }



    do{
        if(auxiliar != 0){ //o espaco sera alocado assim que é verificado que o ataque inserido nao tem valor -1
            ataques = realloc(ataques, (auxiliar + 1)*sizeof(int));
            tipos = realloc(tipos, (auxiliar + 1)*sizeof(int));
            
            if(ataques == NULL || tipos == NULL){
                printf("erro de realocacao");
                exit(1);
            }

        }
        getchar(); //limpar o buffer de entrada
        scanf("%d", &ataques[auxiliar]);
        if((ataques[auxiliar]) == -1){
            break;
        }
        scanf("%d", &tipos[auxiliar]);

        auxiliar++;


    }while(1 == 1);
    getchar(); //limpar o buffer de entrada 

    scanf("%d", &inimigo);

    for(int i = 0; i < M; i++){

        poder = (matriz[i][inimigo])*(ataques[i]);
        if(i == 0 || maior_poder < poder){
            maior_poder = poder;
            id = i;
        }

    }

    

    printf("O melhor ataque possui indice %d e dano %.2f\n", id, maior_poder);

    free(ataques);
    free(tipos);
    for(int i = 0; i < M; i++){
        free(matriz[i]);

    }
    free(matriz);






    return 0;


}