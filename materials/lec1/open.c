
// open.c: create a file, write to it.

#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"

// open并不一定是create file，可能是打开现有文件
// 应当是创建新的文件描述符
int
main()
{
  // 打开（创建）一个文件，返回文件描述符
  int fd = open("output.txt", O_WRONLY|O_CREATE);
  write(fd, "ooo\n", 4);

  exit();
}
