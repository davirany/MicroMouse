# MicroMouse
-------------------------------------------------
| Prioridade de busca | Ação       | Método     |
|-------------------- |----------- |----------- |
| 1                   | Anda reto  | Busca()    |
| 2                   | direita    | Busca()    |
| 3                   | 180        | Busca()    |
-------------------------------------------------

-------------------------------------------------
| Prioridade Volta    | Ação        | Método     |
|-------------------- | ----------- | -----------|
| 4                   | desempilha  | Volta()    |
| 5                   | direita     | Volta()    |
| 6                   | 180         | Volta()    |
| 7                   | "passo4"    | Volta()    |
-------------------------------------------------

Busca() {
    *1-Nós não conhecidos são empilhados na pilha de busca.*
    *2-Sempre vem primeiro em relação à Volta().*
    *3-As coordenadas do novo nó serão inseridas numa tabela hash.*
}

Volta() {
    *1-À medida que desempilhamos olharemos as possibilidades de caminhos que podem ter sido ignorados.*
    *2-Mantem-se no processo de Volta() até que o Busca() volte a ser executado.*
}

Tabela Hash -> coordenadas {
int     key = coordenada (hash)
string  valor = nó (grafo)
}

Grafo -> caminho & próximo nó {
    n0: {
        N: X,
        L: n3,
        S: n7,
        O: X,
    }
}

Pilha -> volta {
    n0 -> no1 -> no2;
}


1
criar hash
criar node do grafo
anda

2 - 3
verifica que andou e nao ta voltando
empilha node
zera rotacoes
atualiza coordenada
cria nova hash
atualiza node anterior
cria no do grafo
anda

4
verifica q nao andou e nao ta voltando
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (0)
rotaciona para direita
atualiza direcao
anda

5 - 7
verifica que andou e nao ta voltando
empilha node
zera rotacoes
atualiza coordenada
cria nova hash
atualiza node anterior
cria node do grafo
anda

8
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (0)
rotaciona para direita
atualiza direcao
anda

9
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (1)
rotaciona 180 graus
atualiza direcao
anda

10
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (2)
define varivel que ta voltando
rotaciona para esquerda
zera rotacao
atualiza direcao
anda

11
verifica que andou e ta voltando
define que nao ta mais voltando
desempilha node
acessa primeiro node da pilha
consulta arestas do node
verifica aresta da direita em relação a direcao que ele ta indo(vazia)
rotaciona para direita
atualiza direcao
anda

12
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (1)
rotaciona 180 graus
atualiza direcao
anda

13
verifica que andou e nao ta voltando
empilha node
zera rotacoes
atualiza coordenada
cria nova hash
atualiza node anterior
cria node do grafo
anda

14
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (0)
rotaciona para direita
atualiza direcao
anda


15
verifica que andou e nao ta voltando
empilha node
zera rotacoes
atualiza coordenada
cria nova hash
atualiza node anterior
cria node do grafo
anda

16
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (0)
rotaciona para direita
atualiza direcao
anda

17
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (1)
rotaciona 180 graus
atualiza direcao
anda

18
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (2)
define varivel que ta voltando
rotaciona para esquerda
zera rotacao
atualiza direcao
anda

19
verifica que andou e ta voltando
define que nao ta mais voltando
desempilha node
acessa primeiro node da pilha
consulta arestas do node
verifica aresta da direita em relação a direcao que ele ta indo(preenchida)
verifica aresta da esquerda em relação a direcao que ele ta indo(preenchida)
verifica aresta a frente em relação a direcao que ele ta indo(vazia)
anda

20
verifica que andou e nao ta voltando
empilha node
zera rotacoes
atualiza coordenada
cria nova hash
atualiza node anterior
cria node do grafo
anda

21
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (0)
rotaciona para direita
atualiza direcao
anda

22
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (1)
rotaciona 180 graus
atualiza direcao
anda

23
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (2)
define varivel que ta voltando
rotaciona para esquerda
zera rotacao
atualiza direcao
anda

24
verifica que andou e ta voltando
define que nao ta mais voltando
desempilha node
acessa primeiro node da pilha
consulta arestas do node
verifica aresta da direita em relação a direcao que ele ta indo(preenchida)
verifica aresta da esquerda em relação a direcao que ele ta indo(preenchida)
verifica aresta a frente em relação a direcao que ele ta indo(preenchida)
define varivel que ta voltando
desempilha node
acessa primeiro node da pilha
verifica qual aresta do node atual corresponde ao primeiro node da pilha
rotaciona a direita até a direcao do node da pilha coincidir
zera rotacao
atualiza direcao
empilha node atual
anda

25
verifica que andou e ta voltando
define que nao ta mais voltando
desempilha node
acessa primeiro node da pilha
consulta arestas do node
verifica aresta da direita em relação a direcao que ele ta indo(preenchida)
verifica aresta da esquerda em relação a direcao que ele ta indo(preenchida)
verifica aresta a frente em relação a direcao que ele ta indo(preenchida)
define varivel que ta voltando
desempilha node
acessa primeiro node da pilha
verifica qual aresta do node atual corresponde ao primeiro node da pilha
rotaciona a direita até a direcao do node da pilha coincidir
zera rotacao
atualiza direcao
empilha node atual
anda

26
verifica que andou e ta voltando
define que nao ta mais voltando
desempilha node
acessa primeiro node da pilha
consulta arestas do node
verifica aresta da direita em relação a direcao que ele ta indo(vazia)
rotaciona para direita
atualiza direcao
anda

27
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (1)
rotaciona 180 graus
atualiza direcao
anda

28 X
verifica q nao andou
atualiza aresta do node da coordenada
verifica se rotacionou uma, duas ou nenhuma vez (2)
define varivel que ta voltando
rotaciona para esquerda
zera rotacao
atualiza direcao
anda