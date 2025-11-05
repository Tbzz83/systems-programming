#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

// prints 'Interrupt'
int main() {
    char *description = strsignal(SIGINT);

    printf("%s\n", description);

    return EXIT_SUCCESS;
}
