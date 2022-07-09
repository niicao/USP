#include <stdio.h>
#include <string.h>

int main(){
    
    char tabuleiro[3][3];
    char jogada;
    char espaco_livre = '-';

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            scanf(" %c", &jogada);
            tabuleiro[i][j] = jogada;

        }
    }

    for(int i = 0; i < 3; i++){
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != espaco_livre){
            printf("%c ganhou", tabuleiro[i][2]);
            return 0;
        }
    }

    for(int j = 0; j < 3; j++){
        if(tabuleiro[2][j] == tabuleiro [1][j] && tabuleiro[1][j] == tabuleiro[0][j] && tabuleiro[0][j] != espaco_livre){
            printf("%c ganhou", tabuleiro[2][j]);
            return 0;
        }

    }

    if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != espaco_livre){
        printf("%c ganhou", tabuleiro[0][0]);
        return 0;
    }

    if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[2][0] != espaco_livre){
        printf("%c ganhou", tabuleiro[0][2]);
        return 0;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabuleiro[i][j] == espaco_livre){
                printf("em jogo");
                return 0;
            }

            
        }
    }

    printf("empate");
    return 0;

    

    
}