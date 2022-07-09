## Descrição
Escreva um programa em C que recebe da entrada padrão informações relativas a dois retângulos e informe na saída se esses retângulos se intersectam. Se eles se intersectarem, imprima o retângulo da área de intersecção.

O formato da entrada será em duas linhas, cada uma com os dados de um dos retângulos. Em cada linha, quatro números estarão dispostos separados por espaço: *__<x> <y> <largura> <altura>__*.

Caso os retângulos não se toquem imprima MISS, caso eles se toquem ou até se atravessem, imprima *__HIT: <x> <y> <largura> <altura>__*, onde os valores <x>, <y>, <largura>, <altura> descrevem o retângulo de intersecção entre os dois retângulos fornecidos.

Para qualquer retângulo usaremos o ponto (<x>, <y>) para representar o vértice superior esquerdo do retângulo. Além disso, nesse sistema de coordenadas os valores de x crescem para a direita enquanto os valores de y crescem para baixo. Ou seja, se tivermos os pontos O = (0, 0) e A = (10, 10), A se encontra em baixo e a direita do ponto O. A <largura> é simplesmente a extensão do retângulo do eixo x e a <altura> a extensão do retângulo no eixo y.
![alt-text]()
 __Atenção:__ Se os dois retângulos se tocam mas a área da intersecção é 0, isso ainda conta como um HIT. Ou seja, é possível que na saída <largura> e/ou <altura> sejam 0.

Imprima um '\n' ao final da linha de saída.

__Restrições__

<x>, <y>, <largura> e <altura> são garantidos de caber dentro de um inteiro de 4 bytes. Isso significa que os valores de saída também possuem essa garantia. Entretanto, é possível que a soma de um desses valores com outro não caiba em 4 bytes.
  ![alt-text]()
