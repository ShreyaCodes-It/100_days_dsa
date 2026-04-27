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

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (n == 0 || arr[0] == -1) return 0;

    Node* root = newNode(arr[0]);

    Node* queue[n];
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

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);

    return 0;
}