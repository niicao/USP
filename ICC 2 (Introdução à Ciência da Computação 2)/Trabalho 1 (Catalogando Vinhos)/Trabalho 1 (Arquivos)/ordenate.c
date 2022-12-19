//Nicholas Yudi Kurita Ikai - 13671852
//Introdução a Ciência da Computação 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vinho.h"

struct Vinho
{
    int id;
    double citric_acid, residual_sugar;
    double density, pH, alcohol;
};

typedef struct Vinho vinho;


int busca_binaria(vinho* lista, double valor, char* key, int comprimento, int minimo, int *id){

    //o caso abaixo ocorre quando nao há vinhos com a caracteristica buscada
    if(minimo+1 == comprimento){
        return 0;
    }


    if(strcmp(key, "citric_acid") == 0){
        if(lista[(comprimento+minimo)/2].citric_acid < valor){
            return busca_binaria(lista, valor, key, comprimento, (comprimento+minimo)/2, id);

        }

        if(lista[(comprimento+minimo)/2].citric_acid > valor){
            return busca_binaria(lista, valor, key, (comprimento+minimo)/2, minimo, id);
        }

        //após encontrar algum vinho com a caracteristica desejada, o programa vai subir na lista ate que encontre um valor diferente
        //do procurado, entao ele armazena o ID do primeiro vinho na lista com o valor desejado (que possui o menor ID) e a partir dai, descer na lista
        //ate encontrar um vinho com um valor maior do que o que está sendo procurado, ao encontrá-lo ele terá armazenado o numero de vinhos
        //percorridos, ou seja, o numero de vinhos que possuem a caracteristica em comum
        if(lista[(comprimento+minimo)/2].citric_acid == valor){
            comprimento = (comprimento+minimo)/2;
            while(lista[comprimento-1].citric_acid == valor && comprimento > 0){
                comprimento--;
            }
            *id = comprimento;
            while(lista[comprimento+1].citric_acid == valor){
                comprimento++;
            }
            return comprimento - *id + 1;
        }
    }

    else if(strcmp(key, "residual_sugar") == 0){
        if(lista[(comprimento+minimo)/2].residual_sugar < valor){
            return busca_binaria(lista, valor, key, comprimento, (comprimento+minimo)/2, id);

        }

        if(lista[(comprimento+minimo)/2].residual_sugar > valor){
            return busca_binaria(lista, valor, key, (comprimento+minimo)/2, minimo, id);
        }

        if(lista[(comprimento+minimo)/2].residual_sugar == valor){
            comprimento = (comprimento+minimo)/2;
            while(lista[comprimento-1].residual_sugar == valor && comprimento > 0){
                comprimento--;
            }
            *id = comprimento;
            while(lista[comprimento+1].residual_sugar == valor){
                comprimento++;
            }
            return comprimento - *id + 1;
        }
    } 
    
    else if(strcmp(key, "density") == 0){
        if(lista[(comprimento+minimo)/2].density < valor){
            return busca_binaria(lista, valor, key, comprimento, (comprimento+minimo)/2, id);

        }

        if(lista[(comprimento+minimo)/2].density > valor){
            return busca_binaria(lista, valor, key, (comprimento+minimo)/2, minimo, id);
        }

        if(lista[(comprimento+minimo)/2].density == valor){
            comprimento = (comprimento+minimo)/2;
            while(lista[comprimento-1].density == valor && comprimento > 0){
                comprimento--;
            }
            *id = comprimento;
            while(lista[comprimento+1].density == valor){
                comprimento++;
            }
            return comprimento - *id + 1;
        }
    } 

    else if(strcmp(key, "pH") == 0){
        if(lista[(comprimento+minimo)/2].pH < valor){
            return busca_binaria(lista, valor, key, comprimento, (comprimento+minimo)/2, id);

        }

        if(lista[(comprimento+minimo)/2].pH > valor){
            return busca_binaria(lista, valor, key, (comprimento+minimo)/2, minimo, id);
        }

        if(lista[(comprimento+minimo)/2].pH == valor){
            comprimento = (comprimento+minimo)/2;
            while(lista[comprimento-1].pH == valor && comprimento > 0){
                comprimento--;
            }
            *id = comprimento;
            while(lista[comprimento+1].pH == valor){
                comprimento++;
            }
            return comprimento - *id + 1;
        }
    }
    
    else if(strcmp(key, "alcohol") == 0){
        if(lista[(comprimento+minimo)/2].alcohol < valor){

            return busca_binaria(lista, valor, key, comprimento, (comprimento+minimo)/2, id);

        }

        if(lista[(comprimento+minimo)/2].alcohol > valor){

            return busca_binaria(lista, valor, key, (comprimento+minimo)/2, minimo, id);
        }

        if(lista[(comprimento+minimo)/2].alcohol == valor){
            comprimento = (comprimento+minimo)/2;
            while(lista[comprimento-1].alcohol == valor && comprimento > 0){
                comprimento--;
            }
            *id = comprimento;
            while(lista[comprimento+1].alcohol == valor){
                comprimento++;
            }
            return comprimento - *id + 1;
        }
    }
}


