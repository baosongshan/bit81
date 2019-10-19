#include"seqlist.h"
//#include"slist.h"
//#include"sclist.h"
//#include"dlist.h"
//#include"dclist.h"
//#include<vld.h>
//#include"stack.h"
#include"queue.h"

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