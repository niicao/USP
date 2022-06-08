#include <stdio.h>

int main()
{
    int A;
    int B;
    int C;
    int D;

    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &D);

    int DIFERENCA;

    DIFERENCA = A*B - C*D;
    printf("%d", DIFERENCA);

    return 0;
}
