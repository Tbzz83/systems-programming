#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define LOOPS 10000
/* 
For 10000 loops here is an example by timing using `time` shell built-in

fork():
real    0m2.055s
user    0m0.182s
sys     0m1.004s


vfork():
real    0m1.359s
user    0m0.100s
sys     0m0.689s
*/

int main(int argc, char *argv[]) {

    for (int i = 0; i < LOOPS; i++) {
        printf("===LOOP %d===\n", i);

        pid_t child_id = 0;

        if (argc > 1) {
            printf("executing vfork()...\n");
            child_id = vfork();
        } else {
            printf("executing fork()...\n");
            child_id = fork();
        }

        switch (child_id) {
            case 0:
                // Child
                printf("I am a child. My process ID is '%d'\n", getpid());
                exit(EXIT_SUCCESS);
        }

        // Parent
        int child_status;
        wait(&child_status);
        printf("I am the parent. My process ID is %d\n", getpid());
        printf("Child process '%d' completed with exit status '%d'\n", child_id, child_status);
    }

    return EXIT_SUCCESS;
}
