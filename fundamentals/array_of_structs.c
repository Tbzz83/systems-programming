#include <stdio.h>

struct Student
{
  char name[25];
  float gpa;
};

int main()
{

  struct Student student1 = {"Johnny", 3.0};
  struct Student student2 = {"Domingo", 2.5};
  struct Student student3 = {"Stephanie", 4.0};
  struct Student student4 = {"Squidward", 2.0};

  struct Student students[] = {student1, student2, student3, student4};
  printf("%ld, %ld\n", sizeof(students), sizeof(students[0]));

  for (int i = 0; i < sizeof(students)/sizeof(students[0]); i++ )
  {

    printf("name: %s, gpa: %.2f \n", students[i].name, students[i].gpa);

  }


  return 0;
}
