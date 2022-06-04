#include <stdio.h>

int main() {
    int coordX = 0, coordY = 0;
    char comando;
    for(int i=0; i < 6; i++){
        scanf("%c", &comando);
        if(comando == 'W')
            coordY++;
        else if(comando == 'S')
            coordY--;
        else if(comando == 'D')
            coordX++;
        else if(comando == 'A')
            coordX--;
            
    }
    
    printf("%d %d\n", coordX, coordY);
    return 0;
}
