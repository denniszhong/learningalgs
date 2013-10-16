//
// LinkedList.h
//

#include <stdlib.h>
#include <stdio.h>
#include <iostream>


struct Node
{
	Node*	next;
	int		data;
};


Node* CreateNode(int nodeValue)
{
	Node *q = (Node*)malloc(sizeof(Node));
	q->data = nodeValue;
	q->next = NULL;

	return q;
}

Node* CreateLinklistFromConsole()
{
	printf("Creating link list from console input(Enter 0 to finish inputing).\n");

	Node *head = NULL;
	int input = 0;
	while (scanf("%d", &input))
	{
		if (input < 0) continue;
		if (input == 0) break;
		
		head = CreateNode(input);
		break;
	}

	Node *p = head;
	//printf("Please input positive integers (input 0 to exit):\n");

	input = 0;
	while (scanf("%d", &input))
	{
		if (input < 0) continue;
		if (input == 0) break;

		p->next = CreateNode(input);
		p = p->next;
	}

	return head;
}

Node* CreateLinklistFromArray(int* arrHead, int arrLen)
{
	Node *head = NULL;

	head = CreateNode(arrHead[0]);
	Node *p = head;

	for (int i = 1; i < arrLen; i++)
	{
		p->next = CreateNode(arrHead[i]);
		p = p->next;
	}

	return head;
}

void PrintLinklist( Node * head ) 
{
	if (head == NULL)
	{
		printf("Header is null, no node exist!");
		return;
	}

	printf("Printing single link list:\n");

	Node *p = head;
	printf("%d ", p->data);

	while (p->next != NULL)
	{
		p = p->next;
		printf("%d ", p->data);
	} 

	printf("\n");
}

