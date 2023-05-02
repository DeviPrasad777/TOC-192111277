#include <stdio.h>
#include <string.h>

#define NUM_STATES 4
#define NUM_SYMBOLS 2
int transitionTable[NUM_STATES][NUM_SYMBOLS][NUM_STATES] = {
    {{0, 1}, {-1, -1}},
    {{-1, -1}, {2, -1}},
    {{-1, -1}, {3, -1}},
    {{-1, -1}, {-1, -1}}
};

int main() {
    char inputString[100];
    int currentState = 0;
    int i, j, k;

    printf("Enter input string: ");
    scanf("%s", inputString);

    for (i = 0; i < strlen(inputString); i++) {
        int symbol = inputString[i] - 'a';
        int nextStates[NUM_STATES] = {-1};

        for (j = 0; j < NUM_STATES; j++) {
            if (currentState == j || currentState == -1) {
                for (k = 0; k < NUM_STATES; k++) {
                    int nextState = transitionTable[j][symbol][k];
                    if (nextState != -1) {
                        nextStates[nextState] = 1;
int transitionTable[NUM_STATES][NUM_SYMBOLS][NUM_STATES] = {
    {{0, 1}, {-1, -1}},
    {{-1, -1}, {2, -1}},
    {{-1, -1}, {3, -1}},
    {{-1, -1}, {-1, -1}}
};

int main() 
{
    char inputString[100];
    int currentState = 0;
    int i, j, k;

    printf("Enter input string: ");
    scanf("%s", inputString);

    for (i = 0; i < strlen(inputString); i++) {
        int symbol = inputString[i] - 'a';
        int nextStates[NUM_STATES] = {-1};

        for (j = 0; j < NUM_STATES; j++) {
            if (currentState == j || currentState == -1) {
                for (k = 0; k < NUM_STATES; k++) {
                    int nextState = transitionTable[j][symbol][k];
                    if (nextState != -1) {
                        nextStates[nextState] = 1;
int transitionTable[NUM_STATES][NUM_SYMBOLS][NUM_STATES] = {
    {{0, 1}, {-1, -1}},
    {{-1, -1}, {2, -1}},
    {{-1, -1}, {3, -1}},
    {{-1, -1}, {-1, -1}}
};

int main() {
    char inputString[100];
    int currentState = 0;
    int i, j, k;

    printf("Enter input string: ");
    scanf("%s", inputString);

    for (i = 0; i < strlen(inputString); i++) {
        int symbol = inputString[i] - 'a';
        int nextStates[NUM_STATES] = {-1};

        for (j = 0; j < NUM_STATES; j++) {
            if (currentState == j || currentState == -1) {
                for (k = 0; k < NUM_STATES; k++) {
                    int nextState = transitionTable[j][symbol][k];
                    if (nextState != -1) {
                        nextStates[nextState] = 1;
                    }
                }
            }
        }

        currentState = -1;
        for (j = 0; j < NUM_STATES; j++) {
            if (nextStates[j] != -1) {
                currentState = j;
                break;
            }
        }

        if (currentState == -1) {
            printf("Rejected\n");
            return 0;
        }
    }

    if (currentState == NUM_STATES - 1) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}

