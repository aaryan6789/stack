#include <stdlib.h>
#include <stdio.h>
#include <error.h>
/*
 * check_parantheses.c
 * Given an string expression
 * Write a program to examine whether the pairs and the order of { } ( ) [ ] is
 * correct.
 */
#define MAX 20
int top = -1;
int chStack[MAX];

static void chPush(char chData){
	// Check for the capacity of the stack
	if (top == (MAX-1)){
		printf("Stack is Full.\n");
		return;
	}
	//Increment the top index
	top++;
	chStack[top] = chData;
	return;
}

static char chPop(){
	if (top == -1){
		printf("Stack is empty.\n");
		exit(1);
	}

	return chStack[top--];
}

static int match_parantheses(char a, char b){
	if (a == '{' && b == '}')
		return 1;
	else if (a == '[' && b == ']')
			return 1;
	else if (a == '(' && b == ')')
			return 1;
	else if (a == '<' && b == '>')
			return 1;
	else
		return 0;
}

int check_parantheses(char exp[]){
	int i = 0;
	char temp;

	// Traverse the expression to check the matching parentheses
	while(exp[i]) {
		/* If an opening parenthesis push it on chStack*/
		if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[' || exp[i] == '<'){
			chPush(exp[i]);
		}

		/*If its a closing parenthesis then pop from chStack */
		if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']' || exp[i] == '>'){
			temp = chPop();

			// Compare the popped item and expression
			if ( !match_parantheses(exp[i], temp)){
				printf("Not a Balanced Parentheses.\n");
				return 0;
			}
		}
		i++;
	}

	if(top == -1){
		printf("The Expression is balanced.\n");
		return 1;
	}
	else{
		printf("The Expression is not balanced.\n");
		return 0;
	}
}
