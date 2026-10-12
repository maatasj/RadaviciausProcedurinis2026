#include <stdio.h>
int rikiavimas(int num) {
  int result = 0;
  if (num < 10) {
    return num;
  }
  for (int digit = 0; digit < 10; digit++) {
    int temp = num;
    while (temp > 0) {
      if (temp % 10 == digit) {
        result = result * 10 + digit;
      }
      temp /= 10;
    }
  }
  return result;
}
int main() {
  int num;
  printf("Irasykite skaiciu, kuri norite isrikiuoti: ");
  scanf("%d", &num);
  printf("%d\n", rikiavimas(num));
  return 0;
}