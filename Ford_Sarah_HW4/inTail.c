#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
	int n = 0;
	int *arr = NULL;
	int num;
	int i, j, k;
	int *p = NULL;
	int rem;
	int count = 0;


	if (argc == 1) { // if no argument given, choose last 10 numbers
		n = 10;
	}


	else {
		n = atoi(argv[1]); // if argument is given, choose last arg[1] numbers 
	}


	arr = (int*) malloc (n * sizeof(int));	// allocate memory on heap for integer array


	for (i=0; i<=n; i++) { // iterate from index 0 to n
		scanf("%d",&num);
		count++;
		if (i==(n)) { // when out of bounds at index n, return index to position 0
			i=0;
		}
		if (num==-1) { // if -1 is received, break from loop
			count--;
			break;
		}
		arr[i]=num;	// assign num to arr element i

	}


	rem = (count%n);  // set remainder equal to count mod n


	k=rem; // set k index equal to rem

	if (count >= n) { // if number of inputs given is greater than array length

		printf("Here are the last %d numbers: ", n);

		for(j=0;j<n;j++) {
			if (k==n) {	
				k=0;
			}
			printf("%d ",arr[k]);
			k++;
		}

		printf("\n");

	}

	else {

		printf("There are only %d numbers: ", count);

		for (j=0;j<count;j++) {

			printf("%d ",arr[j]);

		}

		printf("\n");
	}


	free(arr);

	return;

}
