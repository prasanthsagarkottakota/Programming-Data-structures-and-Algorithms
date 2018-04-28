/*



A bipartite graph is a graph whose vertices can be divided into two disjoint sets U and V (that is, U and V are each independent sets) such that every edge connects a vertex in U to one in V (that is no two graph vertices within the same set are adjacent). Vertex set U and V are often denoted as partite sets. 

Equivalently, a bipartite graph is a graph that does not contain any odd-length cycles.

Example of a bipartite graph:

Now, your task is to find whether given graph is a bipartite graph or not. Write a program in C++ to find whether graph G is bipartite or not.

Input: 
The first line of input contains an integer V denoting the number of vertices in the graph.
The second line contains the adjacency matrix representation of the graph G, each row separated by new line and columns are separated by space. 

Output: “YES” if given graph is bipartite, otherwise “NO”.

Constraints: 

1<=V<=100

1<=E<=100

Example:

Consider the graph



Input:
3
0 1 2

1 0 0

1 0 0

Output:
YES 

*/

// C++ program to find out whether a given graph is Bipartite or not
#include <iostream>
#include <queue>
using namespace std;

int V; 
// This function returns true if graph G[V][V] is Bipartite, else false
bool isBipartite(int G[][1000], int src)
{
    // Create a color array to store colors assigned to all veritces. Vertex 
    // number is used as index in this array. The value '-1' of  colorArr[i] 
    // is used to indicate that no color is assigned to vertex 'i'.  The value 
    // 1 is used to indicate first color is assigned and value 0 indicates 
    // second color is assigned.
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
 
    // Assign first color to source
    colorArr[src] = 1;
 
    // Create a queue (FIFO) of vertex numbers and enqueue source vertex
    // for BFS traversal
    queue <int> q;
    q.push(src);
 
    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();
 
        // Return false if there is a self-loop 
        if (G[u][u] == 1)
           return false;  
 
        // Find all non-colored adjacent vertices
        for (int v = 0; v < V; ++v)
        {
            // An edge from u to v exists and destination v is not colored
            if (G[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
 
            //  An edge from u to v exists and destination v is colored with
            // same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
 
    // If we reach here, then all adjacent vertices can be colored with 
    // alternate color
    return true;
}
 
// Driver program to test above function
int main()
{
    int i,j;
    cin >> V;
    int G[1000][1000];
    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++){
            cin >> G[i][j];
        }
    }
 
    isBipartite(G, 0) ? cout << "YES" : cout << "NO";
    return 0;
}
