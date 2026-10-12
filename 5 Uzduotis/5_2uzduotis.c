#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randi(int a, int b) { return (rand() % (b - a + 1)) + a; }
int main() {
  int a, b, c;
  srand(time(NULL));
  int array[1000];
  printf("This program outputs c random numbers in the interval [a:b]\n");
  printf("Please input a b c, c<=1000:\n");
  while (1) {
    if (scanf("%d%d%d", &a, &b, &c) == 3) {
      if (b > a && c > 0 && c < 1000) {
        break;
      } else {
        printf("Illogical numerator input. \n");
      }
    } else {
      printf("Incorrect input. Please try again\n");
      while ((c = getchar()) != '\n' && c != EOF) {
      }
    }
  }
  printf("Input sucessful\n");
  for (int i = 0; i < c; ++i) {
    array[i] = randi(a, b);
    printf("%*d ", snprintf(NULL, 0, "%d", b), array[i]);
    // Limit to 5 numbers in a line
    if ((i + 1) % 5 == 0) {
      printf("\n");
    }
  }
  return 0;
}