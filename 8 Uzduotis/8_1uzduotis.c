#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateArray(int size, int low, int high) {
  if (low > high) {
    printf("Error. Illogical interval\n");
    return NULL;
  }
  int *data = malloc(size * sizeof(int));
  if (data == NULL) {
    return NULL;
  }
  for (int i = 0; i < size; ++i) {
    *(data + i) = rand() % (high - low + 1) + low;
  }
  return data;
}

int main() {
  srand(time(NULL));
  int size = 23;
  // testavimas
  int *skaiciai = generateArray(size, 10, 20);
  for (int i = 0; i < size; ++i) {
    printf("%d ", skaiciai[i]);
  }
  return 0;
}
