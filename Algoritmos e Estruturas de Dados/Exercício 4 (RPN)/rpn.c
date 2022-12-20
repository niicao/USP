#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pilha.h"
#include "item.h"

typedef struct pilha PILHA;


float rpn(char* sequencia){
    ITEM* auxiliar;
    float operando1, operando2, conversor;
    PILHA* stack = pilha_criar();
    float foperando1, foperando2;
    float resultado = 0;
    int contador = 0;
    while(sequencia[contador] != '\0'){
        if(sequencia[contador] != '+' && sequencia[contador] != '*' && sequencia[contador] != '/' && sequencia[contador] != '-'){
            conversor = sequencia[contador];
            conversor = conversor - '0';
            //a linha acima converte o valor ascii de volta para float
            auxiliar = item_criar(conversor);
            pilha_empilhar(stack, auxiliar);

        }
        


        else{

            operando1 = item_get_chave(pilha_desempilhar(stack));
            operando2 = item_get_chave(pilha_desempilhar(stack));
            if(sequencia[contador] == '+'){
                resultado = operando2 + operando1;
                auxiliar = item_criar(resultado);
                pilha_empilhar(stack, auxiliar);
            }

            else if(sequencia[contador] == '-'){
                resultado = operando2 - operando1;
                auxiliar = item_criar(resultado);
                pilha_empilhar(stack, auxiliar);
            }

            else if(sequencia[contador] == '/'){
                resultado = operando2 / operando1;
                auxiliar = item_criar(resultado);
                pilha_empilhar(stack, auxiliar);               
            }

            else if(sequencia[contador] == '*'){
                resultado = operando2 * operando1;
                auxiliar = item_criar(resultado);
                pilha_empilhar(stack, auxiliar);           
            }
        }
        contador++;
    }
    return resultado;
    while(!pilha_vazia(stack)){
        pilha_desempilhar(stack);
    }
    pilha_apagar(&stack);
}