#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VERTICES 50
 
// This struct represents a directed graph using adjacency list representation
typedef struct Graph_t {
    int V;   // No. of vertices
    bool adj[MAX_VERTICES][MAX_VERTICES];
    struct node** adjLists;
}Graph;
 
// Constructor
Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V;
 
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }
 
    return g;
}
 
// Destructor
void Graph_destroy(Graph* g) { 
    free(g); 
}
 
// Function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
    // Add w to v’s list.
    g->adj[v][w] = true;
}
 
// Prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s)
{
    // Mark all the vertices as not visited
    bool visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }
    
    int queue[MAX_VERTICES];    //queue for BFS
    int front = 0, rear = 0;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue[rear++] = s;
 
    while (front != rear) {
        s = queue[front++];   // Dequeue a vertex from queue and print it
        printf("%d ", s);
 
        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int adjacent = 0; adjacent < g->V;
             adjacent++) {
            if (g->adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }
}


int main()
{
    int nodes,edges;
    printf("enter the number of nodes and edges");
    scanf("%d %d",&nodes,&edges);
    
    // Create a graph
    Graph* g = Graph_create(nodes);
    
    for(int i=0;i<edges;i++){
        int begin,end;
        printf("enter start and end point of a edge");
        scanf("%d %d",&begin,&end);
        Graph_addEdge(g,begin,end);
    }
    printf("\n\n\nMenu\n");
    printf("1:Breadth First Traversal\n");
    printf("2:Depth First Traversal\n");
    printf("3:Exit\n");
    bool x=true;
    while(x){
        int ch;
        printf("\nEnter choice\n");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
            int start;
            printf("enter start node\n");
            scanf("%d",&start);
            printf("Breadth First Traversal \n");
            Graph_BFS(g, start);
            break;
            
            case 2:
            int start2;
            printf("enter start node\n");
            scanf("%d",&start2);
            printf("Depth First Traversal \n");
            Graph_BFS(g,start2);
            break;
            
            case 3:
            printf("Exiting\n");
            Graph_destroy(g);
            x=false;
        }
    }
    return 0;
}
