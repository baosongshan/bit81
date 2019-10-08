#ifndef _SCLIST_H_
#define _SCLIST_H_

#include"common.h"

typedef struct SCListNode
{
	DataType data;
	struct SCListNode *next;
}SCListNode;

typedef struct SCList
{
	SCListNode *first;
	SCListNode *last;
	size_t     size;
}SCList;

SCListNode* _Buynode(DataType x)
{
	SCListNode *s = (SCListNode*)malloc(sizeof(SCListNode));
	//assert(s != NULL);
	if(s == NULL)
		return NULL;
	s->next = NULL;
	s->data = x;
	return s;
}

void SCListInit(SCList *plist);
bool SCListPushBack(SCList *plist, DataType x);
void SCListShow(SCList *plist);
/*
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
*/

void SCListInit(SCList *plist)
{
	SCListNode *s = _Buynode(0);
	plist->first = plist->last = s;
	plist->last->next = plist->first;
	plist->size = 0;
}

bool SCListPushBack(SCList *plist, DataType x)
{
	SCListNode *s = _Buynode(x);
	if(s == NULL)
		return false;

	plist->last->next = s;
	plist->last = s;
	plist->last->next = plist->first; //Ñ­»·

	plist->size++;

	return true;
}

void SCListShow(SCList *plist)
{
	SCListNode *p =plist->first->next;
	while(p != plist->first)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

#endif