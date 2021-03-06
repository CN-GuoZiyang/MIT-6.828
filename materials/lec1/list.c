
// list.c: list file names in the current directory

#include "kernel/types.h"
#include "user/user.h"

struct dirent {
  ushort inum;
  char name[14];
};

int
main()
{
  int fd;
  struct dirent e;

  // 打开当前文件夹
  fd = open(".", 0);
  while(read(fd, &e, sizeof(e)) == sizeof(e)){
    if(e.name[0] != '\0'){
      printf("%s\n", e.name);
    }
  }
  exit();
}
