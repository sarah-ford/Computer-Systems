#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readaline(int n);

char *p = NULL;
int i;
int n;
int count = 0;
int rem, k, j;
char *result = NULL;

int main(int argc, char **argv) {

	if (argc == 1) { // if no argument given, choose last 10 lines
		n = 10;
	}


	else {
		n = atoi(argv[1]); // if argument is given, choose last arg[1] numbers 
	}


	char **myMatrix = NULL; // initialize pointer to array of pointers
	myMatrix = (char **)malloc(n*sizeof(char *)); // allocate memory on heap to 2-D matrix pointer
	for (i=0; i<=n; i++) { // iterate from index 0 to n
		
		count++;
		
		if(i == (n)) { // when out of bounds at index n, return index to position 0
			i=0;
		}

		result = readaline(80);
		if (result == NULL) { // if result of readaline(80) is NULL, break out of loop
			break;
			count--;
		}

		myMatrix[i] = result; // set myMatrix[i] equal to readaline(80) pointer stored in result


	
	}
	

	rem = count%n; // set remainder equal to count mod n

	k = rem-1; // set k index equal to rem minus 1

	for(j=0;j<n;j++) { // iterate through circular array to print each line starting from index k
		if (k==n) {	
			k=0;
		}
		printf("%s",myMatrix[k]);
		k++;
	}


	for (j=0; j<n; j++) {
		free(myMatrix[j]); // free each pointer in 2-D array
	}
	free(myMatrix); // free 2-D array

	return;

}

	char *readaline(int n) {

		p = (char *)malloc(n * sizeof(char)); // allocate memory on heap for pointer p to a string
		char* s = fgets(p,n,stdin); // read in up to 80 characters from standard input and store at location p
		
		if ( s == NULL ){ // if fgets reaches end of file, free p and return NULL
			free(p);
			return NULL;
		}	
		else {
			return p;
		}
	}
