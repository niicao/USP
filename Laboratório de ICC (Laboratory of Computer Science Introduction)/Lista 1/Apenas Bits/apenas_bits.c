#include <stdio.h>

int main() {
    
    int a;
    char b;
    char c;
    char d;
    char e;
    int aux;
    aux = 255;
    scanf("%d", &a); //coleta do numero
    b = a&aux;
    c = (a>>8)&aux; //shift de 8 casas do numero a
    d = (a>>16)&aux; //shift de 16 casas do numero a
    e = (a>>24)&aux; //shift de 24 casas do numero a
    printf("%c%c%c%c", e, d, c, b); //as variaveis foram invertidas, ja que ao usar left shift, a mascara de bits nao funcionava, entao a solucao que achei foi inverter a ordem de print das variaveis char
    
    return 0;
}
