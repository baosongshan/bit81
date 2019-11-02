#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

typedef enum {FALSE, TRUE}BOOL;

#define DataType int
void Swap(DataType *a, DataType *b)
{
	DataType tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif
