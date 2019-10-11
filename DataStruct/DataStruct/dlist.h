#ifndef _DLIST_H_
#define _DLIST_H_

#include"common.h"

typedef struct DListNode
{
	DataType data;
	struct DListNode *prev;
	struct DListNode *next;
}DListNode;

typedef struct DList
{
	DListNode *first;
	DListNode *last;
	size_t     size; 
}DList;

DListNode* _Buynode(DataType x)
{
	DListNode *s = (DListNode*)malloc(sizeof(DListNode));
	if(NULL == s)
		return NULL;
	s->data = x;
	s->next = s->prev = NULL;
	return s;
}

void DListInit(DList *plist);
void DListShow(DList *plist);
bool DListPushBack(DList *plist, DataType x);
bool DListPushFront(DList *plist, DataType x);
DListNode* DListFindByVal(DList *plist, DataType key);
bool DListDeleteByVal(DList *plist, DataType key);

void DListInit(DList *plist)
{
	DListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->size = 0;
}

bool DListPushBack(DList *plist, DataType x)
{
	DListNode *s = _Buynode(x);
	if(s == NULL)
		return false;

	plist->last->next = s;
	s->prev = plist->last;
	plist->last = s;

	plist->size++;
	return true;
}
void DListShow(DList *plist)
{
	DListNode *p = plist->first->next;
	while(p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

bool DListPushFront(DList *plist, DataType x)
{
	DListNode *s = _Buynode(x);
	if(s == NULL)
		return false;

	s->next = plist->first->next;
	if(s->next != NULL)
		s->next->prev = s;
	s->prev = plist->first;
	s->prev->next = s;

	if(plist->size == 0)
		plist->last = s;

	plist->size++;
	return true;
}

DListNode* DListFindByVal(DList *plist, DataType key)
{
	DListNode *p = plist->first->next;
	while(p!=NULL && p->data!=key)
		p = p->next;
	return p;
}

bool DListDeleteByVal(DList *plist, DataType key)
{
	DListNode *p = DListFindByVal(plist, key);
	if(p == NULL)
		return false;

	//É¾³ý//£¿£¿£¿£¿£¿£¿£¿£¿

	return true;
}

/*

bool SListPopBack(SList *plist);
bool SListPopFront(SList *plist);



size_t SListLength(SList *plist);
void SListClear(SList *plist);
void SListDestroy(SList *plist);
void SListReverse(SList *plist);

void SListInsertByVal(SList *plist, DataType x);
void SListSort(SList *plist);
*/

#endif /* _DLIST_H_ */