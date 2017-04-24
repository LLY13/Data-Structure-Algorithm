// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>


typedef struct Node {
	int data;
	Node* Next;
}NODE;

typedef struct {
	int count;
	NODE *Top;
}STACK_HEAD;


STACK_HEAD *CreateStack() {
	STACK_HEAD *myStack = new STACK_HEAD;
	myStack->count = 0;
	myStack->Top = NULL;
	return myStack;
}


void Push(STACK_HEAD *myStack, int value) {
	NODE *pNew = new NODE;
	pNew->data = value;
	pNew->Next = myStack->Top;
	myStack->Top = pNew;
	myStack->count++;
}

int Pop(STACK_HEAD *myStack) {
	int x;
	if (myStack->count != 0) {
		x = myStack->Top->data;
		NODE *pTop = myStack->Top;
		myStack->Top = myStack->Top->Next;
		myStack->count--;
		free(pTop);
	}
	else {
		x = INT_MIN;
	}
	return x;

}

int StackPop(STACK_HEAD *myStack) {
	int x;
	if (myStack->count != 0) {
		x = myStack->Top->data;
	}
	else {
		x = INT_MIN;
	}
	return x;
}

bool IsEmpty(STACK_HEAD *myStack) {
	if (myStack->count != 0) {
		return false;
	}
	else {
		return true;
	}
}

void Destroy(STACK_HEAD *myStack) {
	while (myStack->count != 0) {
		NODE *pTop = myStack->Top;
		myStack->Top = myStack->Top->Next;
		free(pTop);
	}
}

int main()
{
	STACK_HEAD *myStack;
	myStack = CreateStack();
	Push(myStack, 7);
	Push(myStack, 3);
	Push(myStack, 11);

	int x = 0;
	while (x != INT_MIN)
	{
		x = Pop(myStack);
		printf("%d \n", x);
	}
	printf("%d", x);
	system("pause");
    return 0;
}

