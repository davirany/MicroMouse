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