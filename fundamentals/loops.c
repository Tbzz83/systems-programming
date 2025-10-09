#include <stdio.h>
#include <string.h>

void do_while(){
  // Always executes a block of code once, THEN checks a condition
  int number = 0;
  int sum = 0;

  do 
  {
    printf("Enter a number above 0: ");
    scanf("%d", &number);
    if (number > 0)
    {
      sum += number;
    }
  } while (number > 0);

  printf("sum: %d\n", sum);
}

int main(){

  // for loop
  for(int i = 10; i >= 1; i-=2)
  {
    //printf("%d\n", i);
  }

  char name[25];
  name[strlen(name) -1 ] = '\0';

//  while (strlen(name) == 0)
//  {
//    printf("\nWhat's your name? ");
//    fgets(name, sizeof(name), stdin);
//    name[strlen(name) -1 ] = '\0';
//    
//    if (strlen(name) == 0)
//    {
//      printf("You didn't enter a name!");
//    }
//  }

//  printf("Hello %s\n", name);

  // Do while practice
  do_while();

  return 0;
}