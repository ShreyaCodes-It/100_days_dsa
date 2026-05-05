#include <stdio.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int visited[MAX];
int key[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize graph
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        key[i] = INF;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // input edges
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    // start from node 1
    key[1] = 0;
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int min = INF, u = -1;

        // pick minimum key vertex not visited
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // update neighbors
        for (int vtx = 1; vtx <= n; vtx++) {
            if (graph[u][vtx] && !visited[vtx] && graph[u][vtx] < key[vtx]) {
                key[vtx] = graph[u][vtx];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}