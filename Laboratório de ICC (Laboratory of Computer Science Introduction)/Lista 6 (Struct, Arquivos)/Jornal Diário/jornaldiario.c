#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float calculo(int total, int candidato){
    float resultado, tot, cand;
    tot = total;
    cand = candidato;

    resultado = (float)(cand/tot)*100.0;

    return resultado;
}


int main(){
    FILE* arquivo_original;
    FILE* arquivo_candidato;
    char nome_original[100], nome_candidato[100];
    int numero_total = 0, numero_candidato = 0, flag = 1;//comeca em 1, pois se comecasse em zero, desconsideraria a primeira palavra
    char caracter;
    float porcentagem;
    
    scanf("%s\n", nome_original);
    scanf("%s", nome_candidato);

    arquivo_original = fopen(nome_original, "r");
    arquivo_candidato = fopen(nome_candidato, "r");

    if(arquivo_original == NULL || arquivo_candidato == NULL){
        printf("arquivo nao encontrado\n");
        fclose(arquivo_candidato);
        fclose(arquivo_original);
        exit(1);
    }
    
    while((fscanf(arquivo_original, "%c", &caracter) != EOF)){

        if(caracter == '\n' || caracter == '\t' || caracter == '\r' || caracter == ' '){
            flag = 1;
        }

        else if(flag != 0){
            flag = 0;
            numero_total++;
        }
    }

    flag = 1;

    while((fscanf(arquivo_candidato, "%c", &caracter) != EOF)){

        if(caracter == '\n' || caracter == '\t' || caracter == '\r' || caracter == ' '){
            flag = 1;
        }

        else if(flag != 0){
            flag = 0;
            numero_candidato++;
        }
    }



    fclose(arquivo_original);
    fclose(arquivo_candidato);

    porcentagem = calculo(numero_total, numero_candidato);
    if(porcentagem > 20){
        printf("O candidato digitou %d de %d palavras (%.0f%%).\nParabéns, candidato! Você foi aprovado!", numero_candidato, numero_total, floor(porcentagem));
    }

    else{
        printf("O candidato digitou %d de %d palavras (%.0f%%).\nLamentamos informar, mas você não cumpre os requisitos da vaga, candidato!", numero_candidato, numero_total, floor(porcentagem));
    }

    return 0;






}
