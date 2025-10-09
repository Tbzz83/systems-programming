#include <stdio.h>

int findMax(int x, int y) {
  return (x > y) ? x : y;
}


int main(){

  int x = 3;
  int y = 4;
  printf("The max of %d and %d is %d\n", x, y, findMax(x, y));



  return 0;
}