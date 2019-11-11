#include"seqlist.h"
//#include"slist.h"
//#include"sclist.h"
//#include"dlist.h"
//#include"dclist.h"
//#include<vld.h>
//#include"stack.h"
//#include"queue.h"

//#include"bintree.h"
//#include"heap.h"
//#include"bst.h"
//#include"sort.h"

//#include"hashtable.h"

//现在有一个用来存放整数的Hash表，Hash表的存储单位称为桶，
//每个桶能放3个整数，当一个桶中要放的元素超过3个时，
//则要将新的元素存放在溢出桶中，每个溢出桶也能放3个元素，
//多个溢出桶使用链表串起来。此Hash表的基桶数目为素数P，
//Hash表的hash函数对P取模。代码定义如下：

#define P 7
#define NULL_DATA -1
struct bucket_node	
{
	int data[3];
	struct bucket_node *next;
};
struct bucket_node hash_table[P];

//现在假设hash_table已经初始化好了，
//insert_new_element()函数目的是把一个新的值插入hash_table中，
//元素插入成功时，函数返回0，否则返回-1，完成函数。

int insert_new_element(int new_element)
{

}
////////////////////////////////////////////////
int main()
{
	Init_bucket_node(); //
	int array[] = {15,14,21,87,96,293,35,24,149,19,63,16,103,77,5,153,145,356,51,68,705,453 };
	for(int i = 0; i < sizeof(array)/sizeof(int); i++)
	{
		Insert_new_element(array[i]);
	}
	return 0;
}



