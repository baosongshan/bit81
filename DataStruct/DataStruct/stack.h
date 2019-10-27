#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"

#define STACK_DEFAULT_SIZE 8
#define STACK_INC_SIZE 5

//顺序栈
typedef struct SeqStack
{
	DataType *base;
	size_t    capacity;
	int       top;
}SeqStack;

BOOL SeqStackFull(SeqStack *pst) 
{
	if(pst->top >= pst->capacity) 
		return TRUE;
	return FALSE;
}
BOOL SeqStackEmpty(SeqStack *pst)
{
	if(pst->top == 0)
		return TRUE;
	return FALSE;
}

void SeqStackInit(SeqStack *pst, int sz);
SeqStack* SeqStackCreate(int sz);
DataType SeqStackTop(SeqStack *pst);
void SeqStackPush(SeqStack *pst, DataType x);
void SeqStackPop(SeqStack *pst);
void SeqStackShow(SeqStack *pst);

void SeqStackInit(SeqStack *pst, int sz)
{
	pst->capacity = 
		sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType)*pst->capacity);
	pst->top = 0;
}

SeqStack* SeqStackCreate(int sz)
{
	SeqStack *pst = (SeqStack*)malloc(sizeof(SeqStack));
	pst->capacity = 
		sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType)*pst->capacity);
	pst->top = 0;
	return pst;
}

DataType SeqStackTop(SeqStack *pst)
{
	if(SeqStackEmpty(pst))
	{
		printf("栈已空，不能取栈顶元素.\n");
		return;
	}
	return pst->base[pst->top-1];
}

void SeqStackPush(SeqStack *pst, DataType x)
{
	if(SeqStackFull(pst))
	{
		printf("栈已满，%d 不能入栈.\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack *pst)
{
	if(SeqStackEmpty(pst))
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	pst->top--;
}

void SeqStackShow(SeqStack *pst)
{
	for(int i=pst->top-1; i>=0; --i)
		printf("%d\n", pst->base[i]);
}

void SeqStackDestroy(SeqStack *pst)
{
	free(pst);
	free(pst->base);
}

//链栈
#include"bintree.h"
#define StackDataType BinTreeNode* 

typedef struct StackNode
{
	StackDataType data;
	struct StackNode *next;
}StackNode;

typedef StackNode* ListStack;

bool ListStackEmpty(ListStack *pst)
{
	return *pst == NULL;
}
void ListStackInit(ListStack *pst);
StackDataType ListStackTop(ListStack *pst);
void ListStackPush(ListStack *pst, StackDataType x);
void ListStackPop(ListStack *pst);
void ListStackShow(ListStack pst);

void ListStackInit(ListStack *pst)
{
	*pst = NULL;
}

StackDataType ListStackTop(ListStack *pst)
{
	assert(*pst != NULL);//
	return (*pst)->data;
}

void ListStackPush(ListStack *pst, StackDataType x)
{
	StackNode *node = (StackNode*)malloc(sizeof(StackNode));
	assert(node != NULL);
	node->data = x;

	node->next = *pst;
	*pst = node;
}

void ListStackPop(ListStack *pst)
{
	StackNode *p = *pst;
	*pst = p->next;
	free(p);
}


void ListStackShow(ListStack pst)
{
	StackNode *p = pst;
	while(p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}


#endif