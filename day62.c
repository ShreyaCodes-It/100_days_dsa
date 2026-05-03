#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

// Create new node
Node* newNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

// Create graph
Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;

    g->adjList = (Node**)malloc(V * sizeof(Node*));

    for (int i = 0; i < V; i++)
        g->adjList[i] = NULL;

    return g;
}

// Add edge (undirected)
void addEdge(Graph* g, int u, int v) {
    Node* n1 = newNode(v);
    n1->next = g->adjList[u];
    g->adjList[u] = n1;

    Node* n2 = newNode(u);
    n2->next = g->adjList[v];
    g->adjList[v] = n2;

    // 👉 For directed graph, comment below:
    // remove second insertion
}

// Print graph
void printGraph(Graph* g) {
    for (int i = 0; i < g->V; i++) {
        printf("%d: ", i);
        Node* temp = g->adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* g = createGraph(n);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    printGraph(g);

    return 0;
}