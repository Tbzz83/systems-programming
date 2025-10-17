#define _GNU_SOURCE
#include <asm-generic/errno-base.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>
#include <signal.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef CHILD_SIG
#define CHILD_SIG SIGUSR1
#endif

static int child_func(void *arg) {
    int *fd = (int *)arg;

    printf("\n>>> child_func() >>> BEGIN\n");
    printf("child_func: child thread pid = %d\n", getpid());

    if (close(*fd) == -1) {
        printf("close() error in child_func\n");
        exit(EXIT_FAILURE);
    }
    printf("<<< child_func() <<< END\n\n");

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {

    const int STACK_SIZE = 65536;
    char *stack;
    char *stack_top;
    int bytes_written, fd, flags;

    fd = open("/dev/null", O_RDWR);

    flags = (argc > 1) ? CLONE_FILES : 0;

    stack = malloc(STACK_SIZE);

    if (stack == NULL) {
        printf("malloc() failed.\n");
        exit(EXIT_FAILURE);
    }

    stack_top = stack + STACK_SIZE;

    // Ignore CHILD_SIG unless it's a SIGCHLD
    if (CHILD_SIG != 0 && CHILD_SIG != SIGCHLD) {
        if (signal(CHILD_SIG, SIG_IGN) == SIG_ERR) {
            printf("signal() error\n");
            exit(EXIT_FAILURE);
        }
    }

    // Create our child thread
    int child_thread_pid = clone(child_func, stack_top, flags | CHILD_SIG, (void *) &fd);

    if (child_thread_pid == -1) {
        printf("clone() failed.\n");
        exit(EXIT_FAILURE);
    }

    // clone does return the pid of the child
    printf("clone() return value (child thread pid) = %d\n", child_thread_pid);


    if (waitpid(child_thread_pid, NULL, (CHILD_SIG != SIGCHLD) ? __WCLONE : 0) == -1 ) {
        printf("waitpid() error\n");
        exit(EXIT_FAILURE);
    }

    bytes_written = write(fd, "x", 1);
    if (bytes_written == -1 && errno == EBADF) {
        printf("file descriptor %d has been closed\n", fd);
    } else if(bytes_written == -1) {
        printf("write() failed\n");
        exit(EXIT_FAILURE);
    } else {
        printf("write() on file descriptor %d succeeded\n", fd);
    }

    return EXIT_SUCCESS;
}
