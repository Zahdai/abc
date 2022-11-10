#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main(int argc, char **argv) {
	char hostname[256];
	gethostname(hostname, 255);
	long hostid = gethostid();
	struct utsname sysInf;
	uname(&sysInf);
	printf("Сетевое имя: %s\nИмя ОС: %s\nИмя компьютера: %s\n"
		"Номер релиза системы: %s\nНомер версии системы: %s\n"
		"Аппаратный тип: %s\nУникальный идентификатор: %ld\n",
		hostname, sysInf.sysname, sysInf.nodename, sysInf.release,
		sysInf.version, sysInf.machine, hostid);
	return 0;
}
