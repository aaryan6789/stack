#ifndef STACK_H_
#define STACK_H_

/* Stack by Array */

/* Structure Definition
 * Stack Node by Array
 */
struct stack {
	int top;		// index of the topmost element (For peeking)
	int capacity;	// Only Positive numbers
	int *arr;
};

/* Functions Available*/
struct stack *create_Stack(int capacity);
int is_full(struct stack* stackNode);
int is_empty(struct stack* stackNode);
void Apush(struct stack* stackNode, int data);
void Apop(struct stack* stackNode);
int Apeek(struct stack *stackNode);
void Aprint_Stack(struct stack *stackHead, int capacity);

/* Stack by Linked List */
// --------- Structure definition ------
// Structure to represent a Stack (by a Linked List)
struct Lstack{
	int data;
	struct Lstack *next;
};

// ------ Method --------
void Lpush(struct Lstack** head_ref, int data);
int Lpop(struct Lstack** head_ref);
int Ltop(struct Lstack *head);
int isLStackEmpty(struct Lstack *head);
void print_Lstack(struct Lstack* top);

void sortLStack(struct Lstack *unSortedStack_head);

void insertAtBottom(struct Lstack **top_ref, int item);
void reverseStack(struct Lstack** top_ref);


#endif /* STACK_H_ */
