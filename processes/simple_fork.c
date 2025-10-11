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
  pid_t pid = fork();

  switch (pid) {
    case -1:
      printf("Fork failed\n");
      break;
    case 0:
      printf("I am the child\n");
      display_pid(pid);
      exit(EXIT_SUCCESS);
  }

  // Wait collects the exit status from the child, and saves into 
  // the integer variable address you give it
  if (wait(&child_status) == -1) {
    printf("wait error\n");
  }

  printf("child exit status: %d\n", WEXITSTATUS(child_status)); // returns 0 because of child success

  return EXIT_SUCCESS;
}
