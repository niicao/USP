#include <stdio.h>

int main()
{
    int numero, resto;
    scanf("%d", &numero);
    resto=numero%2;
    if(numero<=0){
        printf("INVALIDO");
    }
    else if(resto==1){
        printf("IMPAR");
    }
    else if(resto==0){
        printf("PAR");
    }
    
    
    return 0;
}
