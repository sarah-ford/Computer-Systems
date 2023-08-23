// threadsearch.c: Search for a pattern in a text string.  
//                Uses a defined number of threads to search array.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

int searchPosition(int i);
void *searcher(void *);

#define TEXT_LEN 1000000
#define NUM_THREADS 2

// The pattern and text strings are global variables
// The position, done, and result integers are global variables
// The patlen and textlen integers are global variables
char *pattern;
char text[TEXT_LEN];
int pos = 0;
int done = 0;
int result = -1; // a positive value indicates the location of the match
int patlen;
int textlen;

pthread_mutex_t lock;

int main(int argc, char *argv[]) {

   // Step 1: Extract the pattern string from the command line.   
   
   pattern = argv[1];
   patlen = strlen(pattern);

   // Step 2: Create and populate the text string.
   // Note that it isn't a proper "string" in the C sense,
   // because it doesn't end in '\0'.

   textlen = TEXT_LEN; // will be overridden by the actual length
   int count = 0;
   while (count < TEXT_LEN) {
       int status = scanf("%c", &text[count]);
       count++;
       if (status == EOF) {
          textlen = count;
          break;
       }
   }

   // Step 3: Search for the pattern in the text string

   int i;
   pthread_mutex_init(&lock, NULL);
   
   pthread_t tid[NUM_THREADS];

   for (i = 0; i < NUM_THREADS; i++) {
	pthread_create(&tid[i], NULL, searcher, NULL);
   }

   for (i = 0; i < NUM_THREADS; i++) {
	pthread_join(tid[i], NULL);
   }

   // Step 4: Determine the result and print it

   if (result == -1)
       printf("Pattern not found\n");
   else
       printf("Pattern begins at character %d\n", result);
}




int searchPosition(int i) {
   int j;
   for (j=0;j<strlen(pattern); j++) 
       if (text[i+j] != pattern[j])
          return 0;
   return 1;
}



void *searcher(void *arg) {	
    while (!done && pos<textlen-patlen) {
	pthread_mutex_lock(&lock);   // Start of critical section 1
	int currentPos = pos;
	pos++;
	pthread_mutex_unlock(&lock);   // End of critical section 1
	int f = searchPosition(currentPos);
	pthread_mutex_lock(&lock);   // Start of critical section 2
	if (f == 1) {
		result = currentPos;
		done = 1;
	}
	pthread_mutex_unlock(&lock); // End of critical section 2
    }
    return NULL;
}
