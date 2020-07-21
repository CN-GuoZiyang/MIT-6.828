
// redirect.c: run a command with output redirected

#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

int
main()
{
  int pid;

  pid = fork();
  if(pid == 0){
    // 这里子进程关闭标准输出
    close(1);
    // 这里打开的文件就会默认占用最低的fd，即为1
    open("output.txt", O_WRONLY|O_CREATE);

    char *argv[] = { "echo", "this", "is", "redirected", "echo", 0 };
    // echo默认输出到fd1，这里就是上面打开的文件
    exec("echo", argv);
    printf("exec failed!\n");
    exit();
  } else {
    wait();
  }

  exit();
}
