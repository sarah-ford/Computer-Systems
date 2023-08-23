// Sarah Ford
// HW1 Problem 3
// Calculator.c   Scan in user input and perform basic arithmetic operations

#include <stdlib.h>
#include <stdio.h>

int takesNoArgs(char op);
double processOp(double amt, char op, double val);
double processPlus(double amt, double val);
double processMinus(double amt, double val);
double processTimes(double amt, double val);
double processDivide(double amt, double val);
double processPrint(double amt);
double processClear();

int main() {

double amt = 0.0F; // initialize variable for calculator return amount
double val; // declare variable for float scanned into calculator after operation
char op; // declare variable for operation scanned

printf("CS 2271 Calculator\n");

while(1) {
	int ic = getchar();
	if (ic < 0) break;
	op = (char)ic; // assign op to the first character in a line
	if (op == 'Q') break;

	if (takesNoArgs(op)) {
		val = 0.0F;
		while(1) { // read all the remaining white space in the line until a line break
			int space = getchar();
			char wspace = (char)space;
			if(wspace=='\n') break;
		}
	}
	else {
		scanf("%lf",&val); // read the float value after the operator
		while(1) { // read all the remaining white space in the line until a line break
			int space = getchar();
			char wspace = (char)space;
			if(wspace=='\n') break;
		}
	}
	

	amt = processOp(amt, op, val);

	} // end of while loop

	printf("Thank you and goodbye!\n");
}

int takesNoArgs(char op) {
	return (op == 'C') || (op == '=');
}

double processOp(double amt, char op, double val) {
	if (op == '+') {
		return processPlus(amt, val);
	}
	else if (op == '-') {
		return processMinus(amt, val);
	}
	else if (op == '*') {
		return processTimes(amt, val);
	}
	else if (op == '/') {
		return processDivide(amt, val);
	}
	else if (op == '=') {
		return processPrint(amt);
	}	
	else if (op == 'C') {
		return processClear();
	}
	else {
		printf("Bad Operator\n");
		return amt;
}
}

double processPlus(double amt, double val) {
	return amt + val;
}

double processMinus(double amt, double val) {
	return amt - val;
}

double processTimes(double amt, double val) {
	return amt * val;
}

double processDivide(double amt, double val) {
	return amt / val;
}

double processPrint(double amt) {
	printf("%f\n",amt);
	return amt;
}

double processClear() {
	return 0;
}


