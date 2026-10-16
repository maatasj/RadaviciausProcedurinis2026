#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
// Assuming <time.h> and <stdlib.h> are imported
void generateArray(int data[], int size, int low, int high) {
  if (low > high) {
    printf("Error. Illogical interval\n");
    return;
  }
  for (int i = 0; i < size; ++i) {
    data[i] = rand() % (high - low + 1) + low;
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
}

int main() {
  int data[SIZE];
  srand(time(NULL));

  generateArray(data, SIZE, 5, 50);
  printArray(data, SIZE);
  printf("\n");

  generateArray(data, SIZE, -50, 78);
  printArray(data, SIZE);
  printf("\n");

  generateArray(data, SIZE, 51, 50);
  printArray(data, SIZE);
  printf("\n");
  return 0;
}