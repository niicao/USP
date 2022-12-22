#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fila_apagar(FILA** f){

    fila_remover(*f);

    
    if(!fila_vazia(*f)){
        fila_apagar(f);
    }
    else{
        *f = NULL;
    }

    
}