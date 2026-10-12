#include <stdio.h>
#define MAX_MISINPUT 5
FILE *file;

// factorial function
int factorial(int sk) {
  int sum = 1;
  while (sk > 0) {
    sum *= sk;
    --sk;
  }
  return sum;
}
int main() {
  file = fopen("out.txt", "w");
  int n, temp, ch, missinputs = 0;

  printf("This program calculates n!(factorial)\n");
  printf("Please input n: \n");
  while (1) {
    if (missinputs >= MAX_MISINPUT) {
      printf("Too many incorrectly inputed files.");
      return 0;
    }
    if (scanf("%d", &n) == 1) {
      break;
    } else {
      printf("Incorrect input. Please try again\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
    }
  }
  n = factorial(n);
  printf("%d\n", n);
  fprintf(file, "%d\n", n);
  fclose(file);
  return 0;
}