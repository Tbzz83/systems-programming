#include <stdio.h>

void printAge(int *age)
{
  printf("You are %d years old\n", *age);
}

int main()
{

  int age = 21;
  int *pAge = NULL; // Assign to null if initializing
  pAge = &age;

  printf("Address of age: %p\n", &age); // & is 'address of' operator
  printf("Address of pAge: %p\n", pAge); // p is the pointer variable 'like' object

  printf("Value of age: %d\n", age);
  printf("Value at stored address: %d\n", *pAge); // Indirection operator * allows you to dereferencing it

  printf("Size of age: %ld\n", sizeof(age));
  printf("Size of pAge: %ld\n", sizeof(pAge));

  printAge(pAge);

  return 0;
}