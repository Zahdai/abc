#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main (int argc, char **argv) {
	int status;
	if (!fork()) {
		return 0;
	}
	else {
		sleep(2);
		printf("zombie:\n");
		system("ps");
		wait(&status);
		printf("is dead:\n");
		system("ps");
	}
	return 0;
}
