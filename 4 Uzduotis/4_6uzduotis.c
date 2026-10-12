#include <stdio.h>
int num_digits(int num) {
  int digits = 0;
  while (num > 0) {
    num /= 10;
    digits++;
  }
  return digits;
}
// May be a strange program because the biggest number will always have the most
// digits but oh well
int main() {
  printf("This program returns the number with the most digits from a sequence "
         "of integers. \nPress enter "
         "after every number. Input -1 number to stop\n");
  int num, digits, max_digits_num = 0;
  while (1) {
    if (scanf("%d", &num) == 1) {
      if (num <= 0)
        break;
      if (num_digits(num) > digits) {
        digits = num_digits(num);
        max_digits_num = num;
      }
    } else {
      printf("Invalid input. Please try again: ");
      scanf("%*[^\n]");
    }
  }
  if (max_digits_num != 0) {
    printf("The number with the most digits in the sequence is %d\n",
           max_digits_num);
  } else {
    printf("No numbers have been inputed.\n");
  }
  return 0;
}