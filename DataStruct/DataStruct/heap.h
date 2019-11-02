#ifndef _HEAP_H_
#define _HEAP_H_

#include"common.h"

typedef struct Heap
{
	DataType *heap;
	size_t    capacity;
	size_t    size;
}Heap;

bool HeapEmpty(Heap *php)
{
	return php->size == 0;
}
bool HeapFull(Heap *php)
{
	return php->size >= php->capacity;
}

void HeapInit(Heap *php, int sz);
void HeapDestroy(Heap *php);
bool HeapInsert(Heap *php, DataType x);
void HeapShow(Heap *php);
DataType HeapTop(Heap *php);
bool HeapRemove(Heap *php);

void _AdjustUp(Heap *php, int start);
void _AdjustDown(Heap *php, int start);

void HeapInit(Heap *php, int sz)
{
	php->capacity = sz;
	php->size = 0;
	php->heap = (DataType*)malloc(sizeof(DataType) * sz);
}

void HeapDestroy(Heap *php)
{
	php->capacity = php->size = 0;
	free(php->heap);
	php->heap = NULL;
}

bool HeapInsert(Heap *php, DataType x)
{
	if(HeapFull(php))
		return false;

	php->heap[php->size] = x;
	_AdjustUp(php, php->size);
	php->size++;
}

void _AdjustUp(Heap *php, int start)
{
	int j = start;
	int i = (j-1)/2;
	while(j > 0)
	{
		if(php->heap[j] < php->heap[i])
		{
			Swap(&(php->heap[j]), &(php->heap[i]));
			j = i;
			i = (j-1)/2;
		}
		else
			break;
	}
}
void HeapShow(Heap *php)
{
	int i;
	for(i=0; i<php->size; ++i)
	{
		printf("%d ", php->heap[i]);
	}
	printf("\n");
}
DataType HeapTop(Heap *php)
{
	if(!HeapEmpty(php))
	{
		return php->heap[0];
	}
}
bool HeapRemove(Heap *php)
{
	if(HeapEmpty(php))
		return false;
	php->heap[0] = php->heap[php->size-1];
	php->size--;
	_AdjustDown(php, 0);
}
void _AdjustDown(Heap *php, int start)
{
	int i = start;
	int j = 2*i+1;
	while(j < php->size)
	{
		if(j+1<php->size && php->heap[j]>php->heap[j+1])
			j++;
		if(php->heap[j] < php->heap[i])
		{
			Swap(&(php->heap[j]), &(php->heap[i]));
			i = j;
			j = 2*i+1;
		}
		else
			break;
	}
}

#endif /* _HEAP_H_ */