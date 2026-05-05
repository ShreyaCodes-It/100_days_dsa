#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int timeSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (timeSum + arr[i] > maxTime) {
            painters++;
            timeSum = arr[i];
        } else {
            timeSum += arr[i];
        }
    }

    return (painters <= k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int low = maxVal;
    int high = sum;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}