#include <stdio.h>

int main(){

  int x = 5;
  int y = 2;

  //float z = x / (float) y;

  //int z = x % y;

  x++; // incrementing
  y--;
  printf("x: %d\n", x);
  printf("y: %d\n", y);

  x -= 3;
  printf("x: %d\n", x);


  return 0;
}