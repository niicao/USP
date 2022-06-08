#include <stdio.h>

int main()
{
    double salario;
    double comissao;
    double total;

    scanf("%lf", &salario);
    scanf("%lf", &comissao);

    total = salario + comissao*0.15;
    
    printf("%.2lf", total);
    
    
    return 0;
}
