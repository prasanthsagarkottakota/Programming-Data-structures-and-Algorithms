/*

Given a graph G, compute it's Depth-First Traversal. Write a C++ program to print the DFS traversal of G.

Input:
The first line contains three integers, N, E and s, denoting the number of nodes, edges and source node of G respectively.
The next E lines contain integers a and b, denoting the source and destination of an edge respectively. 

Output:
Output the DFS traversal of G, separated by space.

Example:
Input:

4 4 0

0 3

2 0

2 1

3 1

Output:
0 3 1


*/

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
};

struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);

void DFS(struct Graph*, int);


int main()
{
    int n,e,s,i,a,b;
    scanf("%d %d %d", &n,&e,&s);
    struct Graph* graph = createGraph(n);

    for (i = 0; i < e; i++){
        scanf("%d %d",&a,&b);
        addEdge(graph, a, b);
        
    }

    
    
    

    DFS(graph, s);
    
    return 0;
}

void DFS(struct Graph* graph, int vertex) {
        struct node* adjList = graph->adjLists[vertex];
        struct node* temp = adjList;
        
        graph->visited[vertex] = 1;
        printf("%d ", vertex);
    
        while(temp!=NULL) {
            int connectedVertex = temp->vertex;
        
            if(graph->visited[connectedVertex] == 0) {
                DFS(graph, connectedVertex);
            }
            temp = temp->next;
        }       
}

 
struct node* createNode(int v)
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = malloc(vertices * sizeof(struct node*));
    
    graph->visited = malloc(vertices * sizeof(int));
 
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
    // Add edge from dest to src
    /*
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
    */
}
 
