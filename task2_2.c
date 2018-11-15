#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
	char command[50];
	int i;
	/*if (!argv[1]) {return 0;}

	for (i=1; i<argc; i++) {
		printf("%d\n",i);
	}
	strncpy(command, argv[1],argc);
	printf("%s\n",command);
	system(command);
	printf("SS\n");*/
	strcpy(command,"cat text");
	system(command);
	printf("Hello?\n");
	return 0;
}
