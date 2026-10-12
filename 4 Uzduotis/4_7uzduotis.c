#include <stdio.h>
int main() {
  char char1 = 0;
  unsigned char uchar1 = 0;

  int int1 = 0;
  unsigned int uint1 = 0;

  short short1 = 0;
  unsigned short ushort1 = 0;

  long long1 = 1;
  unsigned long ulong1 = 1;

  long long longlong1 = 1;
  unsigned long long ulonglong1 = 1;
  printf("!Resultas may vary between platforms! Mine was done on MacOS with "
         "gcc\n");
  //---------------------------------------------------------------
  // char bounds
  while ((char)(char1 + 1) > char1) {
    char1++;
  }
  printf("char is bounded by:            [%d : %d]\n", (char)(char1 + 1),
         char1);
  while ((unsigned char)(uchar1 + 1) > uchar1) {
    uchar1++;
  }
  printf("Unsigned char is bounded by:   [%d : %d]\n\n",
         (unsigned char)(uchar1 + 1), uchar1);
  //---------------------------------------------------------------
  // int bounds
  while ((int)(int1 + 1) > int1) {
    int1++;
  }
  printf("Int is bounded by:             [%d : %d]\n", (int)(int1 + 1), int1);

  while ((unsigned int)(uint1 + 1) > uint1) {
    uint1++;
  }
  printf("Unsigned int is bounded by:    [%u : %u]\n\n",
         (unsigned int)(uint1 + 1), uint1);
  //---------------------------------------------------------------
  // short bounds
  while ((short)(short1 + 1) > short1) {
    short1++;
  }
  printf("Short is bounded by:           [%d : %d]\n", (short)(short1 + 1),
         short1);

  while ((unsigned short)(ushort1 + 1) > ushort1) {
    ushort1++;
  }
  printf("Unsigned short is bounded by:  [%d : %d]\n\n",
         (unsigned short)(ushort1 + 1), ushort1);
  //---------------------------------------------------------------
  // long bounds(sum iterations dont work anymore :( )
  while ((long)(long1 * 2) > long1) {
    long1 *= 2;
  }
  printf("long is bounded by:            [%ld: %ld]\n", (long)(long1 * 2),
         long1 * 2 - 1);

  while ((unsigned long)(ulong1 * 2) > ulong1) {
    ulong1 *= 2;
  }
  printf("Unsigned long is bounded by:   [0 : %lu]\n\n",
         (unsigned long)ulong1 * 2 - 1);

  //---------------------------------------------------------------
  // long long bounds
  while ((long long)(longlong1 * 2) > longlong1) {
    longlong1 *= 2;
  }
  printf("long long is bounded by:       [%lld: %lld]\n",
         (long long)(longlong1 * 2), longlong1 * 2 - 1);

  while ((unsigned long long)(ulonglong1 * 2) > ulonglong1) {
    ulonglong1 *= 2;
  }
  printf("Unsigned long long is bounded by:[0 : %llu]\n\n",
         (unsigned long long)ulonglong1 * 2 - 1);
  return 0;
}