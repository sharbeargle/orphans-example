/*
	This program is used to generate orphan processes so SysAdmins can learn how to 
	troubleshoot misbehaving programs.
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	pid_t pid;

	printf("fork()'ing 10 times\n");
	for (int i = 0; i<10; i++) {
		pid = fork();

		if (pid == 0) {
			sleep(60000);
			break;
		} else if (pid < 0) {
			printf("fork() failed\n");
			break;
		}
	}

	if (pid > 0) {
		printf("Parent terminated\n");
	}

	return 0;
}
