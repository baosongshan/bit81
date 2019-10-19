#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"common.h"

#define DEFAULT_QUEUE_SIZE 8

//顺序队列
typedef struct SeqQueue
{
	DataType *base;
	size_t    capacity;
	int       front;
	int       tail;
}SeqQueue;

bool SeqQueueFull(SeqQueue *Q)
{return Q->tail >= Q->capacity;}
bool SeqQueueEmpty(SeqQueue *Q)
{return Q->front == Q->tail;}

void SeqQueueInit(SeqQueue *Q, int sz);
void SeqQueueEn(SeqQueue *Q, DataType x);
DataType SeqQueueFront(SeqQueue *Q);
void SeqQueueDe(SeqQueue *Q);
void SeqQueueShow(SeqQueue *Q);
void SeqQueueDestroy(SeqQueue *Q);
void SeqQueueInit(SeqQueue *Q, int sz)
{
	Q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	Q->base = (DataType *)malloc(sizeof(DataType)*Q->capacity);
	Q->front = Q->tail = 0;
}

DataType SeqQueueFront(SeqQueue *Q)
{
	if(SeqQueueEmpty(Q))
	{
		printf("队列已空， 不能取对头元素.\n");
		return;
	}
	return Q->base[Q->front];
}

void SeqQueueEn(SeqQueue *Q, DataType x)
{
	if(SeqQueueFull(Q))
	{
		printf("队列已满, %d 不能入队.\n", x);
		return;
	}
	Q->base[Q->tail++] = x;
}

void SeqQueueDe(SeqQueue *Q)
{
	if(SeqQueueEmpty(Q))
	{
		printf("队列已空， 不能出队.\n");
		return;
	}
	Q->front++;
}

void SeqQueueShow(SeqQueue *Q)
{
	for(int i=Q->front; i<Q->tail; ++i)
	{
		printf("%d ", Q->base[i]);
	}
	printf("\n");
}

//C++     malloc  new  free  delete
//内存泄漏
void SeqQueueDestroy(SeqQueue *Q)
{
	free(Q->base);
	Q->base = NULL;
	Q->capacity = Q->front = Q->tail = 0;
}

//循环队列
typedef struct SeqCyQueue
{
	DataType *base;
	size_t    capacity;
	int       front;
	int       tail;
}SeqCyQueue;

bool SeqQueueCyFull(SeqCyQueue *Q)
{
	return (Q->tail+1)%Q->capacity == Q->front;
}
bool SeqQueueCyEmpty(SeqCyQueue *Q)
{
	return Q->front == Q->tail;
}

void SeqQueueCyInit(SeqCyQueue *Q, int sz)
{
	Q->capacity = sz > DEFAULT_QUEUE_SIZE ? sz : DEFAULT_QUEUE_SIZE;
	Q->base = (DataType *)malloc(sizeof(DataType)*Q->capacity);
	Q->front = Q->tail = 0;
}
void SeqQueueCyEn(SeqCyQueue *Q, DataType x)
{
	if(SeqQueueCyFull(Q))
	{
		printf("循环队列已满, %d 不能入队.\n", x);
		return;
	}
	Q->base[Q->tail] = x;
	Q->tail = (Q->tail+1) % Q->capacity;
}
DataType SeqQueueCyFront(SeqCyQueue *Q)
{
	if(SeqQueueCyEmpty(Q))
	{
		printf("队列已空， 不能取对头元素.\n");
		return;
	}
	return Q->base[Q->front];
}
void SeqQueueCyDe(SeqCyQueue *Q)
{
	if(SeqQueueCyEmpty(Q))
	{
		printf("队列已空， 不能出队.\n");
		return;
	}
	Q->front = (Q->front+1) % Q->capacity;
}
void SeqQueueCyShow(SeqCyQueue *Q)
{
	for(int i=Q->front; i!=Q->tail;)
	{
		printf("%d ", Q->base[i]);
		i = (i+1) % Q->capacity;
	}
	printf("\n");
}
void SeqQueueCyDestroy(SeqCyQueue *Q)
{
	free(Q->base);
	Q->base = NULL;
	Q->capacity = Q->front = Q->tail = 0;
}

//链式队列
typedef struct LinkQueueNode
{
	DataType data;
	struct LinkQueueNode *next;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *front;
	LinkQueueNode *tail;
}LinkQueue;

bool LinkQueueEmpty(LinkQueue *Q)
{return Q->front == NULL;}
void LinkQueueInit(LinkQueue *Q);
void LinkQueueEn(LinkQueue *Q, DataType x);
void LinkQueueShow(LinkQueue *Q);
DataType LinkQueueFront(LinkQueue *Q);
void LinkQueueDe(LinkQueue *Q);
void LinkQueueDestroy(LinkQueue *Q);

void LinkQueueInit(LinkQueue *Q)
{
	Q->front = Q->tail = NULL;
}

void LinkQueueEn(LinkQueue *Q, DataType x)
{
	LinkQueueNode *s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	if(LinkQueueEmpty(Q))
	{
		Q->front = Q->tail = s;
	}
	else
	{
		Q->tail->next = s;
		Q->tail = s;
	}
}

void LinkQueueShow(LinkQueue *Q)
{
	LinkQueueNode *p = Q->front;
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

DataType LinkQueueFront(LinkQueue *Q)
{
	if(LinkQueueEmpty(Q))
	{
		printf("队列已空， 不能取对头元素.\n");
		return;
	}
	return Q->front->data;
}

void LinkQueueDe(LinkQueue *Q)
{
	if(LinkQueueEmpty(Q))
	{
		printf("队列已空， 不能出队.\n");
		return;
	}
	LinkQueueNode *p = Q->front;
	Q->front = Q->front->next;
	free(p);
}

void LinkQueueDestroy(LinkQueue *Q)
{
	LinkQueueNode *p = Q->front;
	while(p != NULL)
	{
		Q->front = Q->front->next;
		free(p);
		p = Q->front;
	}
	Q->front = Q->tail = NULL;
}

#endif /* _QUEUE_H_ */