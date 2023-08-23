// Sarah Ford
// HW2 Part B   dollar.c
// Program asks user to enter a U.S. dollar amount and then shows how to pay that amount using the smallest number of $20, $10, $5, and $1 bills

#include <stdio.h>

double dollars;
int twenties;
int tens;
int fives;
int ones;

int main()

{
	printf("Enter a dollar amount: ");
	scanf("%lf", &dollars);
	printf("\n");

	twenties = dollars / 20;
	dollars -= (20*twenties);
	tens = dollars / 10;
	dollars -= (10*tens);
	fives = dollars / 5;
	dollars -= (5*fives);
	ones = dollars;

	printf("$20 bills: %d\n",twenties);
	printf("$10 bills: %d\n",tens);
	printf("$5 bills: %d\n", fives);
	printf("$1 bills: %d\n", ones);
	printf("\n");

}
