Algorithm:
1. Start; mark all vertices as unvisited; create an empty queue
2. Mark the source vertex as visited and enqueue it
3. While the queue is not empty:
   a. Dequeue a vertex v and visit/print it
   b. For every unvisited neighbor u of v, mark u visited and enqueue u
4. Repeat step 3 until the queue is empty
5. Stop
Program:
/* Practical 17: Breadth First Search (BFS) (CO3) */
#include <stdio.h>
#define MAX 10
int adj[MAX][MAX], visited[MAX], queue[MAX];
int front = -1, rear = -1;
void enqueue(int v) { queue[++rear] = v; if (front == -1) front = 0; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front > rear || front == -1; }
 
void bfs(int start, int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    front = rear = -1;
    visited[start] = 1;
    enqueue(start);
    printf("BFS Traversal: ");
    while (!isEmpty()) {
        int curr = dequeue();
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) { visited[i] = 1; enqueue(i); }
        }
    }
    printf("\n");
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
    bfs(start, n);
    return 0;
}
