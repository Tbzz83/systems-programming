#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  char string1[] = "Bro";
  char string2[] = "Code";
  char* string3 = malloc(10*sizeof(char));
 
  printf("%p", string3);
  printf("%ld\n", sizeof(string1));
  strcat(string3, string2);
  printf("%s\n", string1);
  printf("Hello, world\n");

  return 0;
}
