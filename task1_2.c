#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/file.h>
#include <unistd.h>
int main(int argc, char **argv) {

	time_t t;
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		printf("Unable to open the file\n");
    exit(1);
  }
	time(&t);
  printf("pid: %3d, getting read shared lock at %s\n", getpid(), ctime(&t));
  flock(fd, LOCK_SH);
  time(&t);
  printf("pid: %4d, exclusive locked at %s\n", getpid(), ctime(&t));
  sleep(20);

	flock(fd, LOCK_UN);
  time(&t);
  printf("pid: %4d, unlocked at %s\n", getpid(), ctime(&t));   

	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		printf("Unable to open the file\n");
    exit(1);
  }
	time(&t);
  printf("pid: %3d, getting read shared lock at %s\n", getpid(), ctime(&t));
  flock(fd, LOCK_SH);
  time(&t);
  printf("pid: %4d, exclusive locked at %s\n", getpid(), ctime(&t));
  sleep(20);
	flock(fd, LOCK_UN);
  time(&t);
  printf("pid: %4d, unlocked at %s\n", getpid(), ctime(&t)); 
}
