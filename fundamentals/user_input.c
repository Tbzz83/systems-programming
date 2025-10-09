#include <stdio.h>
#include <string.h>

int main(){

  int age;
  char name[25]; //bytes

  printf("What is your name?\n");
  //scanf("%s", &name); //scanf reads up to any whitespace
  fgets(name, 25, stdin);
  name[strlen(name)-1] = '\0';

  printf("Hello %s, how are you?\n", name);

  printf("How old are you?\n");
  scanf("%d", &age);

  printf("You are %d years old.\n", age);

  return 0;
}


