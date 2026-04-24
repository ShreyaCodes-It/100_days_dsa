#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node* next;
};

struct Node* insert(struct Node* head, int c, int e) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;

    if (!head) return temp;

    struct Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = temp;

    return head;
}

void printPoly(struct Node* head) {
    struct Node* curr = head;

    while (curr) {
        if (curr->exp == 0)
            printf("%d", curr->coeff);
        else if (curr->exp == 1)
            printf("%dx", curr->coeff);
        else
            printf("%dx^%d", curr->coeff, curr->exp);

        if (curr->next) printf(" + ");
        curr = curr->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }

    printPoly(head);
    return 0;
}