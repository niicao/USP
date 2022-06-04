#include <stdio.h>

int main()
{
    int dist;
    float comb;
    float consmedio;
    
    scanf("%d", &dist);
    scanf("%f", &comb);
    
    consmedio = dist/comb;
    
    printf("%.3f", consmedio);

    
    return 0;
}
