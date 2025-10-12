#include <asm-generic/errno-base.h>
#include <bits/types/sigset_t.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <wait.h>


void display_pid(pid_t pid) {
  printf("My pid is '%d'\n\n", pid);
}

int main() {
  fork();

  // This is problematic, as a new fork will occur in BOTH the parent
  // and the child. Adding more and more forks will exponentially increase
  // the number of children
  fork();

  fork();
  // Wait collects the exit status from the child, and saves into 
  // the integer variable address you give it
  while (true) {
    pid_t child_pid = wait(NULL);
    if (child_pid == -1) {
      if (errno == ECHILD) {
        printf("No more children - bye!\n");
        exit(EXIT_SUCCESS);
      } else {
        printf("wait() error");
        exit(EXIT_FAILURE);
      }
    } else {
      printf("Waiting for child %d\n", child_pid);
    }
  }

  return EXIT_SUCCESS;
}
