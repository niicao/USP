#include <stdio.h>

int main()
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    
    if(a >= b + c||b >= a + c||c >= a + b){
        printf("NAO FORMA TRIANGULO\n");
    }
    else{
        if((a * a) == ( b * b + c * c) || b * b == (a * a + c * c)|| c * c == (a * a + b * b)){
            printf("TRIANGULO RETANGULO\n");
        }
        else{
            if(a * a > (b * b + c * c) || b * b > (a * a + c * c) || c * c > (a * a + b * b)){
                printf("TRIANGULO OBTUSANGULO\n");
            }
            
            else if(a * a < (b * b + c * c) || b * b < (a * a + c * c) || c * c < (a * a + b * b)){
                printf("TRIANGULO ACUTANGULO\n");
                }
        }
        if(a == b && a == c ){
            printf("TRIANGULO EQUILATERO\n");
        }
        
        
        else if(a == b || b == c || c == a){
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    return 0;
}
