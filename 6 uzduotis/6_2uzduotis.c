#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MISINPUT 5
FILE *file;

double roundNumber(double num, int precision) {
  double scale = pow(10.0, precision);
  return round(num * scale) / scale;
}
int howManyDigitsAfterPeriod(char num[]) {
  int i = 0;
  while (num[i] != '.' && num[i] != '\0') {
    ++i;
  }
  if (num[i] == '\0') {
    return 0;
  }
  ++i;
  int counter = 0;
  while (num[i] != '\0') {
    ++counter;
    ++i;
  }
  return counter;
}
void getRidOfThePeriod(char num[]) {
  int i = 0;
  while (num[i] != '\0') {
    if (num[i] == ',') {
      num[i] = '.';
    }
    ++i;
  }
}
int main() {
  char fileName[100] = "in.txt";
  int ch, len, missinputs = 0;
  char temp[10];
  double num;
  printf("The program outputs the lenght of the number n (10<=n<=1000)\nwith "
         "no more than 3 floating point digits \n");
  printf("Please write n in the file in.txt \n");
  while (1) {

    file = fopen(fileName, "r");
    if (missinputs > MAX_MISINPUT) {
      printf("Too many incorrect inputs.\n");
      return 0;
    }
    if (file == NULL || fileName[0] == '\0') {
      printf("File does not exist. Please enter new file name:\n");
      fclose(file);
      scanf("%99s", fileName);
      continue;
      ++missinputs;
    }
    if (fscanf(file, "%9s", temp) == 1) {
      getRidOfThePeriod(temp);
      num = atof(temp);
      len = howManyDigitsAfterPeriod(temp);
      if ((int)num >= 10 && (int)num <= 1000) {
        if (len <= 3) {
          printf("The length of the number is %d\n", (int)strlen(temp));
          fclose(file);
          break;

        } else {
          printf("There must be no more than 3 digits after the period\n\n");
          printf("Please enter of a new filename\n");
          fclose(file);
          scanf("%99s", fileName);
        }
      } else {
        printf("The number has to be between 10 and 1000\n");
        printf("Please enter of a new filename\n");
        fclose(file);
        scanf("%99s", fileName);
      }

    } else {
      printf("Incorrect input. Please try again\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
    }
  }

  return 0;
}