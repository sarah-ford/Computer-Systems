// Sarah Ford
// HW1 Problem 1
// simpleMSquare.c   Scan in user input, build a square using input, and compute row, column, and diagonal sums -- No use of arrays or loops

#include <stdlib.h>
#include <stdio.h>

int main() {

	int one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen; // declaration of indices
	int row_one, row_two, row_three, row_four; // declaration of row sums
	int col_one, col_two, col_three, col_four; // declaration of column sums
	int diag_one, diag_two; // declaration of diagonal sums

	printf("Enter the numbers from 1 to 16 in any order: ");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &one, &two, &three, &four, &five, &six, &seven, &eight, &nine, &ten, &eleven, &twelve, &thirteen, &fourteen, &fifteen, &sixteen);

// scan in sixteen values

	printf("%d",one);
	printf("%d", two);
	printf("\n");
	printf("%d\t %d\t %d\t %d\t", one, two, three, four); // print row one
	printf("\n");
	printf("%d\t %d\t %d\t %d\t", five, six, seven, eight); // print row two
	printf("\n");
	printf("%d\t %d\t %d\t %d\t", nine, ten, eleven, twelve); // print row three
	printf("\n");
	printf("%d\t %d\t %d\t %d\t", thirteen, fourteen, fifteen, sixteen); // print row four
	printf("\n");
	printf("\n");

	row_one = one + two + three + four; // sum row one
	row_two = five + six + seven + eight; // sum row two
	row_three = nine + ten + eleven + twelve; // sum row three
	row_four = thirteen + fourteen + fifteen + sixteen; // sum row four
	col_one = one + five + nine + thirteen; // sum column one
	col_two = two + six + ten + fourteen; // sum column two
	col_three = three + seven + eleven + fifteen; // sum column three
	col_four = four + eight + twelve + sixteen; // sum column four
	diag_one = one + six + eleven + sixteen; // sum diagonal one
	diag_two = four + seven + ten + thirteen; // sum diagonal two

	printf("Row sums: %d\t %d\t %d\t %d\n", row_one, row_two, row_three, row_four);
	printf("Column sums: %d\t %d\t %d\t %d\n", col_one, col_two, col_three, col_four);
	printf("Diagonal sums: %d\t %d\n", diag_one, diag_two);



}
