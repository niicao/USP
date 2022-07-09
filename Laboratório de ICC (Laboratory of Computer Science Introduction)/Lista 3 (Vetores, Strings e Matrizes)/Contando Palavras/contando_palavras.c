#include <stdio.h>
#include <ctype.h>
int main(){
    int linhas = 0, letras = 0, palavras = 0;
    
    int caracter;
    int flag = 1;

    while((caracter = getchar()) != EOF){
        letras++;


        if(caracter == '\n'){
            linhas++;
        }

        if(caracter == '\n' || caracter == '\t' || caracter == '\r' || caracter == ' '){
            flag = 1;
        }

        else if(flag != 0){
            flag = 0;
            palavras++;
        }
    }

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", linhas, palavras, letras);
    return 0;
}