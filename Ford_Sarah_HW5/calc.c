// Author: Sarah Ford
// Description: calc.c evaluates an arithmetic expression given on the command line and prints the result


#include <stdlib.h>
#include <stdio.h>

void pushValStack(int stack[], int *top, int value);
int popValStack(int stack[], int *top);
void pushOpStack(char *stack[], int *top, char *value);
char *popOpStack (char *stack[], int *top);

char* opStack[50];
int valStack[50];
int opTop = 0;
int valTop = 0;


int main(int argc, char **argv) {

	int i;
	for (i=1; i<=(argc-1); i++) { // iterate through argv array of tokens, t
		char *argument = argv[i];

		if (*argument == '+' || *argument=='x' || *argument== '[') { // if t is an operator or a left bracket
			pushOpStack(opStack, &opTop, argument); // push onto the operand stack
		}

		else if(*argument==']'){ // if t is a right bracket
			char *popOp = argv[i-1];
			while((*popOp)!='['){ // pop the operand stack until *popOp is a left bracket
				popOp = popOpStack(opStack, &opTop);
				if((*popOp)=='+'){ // if operator found is addition symbol
			
					int one = popValStack(valStack, &valTop); // pop first value
					int two = popValStack(valStack, &valTop); // pop second value
					int sum = one + two; // add values one and two
					pushValStack(valStack, &valTop, sum); // push sum onto value stack

				}

				if((*popOp)=='x'){ // if operator found is multiplication symbol

					int one = popValStack(valStack, &valTop); // pop first value
					int two = popValStack(valStack, &valTop); // pop second value
					int product = one * two; // multiply values one and two
					pushValStack(valStack, &valTop, product); // push product onto value stack

				}
			}
		}

		else { // if t denotes a number

			int value = atoi(argv[i]); // convert t to an integer
			pushValStack(valStack, &valTop, value); // push t onto value stack

		}


	} 

// Out of tokens, t

	while(opTop!=0){ // pop operand stack until it is empty

	// Perform each operation as before

		char *popOp = popOpStack(opStack, &opTop);
		if((*popOp)=='+'){
			
			int one = popValStack(valStack, &valTop);
			int two = popValStack(valStack, &valTop);
			int sum = one + two;
			pushValStack(valStack, &valTop, sum);

		}

		if((*popOp)=='x'){

			int one = popValStack(valStack, &valTop);
			int two = popValStack(valStack, &valTop);
			int product = one * two;
			pushValStack(valStack, &valTop, product);

		}

	}

// Operand stack is empty

	int result = popValStack(valStack, &valTop); // pop final value on value stack and set it equal to result

	printf("%d\n",result);

	return;

}




void pushValStack(int stack[], int *top, int value) {
	stack[(*top)]=value;
	(*top)++;
	return;
}

int popValStack(int stack[], int *top) {
	int popVal=stack[(*top)-1];
	stack[(*top)-1]=0;
	(*top)--;
	return popVal;
}

void pushOpStack(char *stack[], int *top, char *value) {
	stack[(*top)]=(value);
	(*top)++;
	return;
}

char *popOpStack(char *stack[], int *top){
	char *popVal = stack[(*top)-1];
	stack[(*top)-1]=0;
	(*top)--;
	return popVal;
}


