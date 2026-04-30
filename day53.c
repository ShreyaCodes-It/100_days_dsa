#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

typedef struct {
    Node* node;
    int hd;
} Pair;

void verticalOrder(Node* root) {
    if (!root) return;

    Pair queue[MAX];
    int front = 0, rear = 0;

    int map[200][100];
    int size[200] = {0};

    int offset = 100;

    queue[rear++] = (Pair){root, 0};

    while (front < rear) {
        Pair p = queue[front++];
        Node* curr = p.node;
        int hd = p.hd;

        map[hd + offset][size[hd + offset]++] = curr->data;

        if (curr->left)
            queue[rear++] = (Pair){curr->left, hd - 1};
        if (curr->right)
            queue[rear++] = (Pair){curr->right, hd + 1};
    }

    for (int i = 0; i < 200; i++) {
        if (size[i] > 0) {
            for (int j = 0; j < size[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (arr[0] == -1) return 0;

    Node* root = newNode(arr[0]);

    Node* queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    verticalOrder(root);

    return 0;
}