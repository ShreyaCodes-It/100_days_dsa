#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int a[n], temp[n];

    // input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // input k
    scanf("%d", &k);

    // handle if k > n
    k = k % n;

    // place elements in new position
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = a[i];
    }

    // print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}