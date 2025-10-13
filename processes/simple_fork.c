#include <bits/types/sigset_t.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>


void display_pid(pid_t pid) {
  printf("My pid is '%d'\n\n", pid);
}

int main() {
  int child_status;
  pid_t child_pid = fork();

  char *args[2];
  char *envs[1];

  switch (child_pid) {
    case -1:
      printf("Fork failed\n");
      break;
    case 0:
      args[1] = NULL;
      envs[0] = NULL;

      execve("/usr/bin/ls", args, envs);
      //execl("ls", "-la", NULL);
      exit(EXIT_FAILURE);
  }


  // Wait collects the exit status from the child, and saves into 
  // the integer variable address you give it
  if (waitpid(child_pid, &child_status, 0) == -1) {
    printf("wait error\n");
  }

  printf("child exit status: %d\n", WEXITSTATUS(child_status)); // returns 0 because of child success

  return EXIT_SUCCESS;
}
