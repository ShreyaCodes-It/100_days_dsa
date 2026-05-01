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

// Check mirror
int isMirror(Node* a, Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;

    return (a->data == b->data) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

// Main symmetric check
int isSymmetric(Node* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    if (arr[0] == -1) {
        printf("YES\n");
        return 0;
    }

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

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}