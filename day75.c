#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxLen = 0;

    // hash map simulation using arrays
    int hash[2001];  // range for prefix sum (-1000 to +1000 approx)
    for (int i = 0; i < 2001; i++) hash[i] = -2;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int index = sum + 1000; // shift to handle negative

        if (hash[index] == -2) {
            hash[index] = i; // store first occurrence
        } else {
            int len = i - hash[index];
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    printf("%d\n", maxLen);
    return 0;
}