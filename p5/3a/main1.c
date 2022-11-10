#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

#define nprint() printf("num = %d\n", num)

int main(int agrc, char **argv) {
	pid_t pid0 = getpid(), pid4;
	pid_t pid1 = 1; //так надо
	pid_t pid2 = 1; //для ветвлений
	pid_t pid3 = 0; //вилок
	int num = 0;
	nprint();
	pid1 = fork();
	if (pid1 == 0) {
		num++;
		printf("num = %d\n", num);
	}
	if (pid1 != 0) {
		pid2 = fork();
		nprint();
	}
	if (pid1 == 0 || pid2 == 0) {
		pid3 = fork();
		nprint();
		if (pid3 != 0) {
			pid4 = fork();
			nprint();
		}
	}
	printf("pid = %d\nppid = %d\n", getpid(), getppid());
	return 0;
}
