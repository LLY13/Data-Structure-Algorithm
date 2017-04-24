// MultiLinkedList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>



typedef struct Node{
	unsigned int id;
	char* name;
	char* lastname;
	char* email;
	char* country;
	Node* nextid;
	Node* nextln;
}NODE;

typedef struct {
	int count;
	NODE *pID;
	NODE *pLN;
}MLL;

MLL *CreateMultiLinkList() {
	MLL *myList = new MLL;
	myList->count = 0;
	myList->pID = NULL;
	myList->pLN = NULL;
	return myList;
}

void InsertNode(MLL *myList, unsigned int ID, char Name[], char LastName[], char Email[], char Country[]) {
	NODE *pNew = new NODE;
	Node *pCur = new Node;
	Node* pNext = new Node;
	pNew->id = ID;
	pNew->name = Name;
	pNew->lastname = LastName;
	pNew->email = Email;
	pNew->country = Country;
	// insert by id
	if (myList->count == 0) {
		myList->pID = pNew;
		pNew->nextid = NULL;
	}else if (pNew->id < myList->pID->id) {
		pNew->nextid = myList->pID;
		myList->pID = pNew;
	}else {
		pCur = myList->pID;
		pNext = myList->pID->nextid;
		while (pNew->id > pCur->id)
		{
			if (pNext == NULL || pNew->id < pNext->id) {
				pNew->nextid = pNext;
				pCur->nextid = pNew;
				break;
			}
			else
			{
				pCur = pCur->nextid;
				pNext = pNext->nextid;
			}
		}
	}
	//insert by lastname
	if (myList->count == 0) {
		myList->pLN = pNew;
		pNew->nextln = NULL;
	}
	else if (strcmp(pNew->lastname , myList->pLN->lastname) == -1) {
		pNew->nextln = myList->pLN;
		myList->pLN = pNew;
	}
	else {
		pCur = myList->pLN;
		pNext = myList->pLN->nextln;
		while (strcmp(pNew->lastname , pCur->lastname) == 1)
		{
			if (pNext == NULL || strcmp(pNew->lastname , pNext->lastname) == -1) {
				pNew->nextln = pNext;
				pCur->nextln = pNew;
				break;
			}
			else
			{
				pCur = pCur->nextln;
				pNext = pNext->nextln;
			}
		}
	}
	myList->count += 1;
}

void PrintByID(MLL *myList) {
	NODE *pNew = new NODE;
	Node *pCur = new Node;
	pCur = myList->pID;
	while (pCur != NULL)
	{
		printf("%d %s %s %s %s \n", pCur->id, pCur->name, pCur->lastname, pCur->email, pCur->country);
		pCur = pCur->nextid;
	}

}

void PrintByLN(MLL *myList) {
	NODE *pNew = new NODE;
	Node *pCur = new Node;
	pCur = myList->pLN;
	while (pCur != NULL)
	{
		printf("%d %s %s %s %s \n", pCur->id, pCur->name, pCur->lastname, pCur->email, pCur->country);
		pCur = pCur->nextln;
	}

}



Node *RetrieveNodeByID(MLL *myList, unsigned int ID) {
	Node *pCur = new Node;
	Node* pNext = new Node;
	pCur = myList->pID;
	pNext = myList->pID->nextid;

	if (myList->count == 0) {
		return NULL;
	}
	else {
		if (pCur->id == ID) {
			return pCur;
		}
		else if (pCur->id > ID)
		{
			return NULL;
		}

		else
		{
			while (pCur->id < ID)
			{
				if (pNext->id == ID) {
					return pNext;
				}
				else if(pNext->id > ID || pNext->id == NULL)
				{
					return NULL;
				}
				else
				{
					pCur = pCur->nextid;
					pNext = pNext->nextid;
				}
			}
		}
	}
	
}



Node *RetrieveNodeByLN(MLL *myList, char LastName[]) {
	Node *pCur = new Node;
	Node* pNext = new Node;
	pCur = myList->pLN;
	pNext = myList->pLN->nextln;

	if (myList->count == 0) {
		return NULL;
	}
	else {
		if (strcmp(pCur->lastname , LastName) == 0) {
			return pCur;
		}
		else if (strcmp(pCur->lastname , LastName) == 1)
		{
			return NULL;
		}

		else
		{
			while (strcmp(pCur->lastname , LastName) == -1)
			{
				if (strcmp(pNext->lastname , LastName) == 0) {
					return pNext;
				}
				else if (strcmp(pNext->lastname , LastName) == 1 || pNext->lastname == NULL)
				{
					return NULL;
				}
				else
				{
					pCur = pCur->nextln;
					pNext = pNext->nextln;
				}
			}
		}
	}
}





int main()
{
	MLL *myList;
	myList = CreateMultiLinkList();
	InsertNode(myList, 6, "1", "aaaac", "1", "1");
	InsertNode(myList, 3, "3", "bbbbb", "3", "3");
	InsertNode(myList, 4, "4", "baaaa", "4", "4");
	InsertNode(myList, 2, "2", "aabbb", "2", "2");
	InsertNode(myList, 5, "5", "aaaab", "5", "5");
	InsertNode(myList, 1, "5", "caabb", "5", "5");
	PrintByID(myList);
	printf("\n");
	PrintByLN(myList);
	printf("\n");
	printf("%s", RetrieveNodeByID(myList, 6)->lastname);
	printf("\n");
	printf("%d", RetrieveNodeByLN(myList, "aabbb")->id);
	system("pause");
    return 0;
}

