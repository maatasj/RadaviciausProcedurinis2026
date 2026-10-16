#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// for fun
void generateRandomFile(const char *filename) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    printf("Error.\n");
    return;
  }
  long size = rand() % 300000;
  for (int i = 0; i < size; ++i) {
    char random_bit = rand() % 2;
    fwrite(&random_bit, 1, 1, file);
  }
  fclose(file);
}

long getFileSize(const char *fileName) {
  FILE *file = fopen(fileName, "rb");
  if (file == NULL) {
    printf("Error. File doesn't exist\n");
    return -1;
  }
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fclose(file);
  return size;
}

int main() {
  srand(time(NULL));
  printf("%ld bytes\n", getFileSize("7_5uzduotis.c"));

  generateRandomFile("File.txt");
  printf("%ld bytes\n", getFileSize("File.txt"));
  return 0;
}