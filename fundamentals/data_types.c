#include <stdio.h>
#include <stdbool.h>

int main(){

  int x; // Declaration
  x = 10; // Initialization
  int y = 321;

  int age = 21; // Integer
  float gpa = 2.05; // floating point

  char grade = 'A'; // Has to be single quotes
  char name[] = "Bro"; //Array of characters. Enumlating a string
  bool e = true;
  // float are 4 bytes
  double d = 3.14549865; // 8 bytes
  unsigned char f = 127; // 1 byte

  short int h = 32679; // 2 bytes (-32768
  unsigned short int i = 23984;

  int j = 328713; // 4 bytes %d
  unsigned int k = 42198412; // 4 bytes %u

  long long int l = 1924879812; // 8 bytes %lld
  unsigned long long int m = 412984721094821; // 8 bytes %llu


  printf("f: %d\n", f);
  printf("h: %d\n", h);
  printf("i: %d\n", i);


  return 0;
}
