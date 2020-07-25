
// fork.c: create a new process

#include "kernel/types.h"
#include "user/user.h"

int
main()
{
  int pid;

  pid = fork();

  // fork之后，父子进程执行相同的代码

  printf("fork() returned %d\n", pid);

  // fork后，在子进程内返回0， 在父进程内返回子进程pid，即可区分
  if(pid == 0){
    printf("child\n");
  } else {
    printf("parent\n");
  }
  
  exit();
}
