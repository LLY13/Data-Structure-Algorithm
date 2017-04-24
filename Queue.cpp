// Queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>


typedef struct Node {
	int data;
	Node* Next;
}NODE;

typedef struct {
	int count;
	NODE *Front;
	NODE *Rear;
}QUEUE_HEAD;


QUEUE_HEAD *CreateQueue() {
	QUEUE_HEAD *myQueue = new QUEUE_HEAD;
	myQueue->count = 0;
	myQueue->Front = NULL;
	myQueue->Rear = NULL;
	return myQueue;
}

void Enqueue(QUEUE_HEAD *myQueue, int value) {
	NODE *pNew = new NODE;
	pNew->data = value;
	pNew->Next = NULL;
	if (myQueue->count != 0) {
		myQueue->Rear->Next = pNew;
	}
	myQueue->Rear = pNew;
	if (myQueue->count == 0) {
		myQueue->Front = pNew;
	}
	myQueue->count++;
}

int Dequeue(QUEUE_HEAD *myQueue) {
	int x;
	if (myQueue->count != 0) {
		x = myQueue->Front->data;
		Node *pFront = myQueue->Front;
		myQueue->Front = myQueue->Front->Next;
		myQueue->count--;
		free(pFront);
	}
	return x;
}

int Front_Queue(QUEUE_HEAD *myQueue) {
	int x;
	if (myQueue->count != 0) {
		x = myQueue->Front->data;
	}
	return x;
}

int Rear_Queue(QUEUE_HEAD *myQueue) {
	int x;
	if (myQueue->count != 0) {
		x = myQueue->Rear->data;
	}
	return x;
}

int main()
{
	QUEUE_HEAD *myQueue;
	myQueue = CreateQueue();
	Enqueue(myQueue, 1);
	Enqueue(myQueue, 2);
	Enqueue(myQueue, 3);


	printf("%d \n", Rear_Queue(myQueue));
	printf("%d \n", Front_Queue(myQueue));
	printf("%d \n", Dequeue(myQueue));
	printf("%d \n", Dequeue(myQueue));
	printf("%d \n", Dequeue(myQueue));
	system("pause");
    return 0;
}

