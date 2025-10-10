#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main() {

  pid_t pid = getpid();

  pid_t ppid = getppid();

  // $ ps aux | grep 90570
  // azeezoe  90570  100  0.0   2780  1440 pts/14   R+   09:39   0:15 ./main.out
  printf("%d\n", pid); // prints 90570 for example

  // parent process ID (bash in this case)
//  azeezoe@BBMP814:~$ ps aux | grep 90762
//  azeezoe  90762  0.0  0.0   4920  3680 pts/14   S+   09:42   0:00 /bin/bash /home/azeezoe/.local/bin/basic_c main
//  azeezoe  90770  0.0  0.0   4032  2240 pts/0    S+   09:42   0:00 grep --color=auto 90762
  printf("%d\n", ppid); 


  return 0;

}
