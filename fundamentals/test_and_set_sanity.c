#include <stdio.h>

int test_and_set(int *old_ptr, int new) {
  int old = *old_ptr; // passing by value the contents
  *old_ptr = new;
  printf("old: %d, new: %d, *old_ptr: %d\n", old, new, *old_ptr);
  return old;

}

int main() {
  int num_a = 10;
  printf("num_a: %d\n", num_a);

  int *p_num = &num_a;

  printf("p_num: %p\n", p_num);

  test_and_set(p_num, 5);

  printf("(post test and set) num_a: %d\n", num_a);


  return 0;
}
