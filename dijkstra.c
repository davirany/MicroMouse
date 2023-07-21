#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "graph.h"

int find_min_distance(int distances[], bool visited[], int numVertices)
{
    int minDistance = INT_MAX;
    int minIndex;

    for (int v = 0; v < numVertices; v++)
    {
        if (!visited[v] && distances[v] <= minDistance)
        {
            minDistance = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void dijkstra(Graph *graph, int numVertices, int origin)
{
    int distances[numVertices];
    bool visited[numVertices];
    int predecessors[numVertices];

    for (int v = 0; v < numVertices; v++)
    {
        distances[v] = INT_MAX;
        visited[v] = false;
        predecessors[v] = -1;
    }

    distances[origin] = 0;

    for (int count = 0; count < numVertices - 1; count++)
    {
        int u = find_min_distance(distances, visited, numVertices);
        visited[u] = true;

        Node *adjList = graph->adjLists[u];
        while (adjList != NULL)
        {
            int v = adjList->vertex;
            int weight = adjList->value;

            if (!visited[v] && distances[u] != INT_MAX && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
            }

            adjList = adjList->next;
        }
    }

    printf("Vertex\t Distance from Origin\n");
    for (int v = 0; v < numVertices; v++)
    {
        printf("%d \t\t %d\n", v, distances[v]);
    }
}

void dijkstra_with_termination(Graph *graph, int numVertices, int origin, int destination)
{
    int distances[numVertices];
    bool visited[numVertices];

    for (int v = 0; v < numVertices; v++)
    {
        distances[v] = INT_MAX;
        visited[v] = false;
    }

    distances[origin] = 0;

    for (int count = 0; count < numVertices - 1; count++)
    {
        int u = find_min_distance(distances, visited, numVertices);
        visited[u] = true;

        if (u == destination)
        {
            break;
        }

        Node *adjList = graph->adjLists[u];
        while (adjList != NULL)
        {
            int v = adjList->vertex;
            int weight = adjList->value;

            if (!visited[v] && distances[u] != INT_MAX && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
            }

            adjList = adjList->next;
        }
    }

    printf("Vertex\t Distance from Origin\n");
    for (int v = 0; v < numVertices; v++)
    {
        printf("%d \t\t %d\n", v, distances[v]);
    }
}
