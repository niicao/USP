#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct estudantes
{
    int id;
    char* nome;
    char* curso;
    int idade;
    
};

typedef struct estudantes cadastro;


int main(){
    int numero = 0, aux_nomes = 0;
    cadastro *vetor;
    char caracter;
    
    vetor = malloc(sizeof(cadastro));
    if(vetor == NULL){
        printf("erro de alocacao");
        exit(1);
    }

//receber o NUSP do estudante
    while(1 == 1){
        scanf("%d", &vetor[numero].id);

        if((vetor[numero].id) == -1){
            break;
        }



        getchar(); //limpar o buffer
        vetor[numero].nome = malloc(sizeof(char));
        if(vetor[numero].nome == NULL){
            printf("Erro de alocacao");
            exit(1);
        }

        while(1 == 1){ //receber o nome do estudante

            caracter = getchar();
            if(caracter == '\n'){
                vetor[numero].nome[aux_nomes] = '\0';
                break;
            }

            vetor[numero].nome[aux_nomes] = caracter;
            aux_nomes++;

            vetor[numero].nome = realloc(vetor[numero].nome, (aux_nomes + 1)*sizeof(char));
            if(vetor[numero].nome == NULL){
                printf("Erro de alocacao");
                for(int i = 0; i < numero; i++){
                    free(vetor[i].nome);
                }
                for(int i = 0; i < numero - 1; i++){
                    free(vetor[i].curso);
                }
                free(vetor);
                exit(1);
            }

        }
        aux_nomes = 0; //resetar o contador

        vetor[numero].curso = malloc(sizeof(char));
        
        if(vetor[numero].curso == NULL){
            printf("Erro de alocacao");
            for(int i = 0; i < numero; i++){
                free(vetor[i].curso);
                free(vetor[i].nome);
            }
            free(vetor);
            exit(1);
        }

        while(1 == 1){
            caracter = getchar();
            if(caracter == '\n'){
                vetor[numero].curso[aux_nomes] = '\0';
                break;
            }
            vetor[numero].curso[aux_nomes] = caracter;

            aux_nomes++;

            vetor[numero].curso = realloc(vetor[numero].curso, (aux_nomes+1)*sizeof(char));
            if(vetor[numero].curso == NULL){
                printf("Erro de alocacao");
                for(int i = 0; i < numero; i++){
                    free(vetor[i].curso);
                    free(vetor[i].nome);
                }
                free(vetor);
                exit(1);
            }

        }



        aux_nomes = 0;

        scanf("%d", &vetor[numero].idade);
        numero++;
        vetor = realloc(vetor, (numero + 1)*sizeof(cadastro));
        if(vetor == NULL){
            printf("Erro de alocacao");
            for(int i = 0; i < numero - 1; i++){
                free(vetor[i].nome);
                free(vetor[i].curso);
            }
            free(vetor);
            exit(1);
        }


    }

    
    int operador = 0, numero_consulta;
    char *curso_consulta;

    do{
        scanf("%d", &operador);
        aux_nomes = 0;
        switch (operador){
        case 1:
            scanf("%d", &numero_consulta); //NUSP a ser consultado

            for(int i = 0; i < numero; i++){
                if(vetor[i].id == numero_consulta){
                    printf("Nome: %s\n", vetor[i].nome);
                    printf("Curso: %s\n", vetor[i].curso);
                    printf("N USP: %d\n", vetor[i].id);
                    printf("IDADE: %d\n", vetor[i].idade);
                    printf("\n");
                    break;
                }
            }
            break;
        
        case 2:
            curso_consulta = malloc(sizeof(char));
            if(curso_consulta == NULL){
                printf("Erro de alocacao");
                for(int i = 0; i < numero - 1; i++){
                    free(vetor[i].nome);
                    free(vetor[i].curso);
                }
                free(vetor);
                free(curso_consulta);
                exit(1);
            }

            while(1 == 1){ //recebendo o nome do curso a ser consultado
                caracter = getchar();
                if(caracter == '\n'){
                    curso_consulta[aux_nomes] = '\0';
                    break;
                }

                curso_consulta[aux_nomes] = caracter;
                aux_nomes++;
                curso_consulta = realloc(curso_consulta, sizeof(aux_nomes+1)*sizeof(char));
                if(curso_consulta == NULL){
                    printf("Erro de alocacao");
                    for(int i = 0; i < numero - 1; i++){
                        free(vetor[i].nome);
                        free(vetor[i].curso);
                    }
                    free(vetor);
                    free(curso_consulta);
                    exit(1);
                }

                
            }

            for(int i = 0; i < numero; i++){
                
                if(strcmp(curso_consulta, vetor[i].curso) == 0){
                    printf("Nome: %s\n", vetor[i].nome);
                    printf("Curso: %s\n", vetor[i].curso);
                    printf("N USP: %d\n", vetor[i].id);
                    printf("IDADE: %d\n", vetor[i].idade);
                    printf("\n");
                }
            }
            break;

        case 3: //imprime todos os estudantes
            for(int i = 0; i < numero; i++){
                printf("Nome: %s\n", vetor[i].nome);
                printf("Curso: %s\n", vetor[i].curso);
                printf("N USP: %d\n", vetor[i].id);
                printf("IDADE: %d\n", vetor[i].idade);
                printf("\n");
            }
            break;

        
        default:
            break;
        }

    }while(operador != -1);

    for(int i = 0; i < numero; i++){
        free(vetor[i].nome);
        free(vetor[i].curso);
    }
    free(vetor);
    free(curso_consulta);

    return 0;
}