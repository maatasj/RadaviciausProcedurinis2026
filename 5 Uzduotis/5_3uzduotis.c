#include <stdio.h>

int main() {
  int s, n, counter = 0, temp, ch;
  // input s, n
  printf("This program find pairs of inputed numbers which multiply to s from "
         "n numbers\n");
  printf("Please input s,n: \n");
  while (1) {
    if (scanf("%d%d", &s, &n) == 2) {
      if (n > 0) {
        break;
      } else {
        printf("n cannot be less than 1\n");
      }
    } else {
      printf("Incorrect input. Please try again\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
    }
  }
  // Input array elements
  printf("Input sucessful. Please input %d positive elements.\n", n);
  int array[n];
  while (counter < n) {
    printf("%d) ", counter + 1);
    if (scanf("%d", &temp) == 1) {
      if (temp > 0) {
        array[counter++] = temp;
      } else {
        printf("Please enter a positive number\n");
      }
    } else {
      printf("Incorrect input. Please try again\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
    }
  }
  // Logic
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (array[i] * array[j] == s) {
        printf("(%d,%d)\n", array[i], array[j]);
      }
    }
  }

  return 0;
}