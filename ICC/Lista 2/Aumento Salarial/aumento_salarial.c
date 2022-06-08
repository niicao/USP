#include <stdio.h>

int main() {
    float salario;
    float reajuste;
    scanf("%f", &salario);
    if((0<=salario) & (salario<=400.00))
    {
        reajuste= salario*0.15;
    }
    else if((400.01<=salario) & (salario<=800.00))
    {
        reajuste= salario*0.12;
    }
    else if((800.01<=salario) & (salario<=1200.00))
    {
        reajuste= salario*0.10;
    }
    else if((1200.01<=salario) & (salario<=2000.00))
    {
        reajuste= salario*0.07;
    }
    else if(salario>2000.00){
        reajuste= salario*0.04;
    }
    printf("Novo salario: %.2f\n", salario+reajuste );
    printf("Reajuste ganho: %.2f\n", reajuste);
    printf("Em percentual: %.0f %%", (reajuste/salario)*100);
    return 0;
}
