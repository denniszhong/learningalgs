//
// Linked list
//

#include "LinkedList.h"
#include <stdlib.h>
#include <iostream>




/************************************************************************/
/*

 -----------     -----------     -----------     -----------     -----------     -----------     -----------
 | 1  |  --|---> | 2  |  --|---> | 3  |  --|---> | 4  |  --|---> | 5  |  --|---> | 6  |  --|---> | 7  | /\ |
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
  ^                                                                                                          
  |                                                                                                              
 head = p                                                                                                     


q = p->next :

 -----------     -----------     -----------     -----------     -----------     -----------     -----------
 | 1  |  --|---> | 2  |  --|---> | 3  |  --|---> | 4  |  --|---> | 5  |  --|---> | 6  |  --|---> | 7  | /\ |
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
   ^               ^                                                                                           
   |               |                                                                                               
 head = p          q                                                                                            


p->next = q->next :

 -----------     -----------     -----------     -----------     -----------     -----------     -----------
 | 1  |    |     | 2  |  --|---> | 3  |  --|---> | 4  |  --|---> | 5  |  --|---> | 6  |  --|---> | 7  | /\ |
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
  ^                ^                ^                                                                          
  |                |                |                                                                              
 head              q                p                                                                           


q->next = head :

 -----------     -----------     -----------     -----------     -----------     -----------     -----------
 | 1  |    |<----| 2  |    |     | 3  |  --|---> | 4  |  --|---> | 5  |  --|---> | 6  |  --|---> | 7  | /\ |
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
  ^                ^                ^                                                                          
  |                |                |                                                                              
 head              q                p                                                                           


head = q :

 -----------     -----------     -----------     -----------     -----------     -----------     -----------
 | 1  |    |<----| 2  |    |     | 3  |  --|---> | 4  |  --|---> | 5  |  --|---> | 6  |  --|---> | 7  | /\ |
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
                   ^                ^                                                                          
                   |                |                                                                              
                   q, head          p                                                                           
                                                                                                                  
                                                                                                                  
                                                                                                                  
                                                                                                                  
                                                                                                                  
                                                                                                                  
                                                                                                                  
                                                                                                                  
                                                                                                                  
Final,  p->next != NULL:
                                                                                                                  
 -----------     -----------     -----------     -----------     -----------     -----------     -----------  
 | 1  |    |<----| 2  |    |<----| 3  |    |<----| 4  |    |<----| 5  |    |     | 6  |  --|---> | 7  | /\ |   
 -----------     -----------     -----------     -----------     -----------     -----------     -----------   
                                                                   ^               ^           
                                                                   |               |            
                                                                   q, head         p            
                                                                                                               
                                                                                                               

q = p->next :                                                                                                   
 -----------     -----------     -----------     -----------     -----------     -----------     -----------  
 | 1  |    |<----| 2  |    |<----| 3  |    |<----| 4  |    |<----| 5  |    |     | 6  |  --|---> | 7  | /\ |   
 -----------     -----------     -----------     -----------     -----------     -----------     -----------   
                                                                   ^               ^               ^            
                                                                   |               |               |               
                                                                  head             p               q                
                                                                                                               
                                                                                                               


q->next = p->next : (q->next == NULL)                                                                                                              
                                                                                                               
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
 | 1  |    |<----| 2  |    |<----| 3  |    |<----| 4  |    |<----| 5  |    |     | 6  |  --|---> | 7  | /\ |
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
                                                                   ^               ^               ^  
                                                                   |               |               |     
                                                                  head             p               q  
                                                                                                               
                                                                                                               
                                                                                                               
                                                                                                               
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
 | 1  |    |<----| 2  |    |<----| 3  |    |<----| 4  |    |<----| 5  |    |<----| 6  |    |     | 7  | /\ |
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
                                                                                    ^                  ^      
                                                                                    |                  |          
                                                                                    q, head            p       
                                                                                                               
                                                                                                               
                                                                                                               
                                                                                                               
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
 | 1  |    |<----| 2  |    |<----| 3  |    |<----| 4  |    |<----| 5  |    |<----| 6  |    |     | 7  | /\ |
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
                                                                                    ^                  ^      
                                                                                    |                  |          
                                                                                    q, head            p       
                                                                                                               
                                                                                                               
                                                                                                               
                                                                                                               
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
 | 1  |    |<----| 2  |    |<----| 3  |    |<----| 4  |    |<----| 5  |    |<----| 6  |    |     | 7  | /\ |
 -----------     -----------     -----------     -----------     -----------     -----------     -----------
                                                                                    ^                  ^      
                                                                                    |                  |          
                                                                                    q, head            p       
                                                                                                               
                                                                                                               
                                                                                                               
                                                                                                               
                                                                                                                 
*/

/************************************************************************/

void ReverseLinklist_ref(Node *&head ) 
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}

	Node *p = head, *q = NULL;
/*
	while (p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		q->next = head;
		head = q;
	}
*/

	while (p->next != NULL)
	{
		q = p;
		p = p->next;
		q->next = head;
		head = q;
	}
	//head = p;
}

Node* ReverseLinklist2(Node *head)
{
	if (head->next == NULL || head == NULL)
	{
		return head;
	}

	Node *pCur = head;
	Node *pNext = NULL;
	Node *pResult = NULL;

	while (pCur->next != NULL)
	{
		pNext = pCur->next;
		pCur->next = pResult;
		pResult = pCur;
		pCur = pNext;
	}

	return pResult;
}

void ReverseLinklist2_ref(Node *&head)
{
	printf_s("Reversing link list...\n");

	if (head->next == NULL || head == NULL)
	{
		printf_s("No node exist, cannot revert.\n");
		return ;
	}

	Node *pCur = head;
	Node *pNext = NULL;
	Node *pResult = NULL;

	while (pCur->next != NULL)
	{
		pNext = pCur->next;
		pCur->next = pResult;
		pResult = pCur;
		pCur = pNext;
	}

	head = pResult;
}

// Recursive reverse
void ReverseLinklist3_ref(Node *&head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}

	Node *rest = head->next;
	ReverseLinklist3_ref(rest);

	head->next->next = head;
	head->next = NULL;

	head = rest;
}










Node* Sum2Linklists(Node* linklist1, Node* linklist2)
{
	return NULL;
}













int main(int argc, char const *argv[])
{
	Node *head = NULL;
	
	/*
	head = CreateLinklistFromConsole();
	PrintLinklist(head);
	ReverseLinklist2_ref(head);
	PrintLinklist(head);
	*/

	
	// Test CreateLinklistFromArray()
	//int arrForLinklist[] = {11, 2, 13, 4, 25, 66, 37, 18, 49};
	int arrForLinklist[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arrLength = sizeof(arrForLinklist) / sizeof (arrForLinklist[0]);
	head = CreateLinklistFromArray(arrForLinklist, arrLength);
	PrintLinklist(head);
	ReverseLinklist_ref(head);
	PrintLinklist(head);

	/*
	int listOneArr[] = {1, 3, 4, 5, 2, 8, 3, 7};
	int listTwoArr[] = {2, 6, 2, 3, 9, 0, 1, 3};
	Node* linklist1 = CreateLinklistFromArray(listOneArr, sizeof(listOneArr) / sizeof(listOneArr[0]));
	Node* linklist2 = CreateLinklistFromArray(listTwoArr, sizeof(listTwoArr) / sizeof(listTwoArr[0]));
	PrintLinklist(linklist1);
	PrintLinklist(linklist2);
	Node* sumLinklist = Sum2Linklists(linklist1, linklist2);
	*/
	
	return 0;
}