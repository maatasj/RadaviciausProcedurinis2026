#include <stdio.h>

int main() {
  int a, b, c;
  int fc;
  printf("The program calculates fc = fc-1 + fc-2, where f0=a, f1=b\nIn "
         "simpler terms, it calculates Fibonacci sequence from a custom f1 and "
         "f2\n");
  printf("Please input a,b,c: ");
  while (1) {
    if ((scanf("%d%d%d", &a, &b, &c) == 3)) {
      break;
    } else {
      printf("Invalid input. Please try again\n");
      scanf("%*[^\n]");
    }
  }

  if (a == 0 && b == 0) {
    printf("Invalid input. Sum is always 0.\n");
    return 0;
  }
  printf("Input succesful.\n");
  for (int i = 0; i < (c - 1); ++i) {
    fc = a + b;

    a = b;
    b = fc;
  }
  printf("Result: %d\n", fc);
  return 0;
}
