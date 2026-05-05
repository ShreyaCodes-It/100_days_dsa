#include <stdio.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

int minDistance(int n) {
    int min = INF, idx = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // init graph
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;

        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // remove for directed
    }

    int src;
    scanf("%d", &src);

    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        int u = minDistance(n);
        visited[u] = 1;

        for (int vtx = 1; vtx <= n; vtx++) {
            if (!visited[vtx] &&
                graph[u][vtx] &&
                dist[u] != INF &&
                dist[u] + graph[u][vtx] < dist[vtx]) {

                dist[vtx] = dist[u] + graph[u][vtx];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}