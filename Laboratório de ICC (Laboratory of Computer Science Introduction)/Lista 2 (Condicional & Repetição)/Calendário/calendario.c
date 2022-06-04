// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int dia;
    
    scanf("%d", &dia);
    
    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n                ");
    for(int i=1; i<=30; i++){
        if(i != dia && i < 10){
            printf("  %d ", i);
            
        }
        else if(i != dia && i >= 10){
            printf(" %d ", i );
        }
        else if(i == dia){
            printf("(%2d)", dia);
            
        }
        if((i+4) % 7 == 0){
            printf("\n");
        }
        
        
        
    }
    
    return 0;
}
