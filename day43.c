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

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (arr[0] == -1) {
        free(arr);
        return 0;
    }

    Node* root = newNode(arr[0]);

    Node** q = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    q[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        Node* cur = q[front++];

        if (i < n && arr[i] != -1) {
            cur->left = newNode(arr[i]);
            q[rear++] = cur->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = newNode(arr[i]);
            q[rear++] = cur->right;
        }
        i++;
    }

    inorder(root);

    free(arr);
    free(q);
    return 0;
}