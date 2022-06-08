#include <stdio.h>

int main()
{
    int m[3][5];
    int determinante;
    
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &m[i][j]);
        }
    }
    
    
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            m[i][j+3] = m[i][j];
        }
    }
    
    
    
    
    for(int j = 0; j < 3; j++){
        determinante += m[0][j]*m[1][j+1]*m[2][j+2];   
    }
    
    for(int j = 4; j > 1; j--){
        determinante -= m[0][j]*m[1][j-1]*m[2][j-2];
    }
    
    
    printf("%d", determinante);
    return 0;
}
