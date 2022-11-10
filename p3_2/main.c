#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	FILE *fp = NULL;
	char fileName[20] = "file.txt";
	char text[10] = "Default";
	char *opts = "ho:c";
	int opt;
	while ((opt = getopt(argc, argv, opts)) != -1)
		switch (opt) {
			case '?':
				printf("Illegal option\n");
				return 1;
			case 'h':
				printf("-h\t\tсправка по использованию программы и выход\n"
					"-o arg\t\tзадание нестандартного имени выходного файла\n"
					"-c\t\tособый режим работы\n"
					"args\t\tаргументы задают имена входных файлов\n");
				return 0;
			case 'o':
				strcpy(fileName, optarg);
				break;
			case 'c':
				strcpy(text, "Special");
				break;
		}
	fp = fopen(fileName, "w");
	fputs(text, fp);
	return 0;
}
