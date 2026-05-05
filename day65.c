#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];

// DFS function
int dfs(int v, int n) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            // if not visited → DFS
            if (!visited[i] && dfs(i, n))
                return 1;

            // if already in recursion stack → cycle
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0; // backtrack
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed
    }

    // check cycle for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}