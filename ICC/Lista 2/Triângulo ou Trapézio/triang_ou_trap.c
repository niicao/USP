#include <stdio.h>
int main()
{
    float a, b, c, result;
    
    scanf("%f %f %f", &a, &b, &c);
    if(a < (b + c) && b < (a + c) && c < (a+b)){
        result = a + b + c;
        printf("Perimetro = %.1f", result);
    }
    else{
        result = (a + b) * c/2;
        printf("Area = %.1f", result);
    }
    return 0;
}
