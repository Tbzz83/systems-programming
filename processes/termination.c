
#include <stdio.h>
#include <stdlib.h>


void first_exit_handler(void) {
  printf("I am first_exit_handler!\n");
}

void nested_exit_handler(void) {
  printf("I am called within second_exit_handler\n");
}

void second_exit_handler(void) {
  printf("I am second_exit_handler!\n");
  atexit(nested_exit_handler);
}

void third_on_exit_handler(int status, void *arg) {
  printf("I am third_on_exit_handler. I am called through on_exit()\n");
  printf("I can view exit status as: '%d' where my `atexit()` companions cannot!\n", status);
  printf("I can also print any arguments given to me, such as: %ld\n", *(long*)arg); 
}


int main() {
  
  // Exit handlers will be invoked in reverse declaration
  atexit(first_exit_handler);
  atexit(second_exit_handler);

  // Use malloc here to extend lifetime
  int *pon_exit_arg = (int *) malloc(sizeof(int));

  // If malloc failed, third_exit_handler won't be called.
  if (pon_exit_arg == NULL) {
    printf("Malloc failed.\n");
    exit(EXIT_FAILURE);
  }

  *pon_exit_arg = 10;
  on_exit(third_on_exit_handler, (int *) pon_exit_arg);

  // Even though defined after the `atexit` has been declared, this will print first. 
  // Atexit is only invoked in reverse declaration when the program exits
  printf("\nI should print before exit_handler\nthough I am declared after exit_handler!\n\n");

  printf("\n--- Exit handlers ---\n");
  return EXIT_SUCCESS;
}
