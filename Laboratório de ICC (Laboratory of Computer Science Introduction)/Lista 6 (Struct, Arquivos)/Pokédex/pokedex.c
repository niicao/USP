#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pokemon{
    char nome[50];
    char tipo1[20];
    char tipo2[20];
};

struct atributos{
    int hp;
    int atk;
    int def;
    int atksp;
    int defsp;
    int spd;
};

struct ataques{
    char ataque_nome[20];
    int base_power;
    float accuracy;
    char class;
};



typedef struct pokemon pokemon;
typedef struct atributos atributos;
typedef struct ataques ataques;

//A struct dos ataques foi feita com um vetor e utilizando multiplos de 4 para localizar a qual pokemon pertence.
//exemplo: o pokemon indice 3 com ataque indice 1 terá o ataque na posicao 13 (4*3 + 1)
//por esse motivo toda alocacao de memoria dos ataques tem seu valor multiplicado por 4

int main(){

    pokemon *pokedex;
    atributos *status;
    ataques *kit;

    int operador = 1, indice = 0;
    char caracter;
    int indice_print = 0, atk_print = 0;
    int indice_pkmn;
    int indice_atk;
    int indice_final;

    pokedex = malloc(sizeof(pokemon));
    status = malloc(sizeof(atributos));
    kit = malloc(4*sizeof(ataques));

    if(pokedex == NULL){
        printf("Erro de alocacao na pokedex");
        exit(1);
    }
    if(status == NULL){
        printf("Erro de alocacao no status");
        exit(1);
    }
    if(kit == NULL){
        printf("Erro de alocacao no kit");
        exit(1);
    }
    do{
        scanf("%d\n", &operador);
        //alocacao dinamica das structs
        pokedex = realloc(pokedex, (indice + 1)*sizeof(pokemon));
        status = realloc(status, (indice + 1)*sizeof(atributos));
        kit = realloc(kit, 4*(indice + 1)*sizeof(ataques));
        if(pokedex == NULL){
            printf("Erro de alocacao na pokedex");
            exit(1);
        }
        if(status == NULL){
            printf("Erro de alocacao no status");
            exit(1);
        }
        if(kit == NULL){
            printf("Erro de alocacao no kit");
            exit(1);
        }


        switch(operador){
        case 1: //cadastrar pokemon sem seus ataques

            for(int i = 0; i < 50; i++){ //cadastro dos nome 
                caracter = getchar();
                if(caracter == '\n'){
                    pokedex[indice].nome[i] = '\0';
                    break;
                }
                pokedex[indice].nome[i] = caracter;

            }


            for(int i = 0; i < 20; i++){ //cadastro do tipo 1
                caracter = getchar();
                if(caracter == '\n'){
                    pokedex[indice].tipo1[i] = '\0';
                    break;
                }
                pokedex[indice].tipo1[i] = caracter;

            }

            for(int i = 0; i < 20; i++){ //cadastro do tipo 2
                caracter = getchar();
                if(caracter == '\n'){
                    pokedex[indice].tipo2[i] = '\0';
                    break;
                }
                pokedex[indice].tipo2[i] = caracter;

            }
            //cadastro dos atributos do pokemon
            scanf("%d\n", &status[indice].hp); 
            scanf("%d\n", &status[indice].atk);
            scanf("%d\n", &status[indice].def);
            scanf("%d\n", &status[indice].atksp);
            scanf("%d\n", &status[indice].defsp);
            scanf("%d\n", &status[indice].spd);

            indice++;

            break;

        case 2: //add ataque a um pokemon especifico pelo indice
                
                scanf("%d\n", &indice_pkmn);
                scanf("%d\n", &indice_atk);
                indice_final = (indice_pkmn*4) + indice_atk; //esse indice converte as duas coordenadas (indice do pokemon na pokedex e o indice do ataque) em uma só, a coordenada do vetor de ataques.
                scanf("%s\n", kit[indice_final].ataque_nome);
                scanf("%d\n", &kit[indice_final].base_power);
                scanf("%f\n", &kit[indice_final].accuracy);
                scanf("%c\n", &kit[indice_final].class);



            break;

        case 3://imprimir os dados de um pokemon na base de dados
            scanf("%d\n", &indice_print);
            printf("Nome do Pokemon: %s\n", pokedex[indice_print].nome);
            printf("Tipo primario: %s\n", pokedex[indice_print].tipo1);
            printf("Tipo secundario: %s\n", pokedex[indice_print].tipo2);
            printf("Status:\n");
            printf("\tHP: %d\n", status[indice_print].hp);
            printf("\tAtaque: %d\n", status[indice_print].atk);
            printf("\tDefesa: %d\n", status[indice_print].def);
            printf("\tAtaque Especial: %d\n", status[indice_print].atksp);
            printf("\tDefesa Especial: %d\n", status[indice_print].defsp);
            printf("\tVelocidade: %d\n\n", status[indice_print].spd);
            break;
            
        case 4:
            scanf("%d\n", &indice_print);
            scanf("%d\n", &atk_print);
            indice_print = (indice_print*4) + atk_print;
            printf("Nome do Ataque: %s\n", kit[indice_print].ataque_nome);
            printf("Poder base: %d\n", kit[indice_print].base_power);
            printf("Acuracia: %f\n", kit[indice_print].accuracy);
            printf("Classe: %c\n\n", kit[indice_print].class);
            break;

        default:
            break;
        }
    }while(operador != 0);

    free(pokedex);
    free(status);
    free(kit);


    return 0;
}
