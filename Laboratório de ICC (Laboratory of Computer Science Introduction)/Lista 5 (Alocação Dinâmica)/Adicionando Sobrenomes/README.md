  ## Descrição
  Você deverá receber uma lista de nomes completos. Os nomes tem tamanhos variados e quantidades de sobrenomes variadas.
Como não se sabe inicialmente a quantidade de nomes a serem digitados, você deverá ler nomes até encontrar o caractere '$', com código ASC II decimal de valor 36.
Após ler os nomes, você deverá fazer o seguinte algoritmo:
Para todo nome de índice par na sua lista (a partir de 0), caso exista o próximo nome, você deverá adicionar* o último sobrenome do atual nome de índice par no próximo nome de índice ímpar.
Ao final, você deverá imprimir todos os nomes, na mesma ordem de entrada, pulando uma linha após cada nome.
*Adicionar o nome ao final do último sobrenome. Nenhum sobrenome deverá ser substituído.
Obs: Use alocação dinâmica, você não sabe quantos nomes terão, o tamanho de cada nome e nem quantos sobrenomes tem cada nome, portanto, não faz sentido utilizar vetores estáticos.
