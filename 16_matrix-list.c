Algorithm:
ADJACENCY MATRIX:
1. Initialize a V×V matrix with all entries 0
2. For every edge (u, v): set matrix[u][v] = 1 (and matrix[v][u] = 1 for an undirected graph)
3. Display the matrix

ADJACENCY LIST:
1. Create an array of V linked lists
2. For every edge (u, v): add v to list[u] (and add u to list[v] for an undirected graph)
3. Display all lists
Program:
/* Practical 16: Adjacency Matrix and Adjacency List to represent a Graph (CO3) */
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int adjMatrix[MAX][MAX];
struct Node { int vertex; struct Node *next; };
struct Node *adjList[MAX];
 
void addEdgeMatrix(int u, int v) { adjMatrix[u][v] = 1; adjMatrix[v][u] = 1; }
void addEdgeList(int u, int v) {
    struct Node *n1 = (struct Node*)malloc(sizeof(struct Node));
    n1->vertex = v; n1->next = adjList[u]; adjList[u] = n1;
    struct Node *n2 = (struct Node*)malloc(sizeof(struct Node));
    n2->vertex = u; n2->next = adjList[v]; adjList[v] = n2;
}
void displayMatrix(int n) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}
void displayList(int n) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node *temp = adjList[i];
        while (temp != NULL) { printf("%d -> ", temp->vertex); temp = temp->next; }
        printf("NULL\n");
    }
}
int main() {
    int n, e, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdgeMatrix(u, v);
        addEdgeList(u, v);
    }
    displayMatrix(n);
    displayList(n);
    return 0;
}
