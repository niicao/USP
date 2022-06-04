#include <stdio.h>

int main()
{
    int anoBissexto;
    
    scanf("%d", &anoBissexto);

    if(anoBissexto % 4 == 0){
        printf("SIM");
    }

        else
            printf("NAO");

    return 0;
}
