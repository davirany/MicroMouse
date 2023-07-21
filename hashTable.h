#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdint.h>

typedef struct
{
    unsigned long long key;
    int value;
    hash_node *next;
} hash_node;

typedef struct
{
    int size;
    hash_node **table;
} hash_table;

hash_table *create_hash_table();
void insert(hash_table *table, int key, int value);
void print_hash_table(hash_table *table);
int find(hash_table *table, int key);
uint32_t fnv1a_hash(int x, int y);

#endif
