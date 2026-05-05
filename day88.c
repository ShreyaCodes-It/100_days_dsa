#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// check if we can place k cows with min distance = dist
int canPlace(int arr[], int n, int k, int dist) {
    int count = 1;
    int lastPos = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPos >= dist) {
            count++;
            lastPos = arr[i];
        }
    }

    return (count >= k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    int low = 1;
    int high = arr[n - 1] - arr[0];
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(arr, n, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}