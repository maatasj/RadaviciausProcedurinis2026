#include <stdio.h>
int getPositiveNumber(char *msg) {
  int num;
  char ch;
  while (1) {
    printf("%s", msg);
    if (scanf("%d", &num) == 1) {
      break;
    } else {
      while (((ch = getchar()) != '\n' && ch != EOF)) {
      }
    }
  }
  return num;
}
int main() {
  char *msg = "Please enter a single number and press Enter: ";
  printf("The entered number was %d\n", getPositiveNumber(msg));
  return 0;
}