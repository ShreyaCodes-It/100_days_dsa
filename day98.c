#include <stdio.h>

#define MAX 1000

typedef struct {
    int start;
    int end;
} Interval;

void sortIntervals(Interval arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].start > arr[j + 1].start) {
                Interval temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    sortIntervals(arr, n);

    Interval merged[MAX];
    int idx = 0;

    merged[0] = arr[0];
    idx = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= merged[idx - 1].end) {
            // overlap → merge
            if (arr[i].end > merged[idx - 1].end) {
                merged[idx - 1].end = arr[i].end;
            }
        } else {
            merged[idx++] = arr[i];
        }
    }

    // print result
    for (int i = 0; i < idx; i++) {
        printf("[%d,%d] ", merged[i].start, merged[i].end);
    }

    return 0;
}