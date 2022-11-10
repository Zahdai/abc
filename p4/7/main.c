#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc > 2) {
		printf("type env var\n");
		return 1;
	}
	if (argc == 1)
		clearenv();
	else
		unsetenv(argv[1]);
	extern char **environ;
	int i = 0;
	while (environ[i] != NULL)
		printf("%s\n", environ[i++]);
	return 0;
}
