
#include <stdio.h>

int main() {
    
    double a, b, c, d, menor, media;
    
    scanf(" %le %le %le %le", &a, &b, &c, &d);
    menor = a;
    
    if(menor>b){
        menor = b;
    }
    
    if (c<menor){
        menor = c;
    }
    
    if (d<menor){
        menor = d;
    }

    if(menor == a){
        media = (b + c + d)/3;
    }

    if(menor == b){
        media = (a + c + d)/3;
    }
    
    if(menor == c){
        media = ( a + b + d)/3;
    }
    
    if(menor == d){
        media = (a + b + c)/3;
    }
    
    printf("%.4f\n", media);
    return 0;
}
