#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pilha.h"
#include "item.h"

bool balanceada(char* sequencia){
	PILHA* aberto = pilha_criar();
	ITEM* topo;
	int contador = 0;
	while(sequencia[contador] != '\0' && !(pilha_cheia(aberto))){
		if(sequencia[contador] == '[' || sequencia[contador] == '{' || sequencia[contador] == '('){
			pilha_empilhar(aberto, item_criar(sequencia[contador]));
		}
		else{
            if(pilha_vazia(aberto)){
                pilha_apagar(&aberto);
                return false;
            }
			topo = pilha_topo(aberto);
			if(item_get_chave(topo) == '[' && sequencia[contador] != ']'){
                pilha_apagar(&aberto);
				return false;
			}
			if(item_get_chave(topo) == '{' && sequencia[contador] != '}'){
                pilha_apagar(&aberto);
				return false;
			}
			if(item_get_chave(topo) == '(' && sequencia[contador] != ')'){
                pilha_apagar(&aberto);
				return false;
			}

			else{
				topo = pilha_desempilhar(aberto);
			}
		}
		contador++;
	}
    if(!pilha_vazia(aberto)){
        while(!pilha_vazia(aberto)){
            pilha_desempilhar(aberto);
        }
        pilha_apagar(&aberto);
        return false;
    }
    pilha_apagar(&aberto);
	return true;


}