
// forkexec.c: fork then exec

#include "kernel/types.h"
#include "user/user.h"

int
main()
{
  int pid;

  pid = fork();
  if(pid == 0){
    // 子进程执行新程序
    char *argv[] = { "echo", "this", "is", "the", "echo", "command", 0 };
    exec("echo", argv);
    printf("exec failed!\n");
    exit();
  } else {
    printf("parent waiting\n");
    // 父进程等待子进程执行结束
    wait();
    printf("the child exited\n");
  }

  exit();
}
