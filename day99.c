#include <stdio.h>

#define MAX 1000

typedef struct {
    int pos;
    int speed;
} Car;

// sort by position descending
void sortCars(Car arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].pos < arr[j + 1].pos) {
                Car temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cars[i].pos, &cars[i].speed);
    }

    sortCars(cars, n);

    double stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        // if current car takes more time → new fleet
        if (top == -1 || time > stack[top]) {
            stack[++top] = time;
        }
        // else it joins previous fleet (ignore)
    }

    printf("%d", top + 1);

    return 0;
}