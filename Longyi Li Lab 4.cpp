// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int    data;
	node*	left;
	node*   right;
}Node;

typedef struct {
	node* root;
}Head;

Head* CreateTree() {
	Head* myTree = new Head;
	myTree->root = NULL;
	return myTree;
}

void AddNodeRecursive(Node* addnode, int data) {
	if (data <= addnode->data)
		if (addnode->left == NULL) {
			// place the node on the left
			Node* pNew = new Node;
			pNew->data = data;
			pNew->left = NULL;
			pNew->right = NULL;
			addnode->left = pNew;
		}
		else {
			AddNodeRecursive(addnode->left, data);
		}
	else {
		if (addnode->right == NULL) {
			//place node on the right
			Node* pNew = new Node;
			pNew->data = data;
			pNew->left = NULL;
			pNew->right = NULL;
			addnode->right = pNew;
		}
		else {
			AddNodeRecursive(addnode->right, data);
		}
	}

}

void AddNode(Head* myTree, int data) {
	if (myTree->root == NULL) {
		Node* pNew = new Node;
		pNew->data = data;
		pNew->left = NULL;
		pNew->right = NULL;
		myTree->root = pNew;
	}
	else
		AddNodeRecursive(myTree->root, data);
}

void PrintTree(Node* myNode) {
	if (myNode == NULL) {
		return;

	}
	else
	{
		PrintTree(myNode->left);
		PrintTree(myNode->right);
		printf("%d  ", myNode->data);
	}
}

Node* FindLargestElement(Node* myNode) {
	if (myNode->data == NULL) {
		return NULL;
	}
	else
	{
		if (myNode->right != NULL)
		{
			FindLargestElement(myNode->right);
		}
		else
		{
			return myNode;
		}
	}
}

Node* FindSmallestElement(Node* myNode) {
	if (myNode->data == NULL) {
		return NULL;
	}
	else
	{
		if (myNode->left != NULL)
		{
			FindSmallestElement(myNode->left);
		}
		else
		{
			return myNode;
		}
	}
}

int RetrieveLargestElement(Node* myNode) {
	if (myNode->data == NULL) {
		return -1;
	}
	else
	{
		//create two pointers to store 
		Node* pPrev = NULL;
		Node* pNow = myNode;
		while (pNow->right != NULL) {
			pPrev = pNow;
			pNow = pNow->right;
		}
		if (pPrev == NULL) {
			int res = pNow->data;
			pNow = NULL;
			return res;
		}
		else
		{
			//when largest element has left elements
			if (pNow->left != NULL) {
				pPrev->right = pNow->left;
				return pNow->data;
			}
			else
			{
				//when largest element doesnt have  left elements
				pPrev->right = NULL;
				return pNow->data;
			}
		}
	}
}

int DeleteIn(Node* parent, Node* myNode, int data) {
	if (myNode->data < data) {
		if (myNode->right == NULL) {
			return -1;
		}
		DeleteIn(myNode, myNode->right, data);
	}
	else if (myNode->data > data)
	{
		if (myNode->left == NULL) {
			return -1;
		}
		DeleteIn(myNode, myNode->left, data);
	}
	// mynode's data == data
	else
	{
		//no child
		if (myNode->left == NULL && myNode->right == NULL) {
			int res = myNode->data;
			if (parent->data > data) {
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
			delete myNode;
			return res;
		}
		//only left child
		else if (myNode->right == NULL) {
			int res = myNode->data;
			if (parent->data > data) {
				parent->left = myNode->left;
			}
			else
			{
				parent->right = myNode->left;
			}
			delete myNode;
			return res;
		}
		// only right child
		else if (myNode->left == NULL) {
			int res = myNode->data;
			if (parent->data > data) {
				parent->left = myNode->right;
			}
			else
			{
				parent->right = myNode->right;
			}
			delete myNode;
			return res;
		}
		// two children
		else
		{
			Node* temp = FindSmallestElement(myNode->right);
			int res = myNode->data;
			myNode->data = temp->data;
			if (temp->left == NULL && temp->right == NULL) {
				delete temp;
				myNode->right = NULL;
			}
			else
			{
				if (parent->data > data) {
					parent->left = myNode->right;
				}
				else
				{
					parent->right = myNode->right;
				}
			}
			return res;
		}
	}
}

int Delete(Node* myNode, int data) {
	//Null tree return -1
	if (myNode->data == NULL) {
		return -1;
	}
	//only one element 
	else if (myNode->data == data)
	{
		delete myNode;
		return data;
	}
	//node's value < data
	else if (myNode->data < data)
	{
		if (myNode->right == NULL) {
			return -1;
		}
		DeleteIn(myNode, myNode->right, data);
	}
	//node's value > data
	else
	{
		if (myNode->left == NULL) {
			return -1;
		}
		DeleteIn(myNode, myNode->left, data);
	}
}




int main()
{
	Head* myTree = CreateTree();
	AddNode(myTree, 7);
	AddNode(myTree, 1);
	AddNode(myTree, 11);
	AddNode(myTree, 19);
	AddNode(myTree, 13);
	AddNode(myTree, 20);
	PrintTree(myTree->root);
	printf("\n%d", Delete(myTree->root, 19));
	printf("\n %d %d %d \n", myTree->root->data, myTree->root->left->data, myTree->root->right->data);
	PrintTree(myTree->root);
	printf("\n The Largest Number is %d \n", FindLargestElement(myTree->root)->data);
	printf("\n The Smallest Number is %d \n", FindSmallestElement(myTree->root)->data);
	printf("\n The Largest Number is %d \n", RetrieveLargestElement(myTree->root));
	printf("\n The Largest Number is %d \n", RetrieveLargestElement(myTree->root));
	printf("\n The Largest Number is %d \n", FindLargestElement(myTree->root)->data);
	system("pause");
	return 0;
}