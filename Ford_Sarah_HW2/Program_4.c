// Sarah Ford
// HW2 Part A Program 4

#include <stdio.h>

void foo(int *p, int *q)
{
	int a=10;
	int b=5;
	p=q;
	*p = b*b + 10*a;
}

int i = 0, j=1;

int main()
{
	foo(&i, &j);
	printf("%d %d \n", i, j);
	getchar();
	return 0;
}
