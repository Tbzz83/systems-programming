#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

  srand(time(0));

  int number1 = (rand() % 20) ; // Modulus for the max range 0 - val
  int number2 = (rand() % 20) ; 
  int number3 = (rand() % 20) ; 
  printf("%d\n", number1);
  printf("%d\n", number2);
  printf("%d\n", number3);


  return 0;
}