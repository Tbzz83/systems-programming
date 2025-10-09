#include <stdio.h>
#include <math.h>

int main(){
  const double PI = 3.14159;
  double radius;
  double circumference;
  double area;

  printf("Please enter in a radius\n");
  scanf("%lf", &radius);

  circumference = 2 * PI * radius;
  area = PI * radius * radius;

  printf("Radius: %.2lf\n", radius);
  printf("Circumference: %.2lf\n", circumference);
  printf("Area: %.2lf\n", area);

  return 0;
}