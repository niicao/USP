//Nicholas Yudi Kurita Ikai - 13671852
//Introdução a Ciência da Computação 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vinho.h"
#include "ordenate.h"

struct Vinho
{
    int id;
    double citric_acid, residual_sugar;
    double density, pH, alcohol;
};

//funcao que le o nome do arquivo e abre seu respectivo ponteiro
FILE* open_file(){
    FILE* arquivo;
    char nome[50];
    scanf("%s", nome);

    arquivo = fopen(nome, "r");

    return arquivo;
}


//esta funcao retorna o tamanho em bytes do arquivo lido
long int tamanho_arquivo(FILE* arquivo){
    long int tamanho;
    fseek(arquivo, 0, SEEK_END);
    ftell(arquivo);

    return tamanho;
}

vinho* copiar_lista(vinho* lista, vinho*copia, int comprimento){
    for(int i = 0; i < comprimento; i++){
        copia[i] = lista[i];
    }
    return copia;
}






int main(){
    FILE* arquivo;
    arquivo = open_file();
    unsigned int set_pointer;
    int tamanho_arquivo, comprimento, num_buscas, total;
    int minimo = 0;
    char* busca;
    double valor_busca;
    int id;

    //a funcao abaixo se encarrega de ler o cabeçalho do arquivo que contém os nomes de cada categoria e para quando encontra o primeiro numero
    read_categories(arquivo);


    //setar o cursor para um byte a menos, uma vez que ele leu o primeiro numero para sair do loop na funcao read_categories
    fseek(arquivo, -1, SEEK_CUR);

    vinho* lista;
    vinho* lista_busca;

    //a variavel comprimento se encarrega de saber o numero de vinhos presente na lista
    lista = ler_lista(arquivo, lista, &comprimento);


    scanf("%d", &num_buscas);



    for(int i = 0; i < num_buscas; i++){
        lista_busca = malloc((comprimento+1)*sizeof(vinho));

        for(int i = 0; i <= comprimento; i++){
            lista_busca[i] = lista[i];
        }
        busca = malloc(20*sizeof(char));
        scanf("%s %lf", busca, &valor_busca);
        ordenar(lista_busca, comprimento, busca);
        //a funcao ordenar, ordena o catalogo com base na categoria selecionada (var busca), priorizando sempre a ordem crescente dos IDs

        //total retorna o numero total de vinhos com a caracteristica desejada, retorna -1 caso nao encontre nenhum vinho com aquele caracteristica
        total = busca_binaria(lista_busca, valor_busca, busca, comprimento, minimo, &id);


        if(total > 0){
            printf("ID: %d, Citric Acid: %.5lf, Residual Sugar %.5lf, Density %.5lf, pH %.5lf, Alcohol %.5lf\nTotal de vinhos encontrados: %d\n", lista_busca[id].id, lista_busca[id].citric_acid, lista_busca[id].residual_sugar, lista_busca[id].density, lista_busca[id].pH, lista_busca[id].alcohol, total);
        }
        else{
            printf("Nenhum vinho encontrado\n");
        }
        minimo = 0;
        id = 0;
        total = 1;
        free(busca);
        free(lista_busca);

    }

    
    free(lista);
    fclose(arquivo);
    return 0;


}