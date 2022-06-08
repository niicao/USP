#include <stdio.h>

int main()
{
    int h1, h2, m1, m2, s1, s2, auxh, auxm, auxs, fh, fm, fs;
    scanf("%d", &h1);
    scanf("%d", &m1);
    scanf("%d", &s1);
    scanf("%d", &h2);
    scanf("%d", &m2);
    scanf("%d", &s2);
    auxs= s1+s2;
    if(auxs>=60){ /* uso de if para aferir se a soma de horas irá resultar em um número excedente*/
        fs= auxs % 60;
        m1= m1 + 1;
    }
    
    else{
        fs = auxs;
    }
    
    auxm = m1 + m2;
    if(auxm >= 60){
        fm = auxm % 60;
        h1 = h1 + 1;
    }
    else{
        fm = auxm;
    }
    
    auxh = h1 + h2;
    if (auxh > =24){
        fh = auxh % 24;
    }
    
    else{
        fh = auxh;
    }
    printf("%02d:%02d:%02d", fh, fm, fs); /* uso de %02d para adicionar zeros na frente de horarios menores que 10*/
}
