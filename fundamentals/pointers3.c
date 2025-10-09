#include <stdio.h>
//#include <string.h>
#include <stdlib.h>


typedef struct {
  int value;
} Node;


int main(){
  Node* new = malloc(sizeof(Node));
  int x = new->value;
  printf("%d\n", x);
}
