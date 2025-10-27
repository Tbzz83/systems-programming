#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig) {
    switch (sig) {
    case SIGINT:
        printf("\nCaught SIGINT (Ctrl+C)\n");
        printf("resuming...\n");
        return;
    case SIGQUIT:
        printf("\nCaught SIGQUIT (Ctrl+\\)\n");
        printf("Goodbye from signal handler :3 <3\n"); // UNSAFE
        exit(EXIT_SUCCESS);
    }
}

int main() {

    int i;

    // Allowing our signal_handler to handle multiple signals
    if (signal(SIGINT, &sig_handler) == SIG_ERR) {
        printf("signal failed.\n");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGQUIT, &sig_handler) == SIG_ERR) {
        printf("signal failed.\n");
        exit(EXIT_FAILURE);
    }


    printf("Press 'Ctrl+C' to interrupt, and 'Ctrl+\\' to quit\n");
    for (i = 0; ;i++) {
        printf("%d: Please interrupt or quit...\n", i);
        sleep(3);
    }

    return EXIT_SUCCESS;
}
