#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

// Implementation using Array

/* Structure to represent a STACK *
struct stack {
	int top;		// index of the topmost element (For peeking)
	int capacity;	// Only Positive numbers
	int *arr;
};
 */

/**
 * create_stack - Create Stack of given capacity
 */
struct stack *create_Stack(int capacity){
	// Allocate memory for a stack
	struct stack *stackNode = (struct stack*)malloc(sizeof(struct stack));

	// Fill in data
	stackNode->top = -1;
	stackNode->capacity = capacity;
	stackNode->arr = (int *)malloc((stackNode->capacity)*sizeof(int));

	printf("Created Stack. Capacity=%d, top=%d\n", stackNode->capacity, stackNode->top);
	return stackNode;
}

/**
 * is_full - stack is full or not
 * Stack is full when top is equal to the last index.
 */
int is_full(struct stack* stackNode){
	return stackNode->top == stackNode->capacity - 1;
}

/**
 * is_empty - stack is empty or not
 * Stack is empty when top is equal to -1.
 */
int is_empty(struct stack* stackNode){
	if(stackNode->top == -1){
		printf("Stack is empty.\n");
		return 1;
	}
	return 0;
}

/**
 * push - Adds an item on the stack.
 * Stack follows FILO. So when we push an item on the stack it will go in the
 * bottom and it will increases top by 1.
 */
void Apush(struct stack* stackNode, int data){
	// Check if stack is full or not. Cant add if stack is full aleady.
	if(is_full(stackNode)){
		printf("Stack is full. Can't push %d \n.", data);
		return;
	}

	// Increment the top and add the data at that index
	stackNode->top = stackNode->top + 1;
	stackNode->arr[stackNode->top] = data;

	printf("Pushed %d on the Stack, Now Top = %d\n", data, stackNode->top);
	return;
}

/**
 * pop - Removes an item from the stack.
 * Stack follows FILO.
 * So when we pop an item from the stack it will go from the top and
 * it will decreases top by 1.
 */
void Apop(struct stack* stackNode){
	if(is_empty(stackNode)){
		printf("Stack is Empty. Can't Pop.\n");
		return;
	}

	stackNode->top = stackNode->top - 1;
	printf("Popping: Stack top data item now is : %d\n",
			stackNode->arr[stackNode->top]);
}

int Apeek(struct stack *stackNode){

	if(is_empty(stackNode)){
		printf("Stack is Empty. Can't Peek.\n");
		return -1;
	}

	printf("Peeking: Stack top data = %d\n", stackNode->arr[stackNode->top]);
	return (stackNode->arr[stackNode->top]);
}


void Aprint_Stack(struct stack *stackHead, int capacity){

	for(int i = capacity-1; i>=0; i--){
		printf("%d\n", stackHead->arr[i]);
	}

}
