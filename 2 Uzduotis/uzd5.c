#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  double x, y, z;
  printf("Iveskite tris realiuosius skaicius x, y, z: ");
  scanf("%lf%lf%lf", &x, &y, &z);

  printf("a) %.2f\n", x + (4 * y) + pow(z, 3));
  printf("b) %.2f\n", (x + sqrt(y)) * (pow(z, 4) - fabs(z) + 46.3));
  return 0;
}