#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H

#include"common.h"

#define P 13

typedef struct HashNode
{
	DataType data;
	struct HashNode *link;
}HashNode;

typedef HashNode* HashTable[P];
////////////////////////////////////////////

void HashTableInit(HashTable pht);
HashNode* HashTableFind(HashTable pht, DataType key);
bool HashTableInsert(HashTable pht, DataType x);
bool HashTableRemove(HashTable pht, DataType key);
void HashTableShow(HashTable pht);

int Hash(DataType key)
{
	return (key % P);
}

void HashTableInit(HashTable pht)
{
	for(int i=0; i<P; ++i)
	{
		pht[i] = NULL;
	}
}
bool HashTableInsert(HashTable pht, DataType x)
{
	int index = Hash(x);
	HashNode *s = (HashNode *)malloc(sizeof(HashNode));
	if(s == NULL)
		return false;
	s->data = x;
	s->link = pht[index];
	pht[index] = s;
	return true;
}

HashNode* HashTableFind(HashTable pht, DataType key)
{
	int index = Hash(key);
	HashNode *p = pht[index];
	while(p!=NULL && p->data!=key) 
		p = p->link;
	return p;
}

void HashTableShow(HashTable pht)
{
	for(int i=0; i<P; ++i)
	{
		printf("%d:>", i);
		HashNode *p = pht[i];
		while(p != NULL)
		{
			printf("%d-->", p->data);
			p = p->link;
		}
		printf("Nul.\n");
	}
}

bool HashTableRemove(HashTable pht, DataType key)
{
	HashNode *p = HashTableFind(pht, key);
	if(p == NULL)
		return false;

	//É¾³ý £¿£¿£¿£¿£¿£¿
	int index = Hash(key);
	HashNode *pre = pht[index];
	if(pre == p)
		pht[index] = p->link;
	else
	{
		while(pre->link != p)
			pre = pre->link;
		pre->link = p->link;
	}
	free(p);
	return true;
}

#endif /* _HASH_TABLE_H */