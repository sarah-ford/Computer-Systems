// Sarah Ford
// HW2 Part C   dollarMod.c
// Program utilizes pointers to ask user to enter a U.S. dollar amount and then show how to pay that amount using the smallest number of $20, $10, $5, and $1 bills

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

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

	pay_amount(dollars, &twenties, &tens, &fives, &ones);

	printf("$20 bills: %d\n", twenties);
	printf("$10 bills: %d\n", tens);
	printf("$5 bills: %d\n", fives);
	printf("$1 bills: %d\n", ones);

	printf("\n");

	return 0;

}


void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{

	*twenties = dollars / 20;
	dollars -= (20 * (*twenties));
	*tens = dollars / 10;
	dollars -= (10 * (*tens));
	*fives = dollars / 5;
	dollars -= (5 * (*fives));
	*ones = dollars;
}

