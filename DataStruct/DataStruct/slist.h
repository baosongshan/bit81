#ifndef _SLIST_H_
#define _SLIST_H_

#include"common.h"

typedef struct Node
{
	DataType data;
	struct Node *next;
}Node;

typedef Node* List;

void InitList(List *head);
void CreateList_Tail(List *head);
void CreateList_Front(List *head);
void ShowList(List head);

void InitList(List *head)
{
	*head = NULL;
}

//1 2 3 4 5 6 7 8 9 10
void CreateList_Tail(List *head)
{
	*head = (Node*)malloc(sizeof(Node));
	(*head)->data = 1;
	(*head)->next = NULL;

	Node *p = *head;
	for(int i=2; i<=10; ++i)
	{
		Node *s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

void CreateList_Front(List *head)
{
	//
}

void ShowList(List head)
{
	Node *p = head;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

#endif /*_SLIST_H_*/