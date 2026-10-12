#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binToDec(const char num[]) {
  int dec = 0;
  int power = 0;
  int len = strlen(num);
  for (int i = len - 1; i >= 0; i--) {
    if (num[i] == '1') {
      dec += pow(2, power);
    }
    power += 1;
  }
  return dec;
}

// pakolkas iki 1023 veikia
int decToBin(int num) {
  unsigned long long sum = 0;
  int place = 1;
  while (num > 0) {
    long rem = num % 2;
    sum = sum + rem * place;
    place *= 10;
    num /= 2;
  }
  return sum;
}

int main() {
  long long num;
  char sys1, sys2;
  printf("%d", binToDec("101000101010010101111"));
  exit(1);

  printf(
      "This program converts a number from one counting system to another\n");
  printf("Please input your number ");
  scanf("%lld", &num);
  printf("Please input the counting system of this number and the system to "
         "convert\n");
  printf("b - binary, d - decimal, h - hexadecimal: ");
  scanf("%s%s", &sys1, &sys2);
  return 0;
}