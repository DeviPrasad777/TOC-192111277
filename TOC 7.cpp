#include <stdio.h>
#include <string.h>

// Define the CFG production rules
void S(char input[]);
void A(char input[]);

// Define a function to check if a given string belongs to the language of the CFG
int belongsToLanguage(char input[]) {
  // Check if the input string matches the CFG production rules
  S(input); // check if the input string matches the S production rules
  return strcmp(input, "S") == 0;
}

// Define the CFG production rules
void S(char input[]) {
  if (strlen(input) < 4 || input[0] != 'A' || input[strlen(input)-1] != 'A') {
    return; // stop condition for recursion
  } else {
    A(input); // check if the input string matches the A production rules
    int i = 1;
    while (i < strlen(input) - 1) {
      if (input[i-1] == 'A' && input[i] == '1' && input[i+1] == '0' && input[i+2] == '1' && input[i+3] == 'A') {
        printf("S -> A101A\n");
        input[i-1] = 'S'; // replace 'A101A' with 'S' to reduce the input string
        memmove(input+i, input+i+4, strlen(input)-i-3); // shift the remaining characters to the left
        i = 1; // reset i to 1 to check from the beginning again
        A(input); // check if the input string matches the A production rules again
      } else {
        i++; // increment i if input[i] is not 'A101A'
      }
    }
  }
}

void A(char input[]) {
  if (strlen(input) == 1) {
    return; // stop condition for recursion
  } else {
    int i = 0;
    while (i < strlen(input)) {
      if (input[i] == '0' || input[i] == '1') {
        printf("A -> %cA\n", input[i]);
        i++; // increment i if input[i] is '0' or '1'
      } else {
        printf("A -> ?\n");
        input[i] = 'A'; // replace '?' with 'A' to reduce the input string
        memmove(input+i+1, input+i+2, strlen(input)-i-1); // shift the remaining characters to the left
        i++; // increment i if input[i] is '?'
      }
    }
  }
}

int main() {
  // Get the input string from the user
  char input[100];
  printf("Enter an input string: ");
  scanf("%s", input);

  // Check if the input string belongs to the language of the CFG
  if (belongsToLanguage(input)) {
    printf("Accepted\n");
  } else {
    printf("Rejected\n");
  }

  return 0;
}

