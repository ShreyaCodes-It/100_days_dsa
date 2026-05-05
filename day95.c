#include <stdio.h>

#define MAX 100

// simple insertion sort for buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // buckets
    float bucket[MAX][MAX];
    int bucketCount[MAX] = {0};

    // distribute into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        bucket[index][bucketCount[index]] = arr[i];
        bucketCount[index]++;
    }

    // sort individual buckets
    for (int i = 0; i < n; i++) {
        if (bucketCount[i] > 0) {
            insertionSort(bucket[i], bucketCount[i]);
        }
    }

    // concatenate
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[idx++] = bucket[i][j];
        }
    }

    // print result
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}