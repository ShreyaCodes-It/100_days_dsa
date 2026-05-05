#include <stdio.h>

#define MAX 100
#define INF 99999

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
int dist[MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    // initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // relax edges (n-1 times)
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // print distances
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}