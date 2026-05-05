#include <stdio.h>

#define MAX 1000

void sort(int start[], int end[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (start[j] > start[j + 1]) {

                int temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;

                temp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int start[MAX], end[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &start[i], &end[i]);
    }

    sort(start, end, n);

    int rooms = 0;
    int currentEnd[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {

        int assigned = 0;

        // try to reuse room
        for (int j = 0; j < size; j++) {
            if (start[i] >= currentEnd[j]) {
                currentEnd[j] = end[i];
                assigned = 1;
                break;
            }
        }

        // new room
        if (!assigned) {
            currentEnd[size++] = end[i];
        }
    }

    printf("%d", size);

    return 0;
}