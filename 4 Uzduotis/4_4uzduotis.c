#include <stdio.h>
#include <stdlib.h>
// reusing code from previous exercise(1 uzduotis)
int max(int sk1, int sk2, int sk3) {
  return (sk1 > sk2) ? (sk1 > sk3 ? sk1 : sk3) : (sk2 > sk3 ? sk2 : sk3);
}
int min(int sk1, int sk2, int sk3) {
  return (sk1 < sk2) ? (sk1 < sk3 ? sk1 : sk3) : (sk2 < sk3 ? sk2 : sk3);
}
// finds the greatest common multiple by brute force
int gcd(int a, int b, int c) {
  int maks = 1;
  for (int i = 2; i <= min(a, b, c); ++i) {
    if ((a % i == 0) && (b % i == 0) && (c % i == 0)) {
      maks = i;
    }
  }
  return maks;
}
// finds smallest common multiple with brute force
int scm(int a, int b, int c) {
  int maks = max(a, b, c);
  while (1) {
    if (((maks % a == 0) && (maks % b == 0) && (maks % c == 0))) {
      return maks;
    }
    ++maks;
  }
}
int main() {
  int a, b, c;
  printf(
      "The programs finds the smallest common multiple(SCM) and the greatest "
      "(GCD) common divider \nbetween three numbers a, b, c\n");
  printf("Please input a,b,c: ");
  while (1) {
    if ((scanf("%d%d%d", &a, &b, &c) == 3)) {
      break;
    } else {
      printf("Invalid input. Please try again\n");
      scanf("%*[^\n]");
    }
  }
  printf("GCD: %d\n", gcd(a, b, c));
  printf("SCM: %d\n", scm(a, b, c));
  return 0;
}
