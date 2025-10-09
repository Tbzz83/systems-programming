#include <stdio.h>
#include <stdlib.h>

int main()
{
  // malloc, calloc, realloc, free allow you
  // to implement dynamic memory
  int a; // goes on the stack
  int *p;
  p = (int*)malloc(sizeof(int)); // Goes on the heap!!
  printf("the value of p is: %d\n", *p);
  *p = 10;

  printf("the value of p is: %d\n", *p);
  printf("\nthe address of p is: %p\n", p);

  free(p);
  return 0;
}