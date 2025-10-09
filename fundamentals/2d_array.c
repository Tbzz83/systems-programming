#include <stdio.h>

int main()
{
  
  int numbers[2][3] = {{1, 2, 3},{4, 5, 6}};

  int rows = sizeof(numbers)/sizeof(numbers[0]);
  int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);

  printf("Rows: %d columns: %d\n", rows, columns);

  for(int i = 0; i < rows; i ++)
  {
    for(int j = 0; j < columns; j ++ )
    {
      printf("%d", numbers[i][j]);
    }
    printf("\n");
  }

  return 0;
}