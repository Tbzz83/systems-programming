#include <errno.h>
#include <signal.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void spin_forever() {
    while (1) {}
}

int main() {

    pid_t child_id = fork();

    switch (child_id) {
        case 0:
            printf("Hello from the child. My pid is %d\n", getpid());
            spin_forever();
        default:
            printf("Hello from the parent. My pid is %d and my childs pid is %d\n", getpid(), child_id);
            break;
    }
    printf("Checking if pid %d exists\n", child_id);
    // Set child_id to something fun here to see what happens if the process doesn't exist.
    if (kill(child_id, 0) == -1) {
        // ESRCH no such error has int value of 3.
        printf("pid %d does not exist. errno %d. Terminating...\n", child_id, errno);
        exit(EXIT_FAILURE);
    }

    printf("pid %d exists! Issuing kill signal...\n", child_id);
    kill(child_id, SIGKILL);

    int child_status;
    if (wait(&child_status) == -1) {
        printf("Child failed. Exit status was %d\n", WEXITSTATUS(child_status));
        exit(EXIT_FAILURE);
    }

    printf("\n---\nChild collected!\nChild pid = %d\nExit status = %d\n", child_id, WEXITSTATUS(child_status));
    
    return EXIT_SUCCESS;
}
