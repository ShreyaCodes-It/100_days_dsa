#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int val) {
    struct Node* newNode = createNode(val);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteKey(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // if head itself is key
    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // search key
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // key not found
    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, key;
    struct Node* head = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(&head, x);
    }

    scanf("%d", &key);

    deleteKey(&head, key);

    printList(head);

    return 0;
}