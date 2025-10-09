#include <stdio.h>

typedef char user[25];


typedef struct
{
  char name[25];
  char password[12];
  int id;
} User;

int main()
{


  user best_user = "Johnny";

  User user1 = {"Johnny", "password123", 123456};
  User user2 = {"Domingo", "password123", 123456};

  printf("%s\n", user1.name);


  return 0;
}