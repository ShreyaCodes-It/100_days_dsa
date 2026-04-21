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

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while(a != NULL && b != NULL) {
        if(a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if(a != NULL) tail->next = a;
    if(b != NULL) tail->next = b;

    return dummy.next;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;
    struct Node *l1 = NULL, *l2 = NULL;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(&l1, x);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        insert(&l2, x);
    }

    struct Node* merged = merge(l1, l2);

    printList(merged);

    return 0;
}