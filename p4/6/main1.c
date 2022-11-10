#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("type \"name=value\" for new local param\n");
		return 1;
	}
	if (putenv(argv[1])) {
		printf("error\n");
		return 2;
	}
	return 0;
}
