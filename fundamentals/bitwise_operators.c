#include <stdio.h>

int main()
{

  // & = AND (both bits must be one)
  // | = OR (one or the other or both can be one)
  // ^ = XOR (only one bit can be one)
  // << Left shift (move the bits 'x' bits left. Doubles it)
  // >> Right shift (move the bits 'x' bits right. Halves it)

  int x = 6; // 6   = 00000110
  int y = 12; // 12 = 00001100
  int z = 0; // 0   = 00000000



  z = x & y; // 4 = 00000100
  printf("AND = %d\n", z);

  z = x | y;
  printf("OR = %d\n", z); // 14 

  z = x ^ y;
  printf("XOR = %d\n", z); // 10

  z = x << 1;
  printf("<< = %d\n", z); // 11

  z = x >> 1;
  printf(">> = %d\n", z); // 3

  return 0;
}