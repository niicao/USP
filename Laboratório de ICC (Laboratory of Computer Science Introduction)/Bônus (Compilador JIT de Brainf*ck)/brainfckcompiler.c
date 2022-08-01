#include <stdio.h>
#include <stdlib.h>

int main(){
    char caracter;
    FILE* arquivo;
    arquivo = fopen("executavel.c", "w");
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    fprintf(arquivo, "#include <stdio.h>\n#include <stdlib.h>\n");//imprimir os headers e as declarações
    fprintf(arquivo, "int main(){\n");
    fprintf(arquivo, "char memoria[30000];\n");
    fprintf(arquivo, "int i = 0;\n");
    fprintf(arquivo, "for(int j = 0; j < 30000; j++){\n");
    fprintf(arquivo, "memoria[j] = 0;\n");
    fprintf(arquivo, "}\n");


    do{
        caracter = getchar();//recebendo os comandos da linguagem BF e imprimindo os codigos correspondentes em linguagem C no arquivo
        switch(caracter){
            case '+':
                fprintf(arquivo, "memoria[i]++;\n");
                break;
            case '-':
                fprintf(arquivo, "memoria[i]--;\n");
                break;

            case '>':
                fprintf(arquivo, "i++;\n");
                break;
            case '<':
                fprintf(arquivo, "i--;\n");
                break;
            case '.':
                fprintf(arquivo, "putchar(memoria[i]);\n");
                break;
            case '[':
                fprintf(arquivo, "while(memoria[i]){\n");
                break;
            case ']':
                fprintf(arquivo, "}\n");
                break;

        }

    }while(caracter != EOF);

    fprintf(arquivo, "printf(\"\\n\");\n"); //imprimindo o final do arquivo
    fprintf(arquivo, "for (int j = 0; j < 30000; j++) {\n");
    fprintf(arquivo, "if (memoria[j] != 0) {\n");
    fprintf(arquivo, "printf(\"%%d \", memoria[j]);\n");
    fprintf(arquivo, "}\n");
    fprintf(arquivo, "}\n");
    fprintf(arquivo, "printf(\"\\n\");\n");
    fprintf(arquivo, "return 0;\n}");
    fclose(arquivo);
    system("gcc executavel.c -o jit-exe");//compilando o arquivo jit
    system("./jit-exe");
    return 0;
}