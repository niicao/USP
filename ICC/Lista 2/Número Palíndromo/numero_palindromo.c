#include <stdio.h>

int main()
{
    int numero, aux1, aux3;
    scanf("%d", &numero);
    if((numero < 100)|(numero > 999)){
        printf("INVALIDO");
    }
    else if((numero >= 100)|(numero <= 999)){
        aux1 = numero/100;
        aux3 = ((numero%100)%10);
        if(aux1 == aux3){
            printf("SIM");
        }
        else{
            printf("NAO");
        }
        
    }
        
    
    return 0;
}
