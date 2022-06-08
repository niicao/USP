#include <stdio.h>

int main()
{
    int num, digito1, digito2;
    scanf("%d", &num);
    digito1 = num/10;
    digito2 = num%10;
    if(digito1 == digito2){
        printf("FELIZ");
    }
    else{
        printf("TRISTE");
    }
    
    return 0;
}
