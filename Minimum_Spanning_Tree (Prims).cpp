/*



Given a connected graph G, find the minimum spanning tree of a graph. 
Write a program in C++ for Prim's Minimum Spanning Tree (MST) algorithm.

Input: Number of vertices in G and Adjacency matrix A of graph G, with the value at A[i,j] is the weight of the edge joining vertex i and vertex j. 

Output:  Edge (vertex i -- vertex  j ) and weight of the edge in the below format: 

i -- j  w

Note: The vertex are numbered from 0 to n-1, where n is the total number of vertices.


Example: 

Input:

5

0 2 0 6 0

2 0 3 8 5

0 3 0 0 7

6 8 0 0 9

0 5 7 9 0

Output:

0 -- 1 2

1 -- 2 3

0 -- 3 6

1 -- 4 5


The following function should store MST in array.  Assuming the vertex 0 as source.

int* prim(int** graph,int no_of_vertices); 

This function should return an array of length V arr[i] stores the parent of ith vertex. For source vertex arr[0] = -1



*/

#include <cstdio>
#include <stdlib.h>
#include <limits.h>
// function prints MST as vertex i - vertex j w , in order of vertex j (1 to n-1)
int printMST(int parent[], int n, int** graph)
{
   for (int i = 1; i <  n; i++)
   printf("%d -- %d %d\n", parent[i], i, graph[i][parent[i]]);
}
int* prim(int** graph,int no_of_vertices);
int main(){
  int no_of_vertices;
 scanf("%d", &no_of_vertices); 
  int** graph = new int*[no_of_vertices];
  for(int i = 0; i < no_of_vertices; ++i)
     graph[i] = new int[no_of_vertices];
  for(int i = 0; i <no_of_vertices; ++i)
    for(int j = 0; j < no_of_vertices; ++j)
      scanf("%d",&graph[i][j]);
 
   
  int* parent;
   parent= prim(graph,no_of_vertices);
    // Print the solution
   printMST(parent, no_of_vertices, graph);
     return 0;
}

int minKey(int key[], bool mstSet[],int no_of_vertices)
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < no_of_vertices; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
int* prim(int** graph,int no_of_vertices)
{
     int* parent= (int*)malloc(sizeof(int)*no_of_vertices); 
     int key[no_of_vertices];  
     bool mstSet[no_of_vertices];   

     for (int i = 0; i < no_of_vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     
     parent[0] = -1; 
     for (int count = 0; count < no_of_vertices-1; count++)
     {
         int u = minKey(key, mstSet, no_of_vertices);
         mstSet[u] = true;
         for (int v = 0; v < no_of_vertices; v++)
              if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
  return parent;
   }
