#include <stdio.h>

#define NUM_STATES 4
#define NUM_SYMBOLS 2

int transitionTable[NUM_STATES][NUM_SYMBOLS][NUM_STATES] = {
    {{1, -1}, {-1, -1}},
    {{2, 3}, {-1, -1}},
    {{-1, -1}, {3, -1}},
    {{-1, 1}, {-1, -1}}
};

int eclosure[NUM_STATES][NUM_STATES] = {0};

void epsilonClosure(int state, int current) {
    int i;

    if (eclosure[state][current] == 1) {
        return;
    }

    eclosure[state][current] = 1;

    for (i = 0; i < NUM_STATES; i++) {
        if (transitionTable[current][0][i] != -1) {
            epsilonClosure(state, transitionTable[current][0][i]);
        }
    }
}

int main() {
    int i, j;

    for (i = 0; i < NUM_STATES; i++) {
        eclosure[i][i] = 1;
        epsilonClosure(i, i);
    }

    for (i = 0; i < NUM_STATES; i++) {
        printf("?-closure(%d) = {", i);
        for (j = 0; j < NUM_STATES; j++) {
            if (eclosure[i][j] == 1) {
                printf("%d,", j);
            }
        }
        printf("}\n");
    }

    return 0;
}

