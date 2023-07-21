#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

#define GRAPH_SIZE 1000000

// Função para criar um novo nó
Node *createNode(int v, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar uma aresta ao grafo direcionado
void addEdge(Graph *graph, int src, int dest, int val)
{
    // Adiciona uma aresta do vértice src para o vértice dest com o valor val
    Node *newNode = createNode(dest, val);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Função para imprimir o grafo
void printGraph(Graph *graph, int maxGraph)
{
    int i;
    for (i = 0; i < maxGraph; i++)
    {
        Node *temp = graph->adjLists[i];
        printf("%d: { ", i);
        while (temp)
        {
            printf("%d: %d, ", temp->vertex, temp->value);
            temp = temp->next;
        }
        printf("}\n");
    }
}

// Função para criar um grafo com n vértices
Graph *createGraph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = GRAPH_SIZE;

    // Cria um array de listas de adjacências com tamanho n
    graph->adjLists = (Node **)malloc(GRAPH_SIZE * sizeof(Node *));

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