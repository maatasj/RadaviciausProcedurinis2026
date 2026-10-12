#include <stdio.h>
#include <stdlib.h>
// goated prime number checker
int isPrime(int num) {
  if (num < 2)
    return 0;
  if (num == 2)
    return 1;
  if (num % 2 == 0)
    return 0;
  for (int i = 3; i <= num / i; i += 2) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}
int isInArray(int num, int array[], int size) {
  for (int i = 0; i < size; ++i) {
    if (array[i] == num)
      return 1;
  }
  return 0;
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d\n", array[i]);
  }
}
int main() {

  int s, n, counter = 0, counterp = 0, temp, ch;
  // input s, n
  printf("This program outputs unique inputed prime numbers\n");
  printf("Please enter a non-positive value to stop input \n");
  // Input array elements
  int set[1000];
  int primes[1000];
  // input
  while (1) {
    printf("%d) ", counter + 1);
    if (scanf("%d", &temp) == 1) {
      ++counter;
      if (temp > 0) {
        if (isInArray(temp, primes, counter) == 0 && isPrime(temp)) {
          primes[counterp++] = temp;
        }
      } else {
        printf("Input sucessful.\n");
        break;
      }
    } else {
      printf("Incorrect input. Please try again\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
    }
  }
  // Logic
  printf("Primes:\n");
  printArray(primes, counterp);
  return 0;
}