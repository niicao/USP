#include <stdio.h>

int main() {
    int numRodadas, numJogadores, posicaoPingu, turno = 1;
    
    scanf("%d %d %d", &numRodadas, &numJogadores, &posicaoPingu);
    
    for(int counterRodada = 1; counterRodada<=numRodadas/3; counterRodada++){
        for(int i = 0; i != counterRodada && turno <= numRodadas; i++){
            if(counterRodada<2 && (turno-posicaoPingu)%numJogadores==0){
                printf("%d pinguim\n", counterRodada);
            }
            else if((turno-posicaoPingu)%numJogadores==0){
                printf("%d pinguins\n", counterRodada);
            }
            turno++;
        }
        
        
        for(int i = 0; i != counterRodada && turno <= numRodadas; i++){
            
            if((turno-posicaoPingu)%numJogadores==0){
                    printf("no gelo\n");
            }
            turno++;
        }
        
        
        
        for(int i = 0; i != counterRodada && turno <= numRodadas; i++){
            
            if((turno-posicaoPingu)%numJogadores==0){
            printf("uhuu!\n");
        }
        turno++;
    }
    
}
return 0;
}
