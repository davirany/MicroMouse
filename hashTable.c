#include "hashTable.h"
#include <stdlib.h>
#include <stdio.h>

#define TABLE_SIZE 1000000

struct hash_table *create_hash_table()
{
    struct hash_table *table = malloc(sizeof(struct hash_table));
    table->size = TABLE_SIZE;
    table->table = malloc(sizeof(struct hash_node *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->table[i] = NULL;
    }
    return table;
}

int hash(int key)
{
    return key % TABLE_SIZE;
}

void insert(struct hash_table *table, int key, int value)
{
    int index = hash(key);
    struct hash_node *new_node = malloc(sizeof(struct hash_node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = table->table[index];
    table->table[index] = new_node;
}

int find(struct hash_table *table, int key)
{
    int index = hash(key);
    if (table->table[index] != NULL && table->table[index]->key == key)
    {
        return table->table[index]->value;
    }
    return -1;
}

void print_hash_table(struct hash_table *table)
{
    printf("Conteudo da tabela hash:\n");
    for (int i = 0; i < table->size; i++)
    {
        struct hash_node *node = table->table[i];
        while (node != NULL)
        {
            printf("Chave: %d, Valor: %d\n", node->key, node->value);
            node = node->next;
        }
    }
}

uint32_t fnv1a_hash(int x, int y)
{
    uint32_t hash = 2166136261;
    hash ^= x;
    hash *= 16777619;
    hash ^= y;
    hash *= 16777619;
    return hash;
}
