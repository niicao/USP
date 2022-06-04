#include <stdio.h>

int main()
{
    long int x1, y1, alturaRet1, larguraRet1;
    long int x2, y2, alturaRet2, larguraRet2;
    long int limiteAltura1, limiteLargura1, limiteAltura2, limiteLargura2;
    int hitX = 0, hitY = 0, flag=0;
    long int larguraRes = 0, alturaRes = 0;
    long int coordHitX, coordHitY;
    
    
    scanf("%ld %ld %ld %ld", &x1, &y1, &larguraRet1, &alturaRet1);
    scanf("%ld %ld %ld %ld", &x2, &y2, &larguraRet2, &alturaRet2);
    /* estabelecendo as coordenadas finais (vertice oposto) */
    limiteLargura1 = x1 + larguraRet1;
    limiteAltura1 = y1 + alturaRet1;
    limiteLargura2 = x2 + larguraRet2;
    limiteAltura2 = y2 + alturaRet2;
    
    /* testando o caso em que os vertices apenas se tocam */
    if((limiteLargura1 == y2 || limiteLargura2 == y1)&&(limiteAltura1 == x2 || limiteAltura2 == x1)){
        flag++;
    }
    
    /* testando se o vertice de um retangulo se encontra dentro do outro retangulo */
    if(x1 <= x2 && x2 <= limiteLargura1){
        hitX++;
        coordHitX = x2;
        /* testando o que esta mais proximo da coordenada HitX, a lateral do retangulo1, ou a lateral do
        retangulo2, se for o primeiro caso, a largura sera a diferenca entre a largura1 e a coordHitX
        se for o segundo caso, a largura sera a distancia da coordenada ate o lado do retangulo2
        (este ultimo caso é quando o retangulo se encontra dentro do outro, seja na altura ou na largura) */
        if(limiteLargura1 <= coordHitX + larguraRet2){
            larguraRes = limiteLargura1 - coordHitX;
        }

        else{
            larguraRes = larguraRet2;
        }
    }
    
    if((x2 <= x1) && (x1 <= limiteLargura2)){
        hitX++;
        coordHitX = x1;

        if(limiteLargura2 <= coordHitX + larguraRet1){
            larguraRes = limiteLargura2 - coordHitX;
        }

        else{
            larguraRes = larguraRet1;
        }
    }

    if(y1 <= y2 && y2 <= limiteAltura1){
        hitY++;
        coordHitY = y2;

        if(limiteAltura1 <= coordHitY + alturaRet2){
            alturaRes = limiteAltura1 - coordHitY;
        }

        else{
            alturaRes = alturaRet2;
        }
    }
    
    if(y2 <= y1 && y1 <= limiteAltura2){
        hitY++;
        coordHitY = y1;

        if(limiteAltura2 <= coordHitY + alturaRet1){
            alturaRes = limiteAltura2 - coordHitY;
        }

        else{
            alturaRes = alturaRet1;
        }
    }
    
    /* caso em que apenas os vertices se tocam */
    if(flag == 1){
        larguraRes = 0;
        alturaRes = 0;
    }
    if(hitX >= 1 && hitY >= 1)
        printf("HIT: %ld %ld %ld %ld", coordHitX, coordHitY , larguraRes, alturaRes);
    
    else
        printf("MISS");
    
    
    return 0;
}
