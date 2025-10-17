#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc > 2 || (argc > 1 && strcmp(argv[1], "--help") == 0)) {
        printf("Usage: ./process_accounting.out </path/to/file_to_write_for_accounting/\n");
        printf("(Must run this binary as superuser)\n")
    }

    if (acct(argv[1]) == -1) {
        printf("acct() error.\n");
        exit(EXIT_FAILURE);
    }

    printf("Process accounting %s\n", 
           (argv[1] == NULL) ? "disabled" : "enabled");

    return EXIT_SUCCESS;
}
