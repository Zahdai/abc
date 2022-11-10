#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("type name and value for new local param\n");
		return 1;
	}
	if (setenv(argv[1], argv[2], 1)) {
		printf("memory is over\n");
		return 2;
	}
	return 0;
}
