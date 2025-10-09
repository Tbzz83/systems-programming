#include <stdio.h>

enum Day{Sun = 1, Mon = 2, Tues = 3, Wed = 4, Thu = 5, Fri = 6 , Sat = 7};

int main()
{
  // Short for enumerations
  // Helps make a program more readable

  enum Day today = Mon; // Sun is now an int

  //printf("%d\n", today); // Prints a 1

  if (today == Sun || today == Sat)
  {
    printf("It's the Weekend!\n");
  }
  else
  {
    printf("I have to work today\n");
  }



  return 0;
}