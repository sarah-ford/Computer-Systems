// Sarah Ford
// HW2 Part A Program 1

#include <stdio.h>

void foo(int x)
{
	double a=100;
	double b=40;
	x = a*a + 4*b;
}

int main()
{
	int y = 20;
	foo(y);
	printf("%d",y);
	return 0;
}
