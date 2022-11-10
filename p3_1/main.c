#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	if (argc != 4) {
		printf("3 args requirement\n");
		return 1;
	}
	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double c = atof(argv[3]);
	printf("%fx^2+%fx+%f=0\n", a, b, c);
	double d = pow(b, 2)-4*a*c;
	printf("D=%f\n", d);
	if (d < 0)
		printf("no solution\n");
	else if (d == 0) {
		double x = -b/(2*a);
		printf("x = %f\n", x);
	}
	else {
		double x1 = (-b+sqrt(d))/(2*a);
		double x2 = (-b-sqrt(d))/(2*a);
		printf("x1 = %f\n,x2 = %f\n", x1, x2);
	}
	return 0;
}
