#include <stdio.h>

int readline(int *text, int n);
int *findmatch(int *pattern, int *text, int patternlen, int textlen);
void printmessage(int *position, int *text, int patternlen, int textlen);

int *loc = NULL;
int *rem = NULL;


int main() {
   int text[40], pattern[40], *position;
   int textlen, patternlen;

   printf("Enter text: ");
   textlen = readline(text, 40);
   printf("Enter pattern: ");
   patternlen = readline(pattern, 40);
   position = findmatch(pattern, text, patternlen, textlen);
   printmessage(position, text, patternlen, textlen);
}

int readline(int *text, int n) {
	int count=0, *p;
	for (p=text; p<text+n; p++) { // read up to a maximum of n characters
		*p=getchar();
		count++; // count the total number of characters read
		if (*p<=-1) { // if EOF error encountered, break out of loop
			count--;
			break;
		}
		if (*p=='\n') { // if newline, break out of loop
			count--;
			break;
		}
	}
	return count;
}


int *findmatch(int *pattern, int *text, int patternlen, int textlen) {

	if (patternlen > textlen) // if length of pattern is greater than text
		return NULL;

	int *w = pattern; // initialize a pointer equal to pattern array
	int *p = text; // initialize a pointer equal to text array
	int n = (textlen-1), k = (patternlen-1);
	int places = 1;


// use pointers to iterate through text and look for a match with the first character in pattern
// if match is found, record text memory location of match in variable loc and break from loop
	for (p=text; p<=text+n; p++) {
		if ((*p==*w)||(*w=='?')) {
			loc = &places;
			break;
		}
		places++;
	}

	p = text+(places-1);

	int num = 0;

// use pointers to iterate through pattern and text to check that subsequent characters all match
// if, for length of pattern, non-match is found and pattern character is not ?, set loc to NULL
	for (w=pattern; w<=pattern+k; w++) {
		if ((*w!=*p) && (*w!='?')) {
			loc = NULL;
			break;
		}
	p++;
	} 
	
	return loc;

}


void printmessage(int *position, int *text, int patternlen, int textlen) {

	int n = (textlen-1), k = (patternlen-1);

	if (position==NULL) {
	
		printf("no match\n");
	}
	

	else {

		printf("The pattern was found at char %d. The remaining text chars are:  ",*position);

		for (rem=text+(*loc)+(k); rem<=text+n; rem++) {
			putchar(*rem);
		}

		printf("\n");		

	}
}



