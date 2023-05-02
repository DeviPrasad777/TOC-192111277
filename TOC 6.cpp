#include <stdio.h>
#include <string.h>

// Define the CFG production rules
void S(char input[]);

// Define a function to check if a given string belongs to the language of the CFG
int belongsToLanguage(char input[]) {
  // Check if the input string matches the CFG production rules
  if (strlen(input) == 0) {
    return 1; // empty string is accepted
  } else {
    S(input); // check if the input string matches the S production rules
    return strcmp(input, "S") == 0;
  }
}

// Define the CFG production rules
void S(char input[]) {
  if (strlen(input) == 1) {
    return; // stop condition for recursion
  } else {
    int i = 1;
    while (i < strlen(input) - 1) {
      if (input[0] == '0' && input[strlen(input)-1] == '1' && input[i] == 'S') {
        printf("S -> 0S1\n");
        input[i-1] = 'S'; // replace '0S1' with 'S' to reduce the input string
        memmove(input+i, input+i+2, strlen(input)-i-1); // shift the remaining characters to the left
        i = 1; // reset i to 1 to check from the beginning again
      } else {
        i++; // increment i if input[i] is not '0S1'
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

