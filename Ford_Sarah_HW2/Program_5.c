// Sarah Ford
// HW2 Part A Program 5

#include <stdio.h>

void swap (char *x, char *y)
{
	char *t = x;
	x = y;
	y = t;
}

int main()
{
	char *x = "Computer Systems";
	char *y = "CSCI 2271";
	char *t;
	swap(x,y);
	printf("(%s, %s)\n", x, y);
	t=x;
	x=y;
	y=t;
	printf("(%s, %s)", x, y);
	return 0;
}
