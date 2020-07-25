
// pipe2.c: communication between two processes


#include "kernel/types.h"
#include "user/user.h"

int
main()
{
  int n, pid;
  int fds[2];
  char buf[100];
  
  // create a pipe, with two FDs in fds[0], fds[1].
  pipe(fds);

  pid = fork();
  // 父子进程共享文件描述符，于是可以使用fds通信
  if (pid == 0) {
    write(fds[1], "hello\n", 6);
  } else {
    n = read(fds[0], buf, sizeof(buf));
    write(1, buf, n);
  }

  exit();
}
