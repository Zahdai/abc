#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(void) {
	pid_t pid;
	int num = 0;
	time_t now = time(NULL);
	pid = fork();
	while (time(NULL) - now < 2) {
		num++;
	}
	if (pid == 0) {
		printf("потомок) num=%d\n", num);
	} else if (pid > 0) {
		printf("родитель) num=%d\n", num);
	}
	return 0;
}
