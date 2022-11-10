#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {
	printf("PID=%d\nPPID=%d\nID группы родителя=%d\n"
		"Реальный ID владельца=%d\nРеальный ID группы родителя=%d\n"
		"Эффективный ID владельца=%d\nЭффективный ID группы родителя=%d\n",
		getpid(), getppid(), getpgrp(), getuid(), getgid(), geteuid(),
		getegid());
	return 0;
}
