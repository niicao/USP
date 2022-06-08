#include <stdio.h>

int main()
{
    int m[2][3];
    
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &m[i][j]);
        }
    }
    for(int j = 0; j < 3; j++){
        for (int i = 0; i < 2; i++){
            printf("%d ", m[i][j]);
            if(i == 1){
                printf("\n");
            }
        }
    }
    return 0;
}
