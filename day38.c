#include <stdio.h>
#include <string.h>

#define MAX 1000

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void push_front(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    dq[front] = x;
}

void push_back(int x) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) return;

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    dq[rear] = x;
}

void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void get_front() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

void get_back() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

void display() {
    if (isEmpty()) {
        printf("\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    while (n--) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } 
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } 
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        } 
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        } 
        else if (strcmp(op, "front") == 0) {
            get_front();
        } 
        else if (strcmp(op, "back") == 0) {
            get_back();
        } 
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } 
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        } 
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}