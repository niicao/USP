## Descrição
Implemente um programa em C que leia da entrada padrão um número inteiro. Em seguida, imprima na saída padrão quatro caracteres adjacentes que sejam correspondentes aos 4 bytes contidos no *int*. Ou seja, o programa deve reinterpretar os primeiros (mais significantes) 8 bits do número como o primeiro caractere, os próximos 8 como o segundo e assim por diante.

![alt-text](https://github.com/niicao/USP/blob/main/Laborat%C3%B3rio%20de%20ICC%20(Laboratory%20of%20Computer%20Science%20Introduction)/Lista%201/Apenas%20Bits/apenas%20bit%200.png)

### Atenção: inclua um '\n' após os caracteres impressos.

## Dicas de implementação
Utilize operadores bitwise para isolar os bytes do *int*. Para isolar um conjunto de bits de algum número, podemos usar uma máscara de bits. Isso é, fazer um AND bitwise entre o número e um outro que chamamos de máscara e que, em binário, possui 1 apenas nos bits que nos interessam.

Por exemplo, digamos que estejamos interessados nos 5 bits menos significantes. Então o nossa máscara seria 11111. Veja o exemplo abaixo:

![alt-text](https://github.com/niicao/USP/blob/main/Laborat%C3%B3rio%20de%20ICC%20(Laboratory%20of%20Computer%20Science%20Introduction)/Lista%201/Apenas%20Bits/apenas%20bits%201.png)

![alt-text](https://github.com/niicao/USP/blob/main/Laborat%C3%B3rio%20de%20ICC%20(Laboratory%20of%20Computer%20Science%20Introduction)/Lista%201/Apenas%20Bits/apenas%20bits%202.png)
