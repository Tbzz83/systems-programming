#include <stdio.h>

int main()
{

  char a;
  char b[1];
  char c[3];
  c[0] = 'h';
  c[1] = 'h';
  c[2] = 'h';


  printf("%ld bytes\n", sizeof(a));
  printf("%ld bytes\n", sizeof(b));
  printf("%ld bytes\n", sizeof(c));
  printf("Pointer of c: %s\n", c);

  printf("%p\n", &a);
  printf("%p\n", &b);
  printf("%p\n", &c);
  
  return 0;
}