#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 7

int table[SIZE];

// initialize table
void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

// convert string to uppercase
void toUpper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// hash function
int hash(int key) {
    return key % SIZE;
}

// insert
void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }
}

// search
void search(int key) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == -1) {
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int t, n, key;
    char op[20];

    init();

    scanf("%d", &t); // table size (ignored)
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        toUpper(op);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}