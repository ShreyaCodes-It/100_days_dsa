#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];

// BFS function
void bfs(int start, int n) {
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    int u, v;

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected
    }

    int s;
    scanf("%d", &s);   // source

    bfs(s, n);

    return 0;
}