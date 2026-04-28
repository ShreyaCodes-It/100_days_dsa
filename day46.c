#include <stdio.h>
#include <stdlib.h>

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

void levelOrder(Node* root) {
    if (!root) return;

    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* cur = queue[front++];
        printf("%d ", cur->data);

        if (cur->left)
            queue[rear++] = cur->left;

        if (cur->right)
            queue[rear++] = cur->right;
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

    Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        Node* cur = queue[front++];

        if (i < n && arr[i] != -1) {
            cur->left = newNode(arr[i]);
            queue[rear++] = cur->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = newNode(arr[i]);
            queue[rear++] = cur->right;
        }
        i++;
    }

    levelOrder(root);

    return 0;
}