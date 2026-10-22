#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MISINPUT 7

int ValidEmailCheck(char input[]) {
  int lenght = strlen(input);
  int atIndex = -1;
  int dotIndexes[98], dotCounter = 0;
  if (input[0] == '@' || input[0] == '.') {
    printf("Invalid email. The first digit cannot be '@' or '.'\n");
    return 0;
  }
  for (int i = 0; i < lenght; ++i) {
    // Check for @ and if it repeats
    if (input[i] == '@') {
      if (atIndex == -1) {
        atIndex = i;
      } else {
        printf("Invalid email. There cannot be more than one '@'\n");
        return 0;
      }
    }
    // save indexes of '.'
    if (input[i] == '.') {
      dotIndexes[dotCounter++] = i;
    }
  }
  if (atIndex == -1 || dotCounter == 0 || atIndex > dotIndexes[0] + 1 ||
      input[lenght - 1] == '.') {
    printf("Invalid email. Invalid formatting.\n");
    return 0;
  }
  for (int i = 0; i < dotCounter; ++i) {
    if (input[dotIndexes[i] + 1] == '@' || input[dotIndexes[i] + 1] == '.' ||
        input[dotIndexes[i] - 1] == '.') {
      printf("Invalid email. '@' and '.' cannot be next to each "
             "other\n");
      return 0;
    }
  }
  return 1;
}

void printDomain(char input[]) {
  int len = strlen(input);
  int i = 0;
  printf("Domain: ");
  for (; i < len; ++i) {
    if (input[i] == '@') {
      break;
    }
  }
  ++i;
  for (; i < len; ++i) {
    printf("%c", input[i]);
  }
  printf("\n");
}

int main() {
  const char fileName[] = "emails.txt";
  char input[100];
  int ch, missinputs = 0;

  FILE *file = fopen(fileName, "a");
  if (file == NULL) {
    printf("Error creating or opening file.\n");
    return 0;
  }
  printf("This program checks whether an email is formated correctly.\nIf so, "
         "it appends it to emails.txt\n");

  // User input
  while (1) {
    if (missinputs >= MAX_MISINPUT) {
      printf("Too many incorrect inputs.\n");
      return 0;
    }
    if (scanf("%99s", input) == 1) {
      if (ValidEmailCheck(input)) {
        printDomain(input);
        break;
      } else {
        missinputs++;
      }
    } else {
      printf("Incorrect input. Please try again\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      ++missinputs;
    }
  }
  // Append emails to file and close file
  fprintf(file, "%s\n", input);
  fclose(file);
  return 0;
}