#include <math.h>
#include <stdio.h>
const char upToBase16Digits[] = "0123456789ABCDEF";
int toDecimal(long long num, int sys) {

  int power = 0;
  while (num > 0) {
    int last_digit = num % 10;
  }
}
int main() {
  long long num;
  int sys1, sys2;
  printf("This program converts a number from one counting "
         "system to another(Up to base16)\n");
  printf("Please input your number ");
  scanf("%lld", &num);
  printf("Please input the counting system of this number and the system to "
         "convert[2;16]\n");
  scanf("%d%d", &sys1, &sys2);
  return 0;
}