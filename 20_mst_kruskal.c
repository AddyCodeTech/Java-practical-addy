Algorithm:
1. Sort all edges of the graph in ascending order of weight
2. Initialize each vertex as its own separate set (Union-Find)
3. For every edge (u, v) in sorted order:
   a. If find(u) ≠ find(v) (adding it does not form a cycle), add the edge to the MST and perform union(u, v)
4. Repeat step 3 until V-1 edges have been selected
5. Display the MST edges and the total weight
6. Stop
Program:
/* Practical 20: MST using Kruskal's Algorithm (CO3) */
#include <stdio.h>
#define MAX 20
int parent[MAX];
int find(int i) { while (parent[i] != i) i = parent[i]; return i; }
void unionSet(int i, int j) { parent[find(i)] = find(j); }
 
struct Edge { int u, v, w; };
int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    struct Edge edges[MAX];
    printf("Enter edges as (u v weight):\n");
    for (int i = 0; i < e; i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
 
    for (int i = 0; i < e - 1; i++)
        for (int j = 0; j < e - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                struct Edge t = edges[j]; edges[j] = edges[j + 1]; edges[j + 1] = t;
            }
 
    for (int i = 0; i < n; i++) parent[i] = i;
 
    int total = 0, count = 0;
    printf("\nEdges in MST:\n");
    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (find(u) != find(v)) {
            printf("%d - %d \t%d\n", u, v, edges[i].w);
            unionSet(u, v);
            total += edges[i].w;
            count++;
        }
    }
    printf("Total Weight of MST = %d\n", total);
    return 0;
}
