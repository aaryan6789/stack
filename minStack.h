/* minStack.h | Author: hsahu */
#ifndef MINSTACK_H_
#define MINSTACK_H_

// Since in C we don't have a standard Stack Structure.
// Lets use the Stack by linked list
typedef struct minStack{
	struct Lstack *actStackHead;	// Head of the actual Stack
	struct Lstack *auxStackHead;	// Head of the auxiliary stack
} MinStack;

/* ----------- Methods ----------- */
struct minStack *minStackCreate();
void minStackPush(MinStack *minStack, int data);
void minStackPop(MinStack *minStack);
int minStackAuxTop(MinStack *minStack);
int minStackTop(MinStack *minStack);
int minStackGetMin(MinStack *minstack);

#endif /* MINSTACK_H_ */
