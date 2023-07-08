#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>

struct Node {
    int vertex;
    int value;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v, int val);
void addEdge(struct Graph* graph, int src, int dest, int val);
void printGraph(struct Graph* graph, int maxGraph);
struct Graph* createGraph();

#endif