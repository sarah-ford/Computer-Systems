#include <stdio.h>
#include <stdlib.h>
#include "memorymgr.h"

int multEight(int n);

int BlockSize(int *p);
char *AllocStatus(int *p);

int *frst = NULL;
int *last = NULL;


int multEight(n) {
	if (n%8==0)
		return n;
	else
	return ((n/8) * 8) + 8;
}

int *firstBlock() {

	return frst;
}


int *lastBlock() {

	return last;

}

int isAllocated(int *p) {

	return (*p)%2;
}

char *AllocStatus(int *p) {

	int status = isAllocated(p);
	if (status==1)
		return "allocated";
	return "unallocated";
}

int *nextBlock(int *p) {

	return (p + (BlockSize(p)/4));
}

void initmemory(int size) {

int needed = size + 12;
int total_space = multEight(needed);
int *p = (int *)malloc(total_space);
frst = p + 1;
last = p + ((total_space - 4) / 4);
*last = *last || 1;
*frst = (total_space) - 8;
return;
}

int BlockSize(int *p) {

	if (*p%2 == 1)
		return (*p-1);
	else return *p;
}


void *myalloc(int length) {

	int *p = frst;
	int SizeNeeded = multEight(length + 4);
	while (BlockSize(p)!=0) {
		if ((BlockSize(p)==SizeNeeded) && (!isAllocated(p))) {
			*p = *p+1;
			return p + 1;
		}
		else if ((BlockSize(p)>SizeNeeded) && (!isAllocated(p))) {
			int left_over = *p - SizeNeeded;
			*p = SizeNeeded + 1;
			int *NextPtr = p + (BlockSize(p)/4);
			*NextPtr = left_over;
			return (void *)p+1;
		}
		else {
			p = nextBlock(p);
		}
	}
	return NULL;
}


void myfree(void *ptr) {

	ptr = (int *)ptr;
	int *ptr_header = ptr-1;
	*ptr_header = *ptr_header & -2;
	return;
}


void coalesce() {

	int *ptr = frst;
	int *next = nextBlock(ptr);
	while (next!=last) {
		if (!isAllocated(ptr) && !isAllocated(next)) {
			*ptr += BlockSize(next);
			next = nextBlock(ptr);
		}
		else {
			ptr = nextBlock(ptr);
			next = nextBlock(ptr);
		}
	}
	return;
}


void printallocation() {

	int BlockNum = 0;
	int *p = frst;
	while (BlockSize(p)!=0) {
		char *status = AllocStatus(p);
		int size = BlockSize(p);
		printf("Block %d: size %d\t %s\n",BlockNum, size, status);
		BlockNum+=1;
		p = nextBlock(p);
	}
	return;
}
