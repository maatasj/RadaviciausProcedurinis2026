#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, temp, ch, counter = 0;
  // input s, n
  printf("This program checks if all elements in an array can be made from a "
         "single number n\n");
  printf("Please input n: \n");
  while (1) {
    if (scanf("%d", &n) == 1) {
      break;
    } else {
      printf("Incorrect input. Please try again\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
    }
  }

  // Input array elements
  printf(
      "Please enter array values. Enter a non-positive value to stop input \n");
  int array[1000];
  while (counter < 1000) {
    printf("%d) ", counter + 1);
    if (scanf("%d", &temp) == 1) {
      if (temp > 0) {
        array[counter++] = temp;
      } else {
        printf("Input sucessful.\n");
        break;
      }
    } else {
      printf("Please input a number!\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
    }
  }
}