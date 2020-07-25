
// pipe1.c: communication over a pipe

#include "kernel/types.h"
#include "user/user.h"

int
main()
{
  int fds[2];
  char buf[100];
  int n;

  // create a pipe, with two FDs in fds[0], fds[1].
  // pipe调用传入一个int数组，length为2，0为读出，1为写入
  pipe(fds);
  
  // 向fds[1]写入6个字节的数据，数据为"hello/n"
  write(fds[1], "hello\n", 6);
  // 接着就可以从fds[0]中读出
  n = read(fds[0], buf, sizeof(buf));

  write(1, buf, n);

  exit();
}
