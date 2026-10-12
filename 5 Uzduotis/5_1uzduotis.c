#include <stdio.h>
#define SIZE 10
void printArray(int arr[]) {
  for (int i = 0; i < SIZE; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main() {
  // a) assign array with 0's
  int numbers[SIZE] = {0};

  // b) print array
  printArray(numbers);

  // c) asign values
  numbers[0] = 1;
  numbers[3] = 2;
  numbers[9] = 3;

  // d) delete the third element and shift list
  int pos = 2;
  for (int i = pos; i <= SIZE - 1; ++i) {
    numbers[i] = numbers[i + 1];
  }
  numbers[SIZE - 1] = 0;

  // e) insert 4 at index 6
  pos = 6;
  for (int i = SIZE - 1; i > pos; --i) {
    numbers[i] = numbers[i - 1];
  }
  numbers[6] = 4;

  // f) print array to screen
  printArray(numbers);

  // g)
  int var1, var2;
  while (1) {
    printf("Please input two numbers x and y such that array[x] = y, x<%d:\n",
           SIZE);
    if (scanf("%d%d", &var1, &var2) == 2 && var1 >= 0 && var1 < SIZE) {
      numbers[var1] = var2;
      while (getchar() != '\n')
        ;
      break;
    } else {
      scanf("%*[^\n]");
    }
  }

  // h) remove element at pos x
  printf("Enter array's index to remove an element\n");
  while (1) {
    if (scanf("%d", &pos) == 1 && pos >= 0 && pos < SIZE) {
      while (getchar() != '\n')
        ;

      break;
    } else {
      printf("Incorrect input/array index out of bounds\n");
      scanf("%*[^\n]");
    }
  }
  for (int i = pos; i < SIZE - 1; ++i) {
    numbers[i] = numbers[i + 1];
  }
  numbers[SIZE - 1] = 0;
  // i)
  printf(
      "Please enter the index x at which the program should inset a value y\n");
  while (1) {
    if (scanf("%d%d", &var1, &var2) == 2 && var1 >= 0 && var1 < SIZE) {
      while (getchar() != '\n')
        ;
      break;
    } else {
      printf("Incorrect input/array index out of bounds\n");
      scanf("%*[^\n]");
    }
  }
  for (int i = SIZE - 1; i > var1; --i) {
    numbers[i] = numbers[i - 1];
  }
  numbers[var1] = var2;

  // j) print final array
  printArray(numbers);

  return 0;
}