#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int **imagem;
    int **padding_imagem;
    int altura, largura;
    int largura_padding;

    scanf("%d\n%d", &largura, &altura);

    imagem = (int**)malloc(altura*sizeof(int*));
    if(imagem == NULL){
        printf("Erro de alocacao");
        exit(1);
    }

    for(int i = 0; i < altura; i++){
        imagem[i] = (int*)malloc(largura*sizeof(int));
        if(imagem[i] == NULL){
            printf("Erro de alocacao");
            for(int j = 0; j < i; j++){
                free(imagem[i]);
            }
            free(imagem);
            exit(1);
        }
    }

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            scanf("%d ", &imagem[i][j]);
        }
    }
    
    scanf("%d", &largura_padding);
    
    //calculo das posicoes e coordenadas da matriz com borda

    largura_padding = 2*largura_padding;

    padding_imagem = (int**)malloc((largura_padding + altura)*sizeof(int*));
    if(padding_imagem == NULL){
        printf("Erro de alocacao");
        exit(1);
    }

    for(int i = 0; i < (altura + largura_padding); i++){
        padding_imagem[i] = (int*)malloc((largura_padding + largura)*sizeof(int));
        if(padding_imagem[i] == NULL){
            printf("Erro de alocacao");
            for(int j = 0; j < i; j++){
                free(padding_imagem[i]);
            }
            free(padding_imagem);
            exit(1);
        }
    }


    //insercao da matriz antiga na matriz com borda
    int auxiliar_i = 0, auxiliar_j = 0;
    for(int i = (largura_padding / 2); i < (altura + (largura_padding / 2)); i++){
        for(int j = (largura_padding / 2); j < (largura + (largura_padding / 2)); j++){
            padding_imagem[i][j] = imagem[auxiliar_i][auxiliar_j];
            auxiliar_j++;
        }
        auxiliar_j = 0;
        auxiliar_i++;
    }



    /////////////////////////////////////////////////////////////////////
    //print das matrizes

    for(int i = 0; i < largura_padding + altura; i++){
        for(int j = 0; j < largura_padding + largura; j++){
            printf("%d ", padding_imagem[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i < altura; i++){
        for(int j = 0; j < largura; j++){
            printf("%d ", imagem[i][j]);
        }
        printf("\n");
    }

    return 0;




}
