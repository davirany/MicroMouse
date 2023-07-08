#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
#include "graph.h"

int main()
{

    struct hash_table *table = create_hash_table();
    struct Graph* graph = createGraph();

    int coordinate[2] = {0, 0}, idNodeGraph = 0, direction = 2;
    printf("coordinate: x=%d, y=%d\n", coordinate[0], coordinate[1]);

    // Cria primeiro hash com coordinate 0,0 e primeiro nó do grafo
    uint32_t currentHash = fnv1a_hash(coordinate[0], coordinate[1]);
    insert(table, currentHash, idNodeGraph);
    print_hash_table(table);
    
    // Criar primeiro nó do grafo
    addEdge(graph, 0, 0, 1);

    // Primeira ação pra frente
    char action = 'm';
    printf("%c\n", action);

    int res;
    while (scanf("%d", &res) == 1)
    {
        switch (res)
        {
        case 0:
            if(idNodeGraph == 0){
                addEdge(graph, 0, direction, 1);
            }
            switch (direction) // atualizar coordinate de acordo com a direção
            {
            case 0:
                coordinate[1]++; // north
                // direction++;
                break;
            case 1:
                coordinate[0]++; // east
                // direction++;
                break;
            case 2:
                coordinate[1]--; // south
                // direction++;
                break;
            case 3:
                coordinate[0]--; // west
                // direction = 0;
                break;
            }
            printf("%d %d\n", coordinate[0], coordinate[1]);
            currentHash = fnv1a_hash(coordinate[0], coordinate[1]);
            // printf("%s\n", find(table, currentHash) == -1 ? "nó não existe\n" : "nó existe\n");
            if (find(table, currentHash) == -1) // coordinate não existe na tabela
            {
                printf("Criou novo nó\n");
                idNodeGraph++;
                insert(table, currentHash, idNodeGraph);
                // addEdge(graph, idNodeGraph, direction, 1);
            }
            else
            {
                printf("Achou um no\n");
            }
            print_hash_table(table);
            break;
        case 1:
            printf("Bateu\n");
            break;
        case 2:
            printf("Achou!\n");
            break;
        }
    }
    printf("valor final da hash:\n");
    print_hash_table(table);
    printf("\n");
    printf("valor final do Grafo:\n");
    printGraph(graph, idNodeGraph);
    return 0;
}