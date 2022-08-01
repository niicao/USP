## Descrição
Você irá implementar um algoritmo muito utilizado em Processamento de Imagens: Padding (uma adição de bordas).
Esse procedimento é um pré-processamento da imagem que adiciona uma borda ao redor da imagem original com pixels de valor 0.
Pode-se criar uma borda de qualquer tamanho. Por exemplo, em uma borda de tamanho 2, adicionamos, para cada pixel na extremidade da imagem, 2 pixels na direção da extremidade.
O programa receberá as seguintes entradas:
Largura da imagem.
Altura da imagem.
Largura*Altura pixels da imagem, que são inteiros variando de 0 a 255.
O tamanho da borda.
Como saída o programa deverá exibir a imagem com o padding, e, após pular uma linha, a imagem original.

Exemplo:
Entrada:
3
3
1 1 1
2 2 2
3 3 3
2
Saída:
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 1 1 1 0 0
0 0 2 2 2 0 0
0 0 3 3 3 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

1 1 1
2 2 2
3 3 3

Entrada:
2
3
1 1
2 2
3 3
1

Saída:
0 0 0 0
0 1 1 0
0 2 2 0
0 3 3 0
0 0 0 0

1 1
2 2
3 3  
