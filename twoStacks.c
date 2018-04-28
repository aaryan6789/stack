#include "twoStacks.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * twoStacks.c
 *	Implement 2 stacks using a single array.
 *	Create a Data Structure twoStacks that represents 2 stacks.
 *	twoSatcks is implemented using a single array.
 *	Both the stacks stores the elements in the same array.
 */

/**
 * Implementation Details
 * Method 1:
 * Divide the single array into 2 equal halves.
 * stack1 = from 0 to n/2 and
 * stack2 = from n/2+1 to n-1
 * Disadvantages:
 * 1. Inefficient space utilization.
 * 2. Causes overflow even if there is space left in the array.
 *
 * Method 2:
 * Divide the single array into 2 different stacks in such a way that the stacks
 * starts from the extreme corners of the array.
 * Advantages:
 * 1. This is an space efficient method
 * 2. Doesn't cause overflow if there is still space left in the array.
 *
 * stack1 starts from the left and the 1st element is pushed at index 0.
 * stack2 starts from the end and 1st element is pushed at index (size-1).
 * Overflow is checked by checking the space  between the 2 top elements of both stacks.
 */

/*struct twoStacks{
	int top1;			//Index of the top element of the 1st
	int top2;
	int size;

	int *array;
};*/

/**
 * tsPush - Push an element on twoStack
 * ts : pointer to the twoStack structure
 * data : element to be pushed on the stack
 * stackNum : which stack to push the number on
 */
void tsPush(struct twoStacks *ts, int data, int stackNum){
	//printf("twoStacks Capacity = %d\n", ts->size);

	if(stackNum == 1){
		/* Check if the location where we are trying to push an element is already filled */
		if((ts->top1 + 1) == ts->top2){
			printf("ERROR: twoStacks Full. Can't push any more elements on Stack %d.\n", stackNum);
			return;
		}
		else{
			/* Push the element on the 1st stack */
			ts->top1++;
			ts->array[ts->top1] = data;
			printf("Pushing %d on Stack %d at Index %d.\n", data, stackNum, ts->top1);
		}
	}
	else if(stackNum == 2){
		if((ts->top2 - 1) == ts->top1){
			printf("ERROR: twoStacks Full. Can't push any more elements on Stack %d.\n", stackNum);
			return;
		}
		else{
			/* Push the element on the 2nd stack */
			ts->top2--;
			ts->array[ts->top2] = data;
			printf("Pushing %d on Stack %d at Index %d.\n", data, stackNum, ts->top1);
		}
	}
	else{
		printf("Invalid StackNum.\n");
		return;
	}
}

/**
 * tsPop - Pops an element from the twoStacks structure
 * ts : pointer to the twoStack structure
 * stackNum : which stack to push the number on
 */
void tsPop(struct twoStacks *ts, int stackNum){
	int popped_element;

	if(stackNum == 1){
		if(ts->top1 == -1){
			printf("ERROR: twoStacks Empty. Can't POP any element from Stack %d.\n", stackNum);
			return;
		}
		else{
			popped_element = ts->array[ts->top1];
			ts->array[ts->top1] = -999;			// Assign an invalid value to the element at popped space
			ts->top1--;
			printf("Popped %d from Stack %d\n", popped_element, stackNum);
			return;
		}
	}
	else if(stackNum == 2){
		if(ts->top2 == ts->size){
			printf("ERROR: twoStacks Empty. Can't POP any element from Stack %d.\n", stackNum);
			return;
		}
		else{
			popped_element = ts->array[ts->top2];
			ts->array[ts->top2] = -999;			// Assign an invalid value to the element at popped space
			ts->top2++;
			printf("Popped %d from Stack %d\n", popped_element, stackNum);
			return;
		}
	}
}
