/* twoStacks.h || Created on: Feb 10, 2018 Author: hsahu */
#ifndef TWOSTACKS_H_
#define TWOSTACKS_H_

struct twoStacks{
	int top1;			//Index of the top element of the 1st
	int top2;
	int size;

	int *array;
};

/****** twoStacks Data Structure Methods ******/
void tsPush(struct twoStacks *ts, int data, int stackNum);
void tsPop(struct twoStacks *ts, int stackNum);


#endif /* TWOSTACKS_H_ */
