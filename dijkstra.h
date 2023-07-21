#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdbool.h>
#include "graph.h"

int find_min_distance(int distances[], bool visited[], int numVertices);
void dijkstra(Graph *graph, int numVertices, int origin);
void dijkstra_with_termination(Graph *graph, int numVertices, int origin, int destination);

#endif
