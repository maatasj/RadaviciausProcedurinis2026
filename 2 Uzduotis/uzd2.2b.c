#include <stdio.h>
#include <stdlib.h>
int main() {
  // Daugiau kodo nei prasyta uzduotyje, nes darau del saves mokymuis, taipogi
  // prisiminti ka mokykloje praleidau, nes ejome Pythona ir sintakse, nes kai
  // kurie "shortcutai", kuriuos labai megau nelabai paeina:)

  // Pradiniai sarasai
  int binDec[] = {0b11011, 0b10010100, 0b11001011010101};
  int decBin[] = {37, 241, 2487};
  int hexDec[] = {0x6E2, 0xED33, 0x123456};
  int decHex[] = {243, 2483, 4162};
  int arraySize = sizeof(binDec) / sizeof(binDec[0]);

  // Konvertavimai
  printf("Dvejetainiai  i desimtainius:\n");
  printf("11011 = %d\n", 0b11011);
  printf("10010100 = %d\n", 0b10010100);
  printf("11001011010101 = %d\n", 0b11001011010101);

  // Pasidomejau jog tiesiog C kalba neturi budo paversti desimtainius skaicius
  // i dvinarius be jokiu papildomu biblioteku :d
  // Tai naudosiu sesioliktaine (kuri tuo paciu ir dvejetaine)
  printf("\nDesimtainiai i dvejetaine(per 16taine):\n");
  printf("%d = %X = 0b100101\n", decBin[0], decBin[0]);
  printf("%d = %X = 0b11110001\n", decBin[1], decBin[1]);
  printf("%d = %X = 0b100110110111\n", decBin[2], decBin[2]);

  printf("\nSesioliktainiai i desimtainius:\n");
  for (int i = 0; i < arraySize; i++) {
    printf("%X = %d\n", hexDec[i], hexDec[i]);
  }

  printf("\nDesimtainiai i sesioliktainius:\n");
  for (int i = 0; i < arraySize; i++) {
    printf("%d = %X\n", decHex[i], decHex[i]);
  }

  return 0;
}