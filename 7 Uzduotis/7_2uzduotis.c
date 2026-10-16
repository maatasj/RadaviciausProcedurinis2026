#include <stdio.h>
// Factorial with recursion
int getFactorial(int number) {
  if (number == 0) {
    return 1;
  }
  if (number > 1) {
    return number * getFactorial(number - 1);
  } else {
    return 0;
  }
}
// Factorial with simple for loop
int getFactorial2(int number) {
  int sum = 1;
  if (number > 1) {
    for (int i = 1; i <= number; ++i) {
      sum *= i;
    }
  } else {
    return 0;
  }
  return sum;
}

int main() {
  int a = 5, b = 7, c = 0;
  printf("%d! = %d\n", a, getFactorial(a));
  printf("%d! = %d\n", b, getFactorial2(b));
  printf("%d! = %d\n", c, getFactorial(c));
  return 0;
}