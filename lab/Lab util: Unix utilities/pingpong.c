#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int parent_fd[2], child_fd[2];
  char child_char[1], parent_char[1];
  child_char[0] = 'a';
  parent_char[0] = 'b';
  pipe(parent_fd);
  pipe(child_fd);
  if(fork() == 0) {
    // child process
    int pid = getpid();
    char buf[1];
    read(parent_fd[0], buf, 1);
    if(buf[0] == parent_char[0]) {
      printf("%d: received ping\n", pid);
      write(child_fd[1], child_char, 1);
    }
    exit();
  } else {
    // parent process
    int pid = getpid();
    write(parent_fd[1], parent_char, 1);
    char buf[1];
    read(child_fd[0], buf, 1);
    if(buf[0] == child_char[0]) {
      printf("%d: received ping\n", pid);
    }
    wait();
  }
  exit();
}