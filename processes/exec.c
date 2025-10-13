#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main() {
  char *arg_vec[10];
  char *env_vec[1];

  // Needs to be a NULL terminated string.
  arg_vec[1] = NULL;
  env_vec[0] = NULL;


  printf("Executing simple_writee.sh with spelling error\n");
  // Trying to call non-existent program! (note spelling error)
  if (execve("./simple_writee.sh", arg_vec, env_vec) == -1) {
    // This will print!
    printf("simple_writee.sh error\n");
  }

  printf("Executing simple_write.sh without spelling error\n");
  // Now the correct program
  if (execve("./simple_write.sh", arg_vec, env_vec) == -1) {
    printf("simple_write.sh error\n");
    //return EXIT_FAILURE;
  }

  // NOTE
  // `execve("ls", arg_vec, env_vec)` will fail because the absolute path
  // of the `ls` executable is not provided. Use execvp() instead, as it looks
  // at $PATH by default

  // This text doesn't print, because execve loads the program
  // requested, and never returns if successful.
  printf("Text after execve\n");

  return EXIT_SUCCESS;
}
