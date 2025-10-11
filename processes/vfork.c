#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

#define FILE "./open_me.txt"

void reading_closed_without_fork() {
  char c;
  
  int fd1 = open(FILE, O_RDONLY, 0);

  printf("Opened fd1 as parent\n");

  close(fd1);

  if (read(fd1, &c, 1) == -1) {
    // Will print because we tried to read after closing fd
    printf("Read failed!\n");
  }
}

//Write a program to demonstrate that after a vfork(), the child process can close a
//file descriptor (e.g., descriptor 0) without affecting the corresponding file descriptor
//in the parent.
void reading_closed_with_vfork() {
  char c;
  int fd1 = open(FILE, O_RDONLY, 0);
  printf("Opened fd1 as parent\n");

  printf("\nForking...\n");
  pid_t pid = vfork();

  if (pid == 0) {
    // child
    close(fd1);
    exit(EXIT_SUCCESS);
  }

  // Wait for child
  wait(NULL);

  if (read(fd1, &c, 1) == -1) {
    printf("Read failed!\n");
  } else {
    // Closing the fd as the child had no effect on the parent when using vfork()!
    printf("Successful read of char '%c'\n", c);
  }

//  NOTE (from TLPI)
//  There are a few things that the child process can do between vfork() and exec()
//  without affecting the parent. Among these are operations on open file descriptors
//  (but not stdio file streams). Since the file descriptor table for each process is main-
//  tained in kernel space (Section 5.4) and is duplicated during vfork(), the child process
//  can perform file descriptor operations without affecting the parent.
}

int main() {

  reading_closed_without_fork();
  reading_closed_with_vfork();

  return EXIT_SUCCESS;
}
