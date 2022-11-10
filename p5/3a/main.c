#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

void nprint(int *num) {
	printf("n=%d (%p)\tPID=%d\tPPID=%d\n", ++(*num), num, getpid(), getppid());
}

void forkWInfo(pid_t *pid, int *num, pid_t *ch) {
	*pid = fork();
	if (!(*pid))
		nprint(num);
	else
		*ch = *pid;
}

void newFork(pid_t *pid, int *num, pid_t *ch1, pid_t *ch2) {
	forkWInfo(pid, num, ch1);
	if (*pid)
		forkWInfo(pid, num, ch2);
}

int main(int agrc, char **argv) {
	pid_t ch1, ch2;
	pid_t pid;
	int num = 0;
	nprint(&num);
	newFork(&pid, &num, &ch1, &ch2);
	if (!pid)
		newFork(&pid, &num, &ch1, &ch2);
	if (pid)
		printf("Par: %d; Chld: %d\t%d\n", getpid(), ch1, ch2);
	return 0;
}
