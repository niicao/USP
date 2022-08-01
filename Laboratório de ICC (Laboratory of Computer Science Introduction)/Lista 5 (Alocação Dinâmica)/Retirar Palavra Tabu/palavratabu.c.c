#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char palavraTabu[20];
    char letra;
    char *frase;
    int auxiliar = 0, tamanho_tabu;
    int count = 0;
    char *pointer_flag;

    scanf("%s\n", palavraTabu);
    //determinando o tamanho da palavra tabu
    tamanho_tabu = strlen(palavraTabu);
    frase = malloc(sizeof(char));
    if(frase == NULL){
        printf("erro de alocacao");
    }

    while(1 == 1){ //loop para receber os caracteres enquanto a letra recebida for diferente de '$'
        letra = getchar();
        if(letra == '$'){
            break;
        }
        frase[auxiliar] = letra;
        frase = realloc(frase, (auxiliar + 1)*sizeof(char));

        pointer_flag = strstr(frase, palavraTabu);
        if(pointer_flag != NULL){ //detectar se a frase contem uma palavra tabu
            count++;
            for(int i = auxiliar; i > (auxiliar - tamanho_tabu); i--){ //censura as letras da palavra tabu trocando-as por '*'
                frase[i] = '*';
            }
        }
        auxiliar++;
    
    }   

    printf("A palavra tabu foi encontrada %d vezes\n", count);
    printf("Frase: ");
    for(int i = 0; i < auxiliar; i++){

        if(frase[i] != '*'){ //imprime todos os caracteres nao censurados
            printf("%c", frase[i]);
        }
        
    }

    free(frase);


    return 0;
}