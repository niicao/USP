#include <stdio.h>

int main()
{
    float A;
    float B;
    float C;
    float area_do_triangulo_AC;
    float area_do_circulo_RC;
    float area_do_trapezio;
    float area_do_quadrado;
    float area_do_triangulo_AB;
    
    scanf("%f", &A);
    scanf("%f", &B);
    scanf("%f", &C);
    
    area_do_triangulo_AC = A*C*0.5;
    area_do_circulo_RC = C*C*3.14159;
    area_do_trapezio = (A+B)*C*0.5;
    area_do_quadrado = B*B;
    area_do_triangulo_AB = A*B;
    
    printf("%.3f\n", area_do_triangulo_AC);
    printf("%.3f\n", area_do_circulo_RC);
    printf("%.3f\n", area_do_trapezio);
    printf("%.3f\n", area_do_quadrado);
    printf("%.3f\n", area_do_triangulo_AB);
    
    return 0;
}
