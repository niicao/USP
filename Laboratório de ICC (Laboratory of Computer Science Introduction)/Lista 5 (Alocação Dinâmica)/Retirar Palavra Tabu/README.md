## Descrição
Retirar palavra tabu
Você deve fazer um programa que receba uma palavra tabu (que terá, no máximo, 20 caracteres e pode ser alocada estaticamente) e uma frase, que pode conter espaços, mas não deve ser separada por eles!
A frase deverá ser lida até encontrar o caractere especial '$' (dependendo de sua implementação voce pode usar o código decimal na tabela ASCII do '$', cujo valor é 36).
Tanto a frase quanto a palavra tabu podem ter letras maiúsculas e minúsculas.
A tarefa de seu programa é alocar dinamicamente a frase, retirando, quando encontrada, as palavras tabu desta frase. A correspondência deve ser exata, ou seja, letras maiúsculas e minúsculas são tratadas diferentemente.

Ao final, você deve imprimir o número de vezes que a palavra tabu foi encontrada na frase e a frase resultante, no seguinte formato:
A palavra tabu foi encontrada %d vezes\n
Frase: %s\n

Dica 1: leia a palavra tabu com o comando scanf("%s\n", palavraTabu) para ignorar o caractere '\n' que restará;
Dica 2: para a comparação, é sugerido o uso da função strncmp(). Com uma pequena manipulação do ponteiro da frase é possível usá-la sem problemas :) ;
Dica 3: dependendo da sua implementação, pode ser mais fácil tratar o encontro da palavra tabu enquanto realiza a leitura da frase, e não no final. Isso NÃO é obrigatório, e sim uma SUGESTÃO.

Obs: Você deve ler a frase utilizando alocação dinâmica! Programas que não utilizarem alocação dinâmica para a frase serão desconsiderados!

![alt-text](https://github.com/niicao/USP/blob/main/Laborat%C3%B3rio%20de%20ICC%20(Laboratory%20of%20Computer%20Science%20Introduction)/Lista%205%20(Aloca%C3%A7%C3%A3o%20Din%C3%A2mica)/Retirar%20Palavra%20Tabu/palavratabu0.png)
