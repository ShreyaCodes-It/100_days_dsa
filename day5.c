#include <stdio.h>

int main() {
    int p, q, i = 0, j = 0, k = 0;

    scanf("%d", &p);
    int a[p];

    for(int x = 0; x < p; x++) {
        scanf("%d", &a[x]);
    }

    scanf("%d", &q);
    int b[q];

    for(int x = 0; x < q; x++) {
        scanf("%d", &b[x]);
    }

    int c[p + q];

    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while(i < p) {
        c[k++] = a[i++];
    }

    while(j < q) {
        c[k++] = b[j++];
    }

    for(int x = 0; x < p + q; x++) {
        printf("%d ", c[x]);
    }

    return 0;
}