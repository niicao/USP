#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(){
    char**nomes;
    char letra;
    int *comprimentos;
    int linhas = 0, colunas = 0;
    int auxiliar = 1, marcador = 0;
    nomes = (char**)malloc(1*sizeof(char*));
    if(nomes == NULL){
        printf("erro");
        exit(1);
    }

    nomes[0] = (char*)malloc(1*sizeof(char));
    if(nomes[0] == NULL){
        printf("erro");
        free(nomes);
        exit(1);
    }

    comprimentos = malloc(1*sizeof(int));
    while(1 == 1){
        letra = getchar();


        if(letra == '$'){

            comprimentos[linhas] = colunas;//armazena o tamanho do nome
            linhas++;
            nomes = (char**)realloc(nomes, (linhas + 1)*sizeof(char*));//aloca mais uma linha
            if(nomes == NULL){
                printf("erro");
                exit(1);
            }
            nomes[linhas] = (char*)realloc(nomes[linhas], (colunas + 1)*sizeof(char));//aloca espaco pro primeiro caracter
            if(nomes[linhas] == NULL){
                printf("erro");
                free(nomes);
                exit(1);
            }

            comprimentos = realloc(comprimentos, (linhas + 1)*sizeof(int));//aloca mais um espaco no vetor de tamanhos dos nomes
            colunas = 0;
            break;
        }

        else if(letra == '\n'){
            nomes[linhas][colunas] = '\0';//sinaliza o fim da string

            comprimentos[linhas] = colunas;
            linhas++;
            nomes = (char**)realloc(nomes, (linhas + 1)*sizeof(char*));
            if(nomes == NULL){
                printf("erro");
                exit(1);
            }
            
            colunas = 0;
            nomes[linhas] = (char*)realloc(nomes[linhas], (colunas + 1)*sizeof(char));
            if(nomes[linhas] == NULL){
                printf("erro");
                free(nomes);
                exit(1);
            }

            comprimentos = realloc(comprimentos, (linhas + 1)*sizeof(int));
        }

        else{
            nomes[linhas][colunas] = letra;//armazena a letra
            colunas++;

            nomes[linhas] = (char*)realloc(nomes[linhas], (colunas + 1)*sizeof(char));//aloca espaco para a proxima letra
            if(nomes[linhas] == NULL){
                printf("erro");
                free(nomes);
                exit(1);
            }

        }
    }


    for(int i = 0; i < linhas; i += 2){
        if(i + 1 > linhas){//interrompe caso o ultimo nome seja impar para que nao ocorra segmentation fault
            break;
        }
        for(int j = comprimentos[i] - 1; nomes[i][j] != ' '; j--){//itera do fim da string ate o ultimo espaco
            nomes[i + 1] = realloc(nomes[i + 1], (comprimentos[i + 1] + auxiliar)*sizeof(char));
            auxiliar++;
            marcador = j - 1;//armazena onde comeca o ultimo sobrenome, incluindo o espaco antes dele
        }

        nomes[i + 1] = realloc(nomes[i + 1], (comprimentos[i + 1] + auxiliar + 1)*sizeof(char));//aloca mais um espaco para incluir o \0 no fim da string


        for(int k = marcador; k <= comprimentos[i]; k++){//itera todos os nomes pares
            if(k == comprimentos[i]){
                nomes[i+1][comprimentos[i+1] + k - marcador] = '\0';
            }
            nomes[i+1][comprimentos[i+1] + k - marcador] = nomes[i][k];//pega o ultimo sobrenome do indice i e insere no final do indice i+1

        }

        auxiliar = 0;
        marcador = 0;
    }

    for(int i = 0; i < linhas; i++){
        comprimentos[i] = strlen(nomes[i]);
        for(int j = 0; j < comprimentos[i]; j++){
            printf("%c", nomes[i][j]);
        }
            printf("\n");
        
    }

    
    for(int i = 0; i < linhas; i++){
        free(nomes[i]);
    }
    free(nomes);
    return 0;
}