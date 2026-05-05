#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    int max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    // frequency array
    int count[max + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // prefix sum (not strictly needed for basic sort, but included as asked)
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // output array
    int output[n];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }

    return 0;
}