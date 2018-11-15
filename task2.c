#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {

	if (!argv[1]) {return 0;}

	execvp(argv[1], &argv[1]);
	printf("Hello?\n");
	return 0;
}
