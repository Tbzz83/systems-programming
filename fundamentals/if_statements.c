#include <stdio.h>

int main(){

  int age;

  printf("Please enter your age.\n");
  scanf("%d", &age);

  if(age >= 18){
    printf("You are now signed up!\n");
  } 
  else if (age == 0){
    printf("You can't sign up! You were just born.\n");
  }
  else if (age < 0 ){
    printf("You haven't been born yet!\n");
  }
  else{
    printf("You are not old enough to sign up for a credit card.\n");
  }

  return 0;
}