/*
void main()
{
	int ar[] = {49, 10, 32, 54,38, 65,97, 76, 13,27};
	int n = sizeof(ar) / sizeof(int);
	HashTable ht; //int a;
	HashTableInit(ht); //&a

	for(int i=0; i<n; ++i)
	{
		HashTableInsert(ht, ar[i]);
	}
	HashTableShow(ht);
	printf("=================\n");
	HashTableRemove(ht, 65);
	HashTableShow(ht);
}

/*
void main()
{
	//int ar[] = {49, 38, 65,97, 76, 13,27, 49};
	//int ar[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3 ,5};
	//int ar[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
	//int ar[] = {10, 6, 7, 1, 3, 9, 4, 2};
	int ar[] = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
	int n = sizeof(ar) / sizeof(int);
	PrintArray(ar, 0, n-1);
	TestSort(ar, 0, n-1);
	TestSrotEfficiency();
}

/*
int Compare(const void *e1, const void *e2)
{
	const int *elem1 = (const int*)e1;
	const int *elem2 = (const int*)e2;
	return (*elem1 - *elem2);
}

void main()
{
	//int ar[] = {49, 38, 65,97, 76, 13,27, 49};
	int ar[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3 ,5};
	qsort(ar, 10, sizeof(int), Compare);
}

/*
void main()
{
	//int ar[] = {49, 38, 65,97, 76, 13,27, 49};
	int ar[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3 ,5};
	//int ar[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
	int n = sizeof(ar) / sizeof(int);
	PrintArray(ar, 0, n-1);
	TestSort(ar, 0, n-1);
	TestSrotEfficiency();
}


/*
int main()
{
	BSTree bst;
	int i;
	int j = 0;
	int ar[] = {45, 10, 24, 53, 12, 38, 21, 90, 30};
	int n = sizeof(ar) / sizeof(int);
	BSTreeInit(&bst);

	for(i=0; i<n; ++i)
	{
		Insert(&bst, ar[i]);
	}

	printf("Min = %d\n", Min(bst));
	printf("Max = %d\n", Max(bst));

	Remove(&bst, 45);

	return 0;
}

/*
int main()
{
	BSTree bst;
	int i;
	int j = 0;
	int ar[] = {45, 10, 24, 53, 12, 38, 21, 90, 30};
	int n = sizeof(ar) / sizeof(int);
	BSTreeInit(&bst);

	for(i=0; i<n; ++i)
	{
		Insert(&bst, ar[i]);
	}

	Sort(bst, ar, &j);
	return 0;
}

/*
void main()
{
	int ar[] = {27, 15,19, 18, 28, 34, 65, 49, 25, 37};
	int n = sizeof(ar) / sizeof(int);
	Heap hp;
	int i;
	HeapInit(&hp, n);

	for(i=0; i<n; ++i)
	{
		HeapInsert(&hp, ar[i]);
	}

	HeapShow(&hp);

	HeapRemove(&hp);
	HeapShow(&hp);

	HeapRemove(&hp);
	HeapShow(&hp);

	HeapDestroy(&hp);
}


/*
int main()
{
	//char *str = "ABC##DE##F##G#H##";
	//char *str1 = "ABC##D#F##GE##H##";
	char *vlr = "ABCDEFGH";
	char *lvr = "CBEDFAGH";
	char *lrv = "CEFDBHGA";
	int n = strlen(lvr);
	int i = 0, j = 0;
	BinTree bt,bt1;
	BinTreeInit(&bt);
	BinTreeInit(&bt1);
	//BinTreeCreate(&bt);
	//BinTreeCreateByStr(&bt, str, &i);
	//BinTreeCreateByStr(&bt1, str1, &j);
	//BinTreeCreateBy_VLR_LVR(&bt, vlr, lvr, n);
	BinTreeCreateBy_LVR_LRV(&bt, lvr, lrv, n);

	printf("VLR   :");
	PreOrder(&bt);
	printf("\n");
	printf("VLR NR:");
	PreOrderNoR(&bt);
	printf("\n");
	printf("\n");

	printf("LVR   :");
	InOrder(&bt);
	printf("\n");
	printf("LVR NR:");
	InOrderNoR(&bt);
	printf("\n");
	printf("\n");

	printf("LRV   :");
	PostOrder(&bt);
	printf("\n");
	printf("LRV NR:");
	PostOrderNoR(&bt);
	printf("\n");
	printf("\n");


	printf("Level:");
	LevelOrder(&bt);
	printf("\n");

	printf("Size = %d\n", Size(&bt));
	printf("Hegith = %d\n", Height(&bt));

	BinTreeNode *p = Find(&bt, 'B');
	p = Parent(&bt, 'H');

	//Clone(&bt, &bt1);
	bool flag = Equal(&bt, &bt1);

	return 0;
}

/*
int main()
{
	LinkQueue LQ;
	LinkQueueInit(&LQ);
	LinkQueueEn(&LQ, 1);
	LinkQueueEn(&LQ, 2);
	LinkQueueEn(&LQ, 3);
	LinkQueueEn(&LQ, 4);
	LinkQueueEn(&LQ, 5);

	LinkQueueShow(&LQ);

	LinkQueueDestroy(&LQ);
	return 0;
}

/*
int main()
{
	SeqCyQueue CQ;
	SeqQueueCyInit(&CQ, 8);
	SeqQueueCyEn(&CQ, 1);
	SeqQueueCyEn(&CQ, 2);
	SeqQueueCyEn(&CQ, 3);
	SeqQueueCyEn(&CQ, 4);
	SeqQueueCyEn(&CQ, 5);

	SeqQueueCyShow(&CQ);
	SeqQueueCyDe(&CQ);
	SeqQueueCyDe(&CQ);
	SeqQueueCyShow(&CQ);

	SeqQueueCyEn(&CQ, 6);
	SeqQueueCyEn(&CQ, 7);
	SeqQueueCyEn(&CQ, 8);
	SeqQueueCyEn(&CQ, 9);

	SeqQueueCyShow(&CQ);

	SeqQueueCyEn(&CQ, 19);

	return 0;
}

/*
int main()
{
	SeqQueue Q;//
	SeqQueueInit(&Q, DEFAULT_QUEUE_SIZE);
	SeqQueueEn(&Q, 1); //
	SeqQueueEn(&Q, 2);
	SeqQueueEn(&Q, 3);
	SeqQueueEn(&Q, 4);
	SeqQueueEn(&Q, 5);
	SeqQueueShow(&Q);

	SeqQueueDe(&Q);
	SeqQueueDe(&Q);

	SeqQueueShow(&Q);

	SeqQueueEn(&Q, 6);
	SeqQueueEn(&Q, 7);
	SeqQueueEn(&Q, 8);
	SeqQueueEn(&Q, 9);

	SeqQueueDestroy(&Q);

	return 0;
}


/*
int main()
{
	ListStack st; 
	ListStackInit(&st);
	ListStackPush(&st, 1);
	ListStackPush(&st, 2);
	ListStackPush(&st, 3);
	ListStackShow(st);
	printf("==============\n");
	ListStackPop(&st);
	ListStackShow(st);



	return 0;
}

/*
int main()
{
	SeqStack st;
	SeqStackInit(&st, STACK_DEFAULT_SIZE);
	//SeqStack *pst = SeqStackCreate(STACK_DEFAULT_SIZE);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackPush(&st, 6);
	SeqStackPush(&st, 7);
	SeqStackPush(&st, 8);

	int val = SeqStackTop(&st);
	SeqStackPop(&st);

	SeqStackPush(&st, 9);

	SeqStackShow(&st);

	return  0;
}

/*
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

typedef Node* List;


void InitList(List *head)
{
	*head = (Node*)malloc(sizeof(Node));
	(*head)->next = NULL;
}

void CreateList(List *head)
{
	Node *p = *head;
	for(int i=1; i<=5; ++i)
	{
		Node *s = (Node*)malloc(sizeof(Node));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}

struct Node* middleNode(struct Node* head)
{
    int nodeCount = 0;
    struct Node *p = head->next;
    while(p != NULL)
    {
        nodeCount++;
        p = p->next;
    }

    p = head->next;
    for(int i=0; i<nodeCount/2; ++i)
        p = p->next;
    return p;
}

int main()  //主函数  主线程
{
	List mylist;
	InitList(&mylist);
	CreateList(&mylist);

	struct Node *p = middleNode(mylist);
	return 0;
}

/*
int main()
{
	//SeqList mylist;
	//SeqListInit(&mylist, SEQLIST_DEFAULT_SIZE);

	//SList mylist;
	//SListInit(&mylist);

	//SCList mylist;
	//SCListInit(&mylist);

	//DList mylist;
	//DListInit(&mylist);

	DCList mylist;
	DCListInit(&mylist);



	DCListNode *p;

	int pos;
	int select = 1;
	DataType item, key;
	DataType ret;
	bool flag;
	while(select)
	{
		printf("*****************************************\n");
		printf("* [1] push_back         [2] push_front  *\n");
		printf("* [3] show_list         [0] quit_system *\n");
		printf("* [4] pop_back          [5] pop_front   *\n");
		printf("* [6] insert_pos        [7] insert_val  *\n");
		printf("* [8] delete_pos        [9] delete_val  *\n");
		printf("* [10] find_pos         [11] find_val   *\n");
		printf("* [12] sort             [13] reverse    *\n");
		printf("* [14] length           [15] clear      *\n");
		printf("* [16] modify_pos       [17] modify_val *\n");
		printf("* [18] capacity                         *\n");
		printf("*****************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;
		switch(select)
		{
		case 1:
			printf("请输入要插入的数据<-1结束>:>");
			while(scanf("%d", &item), item!=-1)
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<-1结束>:>");
			while(scanf("%d", &item), item!=-1)
			{
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			//SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist,item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListDeleteByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &key);
			DCListDeleteByVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的位置:>");
			scanf("%d", &pos);
			//flag = SeqListFindByPos(&mylist, pos, &ret); //true false
			if(flag)
				printf("查找的数据为:> %d\n", ret);
			else
				printf("查找的数据不存在.\n");
			break;
		case 11:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = DCListFindByVal(&mylist, key);
			if(pos == -1)
				printf("查找的数据不存在.\n");
			else
				printf("数据所在的下标为:> %d\n", pos);
			break;
		case 12:
			DCListSort(&mylist);
			break;
		case 13:
			DCListReverse(&mylist);
			break;
		case 14:
			//printf("SeqList Length = %d\n", SListLength(&mylist));
			break;
		case 15:
			DCListClear(&mylist);
			break;
		case 18:
			//printf("capacity = %d\n", SeqListCapacity(&mylist));
			break;
		default:
			printf("输入错误，请重新输入......\n");
			break;
		}
		system("pause");
		system("cls"); 
	}

	DCListDestroy(&mylist);
	return 0;
}
*/