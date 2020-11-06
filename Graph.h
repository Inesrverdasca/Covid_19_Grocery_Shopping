#ifndef __GRAPH_H
#define __GRAPH_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Vertex {
    int id;
    int flow;
    bool visited;
    struct Vertex*next;
} Vertex;


typedef struct Graph {
    int numVertices;
    Vertex** adjLists;
} Graph;

Graph* createGraph(int numVertices);
void addEdge(Graph* graph, int src, int dest);
void destroyGraph(Graph* graph);

#endif