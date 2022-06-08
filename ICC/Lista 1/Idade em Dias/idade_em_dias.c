

#include <stdio.h>

int main()
{
    int idade;
    int anos;
    int meses;
    int dias;
    int resto1;
    
    scanf("%d", &idade);
    
    anos = idade/365;
    meses = idade%365/30;
    resto1 = idade%365;
    dias = resto1%30;
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)", dias);
    
    
    
    return 0;
}
