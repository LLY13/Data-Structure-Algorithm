// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

//   Longyi Li    1471421

#include "stdafx.h"
#include <stdlib.h>

//create a stack
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

char Pop(STACK_HEAD *myStack) {
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

char StackPop(STACK_HEAD *myStack) {
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
// method to compare two operators
//if  op1's priority is higher than op2's return 1, else retuen 0;
int Compare(char op1, char op2) {
	// (  )  compared to others
	if (op1 == '(' || op1 == ')') {
		return 1;
	}

	// ^ compared to others
	if (op1 == '^') {
		if (op2 == '(' || op2 == ')') {
			return 0;
		}
		else
		{
			return 1;
		}
	}
	// * / compared to others
	if (op1 == '*' || op1 == '/') {
		if (op2 == '+' || op2 == '-') {
			return 1;
		}
		else
		{
			return 0;
		}
	}

	//+ - compared to others
	if (op1 == '+' || op1 == '-') {
		return 0;
	}
}



void infix2postfix(char *ext, char *postfix) {
	int j = 0;
	STACK_HEAD *myStack;
	myStack = CreateStack();
	for (int i = 0; ext[i]; i++) {
		// if its a character put it in postfix
		if (ext[i] <= 'Z' && ext[i] >= 'A') {
			postfix[j++] = ext[i];
		}
		else {
			//if its not a character
			//if stack is empty
			if (IsEmpty(myStack)) {
				Push(myStack,ext[i]);
			}
			//if stack is not empty
			else {
				//if ext[i] == )
				if (ext[i] == ')') {
					while (!IsEmpty(myStack) && StackPop(myStack) != '(')
					{
						postfix[j++] = Pop(myStack);
						if (StackPop(myStack) == '(') {
							Pop(myStack);
						}
					}
				}
				else
				//if ext[i] != )
				{
					//if ext[i]'s priority is lower that myStack;s last , output all myStack until (
					if(Compare(ext[i], StackPop(myStack)) == 0){
						while (!IsEmpty(myStack) && StackPop(myStack) !=  '(')
						{
							postfix[j++] = Pop(myStack);
						}
						Push(myStack, ext[i]);
					}
					//if ext[i]'s priority is not lower that myStack;s last, push it into stack
					else
					{
						Push(myStack, ext[i]);
					}

				}
			}
		}
	}
	// if stack is not empty , out put all except (

	while (!IsEmpty(myStack) && StackPop(myStack) != '(') 
	{
		char y = Pop(myStack);
		postfix[j++] = y;
	}
	//end
	postfix[j] = '\0';
		
}

int main()
{

	//   Longyi Li    1471421

	char *infix = "A*B+C*D";
	char postfix[100];
	infix2postfix(infix, postfix);
	printf("%s\n\n\n\n\n", postfix);
	system("pause");
	return 0;
}