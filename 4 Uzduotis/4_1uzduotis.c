#include <math.h>
#include <stdio.h>

int main() {
  int a, b, c, D;
  double sol1, sol2;
  char n;
  printf("The program calculates a quadratic expression ax^2+bx+c=0 with given "
         "a,b,c\n");
  printf("Please input a,b,c: ");
  while (1) {
    if ((scanf("%d%d%d", &a, &b, &c) == 3)) {
      break;
    } else {
      printf("Invalid input. Please try again\n");
      scanf("%*[^\n]");
    }
  }
  printf("Input succesful.\n");
  if (a == 0) {
    printf("x = %.2lf\n", (-(double)c / b));
    return 0;
  }
  D = b * b - (4 * a * c);
  if (D < 0) {
    printf("There are no solutions\n");
  } else if (D == 0) {
    printf("x = %.2lf", (double)(-b / (2 * a)));
  } else {
    sol1 = ((-b + sqrt(D)) / (2 * a));
    sol2 = ((-b - sqrt(D)) / (2 * a));
    printf("x1 = %.2lf x2 = %.2lf\n", sol1, sol2);
  }
  return 0;
}
