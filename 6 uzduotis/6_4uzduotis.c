#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MISINPUT 7

int isLeapYear(int year) {
  return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int checkDateValidity(int year, int month, int day) {
  int daysOfYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year < 1 || month < 1 || day < 1 || month > 12) {
    return 0;
  }
  if (isLeapYear(year)) {
    daysOfYear[1] = 29;
  }
  if (day > daysOfYear[month - 1]) {
    return 0;
  }
  return 1;
}
int checkValidity(char input[]) {
  int year, month, day;
  if (input[4] != '-' || input[7] != '-') {
    return 0;
  }
  if (sscanf(input, "%d-%d-%d", &year, &month, &day) != 3) {
    printf("Incorrect format. Please try again\n");
    return 0;
  }
  if (checkDateValidity(year, month, day) == 0) {
    printf("Date does not exist. Please try again\n");
    return 0;
  }
  return 1;
}
// Fills array with week days
void getWeekDaysList(char weekDays[7][20], const char fileName[]) {
  FILE *weekdaysfile;
  weekdaysfile = fopen(fileName, "r");
  if (weekdaysfile == NULL) {
    printf("Could not read file\n");
    return;
  }
  for (int i = 0; i < 7; ++i) {
    if (fscanf(weekdaysfile, "%19s", weekDays[i]) != 1) {
      printf("Incorrect week day formatting\n");
      return;
    }
  }
  fclose(weekdaysfile);
}
int HowManyDays(int year, int month, int day) {
  int sum = day;
  int daysOfYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (isLeapYear(year)) {
    daysOfYear[1] = 29;
  }
  for (int i = 1; i < year; i++) {
    if (isLeapYear(i)) {
      sum += 366;
    } else {
      sum += 365;
    }
  }
  for (int i = 0; i < month - 1; ++i) {
    sum += daysOfYear[i];
  }
  return sum;
}
int Datediff(int years, int months, int days, int yearf, int monthf, int dayf) {
  return abs(HowManyDays(years, months, days) -
             HowManyDays(yearf, monthf, dayf));
}
void dayOFTheWeek(char input[], char weekDays[7][20]) {
  // This function uses the ISO8601 standard, which uses an Proleptic Gregorian
  // calendar before 1582-10-15.
  // https://en.wikipedia.org/wiki/ISO_8601

  int year, month, day, date_diff;
  sscanf(input, "%d-%d-%d", &year, &month, &day);
  date_diff = Datediff(1, 1, 1, year, month, day);
  int index = date_diff % 7;
  printf("The day of the week is %s\n", weekDays[index]);
}

int main() {
  char weekDays[7][20], input[50];
  char fileName[100] = "";
  int ch, missinputs = 0;
  int a, b, c, mid;
  getWeekDaysList(weekDays, "week.txt");
  printf("This program reads whether the date was typed correctly in the "
         "format YYYY-MM-DD\n");

  // Reading numbers
  while (1) {
    if (missinputs >= MAX_MISINPUT) {
      printf("Too many incorrect inputs.\n");
      return 0;
    }
    if (scanf("%49s", input) == 1) {
      if (checkValidity(input)) {
        dayOFTheWeek(input, weekDays);
        break;
      } else {
        printf("Incorrect input. Please try again\n");
      }
    } else {
      printf("Incorrect input. Please try again\n");
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      ++missinputs;
    }
  }

  return 0;
}