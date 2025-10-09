#include <stdio.h>

void hello(char[], int); // Function prototype
// Ensures calls to a function are made with the 
// Correct arguments

int main()
{

  char name[] = "Tobi";
  int age = 26;
  hello(name, age);
  // hello(name); // This function won't work bc of our prototype

  return 0;
}

void hello(char name[], int age)
{
  printf("Hello, %s\n", name);
  printf("You are %d years old\n", age);
}