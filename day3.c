#include <stdio.h>

int main() {
    int n, i, k, found = 0, count = 0;

    scanf("%d", &n);

    int arr[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for(i = 0; i < n; i++) {
        count++;
        if(arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", count);

    return 0;
}