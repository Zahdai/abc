#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("No string param\n");
		return 0;
	}
	int status;
	if (!fork()) {
		printf("child process starting with sleep(2)...\n");
		sleep(2);/*
		char *user_args[argc];
		int i = 0;
		for (; i < argc-1; i++)
			strcpy(user_args[i], argv[i+1]);
		user_args[i] = NULL;
		char path[100] = "/bin/";
		execv(strcat(path, argv[1]), user_args);*/
		char path[100] = "/bin/";
		execv(strcat(path, argv[1]), &argv[1]);
	} else {
		wait(&status);
		printf("child process is over with status: ");
		if (WIFEXITED(status))
			printf("usual exit (%d)\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("exit with signal\n");
		else
			printf("?\n");
		printf("endless loop in parent process...\n");
		while (1) {}
	}
	return 0;
}
