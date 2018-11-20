#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc, char **argv) {

  if (!argv[1]) {return 0;}
  int pid;
  
  switch (pid = fork()) {
  case -1:              /* error in fork */
    exit(1);
  case 0:               /* child process */
    printf("Child %d was born, running child...\n", getpid());
    if (execvp(argv[1], argv+1) == -1) {
      perror("execvp");
      exit(1);
    }
    break;
    
  default:              /* parent process */
    printf("Child has not yet born, parent is %d...\n", getpid());
    
    if (wait(&pid) == -1) {
      perror("wait");
      exit(1);
    }
    printf("Child done, status %d\n",pid);
    break;
  }
}
