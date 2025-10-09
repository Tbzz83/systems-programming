#include <stdio.h>

int main()
{

  for(int i =1; i <= 20; i++)
  {
    if (i == 13) 
    {
      continue; // Skip unlucky 13!
      // break;
      // break will exit out of the loop completely 
    }
    printf("%d\n", i);
  }



  return 0;
}