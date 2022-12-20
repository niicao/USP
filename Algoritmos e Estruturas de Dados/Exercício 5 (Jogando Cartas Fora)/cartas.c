#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "fila.h"

void cartas(int n){
    FILA* fila, *fila_discart;

    fila = fila_criar();
    fila_discart = fila_criar();

    for(int i = 1; i <= n; i++){
        fila_inserir(fila, item_criar(i));
    }

    int count = 1;

    while(!fila_vazia(fila)){
        if(fila_tamanho(fila) == 1){
            printf("Discarded cards:");
            while(!fila_vazia(fila_discart)){
                printf(" %d", item_get_chave(fila_remover(fila_discart)));
                if(!fila_vazia(fila_discart)){
                    printf(",");
                }
            }
            printf("\n");
            printf("Remaining card: ");
            printf("%d\n", item_get_chave(fila_remover(fila)));
            break;
        }
        if(count % 2 == 1){
            fila_inserir(fila_discart, fila_remover(fila));
        }
        else if(count % 2 == 0){
            fila_inserir(fila, fila_remover(fila));
        }
       
       count++;
    }

    fila_apagar(&fila);
    fila_apagar(&fila_discart);

   

}