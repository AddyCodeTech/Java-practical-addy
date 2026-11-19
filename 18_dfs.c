Algorithm:
DFS(v):
1. Mark vertex v as visited and print/visit it
2. For every neighbor u of v: if u is not visited, recursively call DFS(u)
3. When all neighbors of v have been explored, return (backtrack) to the caller
Program:
/* Practical 18: Depth First Search (DFS) (CO3) */
#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX];
void dfs(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) dfs(i, n);
    }
}
int main() {
    int n, e, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    dfs(start, n);
    printf("\n");
    return 0;
}
