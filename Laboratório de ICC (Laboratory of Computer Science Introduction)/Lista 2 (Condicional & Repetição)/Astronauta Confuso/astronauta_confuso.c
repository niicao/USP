

#include <stdio.h>

int main()
{
        
    /* 1 */ 
    int ladoDoQuadr, espacoPercorr, espacoTot, chamadasFalt, chegouavez, limiteInf = 0;
    
    /* 2 */
    int horizontal = 0, vertical = 0;
     
    scanf("%d %d",&ladoDoQuadr, &espacoPercorr); 
    
    /* 3 */
    
    espacoTot = ladoDoQuadr*ladoDoQuadr;
    
    if(espacoPercorr > espacoTot){
        printf("O astronauta ja saiu em missao ha %d chamadas.\n", espacoPercorr-espacoTot);
        return 0;
    }
    /* a vez do astronauta só chega se o espacoPercorr for >= que o espacoTot */
    chegouavez = espacoPercorr;
    
    chamadasFalt = espacoTot - espacoPercorr; 
    
    if(espacoPercorr == 1){
        printf("O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!", vertical, horizontal, chamadasFalt);
    }
    
    /* contagem da casa 1 (sem isso, a posicao [0;0] nao seria contada como primeira posicao da fila) */
    espacoPercorr--;
    

    while(espacoPercorr > 0){
    
        /* percorre de 0 a L-1 */
        while(horizontal < ladoDoQuadr - 1){
            horizontal++;
            espacoPercorr--;
            
            if(espacoPercorr == 0 && chegouavez == espacoTot){
                    printf("O astronauta esta na posicao: %d %d\nPreste atencao, astronauta, chegou a sua vez!", vertical, horizontal);
                    return 0;
                }
            
            else if(espacoPercorr == 0){
                printf("O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!", vertical, horizontal, chamadasFalt);
                    return 0;
            }
        }
        
        /* percorre de 0 a L-1 */
        while(vertical < ladoDoQuadr - 1){
            vertical++;
            espacoPercorr--;
            
            if(espacoPercorr == 0 && chegouavez == espacoTot){
                    printf("O astronauta esta na posicao: %d %d\nPreste atencao, astronauta, chegou a sua vez!", vertical, horizontal);
                    return 0;
                }
            
            else if(espacoPercorr == 0){
                printf("O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!", vertical, horizontal, chamadasFalt);
                    return 0;
            }
        }
        
        /* percorre de L-1 a 0 */
        while(horizontal > limiteInf){
            horizontal--;
            espacoPercorr--;
            
            if(espacoPercorr == 0 && chegouavez == espacoTot){
                    printf("O astronauta esta na posicao: %d %d\nPreste atencao, astronauta, chegou a sua vez!", vertical, horizontal);
                    return 0;
                }
            
            else if(espacoPercorr == 0){
                printf("O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!", vertical, horizontal, chamadasFalt);
                    return 0;
            }
           
        }
        
        /* percorre de L-1 a L-(L-1) */
        while(vertical > limiteInf + 1){
            vertical--;
            espacoPercorr--;
            
            if(espacoPercorr == 0 && chegouavez == espacoTot){
                    printf("O astronauta esta na posicao: %d %d\nPreste atencao, astronauta, chegou a sua vez!", vertical, horizontal);
                    return 0;
                }
            
            else if(espacoPercorr == 0){
                printf("O astronauta esta na posicao: %d %d\nAinda faltam %d chamadas para a sua vez!", vertical, horizontal, chamadasFalt);
                    return 0;
            }
        }
        /* LadoDoQuadr é reduzido e o limiteInf aumentado, da forma que os intervalos serao sempre [limiteInf, ladoDoQuadr]
        entao num quadrado 5x5, serao ao fim de cada ciclo [0,4] [1,3] [2,2]*/
        ladoDoQuadr--;
        limiteInf++;
    }
    return 0;
}
