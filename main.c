#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "twoStacks.h"
#include "check_parantheses.h"
#include "minStack.h"

int main(){
	printf("\n\n ********* STACK by ARRAY ******** \n");
	struct stack *stackNode = create_Stack(5);
	Apush(stackNode, 5);
	Apush(stackNode, 6);
	Apush(stackNode, 7);
	Apush(stackNode, 9);
	Apush(stackNode, 10);

	Apeek(stackNode);
	printf("Print the Stack:\n");
	Aprint_Stack(stackNode, 3);
	Apop(stackNode);
	Apush(stackNode, 11);

	printf("\n\n ********* STACK by LINKED LIST ******** \n");
	struct Lstack *head = NULL;
	Lpush(&head, 70);
	Lpush(&head, 20);
	Lpush(&head, 60);
	Lpush(&head, 40);
	int ltop = Ltop(head);
	printf("Ltop = %d \n", ltop);
	print_Lstack(head);
	printf("\n\n Reversing Stack \n");
	reverseStack(&head);
	print_Lstack(head);


	printf("\n\n Sorting Stack \n");
	sortLStack(head);
	print_Lstack(head);


	printf("\n\n ********* twoStacks ********\n");
	struct twoStacks ts;
	ts.size = 3;
	/* Allocate Memory for the twoStacks */
	ts.array = (int *)calloc(sizeof(int), ts.size);
	ts.top1 = -1;
	ts.top2 = ts.size;

	tsPush(&ts, 2, 1);
	tsPush(&ts, 3, 1);
	tsPush(&ts, 4, 1);
	tsPush(&ts, 5, 2);
	tsPush(&ts, 6, 2);
	tsPop(&ts, 1);

	/********* check Parentheses *********/
	char express[6] = {'{','{','{','}','}','}'};
	int isBalanced = check_parantheses(express);
	printf("IS Balanced = %d", isBalanced);

	/********* minStack ********/
	printf("\n\n ********* minStack ******** \n");
	struct minStack *minStack = minStackCreate();
	minStackPush(minStack, 10);
	minStackPush(minStack, 20);
	minStackPush(minStack, 5);
	minStackPop(minStack);
	minStackPush(minStack, 30);
	minStackAuxTop(minStack);
	print_Lstack(minStack->actStackHead);
	print_Lstack(minStack->auxStackHead);

	minStackTop(minStack);
	minStackGetMin(minStack);


	return 0;
}
