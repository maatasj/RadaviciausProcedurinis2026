#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MISINPUT 7
FILE *file;
int findMiddle(int a, int b, int c) {
  if ((a >= b && a <= c) || (a <= b && a >= c))
    return a;
  if ((b >= a && b <= c) || (b <= a && b >= c))
    return b;
  return c;
}

int doesEndWithTXT(char fileName[]) {
  int len = strlen(fileName);
  if (len < 4) {
    return 0;
  }
  if (strcmp(fileName + len - 4, ".txt") == 0) {
    return 1;
  }
  return 0;
}
int main() {
  char fileName[100] = "";
  int ch, missinputs = 0;
  int a, b, c, mid;

  printf("This program reads 3 numbers and outputs the middle number a chosen "
         "file\n");
  printf("Please enter three numbers:  ");
  // Reading numbers
  while (1) {
    if (missinputs >= MAX_MISINPUT) {
      printf("Too many incorrect inputs.\n");
      return 0;
    }
    if (scanf("%d;%d;%d", &a, &b, &c) == 3) {
      printf("Input succesful\n");
      mid = findMiddle(a, b, c);
      break;
    } else {
      printf("Incorrect input. Please try again\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      ++missinputs;
    }
  }
  // Reading filename

  while (1) {
    printf("Please enter filename, ending with .txt\n");
    scanf("%99s", fileName);
    if (doesEndWithTXT(fileName) == 1) {

      file = fopen(fileName, "w");

      if (file == NULL || fileName[0] == '\0') {
        printf("Please enter a valid file name ending with .txt:\n");
        scanf("%99s", fileName);
        ++missinputs;
        continue;
      }
      fprintf(file, "%d", mid);
      fclose(file);
      break;
    } else {
      continue;
    }
  }

  return 0;
}