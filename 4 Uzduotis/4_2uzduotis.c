#include <stdio.h>

int main() {
  int a, b, c, counter = 0;
  printf("The program calculates all positive integers from interval (a;b] "
         "which divide from c with a remainder of 1, given a,b,c\n");
  printf("Please input a,b,c: ");
  while (1) {
    if ((scanf("%d%d%d", &a, &b, &c) == 3)) {
      break;
    } else {
      printf("Invalid input. Please try again\n");
      scanf("%*[^\n]");
    }
  }
  printf("Input successful.\n");
  for (int i = a; i <= b; ++i) {
    if (c % i == 1) {
      printf("%d ", i);
      counter++;
    }
  }
  if (counter == 0) {
    printf("No numbers have been found.");
  }
  printf("\n");
  return 0;
}
