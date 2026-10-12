#include <stdio.h>
int max(int sk1, int sk2, int sk3) {
  return (sk1 > sk2) ? (sk1 > sk3 ? sk1 : sk3) : (sk2 > sk3 ? sk2 : sk3);
}
int min(int sk1, int sk2, int sk3) {
  return (sk1 < sk2) ? (sk1 < sk3 ? sk1 : sk3) : (sk2 < sk3 ? sk2 : sk3);
}

int main() {
  int num1, num2, num3;
  int mini, maks;

  printf("Iveskite tris skaicius. Programa grazins didziausia ir maziausia\n");
  scanf("%d%d%d", &num1, &num2, &num3);

  maks = max(num1, num2, num3);
  mini = min(num1, num2, num3);
  printf("Max: %d\nMin: %d\n", maks, mini);
}