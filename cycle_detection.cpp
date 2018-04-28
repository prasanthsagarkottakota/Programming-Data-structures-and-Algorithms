/*

Given a graph G, write a C program to find whether it contains cycle or not.

Input:
The first line contains two integers, N and E, denoting the number of nodes and edges of G respectively.
The next E lines contain integers a and b, denoting the source and destination of an edge respectively. 

Output:
In a single line, output "cyclic" if the graph contains cycle else "acyclic".

Example:
Input:

4 4

0 1

0 2

2 0

3 2


Output:
cyclic

*/
#include <stdlib.h>
 
typedef struct {
    unsigned int first;
    unsigned int second;
} edge;
 
static unsigned int cyclic_recursive(const edge *edges, unsigned int n, unsigned int *visited,
        unsigned int order, unsigned int vertex, unsigned int predecessor)
{
    unsigned int i;
    unsigned int cycle_found = 0;
    visited[vertex] = 1;
    for (i = 0; i < n && !cycle_found; i++) {
        if (edges[i].first == vertex || edges[i].second == vertex) {
            /* Adjacent */
            const unsigned int neighbour = edges[i].first == vertex ?
                    edges[i].second : edges[i].first;
            if (visited[neighbour] == 0) {
                /* Not yet visited */
                cycle_found = cyclic_recursive(edges, n, visited, order, neighbour, vertex);
            }
            else if (neighbour != predecessor) {
                /* Found a cycle */
                cycle_found = 1;
            }
        }
    }
    return cycle_found;
}
 
unsigned int cyclic(const edge *edges, unsigned int n, unsigned int order)
{
    unsigned int *visited = calloc(order, sizeof(unsigned int));
    unsigned int cycle_found;
    if (visited == NULL) {
        return 0;
    }
    cycle_found  = cyclic_recursive(edges, n, visited, order, 0, 0);
    free(visited);
    return cycle_found;
}

#include <stdio.h>
 
int main(void)
{
    int n,e,i,a,b;
    scanf("%d %d", &n,&e);

    //const unsigned int order = 6; /* Vertices */
    //const unsigned int n = 6; /* Edges */
    edge *edges;
    unsigned int c;
    
    edges = malloc(e * sizeof(edge));
    if (edges == NULL) {
        return 1;
    }
    for (i = 0; i < e; i++){
        scanf("%d %d",&a,&b);
        edges[i].first = a;
        edges[i].second = b;    
    }

 
    c = cyclic(edges, e, n);
    printf("%s", c ? "cyclic" : "acyclic");
    free(edges);
 
    return 0;
}
