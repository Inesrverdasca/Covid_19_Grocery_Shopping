#ifndef __GRAPH_H
#define __GRAPH_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool* added;
int* parents;
int head, tail;
int* q;
int* visited;

typedef struct Vertex {
    int id;
    int flow;
    bool visited;
    struct Vertex*next;
} Vertex;


typedef struct Graph {
    int numVertices;
    int numAvenues;
    Vertex** adjLists;
} Graph;

Graph* createGraph(int numVertices);
void addEdge(Graph* graph, int src, int dest);
void destroyGraph(Graph* graph);

#endif