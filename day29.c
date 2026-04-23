#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, val, k;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input n
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        scanf("%d", &val);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input k
    scanf("%d", &k);

    // Edge case
    if(head == NULL || k == 0) {
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Find length and last node
    int len = 1;
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
        len++;
    }

    // Make circular
    temp->next = head;

    // Effective rotations
    k = k % len;

    // Find (len - k)th node
    int steps = len - k;
    struct Node* newTail = head;

    for(i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // New head
    struct Node* newHead = newTail->next;

    // Break circular link
    newTail->next = NULL;

    // Print result
    temp = newHead;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}