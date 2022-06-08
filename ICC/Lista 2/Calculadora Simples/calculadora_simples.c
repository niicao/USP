#include <stdio.h>

int main()
{
    float a, b, aux;
    int c, error;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%d", &c);
    error = -1;
    if(c==1){
        aux=a+b;
        printf("%.1f", aux);
    }
    else if(c==2){
        aux=a-b;
        printf("%.1f", aux);
    }
    else if(c==3){
        aux=a*b;
        printf("%.1f", aux);
    }
    else if(c==4){
        aux=a/b;
        printf("%.1f", aux);
    }
    else if ((c<1) | (c>4)){
        printf("%d", error);
    }
    return 0;
}
