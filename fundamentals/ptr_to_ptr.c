#include <stdio.h>
#include <stdlib.h>

void broken_modify_ptr(int *ptr, int *val) {
  /* 
  Because we modify `ptr` within the scope of this
  function directly, nothing happens to the actual
  address at *ptr. This is because `ptr` itself is 
  just a copy of the original `ptr` from main that 
  has a value that is the same address
  */
  ptr = val;
  printf("====Inside broken function here====\n");
  printf("```code\n");
  printf("ptr = &val;\n");
  printf("```\n");
  printf("output: *ptr = %d\n", *ptr);
  printf("===================================\n");

}

void modify_ptr(int **ptr, int *val) {
  /*
  We need to do it this way in order to change 
  what `ptr` is pointing at without overwriting
  the original address of what it is currently pointing at
  */
  *ptr = val; 
  // ^ reads as "The address of the pointer is changed to be
  // the address of val (&val)"
  printf("====Inside working function here====\n");
  printf("```code\n");
  printf("*ptr = &val;\n");
  printf("```\n");
  printf("output: *ptr = %d\n", **ptr);
  printf("===================================\n");
}

int main()
{
  int x = 5;
  int *ptr = &x;

  int new = 11;
  printf("\n");
  printf("ptr val before *p: %d\n", *ptr);
  printf("%p\n", ptr);
  broken_modify_ptr(ptr, &new);
  printf("%p\n", ptr);
  printf("ptr val after broken fn *p: %d\n", *ptr);
  printf("\n");
  printf("ptr val before *p: %d\n", *ptr);
  modify_ptr(&ptr, &new);
  printf("ptr val after working fn *p: %d\n", *ptr);
  printf("x val after working fn. Preserved! %d\n", x);
  printf("%p\n", ptr);
  // free(ptr); is unnessecary because `new` wasn't created with malloc so it
  // exists on the stack not the heap. Call free only when you use the heap

  return 0;
}