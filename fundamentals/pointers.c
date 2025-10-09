#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(){
  char string1[] = "Bro";
  char string2[] = "Code";

  int var = 10;
  
  char* ptr = &string1[0];
  //int* ptr = &var;

  printf("Sizeof string1; %ld\n", sizeof(string1));
  printf("Address of first value in string1: %p\n", &string1[0]);
  printf("Address of first value in string1 (from pointer): %p\n", ptr);

  printf("Value of data in address %p is: %c\n", &string1[0], string1[0] );
  printf("Value of data in address (from pointer) %p is: %c\n", ptr, *ptr );
  //printf("%s\n", string1);

  // pointer to a pointer
  printf("\n");
  int val = 1;
  int * p = &val;
  printf("address of the pointer itself: %p\n", &p);
  printf("address of what p points to: %p\n", p);

  int **q = &p;
  printf("var by value: %d\n", val);
  printf("var by *p: %d\n", *p);
  printf("var by **q: %d\n", **q);
  printf("\n");
  printf("address of var by p: %p\n", p);
  printf("address of var by *q: %p\n", *q);
  printf("assert these are equal\n");
  assert(p == *q);
  printf("assertion 'p == q*' passed!\n");
  printf("\n");
  printf("address of p itself from &p: %p\n", &p);
  printf("address of p itself from q: %p\n", q);
  assert(q == &p);
  printf("assertion 'q == &p' passed!\n");
  printf("\n");
  printf("address of q itself from &q: %p\n", &q);
  // https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/
  


  return 0;
}