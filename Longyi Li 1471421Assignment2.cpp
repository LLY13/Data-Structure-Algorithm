#include "stdafx.h"
#include <stdlib.h>
#include <string.h>

// Longyi Li 1471421  Assignment2
// node to store characters
typedef struct Node {
	char ch;
	//pointer to point next list
	Node* nextL;
	//pointer to point next character
	Node* nextC;
}NODE;



//create a list
NODE *CreateList() {
	NODE *myList = new NODE;
	myList->ch = NULL;
	myList->nextC = NULL;
	myList->nextL = NULL;
	return myList;
}

//function to check if this char is in this list
bool CharExist(char charac, Node *node) {
	if (node->nextC == NULL) {
		return false;
	}
	else
	{
		Node *pCur = node->nextC;
		while (pCur->ch != charac)
		{
			if (pCur->nextC != NULL) {
				pCur = pCur->nextC;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
}


//function to create a new node in the list if existed return this node
NODE *CreateNode(char charac, NODE *node) {
	// if there is no NODE in this list  create a new one and add it in the list
	if (node->nextC == NULL) {
		NODE *pNew = new NODE;
		pNew->ch = charac;
		pNew->nextL = NULL;
		pNew->nextC = NULL;
		node->nextC = pNew;
		//printf("%d", 1);
		return pNew;
	}
	// if there is  NODE in this list 
	else {
		//if this character not in this list add this node
		//printf("%d", 2);
		if (!CharExist(charac, node)) {
			Node *pCur = node;
			while (pCur->nextC != NULL)
			{
				pCur = pCur->nextC;
			}
			NODE *pNew = new NODE;
			pNew->ch = charac;
			pNew->nextL = NULL;
			pNew->nextC = NULL;
			pCur->nextC = pNew;
			return pNew;
		}
		//if this character already exists in this list return this node
		else
		{
			Node *pCur = node->nextC;
			while (pCur->ch != charac)
			{
				pCur = pCur->nextC;
			}
			return pCur;
		}
	}
}




//function to add a word into this dictionary
int AddWord(char word[], Node *node) {
	int res = 0;
	//iterate all char in this string
	for (int i = 0; word[i] != 0; i++) {
		//find the node or create the node
		//if there is no list in this node create a new list and point this node to it
		Node *pCur = CreateNode(word[i], node);
		if (pCur->nextL == NULL)
		{
			//printf("%d", 3);
			res = 1;
			NODE *pNew = new NODE;
			pNew->ch = NULL;
			pNew->nextC = NULL;
			pNew->nextL = NULL;

			pCur->nextL = pNew;
		}
		node = pCur->nextL;
	}
	return res;
}


//function to test if a word is in the dictionary
int TestWord(char word[], Node *node) {
	int res = 0;
	for (int i = 0; word[i] != 0; i++) {
		if (CharExist(word[i], node)) {
			Node *pCur = CreateNode(word[i], node);
			node = pCur->nextL;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

//function to populate the tree
int Populate(char filename[], Node *node) {
	FILE *fp;
	char StrLine[1024];             
	if ((fp = fopen(filename, "r")) == NULL) 
	{
		return 0;
	}

	while (!feof(fp))
	{
		fgets(StrLine, 1024, fp);  
		//printf("%s\n", StrLine);
		AddWord(StrLine, node);
	}
	fclose(fp);                     
	return 1;
	
}




int main()
{
	NODE *mylist = CreateList();
	char word[] = "abcdd";
	char word2[] = "abc";
	char filename[] = "D:\\SEMESTER1\\6426 Data Structure & Algorithm\\Assignment2\\20k.txt";
	printf("%d", AddWord(word, mylist)); 
	printf("\n");
	printf("%d", AddWord(word2, mylist));
	printf("\n");
	printf("%d", Populate(filename, mylist));

	printf("%d", TestWord("the", mylist));
	printf("%d", TestWord("all", mylist));

	system("pause");
	
	return 0;
}