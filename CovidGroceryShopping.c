#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Graph.c"

typedef struct Queue {
    int id;
    struct Queue* next;
} Queue;


Graph* processInput() {
    int* super;
    int* homes;
    char line[20];
    int numAvenues = 0, numStreets = 0, numSuperMarkets = 0, numPeople = 0;
    int numVertices = 0;
    int avenue = 0;
    int street = 0;
    int i = 0;

    fgets(line, sizeof(line)/sizeof(char), stdin);
    numAvenues = atoi(strtok(line, " "));
    numStreets = atoi(strtok(NULL, " "));
    numVertices = numAvenues*numStreets;


    fgets(line, sizeof(line)/sizeof(char), stdin);
    numSuperMarkets = atoi(strtok(line, " "));
    numPeople = atoi(strtok(NULL, " "));

    Graph* graph = createGraph(numVertices);
    
    graph->numVertices = numVertices;
    graph->numAvenues = numAvenues;
    homes = (int*)malloc((numPeople+1)*sizeof(int));
    super = (int*)malloc((numSuperMarkets+1)*sizeof(int));

    for(i = 1; i <= numSuperMarkets; i++) {
        fgets(line, sizeof(line)/sizeof(char), stdin);
        avenue = atoi(strtok(line, " "));
        street = atoi(strtok(NULL, " "));
        super[i] = avenue + (street - 1)*numAvenues;
        addEdge(graph, super[i]*2, graph->numVertices*2 + 1);
    }

    for(i = 1; i <= numPeople; i++) {
        fgets(line, sizeof(line)/sizeof(char), stdin);
        avenue = atoi(strtok(line, " "));
        street = atoi(strtok(NULL, " "));
        homes[i] = avenue + (street - 1)*numAvenues; 
        addEdge(graph, 0, (homes[i])*2-1); 
    }
    
    free(homes);
    free(super);
    return graph;
}

int dequeue() {
    int x = q[head];
    head++;
    return x;
}

void enqueue(int x) {
    q[tail] = x;
    tail++;
}

int bfs(Graph* graph) {
    int i;

    for(i = 0; i <= graph->numVertices*2 + 1; i++) {
        visited[i] = false;
        parents[i] = -1;
    }

    head = tail = 0;
    visited[0] = true;
    enqueue(0);

    while(head != tail) {
        int u = dequeue();

        if(added[u] == false && u != 0 && u != graph->numVertices*2 + 1) {
            added[u] = true;
            if(u%2 == 1) {
                addEdge(graph, u, u + 1);
            }
            
            if(u%2 == 0) {
                if(u%(graph->numAvenues*2) != 0) {   
                    addEdge(graph, u, u + 1);
                }

                if(u%(graph->numAvenues*2) != 2) {
                    addEdge(graph, u, u - 3);
                }

                if(u + graph->numAvenues*2 <= graph->numVertices*2) {
                    addEdge(graph, u, u + graph->numAvenues*2 - 1);
                }

                if(u - graph->numAvenues*2 > 0) {
                    addEdge(graph, u, u - graph->numAvenues*2 - 1);
                } 
            }
        }
         
        Vertex* v = graph->adjLists[u];

        for(;v != NULL; v = v->next) {
            if(visited[v->id] == false && 1 - v->flow > 0) {
                enqueue(v->id);
                parents[v->id] = u;
                visited[v->id] =true;   
            }  
        }  
    }      
    return visited[graph->numVertices*2 + 1];
}  

int edmondsKarp(Graph* graph) {
    int maxFlow = 0;
    int u;
    while(bfs(graph)) {
        for (u = graph->numVertices*2 + 1; parents[u] >= 0; u = parents[u]) {

            Vertex* temp = graph->adjLists[parents[u]];

            for(; temp != NULL; temp = temp->next) {
                if(temp->id == u) {
                    temp->flow += 1;
                    break;
                }
            }
            
            Vertex* aux = graph->adjLists[u];
            for(; aux != NULL; aux = aux->next) {
                if(aux->id == parents[u]) {
                    aux->flow -= 1;
                    break;              
                }
            }

            addEdge(graph, u, parents[u]);
        }
        maxFlow++;
    }
    return maxFlow; 
}

int main() {
    
    Graph* graph = processInput();
    

    printf("%d\n", edmondsKarp(graph));

    destroyGraph(graph);
    free(parents);
    free(q);
    free(visited);
    free(added);
    return 0;
}