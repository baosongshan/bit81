#ifndef _SLIST_H_
#define _SLIST_H_

#include"common.h"

typedef struct SListNode
{
	DataType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *first;
	SListNode *last;
	size_t     size;
}SList;

SListNode* _Buynode(DataType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	//assert(s != NULL);
	if(s == NULL)
		return NULL;
	s->next = NULL;
	s->data = x;
	return s;
}

void SListInit(SList *plist);
void SListShow(SList *plist);
bool SListPushBack(SList *plist, DataType x);
bool SListPushFront(SList *plist, DataType x);
bool SListPopBack(SList *plist);
bool SListPopFront(SList *plist);
SListNode* SListFindByVal(SList *plist, DataType key);
bool SListDeleteByVal(SList *plist, DataType key);

size_t SListLength(SList *plist);
void SListClear(SList *plist);
void SListDestroy(SList *plist);
void SListReverse(SList *plist);

void SListInsertByVal(SList *plist, DataType x);
void SListSort(SList *plist);

/////////////////////////////////////////////////////////
void SListInit(SList *plist)
{
	SListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}

bool SListPushBack(SList *plist, DataType x)
{
	SListNode *s = _Buynode(x);
	if(s == NULL)
		return false;
	plist->last->next = s;
	plist->last = s;
	plist->size++;
	return true;
}

bool SListPushFront(SList *plist, DataType x)
{
	SListNode *s = _Buynode(x);
	if(s == NULL)
		return false;
	s->next = plist->first->next;
	plist->first->next = s;
	if(plist->size == 0)
		plist->last = s;
	plist->size++;
	return true;
}

void SListShow(SList *plist)
{
	SListNode *p =plist->first->next;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

bool SListPopBack(SList *plist)
{
	SListNode *p;
	if(plist->size == 0)
		return false;
	p = plist->first;
	while(p->next != plist->last)
		 p = p->next;

	p->next = NULL;
	free(plist->last);
	plist->last = p;
	plist->size--;
	return true;
}
bool SListPopFront(SList *plist)
{
	SListNode *p;
	if(plist->size == 0)
		return false;
	p = plist->first->next;
	plist->first->next = p->next;
	free(p);
	plist->size--;
	if(plist->size == 0)
		plist->last = plist->first;
	return true;
}

SListNode* SListFindByVal(SList *plist, DataType key)
{
	SListNode *p = plist->first->next;
	while(p!=NULL  && p->data!=key)
		p = p->next;
	return p;
}

bool SListDeleteByVal(SList *plist, DataType key)
{
	SListNode *q;
	SListNode *p = plist->first;
	while(p->next!=NULL && p->next->data!=key)
		p = p->next;
	if(p->next == NULL)
		return false;

	 q = p->next;
	if(p->next == plist->last)
		plist->last = p;
	p->next = q->next;
	free(q);
	plist->size--;
	return true;
}

size_t SListLength(SList *plist)
{
	return plist->size;
}

void SListClear(SList *plist)
{
	SListNode *p = plist->first->next;
	while(p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	plist->last = plist->first;
	plist->size = 0;
}

void SListDestroy(SList *plist)
{
	SListClear(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}

void SListReverse(SList *plist)
{
	if(plist->size > 1)
	{
		SListNode *p1, *p2, *p3;
		p1 = NULL;
		p2 = plist->first->next;
		p3 = p2->next;

		plist->last = p2;
		while(p2 != NULL)
		{
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			if(p3 != NULL)
				p3 = p3->next;//
		}
		plist->first->next = p1;
	}
}

void SListInsertByVal(SList *plist, DataType x)
{
	SListNode *p = plist->first;
	while(p->next!=NULL && x>p->next->data)
		p = p->next;

	SListNode *s = _Buynode(x);
	if(p->next == NULL)
	{
		p->next = s;
		plist->last = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}
	plist->size++;
}

void SListSort(SList *plist)
{
	if(plist->size > 1)
	{
		SListNode *prev;
		SListNode *p = plist->first->next;
		SListNode *q = p->next;
		plist->last = p;
		plist->last->next = NULL;

		p = q;
		while(p != NULL)
		{
			q = q->next;
			prev = plist->first;
			while(prev->next!=NULL && p->data>prev->next->data)
				prev = prev->next;

			if(prev->next == NULL)
			{
				prev->next = p;
				plist->last = p;
				p->next = NULL;
			}
			else
			{
				p->next = prev->next;
				prev->next = p;
			}
			p = q;
		}
	}
}


#if 0
void SListReverse(SList *plist)
{
	SListNode *p = plist->first->next;
	SListNode *q = p->next;	
	plist->last = p;
	plist->last->next = NULL;
	p = q;
	while(p != NULL)
	{
		q = p->next;
		p->next = plist->first->next;
		plist->first->next = p;
		p = q;
	}
}


SListNode* SListFindByVal(SList *plist, DataType key)
{
	SListNode *p = plist->first->next;
	while(p != NULL)
	{
		if(p->data == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}



typedef struct Node
{
	DataType data;
	struct Node *next;
}Node;

typedef Node* List;

void InitList(List *head);
void CreateList_Tail(List *head);
void CreateList_Front(List *head);
void CreateList(List *head);
void ShowList(List head);

void InitList(List *head)
{
	*head = (Node*)malloc(sizeof(Node));
	(*head)->next = NULL;
}

void CreateList(List *head)
{
	Node *p = *head;
	for(int i=1; i<=10; ++i)
	{
		Node *s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}
void ShowList(List head)
{
	Node *p = head->next;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}



void CreateList(List *head)
{
	*head = (Node*)malloc(sizeof(Node));
	(*head)->data = 1;
	(*head)->next = NULL;

	Node *p = *head;
	for(int i=2; i<=10; ++i)
	{
		p = p->next = (Node*)malloc(sizeof(Node));
		assert(p != NULL);
		p->data = i;
		p->next = NULL;
	}
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
	(*head) = (Node*)malloc(sizeof(Node));
	(*head)->data = 1;
	(*head)->next = NULL;

	for(int i=2; i<=10; ++i)
	{
		Node *s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;

		s->next = (*head);
		*head = s;
	}
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
#endif

#endif /*_SLIST_H_*/