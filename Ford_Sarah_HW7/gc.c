#include <stdlib.h>
#include <stdio.h>
#include "memorymgr.h"
#include "gc.h"

void *stackBottom();
void mark(int *p);
void sweep();
void unmark(int *p);
void markIt(int*p);
int *findBlock(int * p);

void gc() {
	int **max = (int **)stackBottom();
	int *dummy;
	int **p = &dummy;

	while (p!=max) {
		mark(*p); // mark the pointer that p points to
		p++;
	}

	sweep(); // deallocated all unmarked blocks
}


void markIt(int*p) { // marks block header that p points to
	int save = (*p) % 2;
	*p = (*p) / 4 * 4 + save + 2;
}


void mark(int *p) { // mark pointer if root node points to heap location
	int *ptr = findBlock(p);
	if(ptr == NULL || isMarked(ptr)) // if pointer is not on heap or if already marked
	{
		return;
	}
	markIt(ptr); // mark pointer

	int*nextblk = nextBlock(ptr);
	ptr++;

	while(ptr < nextblk) // mark each pointer in block
	{
		mark(ptr);
		ptr++;
	}

}


int *findBlock(int * p) { // find block that pointer p is in
	int *s = firstBlock();
	int *l = lastBlock();

	if(p < s || p > l){ return NULL; } // if pointer does not point to location on heap

	int *ptr = s;
	while (p > nextBlock(ptr)){ ptr = nextBlock(ptr); } // walk heap until p is less than nextblock

	return isAllocated(ptr) ? ptr : NULL; // return pointer if pointer is allocated
}


void sweep() {
	int *ptr = firstBlock();
	while (ptr != lastBlock()) {
		if(isMarked(ptr)) // if pointer is marked, unmark and move to next block
		{
			unmark(ptr);
		}
		else if(isAllocated(ptr)) // if pointer is not marked but allocated, free pointer
		{
			myfree(ptr + 1);
		}
		ptr = nextBlock(ptr);
	}
	coalesce(); // coalesce free blocks
}


int isMarked(int *p) { // check if p is marked
	int x = (*p) % 4 > 1;
	return x;
}


void unmark(int*p) { // unmark pointer p
	int save = (*p) % 2;
	*p = (*p) / 4 * 4 + save;
}


void *stackBottom() {

	unsigned long bottom;
		FILE *statfp = fopen("/proc/self/stat", "r");
		fscanf(statfp, 
			"%*d %*s %*c %*d %*d %*d %*d %*d %*u "
			"%*u %*u %*u %*u %*u %*u %*d %*d "
			"%*d %*d %*d %*d %*u %*u %*d "
			"%*u %*u %*u %lu", &bottom);
		fclose(statfp);
	return (void *) bottom;
}


