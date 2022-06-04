#include <stdio.h>

int main()
{
    double ray;
    double area;
  
    scanf("%lf", &ray);
  
    area = ray * ray * 3.14159;
  
    printf("%.4f", area);
    
    return 0;
}
