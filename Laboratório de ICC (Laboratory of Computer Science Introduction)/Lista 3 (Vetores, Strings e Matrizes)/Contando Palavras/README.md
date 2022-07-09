## Descrição
Escreva um programa em c que conte o número de caracteres, palavras e linhas de um arquivo e imprima esses valores no seguinte formato:
![alt-text]()
Uma palavra é definida como uma sequência de caracteres quaisquer (ASCII) que não sejam ' ', '\t', '\n' nem '\r'. Ou seja, a frase "hello, world\n" é composta de duas palavras e a frase "h e l l o" seria composta de 5 palavras. Como um outro exemplo, também é possível ter uma sequência de caracteres que não compões palavra alguma: "\t\n \r\n \n\n" . Além disso seu programa deverá tolerar tipos diferentes de indicadores de pula linha. Existem 3 possibilidades de formatos de pula linha: '\n', "\r\n" e somente '\r'. Cada um desses formados pode ser usado para indicar **uma** nova linha.

O número de linhas é o número de **pula linhas** do arquivo. Portanto, um arquivo sem nenhum pula linha seria considerado como tendo 0 linhas.

Esse programa se assemelha do utilitário wc do sistema operacional Linux e é muito utilizado, as vezes diariamente, por usuários do sistema.

**Atenção:** Ao final de todas as linhas, quando a entrada termina, um caractere especial será lido: o End Of File, ouEOF. Esse caractere indica que não há mais entrada e seu programa deverá parar a leitura.
![alt-text]()
## Dica de implementação
Pesquise um pouco sobre a função *__ungetc__* e veja se ela lhe pode ser útil.
