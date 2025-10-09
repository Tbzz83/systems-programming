#include <stdio.h>

void birthday(char name[]) {
  printf("Happy bday %s\n", name);
}
int main(){
  char name[] = "Me";
  birthday(name);
  birthday(name);
  birthday(name);
  return 0;
}