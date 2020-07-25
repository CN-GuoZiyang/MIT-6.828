
// exec.c: replace a process with an executable file

#include "kernel/types.h"
#include "user/user.h"

int
main()
{
  char *argv[] = { "echo", "hello", 0 };

  // 第一个参数为可执行文件位置，argv为其参数
  exec("echo", argv);

  // 如果执行成功，则会替换当前进程，就不会执行下面的语句
  printf("exec failed!\n");

  exit();
}