//a funcao retorna a propria funcao ate que o comprimento seja zero, onde o comprimento representa a maior posicao i do vetor
// que ainda nao foi substituida pela variavel de maior valor nao ordenada
vinho* ordenar(vinho* lista, int comprimento, char* key){
    vinho auxiliar, swap;
    double maior_valor = 0;
    int id, posicao;
    if(comprimento == 1){
        return lista;
    }

    else if(strcmp(key, "citric_acid") == 0){
        for(int i = 0; i < comprimento; i++){
            if(lista[i].citric_acid > maior_valor){
                id = i;
                posicao = i;
                maior_valor = lista[i].citric_acid;
                auxiliar = lista[i];
            }

            if(lista[i].citric_acid == maior_valor){
                if(lista[i].id > auxiliar.id){
                    posicao = i;
                    maior_valor = lista[i].citric_acid;
                    auxiliar = lista[i];
                }
            }

        }
    swap = lista[comprimento];
    lista[comprimento] = auxiliar;
    lista[posicao] = swap;

    return ordenar(lista, comprimento-1, key);
    }



    else if(strcmp(key, "residual_sugar") == 0){
        for(int i = 0; i < comprimento; i++){
            if(lista[i].residual_sugar > maior_valor){
                id = i;
                posicao = i;
                maior_valor = lista[i].residual_sugar;
                auxiliar = lista[i];
            }

            if(lista[i].residual_sugar == maior_valor){
                if(lista[i].id > auxiliar.id){
                    posicao = i;
                    maior_valor = lista[i].residual_sugar;
                    auxiliar = lista[i];
                }
            }

        }
    swap = lista[comprimento];
    lista[comprimento] = auxiliar;
    lista[posicao] = swap;

    return ordenar(lista, comprimento-1, key);
    }

    else if(strcmp(key, "density") == 0){
        for(int i = 0; i < comprimento; i++){
            if(lista[i].density > maior_valor){
                id = i;
                posicao = i;
                maior_valor = lista[i].density;
                auxiliar = lista[i];
            }
            if(lista[i].density == maior_valor){
                if(lista[i].id > auxiliar.id){
                    posicao = i;
                    maior_valor = lista[i].density;
                    auxiliar = lista[i];
                }
            }

        }
    swap = lista[comprimento];
    lista[comprimento] = auxiliar;
    lista[posicao] = swap;

    return ordenar(lista, comprimento-1, key);
    }  

    else if(strcmp(key, "pH") == 0){
        for(int i = 0; i < comprimento; i++){
            if(lista[i].pH > maior_valor){
                id = i;
                posicao = i;
                maior_valor = lista[i].pH;
                auxiliar = lista[i];
            }

            if(lista[i].pH == maior_valor){
                if(lista[i].id > auxiliar.id){
                    posicao = i;
                    maior_valor = lista[i].pH;
                    auxiliar = lista[i];
                }
            }


        }
    swap = lista[comprimento];
    lista[comprimento] = auxiliar;
    lista[posicao] = swap;

    return ordenar(lista, comprimento-1, key);
    }

    else if(strcmp(key, "alcohol") == 0){
        for(int i = 0; i < comprimento; i++){
            if(lista[i].alcohol > maior_valor){
                id = i;
                posicao = i;
                maior_valor = lista[i].alcohol;
                auxiliar = lista[i];
            }

            if(lista[i].alcohol == maior_valor){
                if(lista[i].id > auxiliar.id){
                    posicao = i;
                    maior_valor = lista[i].alcohol;
                    auxiliar = lista[i];
                }
            }


        }
    swap = lista[comprimento];
    lista[comprimento] = auxiliar;
    lista[posicao] = swap;

    return ordenar(lista, comprimento-1, key);
    }

}