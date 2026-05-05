#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];
    int count[MAX] = {0};

    // input names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // count frequency
    for (int i = 0; i < n; i++) {
        if (count[i] != -1) {
            int c = 1;
            for (int j = i + 1; j < n; j++) {
                if (strcmp(names[i], names[j]) == 0) {
                    c++;
                    count[j] = -1; // mark counted
                }
            }
            count[i] = c;
        }
    }

    // find winner
    int maxVotes = 0;
    char winner[LEN];

    for (int i = 0; i < n; i++) {
        if (count[i] != -1) {
            if (count[i] > maxVotes) {
                maxVotes = count[i];
                strcpy(winner, names[i]);
            } else if (count[i] == maxVotes) {
                if (strcmp(names[i], winner) < 0) {
                    strcpy(winner, names[i]);
                }
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}