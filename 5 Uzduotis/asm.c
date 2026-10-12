#include <math.h>
#include <stdio.h>
double roundNumber(double num, int precision) {
  double scale = pow(10.0, precision);
  return round(num * scale) / scale;
}
int main() {
  double sk = 5.6;
  if ((fabs(sk - roundNumber(sk, 3))) > 1e-9) {
    printf("Blogai\n");

  } else {
    printf("Gerai\n");
  }
}
