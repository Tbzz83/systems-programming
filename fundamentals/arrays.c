#include <stdio.h>

int main()
{

  //double prices[] = {5.0, 10.0, 15.0, 20.0};
  double prices[6];

  prices[0] = 5.0;
  prices[1] = 10.0;
  prices[2] = 15.0;
  prices[3] = 20.0;
  prices[4] = 25.0;
  prices[5] = 30.0;

  char name[] = "Bro"; // array of chars
  //printf("$%.1lf\n", prices[3]);

  printf("Sizeof prices is: %ld\n", sizeof(prices));
  // Loop over the array
  for (int i = 0; i < sizeof(prices)/sizeof(prices[0]); i++)
  {
    printf("$%.2lf\n", prices[i]);
  }

  return 0;
}