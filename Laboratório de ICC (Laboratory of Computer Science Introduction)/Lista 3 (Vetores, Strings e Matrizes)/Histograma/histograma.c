/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{   
    int imagem[25];
    
    int aux0 = 0, aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0;
    for(int i = 0; i < 25; i++){
        scanf("%d", &imagem[i]);
    }
    
    int posicoes0[25], posicoes1[25], posicoes2[25], posicoes3[25], posicoes4[25];
    
    for(int i = 0; i < 25; i++){
        
        if(imagem[i] == 0){
            posicoes0[aux0] = i;
            aux0++;
        }
        
        if(imagem[i] == 1){
            posicoes1[aux1] = i;
            aux1++;
        }
        
        
        if(imagem[i] == 2){
            posicoes2[aux2] = i;
            aux2++;
        }
        
        if(imagem[i] == 3){
            posicoes3[aux3] = i;
            aux3++;
        }
            
        if(imagem[i] == 4){
            posicoes4[aux4] = i;
            aux4++;
        }
        
    }
    
    printf("0: |");
    for(int i = 0; i < aux0; i++){
        printf("#");
        
        if(i == aux0-1){
            printf("\n");
        }
    }
    
    printf("1: |");
    for(int i = 0; i < aux1; i++){
        printf("#");
        
        if(i == aux1-1){
            printf("\n");
        }
    }
    
    printf("2: |");
    for(int i = 0; i < aux2; i++){
        printf("#");
        
        if(i == aux2-1){
            printf("\n");
        }
    }
    
    printf("3: |");
    for(int i = 0; i < aux3; i++){
        printf("#");
        
        if(i == aux3-1){
            printf("\n");
        }
    }
    
    printf("4: |");
    for(int i = 0; i < aux4; i++){
        printf("#");
        
        if(i == aux4-1){
            printf("\n");
        }
    }

    /*for(int i = 0; i < 25; i++){
        printf("%d %d %d %d %d", posicoes0[i], posicoes1[i], posicoes2[i], posicoes3[i], posicoes4[i]);
    }*/
    
    
    if(aux0 > aux1 && aux0 > aux2 && aux0 > aux3 && aux0 > aux4){
        for(int i = 0; i < aux0; i++){
            printf("%d\n", posicoes0[i]);
        }
        return 0;
    }
    
    if(aux1 > aux0 && aux1 > aux2 && aux1 > aux3 && aux1 > aux4){
        for(int i = 0; i < aux1; i++){
            printf("%d\n", posicoes1[i]);
        }
        return 0;
    }
    
    if(aux2 > aux0 && aux2 > aux1 && aux2 > aux3 && aux2 > aux4){
        for(int i = 0; i < aux2; i++){
            printf("%d\n", posicoes2[i]);
        }
        return 0;
    }
    
    if(aux3 > aux0 && aux3 > aux2 && aux3 > aux1 && aux3 > aux4){
        for(int i = 0; i < aux3; i++){
            printf("%d\n", posicoes3[i]);
        }
        return 0;
    }
    
    if(aux4> aux0 && aux4 > aux1 && aux4 > aux2 && aux4 > aux3){
        for(int i = 0; i < aux4; i++){
            printf("%d\n", posicoes4[i]);
        }
        return 0;
    }
    
    return 0;
}
