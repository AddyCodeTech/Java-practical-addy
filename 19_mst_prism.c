Algorithm:
1. Start; choose an arbitrary vertex as the initial MST node and mark it visited
2. Repeat until all vertices are included in the MST:
   a. Among all edges connecting a visited vertex to an unvisited vertex, find the one with minimum weight
   b. Add that edge and vertex to the MST; mark the new vertex visited
3. Display the MST edges and the total weight
4. Stop
Program:
/* Practical 19: MST using Prim's Algorithm (CO3) */
#include <stdio.h>
#define MAX 10
#define INF 9999
int graph[MAX][MAX];
int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &graph[i][j]);
 
    int parent[MAX], key[MAX], visited[MAX];
    for (int i = 0; i < n; i++) { key[i] = INF; visited[i] = 0; }
    key[0] = 0; parent[0] = -1;
 
    for (int count = 0; count < n - 1; count++) {
        int min = INF, u = -1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && key[v] < min) { min = key[v]; u = v; }
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }
    int total = 0;
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < n; i++) { printf("%d - %d \t%d\n", parent[i], i, key[i]); total += key[i]; }
    printf("Total Weight of MST = %d\n", total);
    return 0;
}
