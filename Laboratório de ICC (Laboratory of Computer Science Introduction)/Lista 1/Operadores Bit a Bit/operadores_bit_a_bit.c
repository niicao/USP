#include <stdio.h>

int main()
{
    int a;
    int b;
  
    scanf("%d", &a);
    scanf("%d", &b);
  
    printf("%d\n", a&b);
    printf("%d\n", a|b);
    printf("%d\n", a^b);
    printf("%d\n",~a);
    printf("%d\n", ~b);
    printf("%d\n", a>>2);
    printf("%d", b<<2);
    return 0;
}
