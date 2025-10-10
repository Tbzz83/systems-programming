#include <errno.h>
#include <gnu/libc-version.h>
#include <stdio.h>
#include "library.h"

int main() {
  // Checking libc version
  printf("%s\n", gnu_get_libc_version()); // prints 2.35
  
  // errno
  errno = EACCES;
  perror("Test error"); // prints: 'Test string: Permission denied'

  printf("1 + 2 = %d\n", add(1,2));
  printf("5 - 3 = %d\n", sub(5,3));
}

