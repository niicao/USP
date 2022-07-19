#include <stdio.h>
#include <stdlib.h>



void einstein(char matriz[32][64]){
    char copia[32][64];

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            copia[i][j] = matriz[i][j];
            
        }
    }


    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            switch(matriz[i][j]){

                case '#':
                    if((matriz[i+1][j] == ' ' || matriz[i+1][j] == '~') && i < 31 ){
                        char tmp = copia[i][j];
                        copia[i][j] = copia[i + 1][j];
                        copia[i + 1][j] = tmp;
                        break;
                    }

                    else if((matriz[i+1][j-1] == ' ' || matriz[i+1][j-1] == '~') && i < 31 && j > 0){
                        char tmp = copia[i][j];
                        copia[i][j] = copia[i+1][j-1];
                        copia[i+1][j-1] = tmp;
                        break;
                    }

                    else if((matriz[i+1][j+1] == ' ' || matriz[i+1][j+1] == '~') && i < 31 && j < 63){
                        char tmp = copia[i][j];
                        copia[i][j] = copia[i + 1][j + 1];
                        copia[i + 1][j + 1] = tmp;
                        break;
                    }

                    else{
                        copia[i][j] = matriz[i][j];
                        break;
                    }

                case '~':
                    if(matriz[i+1][j] == ' ' && i < 31){
                        char tmp = copia[i][j];
                        copia[i][j] = copia[i + 1][j];
                        copia[i + 1][j] = tmp;
                        break;
                    }

                    else if(matriz[i+1][j-1] == ' ' && i < 31 && j > 0){
                        char tmp = copia[i][j];
                        copia[i][j] = copia[i + 1][j - 1];
                        copia[i + 1][j - 1] = tmp;
                        break;
                    }

                    else if(matriz[i + 1][j + 1] == ' ' && i < 31 && j < 63){
                        char tmp = copia[i][j];
                        copia[i][j] = copia[i + 1][j + 1];
                        copia[i + 1][j + 1] = tmp;
                        break;
                    }

                    else if(matriz[i][j - 1] == ' ' && j > 0){
                        char tmp = copia[i][j];
                        copia[i][j] = copia[i][j - 1];
                        copia[i][j - 1] = tmp;
                        break;
                    }

                    else if(matriz[i][j+1] == ' ' && j < 63){
                        char tmp = copia[i][j];
                        copia[i][j] = copia[i][j + 1];
                        copia[i][j + 1] = tmp;
                        break;
                    }

                default:
                    break;


            }

            
        }
    }


    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            matriz[i][j] = copia[i][j];
        }
    }
}

int main(){
    char matriz[32][64];
    int n_frames, frame, x, y;
    char nova_particula;
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 64; j++){
            matriz[i][j] = ' ';
        }
    }

    scanf("%d\n", &n_frames);

    int contador = 0;
    while (contador < n_frames) {

            // `scanf` retorna EOF quando chega ao fim da entrada.
            int n_lido = scanf(" %d: %d %d %c", &frame, &x, &y, &nova_particula);

            // Se não há mais partículas a serem criadas, continue até o final
            // da simulação.
            if (n_lido == EOF) {
                    frame = n_frames;
            }

            // Calcula todos os frames até o próximo frame onde queremos criar
            // uma partícula.
            while (contador < frame) {
                    printf("frame: %d\n", contador + 1);
                    for(int i = 0; i < 32; i++){
                        for(int j = 0; j < 64; j++){
                            printf("%c", matriz[i][j]);
                        }
                        printf("\n");
                    }
                    einstein(matriz);
                    /* Seu código de calcular a física */
                    contador++;
            }

            // Se há uma particula a ser criada, crie ela.
            if (n_lido != EOF) {
                    matriz[y][x] = nova_particula;
            }
    }

    return 0;
}