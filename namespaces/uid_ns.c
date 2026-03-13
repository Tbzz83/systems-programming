
#define _GNU_SOURCE
#include "namespaces.h"
#include <asm-generic/errno-base.h>
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

int uid_ns_child_func(void* arg) {
    printf("\nhello from uid_ns child_func()\n");
    printf("child proccess here: `getpid() = %d`\n", getpid());
    return EXIT_SUCCESS;
}

int uid_ns() {
    printf("-------------------------------\n");
    printf("Hello from uid_ns() function!\n");


    printf("calling proccess here: pid = %d\n", getpid());

    // CLONE_PARENT makes the parent process the same as the parent
    // of the process who called clone(). In this case, the parent is
    // bash
    int flags = CLONE_NEWUSER;

    // Create our child thread
    pid_t child_pid = clone(uid_ns_child_func, create_child_stack(), flags | SIGCHLD, NULL);
    if (child_pid == -1) {
        perror("clone");
        printf("Did you forget to run using sudo? Unless you use CLONE_NEWUSER, CLONE_NEWPID is a privileged operation!\n");
        return EXIT_FAILURE;
    }

    waitpid(child_pid, NULL, 0);
    printf("-------------------------------\n");
    return EXIT_SUCCESS;
}
