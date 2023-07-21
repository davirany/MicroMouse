#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>

typedef struct
{
    int vertex;
    int value;
    Node *next;
} Node;

typedef struct
{
    int numVertices;
    Node **adjLists;
} Graph;

Node *createNode(int v, int val);
void addEdge(Graph *graph, int src, int dest, int val);
void printGraph(Graph *graph, int maxGraph);
Graph *createGraph();

#endif