#include <stdio.h>
#include <stdlib.h>
#include "namespaces.h"

// Returns a char * to the stack top of allocated memory
// for a new child process or thread to use with clone()
char* create_child_stack() {
    const int STACK_SIZE = 65536;
    char *stack;
    char *stack_top;
    int bytes_written, fd, flags;

    stack = malloc(STACK_SIZE);
    if (stack == NULL) {
        printf("malloc() failed.\n");
        exit(EXIT_FAILURE);
    }

    return stack + STACK_SIZE;
}
