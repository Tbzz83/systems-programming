#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static jmp_buf env;

static void 
fn2(int argc) {
  longjmp(env, 2);
}

static void 
fn1(int argc) {
  if (argc == 1) {
    longjmp(env, 1);
  } else {
    fn2(argc);
  }
}

void jump(int argc) {
  int jmp_val = setjmp(env);

  switch (jmp_val) {
    case 0:
      printf("Initial jmp_val after setjmp(env) is: %d\n", jmp_val);
    fn1(argc);
    break;

    case 1:
      printf("We just long jumped with a return val of %d\n", jmp_val);
      break;
    case 2:
      printf("We just long jumped with a return val of %d\n", jmp_val);
      break;
  }
}

int main(int argc, char *argv[]) {
  jump(argc);

  //longjmp(env, 1); // will cause segfault because trying to jump into function that has already returned

  return EXIT_SUCCESS;
}
