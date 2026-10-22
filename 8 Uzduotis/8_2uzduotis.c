#include <stdio.h>
#include <stdlib.h>

char *getBiggestSize(int argc, char **argv) {
  int maxSize = -1;
  char *biggestFileName = NULL;
  if (argc < 2) {
    return NULL;
  }
  for (int i = 1; i < argc; ++i) {
    FILE *file = fopen(argv[i], "rb");
    if (file == NULL) {
      printf("Error. File doesn't exist\n");
      continue;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);
    if (size > maxSize) {
      biggestFileName = argv[i];
      maxSize = size;
    }
  }

  return biggestFileName;
}

int main(int argc, char **argv) {
  printf("%s\n", getBiggestSize(argc, argv));

  return 0;
}