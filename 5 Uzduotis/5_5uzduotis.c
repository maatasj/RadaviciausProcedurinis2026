#include <stdio.h>
#include <stdlib.h>
// Checks if a number can be writen with the same digits as another number
int isNumInsideNum(int num, int digits1[]) {
  int digits[10] = {0};
  int digit;
  while (num > 0) {
    digits[num % 10] += 1;
    num /= 10;
  }
  for (int i = 0; i < 10; ++i) {
    if (digits[i] > digits1[i]) {
      return 0;
    }
  }
  return 1;
}
// Checks if all a condition applies to all numbers in an array
int doesApplyToArray(int arrayBig[], int nums[], int counter) {
  for (int i = 0; i < counter; ++i) {
    if (isNumInsideNum(nums[i], arrayBig) == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n, counter = 0, temp, ch, numDigits[10] = {0};
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
  // Write digits as numbers in array
  while (n > 0) {
    numDigits[n % 10] += 1;
    n /= 10;
  }

  if (doesApplyToArray(numDigits, array, counter) == 1) {
    printf("Can be made\n");
  } else {
    printf("Cannot be made\n");
  }
}