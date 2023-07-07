#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

int main()
{

    struct hash_table *table = create_hash_table();
    int coordinate[2] = {0, 0}, idNodeGraph = 0, direction = 0;
    printf("coordinate: x=%d, y=%d\n", coordinate[0], coordinate[1]);

    // Cria primeiro hash com coordinate 0,0 e primeiro nó do grafo
    uint32_t currentHash = fnv1a_hash(coordinate[0], coordinate[1]);
    insert(table, currentHash, idNodeGraph);
    print_hash_table(table);
    // --> criar nó do grafo

    // Primeira ação pra frente
    // char action = 'm';
    // printf("%c\n", action);

    int res;
    while (scanf("%d", &res) == 1)
    {
        switch (res)
        {
        case 0:
            switch (direction) // atualizar coordinate de acordo com a direção
            {
            case 0:
                coordinate[1]++; // north
                direction++;
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
            printf("%u\n", currentHash);
            printf("%d\n", find(table, currentHash));
            if (find(table, currentHash) == -1) // coordinate existe
            {
                printf("passou aqui\n");
                idNodeGraph++;
                insert(table, currentHash, idNodeGraph);
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
    return 0;
}