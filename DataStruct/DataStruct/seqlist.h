#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"common.h"

#define SEQLIST_DEFAULT_SIZE 8
#define SEQLIST_INC_SIZE 5

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
size_t SeqListCapacity(SeqList *psl);
bool SeqListModifyByPos(SeqList *psl, int pos, DataType x);
bool SeqListModifyByVal(SeqList *psl, DataType key, DataType x);

bool SeqListPopBack(SeqList *psl);
bool SeqListPopFront(SeqList *psl);
bool SeqListInsertByPos(SeqList *psl, int pos, DataType x);
bool SeqListInsertByVal(SeqList *psl, DataType x);
void SeqListClear(SeqList *psl);
void SeqListDestroy(SeqList *psl);

bool SeqListFindByPos(SeqList *psl, int pos, DataType *ret);
int  SeqListFindByVal(SeqList *psl, DataType key);

bool SeqListDeleteByPos(SeqList *psl, int pos);
bool SeqListDeleteByVal(SeqList *psl, DataType key);

void SeqListSort(SeqList *psl);
void SeqListReverse(SeqList *psl);

bool SeqListIsFull(SeqList *psl)
{return psl->size >= psl->capacity;}
bool SeqListIsEmpty(SeqList *psl)
{return psl->size == 0;}

bool _SeqListInc(SeqList *psl)
{
	assert(psl != NULL);
	psl->base = realloc(psl->base, sizeof(DataType)*(psl->capacity+SEQLIST_INC_SIZE));
	if(psl->base == NULL)
		return false;
	psl->capacity += SEQLIST_INC_SIZE;//2
	return true;
}
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
	if(SeqListIsFull(psl) && !_SeqListInc(psl))//2
	{
		printf("push_back:顺序表已满, %d 不能插入.\n",x);
		return false;
	}
	psl->base[psl->size++] = x;
	return true;
}

bool SeqListPushFront(SeqList *psl, DataType x)
{
	assert(psl != NULL);
	if(SeqListIsFull(psl) && !_SeqListInc(psl))
	{
		printf("push_front:顺序表已满, %d 不能插入.\n",x);
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
size_t SeqListCapacity(SeqList *psl)
{
	assert(psl != NULL);
	return psl->capacity;
}

bool SeqListPopBack(SeqList *psl)
{
	assert(psl != NULL);
	if(SeqListIsEmpty(psl))
	{
		printf("顺序表已空，不能尾删.\n");
		return false;
	}
	psl->size--;
	return true;
}

bool SeqListPopFront(SeqList *psl)
{
	assert(psl != NULL);
	if(SeqListIsEmpty(psl))
	{
		printf("顺序表已空，不能头删.\n");
		return false;
	}

	for(int i=0; i<psl->size-1; ++i)
	{
	   psl->base[i] = psl->base[i+1];
	}
	psl->size--;
	return true;
}

bool SeqListInsertByPos(SeqList *psl, int pos, DataType x)
{
	assert(psl != NULL);
	if(SeqListIsFull(psl) && !_SeqListInc(psl))
	{
		printf("insert_pos:顺序表已满, %d 不能插入.\n",x);
		return false;
	}
	if(pos<0 || pos>psl->size)
	{
		printf("插入的位置不合法.\n");
		return false;
	}

	for(int i=psl->size; i>pos; --i)
	{
		psl->base[i] = psl->base[i-1];
	}
	psl->base[pos] = x;
	psl->size++;
	return true;
}

bool SeqListInsertByVal(SeqList *psl, DataType x)
{
	assert(psl != NULL);
	if(SeqListIsFull(psl) && !_SeqListInc(psl ))
	{
		printf("insert_val:顺序表已满, %d 不能插入.\n",x);
		return false;
	}
	int i;
	for(i=psl->size-1; i>=0&&x<psl->base[i]; --i)
	{
		psl->base[i+1] = psl->base[i];
	}
	psl->base[i+1] = x;
	psl->size++;
	return true;
}

void SeqListClear(SeqList *psl)
{
	assert(psl != NULL);
	psl->size = 0;
}
void SeqListDestroy(SeqList *psl)
{
	free(psl->base);
	psl->base = NULL;
	psl->capacity = psl->size = 0;
}


bool SeqListFindByPos(SeqList *psl, int pos, DataType *ret)
{
	assert(psl != NULL);
	if(pos<0 || pos>psl->size-1)
	{
		printf("要查找的位置不合法.\n");
		return false;
	}
	*ret = psl->base[pos];
	return true;
}

int SeqListFindByVal(SeqList *psl, DataType key)
{
	assert(psl != NULL);
	for(int i=0; i<psl->size; ++i)
	{
		if(psl->base[i] == key)
			return i;
	}
	return -1;
}

bool SeqListModifyByPos(SeqList *psl, int pos, DataType x)
{
	assert(psl != NULL);
	if(pos<0 || pos>psl->size-1)
	{
		printf("修改的位置不合法.\n");
		return false;
	}
	psl->base[pos] = x;
	return true;
}

bool SeqListModifyByVal(SeqList *psl, DataType key, DataType x)
{
	int index = SeqListFindByVal(psl, key);
	if(index == -1)
		return false;
	psl->base[index] = x;
	return true;
}


bool SeqListDeleteByPos(SeqList *psl, int pos)
{
	assert(psl != NULL);
	if(pos<0 || pos>psl->size-1)
	{
		printf("要查找的位置不合法.\n");
		return false;
	}
	for(int i=pos; i<psl->size-1; ++i)
	{
		psl->base[i] = psl->base[i+1];
	}
	psl->size--;
	return true;
}

bool SeqListDeleteByVal(SeqList *psl, DataType key)
{
	assert(psl != NULL);
	int index = SeqListFindByVal(psl, key);
	if(index == -1)
	{
		printf("要删除的数据不存在.\n");
		return false;
	}
	return SeqListDeleteByPos(psl, index);
}

void SeqListSort(SeqList *psl)
{
	for(int i=0; i<psl->size-1; ++i)
	{
		for(int j=0; j<psl->size-i-1; ++j)
		{
			if(psl->base[j] > psl->base[j+1])
			{
				Swap(&(psl->base[j]), &(psl->base[j+1]));
			}
		}
	}
}

void SeqListReverse(SeqList *psl)
{
	assert(psl != NULL);
	int begin  = 0;
	int end = psl->size-1;
	while(begin < end)
	{
		Swap(&(psl->base[begin]), &(psl->base[end]));
		begin++;
		end--;
	}
}

#endif