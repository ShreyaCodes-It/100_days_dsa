#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];

// Kahn's Algorithm
void topoSort(int n) {
    int front = 0, rear = 0;

    // push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // check cycle
    if (count != n) {
        printf("\nCycle detected (Topological sort not possible)");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    topoSort(n);

    return 0;
}