// Sarah Ford
// HW2 Part A Program 2

#include <stdio.h>

void foo(int *ptr)
{
	double a=10;
	double b=4;
	*ptr = a*a + 4*b + 5;
}

int main()
{
	int y=20;
	foo(&y);
	printf("%d",y);

	return 0;
}
