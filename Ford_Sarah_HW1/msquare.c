// Sarah Ford
// HW1 Problem 1
// msquare.c   Scan in user input, build a square using input, and compute row, column, and diagonal sums

#include <stdlib.h>
#include <stdio.h>

int main() {
	
	int numarray[16];
	int i;
	printf("Enter the numbers from 1 to 16 in any order: ");
	for(i=0;i<16;i++){
	scanf("%d,",&numarray[i]); // scan in an array of integers with indices 0 to 15
	}
	printf("\n");
	int row=0; // initialize row index
	int col=0; // initialize column index
	int diag1=0; // initialize diagonal 1 index
	int diag2=3; // initialize diagonal 2 index
	int d1sum=0; // initialize diagonal one sum
	int d2sum=0; // initialize diagonal two sum
	int rsum=0; // initialize row sum
	int colsum=0; // initialize column sum
	int rsumarray[4]; // declare array of size four for sum of four rows
	int csumarray[4]; // declare array of size four for sum of four columns
	int dsumarray[2]; // declare array of size two for sum of two diagonals

	for(i=0;i<16;i++){ // iterate through array to print out magic square


	if ((i+1)%4==0){
		printf("%d\n",numarray[i]); // add a new line after every fourth element
	}

	else
		{
		printf("%d\t",numarray[i]); // print all other elements with a tab after each
		}

	}

	for(i=0;i<4;i++){
	rsum=numarray[row]+numarray[row+1]+numarray[row+2]+numarray[row+3]; // sum each row
	rsumarray[i]=rsum; // create row sum array from row sums
	colsum=numarray[i]+numarray[i+4]+numarray[i+8]+numarray[i+12]; // sum each column
	csumarray[i]=colsum; // create column array from column sums
	row=row+4;
	}
	
	for(i=0;i<4;i++){
	d1sum=d1sum+numarray[diag1]; // sum diagonal 1
	d2sum=d2sum+numarray[diag2]; // sum diagonal 2
	diag1=diag1+5;
	diag2=diag2+3;
	}

	dsumarray[0]=d1sum;
	dsumarray[1]=d2sum;
		
	printf("\n");
	printf("Row sums: ");

	for(i=0;i<4;i++){
	printf("%d\t",rsumarray[i]); // print row sum array elements
	}

	printf("\n");

	printf("Column sums: ");

	for(i=0;i<4;i++){
	printf("%d\t",csumarray[i]); // print column sum array elements
	}	
	
	printf("\n");

	printf("Diagonal sums: ");

	for(i=0;i<2;i++){
	printf("%d\t",dsumarray[i]); // print diagonal sum array elements
	}
	printf("\n");
	return 0;

}
