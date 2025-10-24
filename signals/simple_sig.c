#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig) {
    printf("\nGoodbye from signal handler :3 <3\n"); // UNSAFE
    exit(EXIT_SUCCESS);
}

int main() {

    int i;

    if (signal(SIGINT, &sig_handler) == SIG_ERR) {
        printf("signal failed.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; ;i++) {
        printf("%d: Please terminate me... (ctrl+c)\n", i);
        sleep(3);
    }

    return EXIT_SUCCESS;
}
