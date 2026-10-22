#include <stdio.h>
#include <stdlib.h>

int splitData(int *arr1, int size, int splitSize, int **arr11, int **arr12) {
  if (arr1 == NULL || size < 1 || splitSize > size || splitSize < 0) {
    return -1;
  }
  if (arr11 == NULL || arr12 == NULL || *arr11 != NULL || *arr12 != NULL) {
    return -1;
  }
  int size2 = size - splitSize;
  *arr11 = malloc(splitSize * sizeof(int));
  *arr12 = malloc(size2 * sizeof(int));
  if (*arr11 == NULL || arr12 == NULL) {
    free(*arr11);
    free(*arr12);
    *arr11 = NULL;
    *arr12 = NULL;
    return -1;
  }
  if (*arr11 != NULL) {
    for (int i = 0; i < splitSize; ++i) {
      *(*arr11 + i) = arr1[i];
    }
  }

  if (*arr12 != NULL) {
    for (int i = 0; i < size2; ++i) {
      *(*arr12 + i) = arr1[i + splitSize];
    }
  }
  return 0;
}

// easier code reading:)
void printArray(int *arr1, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr1[i]);
  }
}
int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  int *arr11 = NULL;
  int *arr12 = NULL;
  int split = 3;

  if (!splitData(arr1, 5, split, &arr11, &arr12)) {
    printArray(arr11, split);
    printf("\n");
    printArray(arr12, 5 - split);
  }
}
