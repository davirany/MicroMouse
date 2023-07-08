#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

#define GRAPH_SIZE 1000000

// Função para criar um novo nó
struct Node* createNode(int v, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar uma aresta ao grafo direcionado
void addEdge(struct Graph* graph, int src, int dest, int val) {
    // Adiciona uma aresta do vértice src para o vértice dest com o valor val
    struct Node* newNode = createNode(dest, val);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph, int maxGraph) {
    int i;
    for (i = 0; i < maxGraph; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%d: { ", i);
        while (temp) {
            printf("%d: %d, ", temp->vertex, temp->value);
            temp = temp->next;
        }
        printf("}\n");
    }
}

// Função para criar um grafo com n vértices
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = GRAPH_SIZE;
    
    // Cria um array de listas de adjacências com tamanho n
    graph->adjLists = (struct Node**)malloc(GRAPH_SIZE * sizeof(struct Node*));
    
    // int i;
    // for (i = 0; i < GRAPH_SIZE; i++) {
    //     graph->adjLists[i] = NULL;

    //     // Adiciona as arestas 0, 1, 2, 3 em cada nó
    //     addEdge(graph, i, 0, 1);
    //     addEdge(graph, i, 1, 3);
    //     addEdge(graph, i, 2, -1);
    //     addEdge(graph, i, 3, 7);
    // }
    
    return graph;
}