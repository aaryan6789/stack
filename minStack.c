/* stack_min.c | Author:hsahu */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>

#include "stack.h"
#include "minStack.h"

/**
 * Design a Data Structure SpecialStack that supports all the stack operations
 * like push(), pop(), isEmpty(), isFull() and an additional operation getMin()
 * which should return minimum element from the SpecialStack.
 * All these operations of SpecialStack must be O(1).
 * To implement SpecialStack, you should only use standard Stack data structure
 * and no other data structure like arrays, list, .. etc.
 */
/** Solution:
 *  Use two stacks: one to store actual stack elements and
 *  				other as an auxiliary stack to store minimum values.
 *  The idea is to do push() and pop() operations in such a way that the top of
 *  auxiliary stack is always the minimum.
 *  Let us see how push() and pop() operations work.
 *
 *  Push(int x) // inserts an element x to Special Stack
 *  1) push x to the first stack (the stack with actual elements)
 *  2) compare x with the top element of the second stack (the auxiliary stack).
 *  Let the top element be y.
 *  a) If x is smaller than y then push x to the auxiliary stack.
 *  b) If x is greater than y then push y to the auxiliary stack.
 *
 *  int Pop() // removes an element from Special Stack and return the removed element
 *  1) pop the top element from the auxiliary stack.
 *  2) pop the top element from the actual stack and return it.
 *
 *  The step 1 is necessary to make sure that the auxiliary stack is also
 *  updated for future operations.
 *
 *  int getMin() // returns the minimum element from Special Stack
 *  1) Return the top element of auxiliary stack.
 *  We can see that all above operations are O(1).
 */

/*// Since in C we don't have a standard Stack Structure.
// Lets use the Stack by linked list
typedef struct minStack{
	struct Lstack *actStackHead;	// Head of the actual Stack
	struct Lstack *auxStackHead;	// Head of the auxiliary stack
} MinStack;*/

struct minStack *minStackCreate() {
	/* Allocate Memory to the minStack Structure*/
	struct minStack *minStackNode = (MinStack *)malloc(sizeof(MinStack));

	/* Initialize the head pointers to the 2 stacks to NULL */
	minStackNode->actStackHead = NULL;
	minStackNode->auxStackHead = NULL;

	printf("Created minStack Data Structure.\n");
	return (minStackNode);
}

void minStackPush(MinStack *minStack, int data){
	printf("Push %d on minStack.\n", data);

	printf("Pushing %d on Actual Stack.\n", data);
	Lpush(&minStack->actStackHead, data);

	printf("Pushing selective item on Aux Stack under the hood ;) \n");
	int auxTop = Ltop(minStack->auxStackHead);
	printf("auxTop = %d \n", auxTop);
	// Compare the incoming data with the auxiliary top element
	if (auxTop == INT_MIN){
		printf("Auxiliary Stack is Empty.\n");
		// Push the data on the auxiliary Stack
		Lpush(&minStack->auxStackHead, data);
	}
	else if (data <= auxTop){
		printf("auxTop = %d \n", auxTop);
		// Push the data on the auxiliary Stack
		Lpush(&minStack->auxStackHead, data);
	}
	else if (data > auxTop){
		// Push auxTop on the auxiliary Stack
		Lpush(&minStack->auxStackHead, auxTop);
	}
	return;
}

/**
 * minStackPop - Pop an element from the minStack Structure
 */
void minStackPop(MinStack *minStack) {
	printf("Popping from minStack \n");
	Lpop(&minStack->actStackHead);
	Lpop(&minStack->auxStackHead);
}

/**
 * minStackAuxTop - Get the top of the Auxiliary Stack of the minStack Structure
 * @minStack: Pointer to the minStack
 * @returns: the top element of the auxiliary stack
 */
int minStackAuxTop(MinStack *minStack) {
	if(!minStack){
		printf("Invalid MinStack.\n");
		return -EINVAL;
	}

	printf("Top of the Auxiliary Stack is = %d \n", Ltop(minStack->auxStackHead));
	return (Ltop(minStack->auxStackHead));
}

/**
 * minStackTop - Get the top of the minStack Structure
 */
int minStackTop(MinStack *minStack) {
	if(!minStack){
		printf("Invalid MinStack.\n");
		return -EINVAL;
	}

	printf("Top element of the minStack is = %d \n", Ltop(minStack->actStackHead));
	return (Ltop(minStack->actStackHead));
}

int minStackGetMin(MinStack *minstack) {
	printf("Getting the MIN element of the minStack structure %d \n", minStackAuxTop(minstack));
	return (minStackAuxTop(minstack));
}

void minStackFree(MinStack* obj) {
	return;
}
