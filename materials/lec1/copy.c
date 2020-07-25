
// copy.c: copy input to output.

#include "kernel/types.h"
#include "user/user.h"


// 每个进程都会默认打开三个文件描述符：fd0、1和2，分别为标准输入、标准输出和错误输出
int
main()
{
  char buf[64];

  while(1){
    // fd0为标准输入，以下为从输入中读取64个字符到buf数组中
    // 返回值为读取到的字节数
    int n = read(0, buf, sizeof(buf));
    if(n <= 0)
      break;
    // fd1为标准输出，将buf中的字符输出到屏幕
    write(1, buf, n);
  }

  exit();
}
