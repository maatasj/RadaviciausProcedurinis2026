#include <stdio.h>
int showMenu(char *menuTitle, char *menuOptions[], int menuSize,
             char *inputMsg) {
  int input;
  char ch;

  while (1) {
    printf("%s\n", menuTitle);
    for (int i = 0; i < menuSize; ++i) {
      printf("%d) %s\n", i + 1, menuOptions[i]);
    }
    printf("%s", inputMsg);
    if (scanf("%d", &input) == 1 && input > 0 && input <= menuSize) {
      return input;
    } else {
      printf("%s\n", inputMsg);
      while ((ch = getchar()) != '\n' && ch != EOF) {
      }
      continue;
    }
  }
  return input;
}

int main() {
  char *menuTitle = "---Meniu---";
  char *menuOptions[] = {"Pradėti naują žaidimą",
                         "Peržiūrėti geriausius rezultatus",
                         "Išeiti iš programos"};
  int menuSize = 3;
  char *inputMsg = "Pasirinkite: ";
  showMenu(menuTitle, menuOptions, menuSize, inputMsg);

  return 0;
}