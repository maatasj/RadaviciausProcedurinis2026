#include <stdio.h>
int sum(double nums[], int size) {
  int sum = 0;
  for (int i = 0; i < size; ++i) {
    sum += nums[i];
  }
  return sum;
}
int max(double nums[], int size) {
  int maks = nums[0];
  for (int i = 1; i < size; ++i) {
    if (nums[i] > maks)
      maks = nums[i];
  }
  return maks;
}
int min(double nums[], int size) {
  int minn = nums[0];
  for (int i = 1; i < size; ++i) {
    if (nums[i] < minn)
      minn = nums[i];
  }
  return minn;
}
int main() {
  int size, counter = 0;
  double average, num;
  printf(
      "The program calculates the sum, average and finds min and max value.\n");
  printf("Please input the number of numbers: ");
  while (1) {
    if ((scanf("%d", &size) == 1)) {
      break;
    } else {
      printf("Invalid input. Please try again: ");
      scanf("%*[^\n]");
    }
  }
  double numbers[size];
  printf("Enter %d numbers: (After each number press Enter) \n", size);
  while (counter < size) {
    printf("%d): ", counter + 1);
    if ((scanf("%lf", &num) == 1)) {

      numbers[counter++] = num;
    } else {
      printf("Invalid input. Please try again\n");
      scanf("%*[^\n]");
    }
  }
  printf("Input sucessful. \n");
  printf("The sum of numbers is %d\n", sum(numbers, size));
  printf("The average of given numbers is %.2f\n",
         (float)sum(numbers, size) / size);
  printf("The biggest number is %d\n", max(numbers, size));
  printf("The smallest number is %d\n", min(numbers, size));
  return 0;
}