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

int countKey(struct Node* head, int key) {
    int count = 0;

    while(head != NULL) {
        if(head->data == key) {
            count++;
        }
        head = head->next;
    }

    return count;
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

    printf("%d", countKey(head, key));

    return 0;
}