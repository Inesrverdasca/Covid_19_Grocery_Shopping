#include "Graph.h"

Graph* createGraph(int numVertices) {
    int i;
    Graph* graph = malloc(sizeof(struct Graph));
    
    parents = (int*)malloc((numVertices*2+2)*sizeof(int));
    q = (int*)malloc((numVertices*2+4)*sizeof(int));
    visited = (int*)malloc((numVertices*2+2)*sizeof(int));
    added = (bool*)malloc((numVertices*2+2)*sizeof(bool));

    graph->adjLists = (Vertex**)malloc((numVertices*2 + 2)*sizeof(Vertex*));

    for(i = 0; i <= graph->numVertices*2 + 1; i++) {
        graph->adjLists[i] = NULL;
        added[i] = false;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Vertex* aux = (Vertex*)malloc(sizeof(Vertex));

    aux->flow = 0;
    aux->id = dest;
    aux->visited = false;

    aux->next = graph->adjLists[src];
    graph->adjLists[src] = aux;    
}

void destroyGraph(Graph* graph) {
    for(int i = 1; i <= graph->numVertices; i++) {
        Vertex* vertexAux = graph->adjLists[i];
        while(vertexAux != NULL) {
            Vertex* vextexNext = vertexAux->next;
            free(vertexAux);
            vertexAux = vextexNext;
        }
    }
    free(graph->adjLists);
    free(graph);
}