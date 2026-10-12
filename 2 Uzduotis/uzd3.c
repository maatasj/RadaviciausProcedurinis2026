#include <stdio.h>
int main() {
  int numb;
  scanf("%d", &numb);
  printf("%s", numb % 2 == 0 ? "Lyginis\n" : "Nelyginis\n");
  return 0;
}