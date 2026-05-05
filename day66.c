#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

// DFS function
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {

            if (!visited[i] && dfs(i))
                return 1;

            else if (recStack[i])
                return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // directed edge
    }

    if (hasCycle())
        printf("YES");
    else
        printf("NO");

    return 0;
}