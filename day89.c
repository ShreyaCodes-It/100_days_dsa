#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] > maxPages) {
            students++;
            pagesSum = arr[i];
        } else {
            pagesSum += arr[i];
        }
    }

    return (students <= m);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

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

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}