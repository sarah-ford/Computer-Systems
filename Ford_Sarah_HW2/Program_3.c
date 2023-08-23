// Sarah Ford
// HW2 Part A Program 3

#include <stdio.h>

int main()
{
	double *ptr;
	double x;

	ptr = &x;
	*ptr = 10.254575;

	printf(" x = %0.2f\n", x);
	printf(" *ptr = %f\n", *ptr);

	*ptr += 10;
	printf(" x = %f\n", x);
	printf(" *ptr = %f\n", *ptr);

	(*ptr)++;
	printf(" x = %0.4f\n", x);
	printf(" *ptr = %0.4f\n", *ptr);

	return 0;
}
