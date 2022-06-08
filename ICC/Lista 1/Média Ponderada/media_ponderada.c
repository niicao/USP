#include <stdio.h>

int main()
{
    float notaA;
    float notaB;
    float media;
    
    scanf("%f", &notaA);
    scanf("%f", &notaB);
    media = (notaA*3.5 + notaB*7.5)/11;
    printf("%.5f", media);
    
    
    return 0;
}
