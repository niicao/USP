## Descrição
Um Histograma é um gráfico muito utilizado em aplicações de processamento de imagens. Nele, são guardadas as informações de quantos pixels da imagem possuem determinado valor (ou seja, quantos pixels possuem determinada coloração). Este gráfico é comumente representado por um vetor, no qual cada índice corresponde a um valor de cor, e o valor dentro do índice é a contagem de pixels que possuem tal cor. Por exemplo, considere uma imagem com dimensões 5x5, com apenas 5 tons diferentes (os pixels podem assumir apenas valores entre 0 e 4): Se existirem 10 pixels da cor '3', o vetor do histograma no índice 3 conterá o valor 10.

Para facilitar o processamento da imagem, ela será representada como um vetor, de tamanho igual a altura*largura.

Seu programa deverá receber os valores dos 25 pixels de uma imagem 5x5, que possui apenas 5 cores diferentes, e imprimir seu histograma correspondente no terminal, usando a formatação proposta: valor da cor: |#\n Sendo que o caractere '#' deve ser impresso o número de vezes correspondente ao valor daquela cor no histograma.

Além disso, para a cor mais presente na imagem, imprima o índice de cada pixel que possui determinada cor (desconsidere o caso de empate, sempre haverá um único valor com mais ocorrências). Os índices deverão ser impressos em ordem crescente. Após cada índice, adicione um '\n', como no exemplo:

Exemplo 1: Entrada: 1 3 3 4 4 1 2 2 0 0 0 0 1 2 2 4 0 2 3 4 1 1 1 1 1

Saída: 0: |#####\n 1: |########\n 2: |#####\n 3: |###\n 4: |####\n 0\n 5\n 12\n 20\n 21\n 22\n 23\n 24\n
