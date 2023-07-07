#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdint.h>

struct hash_node
{
    int key;
    int value;
    struct hash_node *next;
};

struct hash_table
{
    int size;
    struct hash_node **table;
};

struct hash_table *create_hash_table();
void insert(struct hash_table *table, int key, int value);
void print_hash_table(struct hash_table *table);
int find(struct hash_table *table, int key);
uint32_t fnv1a_hash(int x, int y);

#endif
