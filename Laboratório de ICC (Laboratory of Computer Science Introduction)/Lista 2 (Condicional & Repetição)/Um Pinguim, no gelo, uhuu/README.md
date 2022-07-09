## Descrição
Pingu acabou de aprender um novo jogo e está empolgado para compartilhar com seus amigos. O jogo se chama "Um Pinguim, no gelo, uhuu!" e consiste em formar uma roda com todos os participantes e definir uma pessoa para começar e o sentido no qual as rodadas irão. Então, a pessoa que começa diz "1 pinguim", o próximo "no gelo" e o outro "uhuu!". Depois disso incrementamos o número de pinguins e, como consequência, repetimos cada fragmento de acordo com o número de pinguins. Ou seja, na quarta rodada a pessoa diria "2 pinguins" e a quinta "2 pinguins" novamente, então "no gelo", "no gelo", "uhuu!", "uhuu!". Incrementamos novamente a quantidade de pinguins e aí "3 pinguins" (3x), "no gelo" (3x), "uhuu!" (3x). Se alguma pessoa errar, ela perde e tem que sair do jogo. Quanto mais pinguins, mais difícil lembrar o que tem de ser dito na sua vez!

Os amigos de Pingu gostam bastante do jogo e jogam várias vezes. Mas Pingu nunca consegue se lembrar o que tem que falar na sua rodada e sempre perde o jogo!

Veio a pandemia e Pingu e seus amigos continuavam jogando o jogo através de mensagens. Agora que Pingu está estudando computação começa a ver o jogo de outra maneira e pensa numa forma de sempre ganhar dos seus amigos!

Escreva um programa em C que imprima o que Pingu terá de falar na rodada dele. Seu programa receberá como entrada um número o máximo de rodadas (n), o número de jogadores (m), e a posição de Pingu na ordem de rodadas (p). Quando p = 1, Pingu começa, e quando p = m, ele é o último a jogar.

**Restrições**

n é garantido de caber num inteiro de 4 bytes. 1 <= n < 2^31.

m é garantido de caber num inteiro de 4 bytes. 2 <= m < 2^31.

1 <= p <= m

text

Explicação: As 11 rodadas foram

1. 1 pinguim (vez de Pingu)
1. no gelo
1. uhuu! (vez de Pingu)
1. 2 pinguins
1. 2 pinguins (vez de Pingu)
1. no gelo
1. no gelo (vez de Pingu)
1. uhuu!
1. uhuu! (vez de Pingu)
1. 3 pinguins
1. 3 pinguins (vez de Pingu)

![alt-text]()
