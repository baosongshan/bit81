#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"common.h"

#define SEQLIST_DEFAULT_SIZE 8

typedef struct SeqList
{
	DataType *base;
	size_t    capacity;
	size_t    size;
}SeqList;

//申明
void SeqListInit(SeqList *psl, int sz);
bool SeqListPushBack(SeqList *psl, DataType x);
bool SeqListPushFront(SeqList *psl, DataType x);
size_t SeqListLength(SeqList *psl);
void SeqListModifyByPos(SeqList *psl, int pos, DataType x);

bool SeqListIsFull(SeqList *psl)
{return psl->size >= psl->capacity;}
bool SeqListIsEmpty(SeqList *psl)
{return psl->size == 0;}
////////////////////////////////////////////////////
//实现
void SeqListInit(SeqList *psl, int sz)
{
	psl->capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
	psl->base = (DataType*)malloc(sizeof(DataType)*(psl->capacity));
	psl->size = 0;
}

bool SeqListPushBack(SeqList *psl, DataType x) 
{
	assert(psl != NULL);
	if(SeqListIsFull(psl))
	{
		printf("顺序表已满, %d 不能插入.\n",x);
		return false;
	}
	psl->base[psl->size++] = x;
	return true;
}

bool SeqListPushFront(SeqList *psl, DataType x)
{
	assert(psl != NULL);
	if(SeqListIsFull(psl))
	{
		printf("顺序表已满, %d 不能插入.\n",x);
		return false;
	}
	for(int i=psl->size; i>0; --i)
	{
		psl->base[i] = psl->base[i-1];
	}
	psl->base[0] = x;
	psl->size++;
	return true;
}

void SeqListShow(SeqList *psl)
{
	for(int i=0; i<psl->size; ++i)
	{
		printf("%d ", psl->base[i]);
	}
	printf("\n");
}
size_t SeqListLength(SeqList *psl)
{
	assert(psl != NULL);
	return psl->size;
}

#endif