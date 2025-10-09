#include <stdio.h>
#include <stdbool.h>

int main()
{
  
  FILE *pF= fopen("test.txt", "r");

  if (pF == NULL) {
    printf("Error opening file");
    return 1;
  }

  while(true) {
    char ch = fgetc(pF);
    if (ch == EOF) {
      break;
    }
    //printf("%c", ch);
  }
  fclose(pF);

  FILE *fp= fopen("test.txt", "r");
  char buffer[256];

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
  }
  fclose(fp);




  

  return 0;
}