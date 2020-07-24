#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void close_fd(int *fd)
{
  close(fd[0]);
  close(fd[1]);
}

void prime()
{
  int len, p, n, fd[2];
  if((len = read(0, &p, sizeof(int))) <= 0 || p <= 0) {
    // close the write end to close its child process
    close(1);
    exit();
  }
  printf("prime %d\n", p);
  pipe(fd);
  if(fork() == 0) {
    // child process
    close(0);
    dup(fd[0]);
    close_fd(fd);
    prime();
  } else {
    close(1);
    dup(fd[1]);
    close_fd(fd);
    while((len = read(0, &n, sizeof(int))) > 0 && n > 0) {
      if(n % p != 0) {
        write(1, &n, sizeof(int));
      }
    }
    if(len <= 0 || n <= 0) {
      close(1);
      exit();
    }
  }
}

int
main(int argc, char *argv[])
{
  int i, fd[2];
  pipe(fd);
  if(fork() == 0) {
    // child process
    close(0);
    dup(fd[0]);
    close_fd(fd);
    prime();
  } else {
    // parent process
    close(1);
    dup(fd[1]);
    close_fd(fd);
    for(i = 2; i <= 35; i ++) {
      write(1, &i, sizeof(int));
    }
    close(1);
    wait();
  }
  exit();
}