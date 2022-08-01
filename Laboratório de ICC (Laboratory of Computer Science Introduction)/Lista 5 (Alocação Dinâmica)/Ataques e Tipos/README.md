## Descrição
Você deverá simular a IA de um jogador escolhendo qual o melhor ataque contra determinado oponente. Para isso, é preciso saber qual a relação entre os diversos tipos existentes no jogo, qual o dano e o tipo de cada ataque do jogador, e o tipo do inimigo.
As relações entre tipos são dadas por uma matriz MxM, na qual M é a quantidade de tipos existentes no jogo, e será fornecida ao usuário no início do programa. Cada elemento dessa matriz é um float que indica por qual valor o ataque de um tipo (linha) deve ser multiplicado quando usado em outro tipo (coluna).
Cada ataque possui duas informações: a primeira é seu poder de ataque (inteiro), e a segunda seu tipo (índice do tipo na tabela).
Você deverá ler os dados de cada ataque até encontrar o valor -1 na leitura do primeiro atributo*, totalizando N ataques.
Por fim, a última entrada é o tipo do inimigo. Esse é o tipo no qual o ataque será usado!
Seu objetivo é descobrir qual o melhor ataque a ser usado no inimigo do tipo fornecido como entrada e, então imprimir a seguinte mensagem:
"O melhor ataque possui indice X e dano Y\n", sendo X o índice (de 0 a N) do ataque, e Y o dano dado por tal ataque (imprima apenas as 2 primeiras casas decimais do dano).
*Não leia o segundo atributo caso encontre -1.
Exemplo:
Entrada:
3
1 2 1
2 1 0.5
1 1 2
2 0
2 1
2 2
-1
2
Saída:
O melhor ataque possui indice 2 e dano 4.00

Obs: A tabela com os tipos e fraquezas funciona de maneira muito similar ao que é usada em jogos de verdade, como neste exemplo de Pokémon: https://www.gamerview.com.br/wp-content/uploads/2019/05/Artigo-Pok%C3%A9mon-1-Cartilha-Tipos001.jpg Talvez ajude vocês a visualizar melhor :)
