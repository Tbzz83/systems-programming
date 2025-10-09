#include <stdio.h>

int main(int argc, char *argv[]) 
{
  printf("you have entered %d argument(s)\n", argc);

  printf("%p\n", &argv[0]); // Address of the pointer
  printf("%p\n", argv[0]); // Address of the string
  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }


  return 0;
}