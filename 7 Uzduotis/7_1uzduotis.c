#include <stdio.h>

int isInRange(int number, int low, int high) {
  if (low > high) {
    return 0;
  }
  return (number >= low && number <= high);
}

int main() {
  int low = 5, high = 15;
  printf("Skaičius 10 intervale [5; 15]: %d\n", isInRange(10, low, high));
  printf("Skaičius 3 intervale [5; 15]: %d\n", isInRange(3, low, high));
  printf("Skaičius 15 intervale [5; 15]: %d\n", isInRange(15, low, high));
  return 0;
}