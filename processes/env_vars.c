#include <stdio.h>
#include <stdlib.h>

extern char **environ;
char env_var[] = "TEST_VALUE";

int main() {


  const char* value = getenv(env_var);


  printf("Accessing an env var %s\n", env_var);
  printf("%s: %s\n", env_var, value);


  printf("Setting env var: ENV_VAR_MODS=TRUE\n");

  char new_env_var[] = "ENV_VAR_MODS=TRUE";
  putenv(new_env_var);
  printf("Printing: ENV_VAR_MODS: %s\n", getenv("ENV_VAR_MODS"));

  return EXIT_SUCCESS;
}
