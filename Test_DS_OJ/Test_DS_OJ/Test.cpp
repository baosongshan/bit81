#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;

 

ListNode* CreateList(int ar[], int n)
{
	 ListNode *head = NULL;
	 ListNode *tail = NULL;
	 for(int i=0; i<n; ++i)
	 {
		 ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		 s->val = ar[i];
		 s->next = NULL;

		 if(head == NULL)
		 {
			 head = tail = s;
		 }
		 else
		 {
			 tail->next = s;
			 tail = tail->next;
		 }
	 }
	 return head;
}

ListNode* deleteDuplication(ListNode* pHead)
{
	 if (pHead == NULL)
		 return NULL;
	 ListNode *pPre = NULL;
	 ListNode *pCur = pHead;
	 ListNode *pNext = pHead->next;
	 while(pNext != NULL)
	 {
		 if(pCur->val != pNext->val)
		 {
			 pPre = pCur;
			 pCur = pNext;
			 pNext = pNext->next;
		 }
		 else
		 {
			 while(pNext && pNext->val==pCur->val)
			 {
				 pNext = pNext->next;
			 }
			 if(pPre != NULL)
				 pPre->next = pNext;
			 else
				 pHead = pNext;

			 while(pCur != pNext)
			 {
				 ListNode *p = pCur;
				 pCur = pCur->next;
				 free(p);
			 }

			 if(pNext != NULL)
				 pNext = pNext->next;
		 }
	 }
	 return pHead;
}

void main()
{
	List mylist = NULL;
	int ar[] = {1, 2, 3, 3, 4, 4, 5};
	//int ar[] = {1, 2, 3, 3, 3, 3, 3};
	//int ar[] = {1, 1, 1, 2, 3, 3, 3, 4, 5, 5, 5};
	//int ar[] = {1, 1, 1, 1, 1, 1, 1};
	//int ar[] = {1, 1, 1, 1, 2, 2, 2};
	int n = sizeof(ar) / sizeof(int);
	mylist = CreateList(ar, n);

	mylist = deleteDuplication(mylist);
}
/*
ListNode* deleteDuplication(ListNode* pHead)
 {
	 if (pHead == NULL)
		 return NULL;
	 ListNode *pPre = NULL;
	 ListNode *pCur = pHead;
	 ListNode *pNext = pHead->next;
	 while (pNext != NULL)
	 {
		 if (pCur->val != pNext->val)
		 {
			 pPre = pCur;
			 pCur = pNext;
			 pNext = pNext->next;
		 }
		 else
		 {
			 while (pNext != NULL && pCur->val == pNext->val)
			 {
				 pCur = pNext;
				 pNext = pNext->next;
			 }

			pCur = pNext;
			if(pNext != NULL)
				pNext = pNext->next;

			ListNode *p, *q;
			if(pPre == NULL)
			{
				q = pPre;
				pPre = pHead;
				pHead = pCur;
			}
			
			p = pPre->next;
			while(p != pCur)
			{
				pPre->next = p->next;
				free(p);
				p = pPre->next;
			}
			if(q==NULL || pPre==NULL)
			{
				free(pPre);
				pPre = NULL;
			}
		 }
	 }
	 return pHead;
 }

 void main()
 {
	 List mylist = NULL;
	 //int ar[] = {1, 2, 3, 3, 4, 4, 5};
	 //int ar[] = {1, 2, 3, 3, 3, 3, 3};
	 int ar[] = {1, 1, 1, 2, 3, 3, 3, 4, 5, 5, 5};
	 //int ar[] = {1, 1, 1, 1, 1, 1, 1};
	 //int ar[] = {1, 1, 1, 1, 2, 2, 2};
	 int n = sizeof(ar) / sizeof(int);
	 mylist = CreateList(ar, n);

	 mylist = deleteDuplication(mylist);
 }

/*
typedef struct TreeNode
{
	char data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

typedef TreeNode* BinTree;

void BinTreeInit(BinTree *t);

void BinTreeInit(BinTree *t)
{
	*t = NULL;
}

void BinTreeCreate(BinTree *t)
{
	char item;
	scanf("%c", &item);
	if(item == '#')
	{
		*t = NULL;
	}
	else
	{
		*t = (TreeNode*)malloc(sizeof(TreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate(&((*t)->left));
		BinTreeCreate(&((*t)->right));
	}
}

///////////////////////////////////////////////////////////////
int Height(struct TreeNode *t)
{
    if(t == NULL)
        return 0;
    else
    {
        int left_h = Height(t->left);
        int right_h = Height(t->right);
        return (left_h > right_h ? left_h : right_h) + 1;        
    }
}
char** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int max_level = Height(root);
    *returnSize = max_level;
    char **levelArray = (char**)malloc(sizeof(int*) * max_level);
    *returnColumnSizes = (int*)malloc(sizeof(int) * max_level);

    struct TreeNode *q1[1000], *q2[1000]; //
    int q1_size=0, q2_size=0;

    q1[0] = root;
    q1_size++;
    int level = 0;
    while(level < max_level)
    {
        levelArray[level] = (char*)malloc(sizeof(int) * q1_size);
        for(int i=0; i<q1_size; ++i)
        {
            levelArray[level][i] = q1[i]->data;
        }
        (*returnColumnSizes)[level] = q1_size;

        for(int i=0; i<q1_size; ++i)
        {
            if(q1[i]->left != NULL)
                q2[q2_size++] = q1[i]->left;
            if(q1[i]->right != NULL)
                q2[q2_size++] = q1[i]->right;
        }

        memcpy(q1, q2, sizeof(struct TreeNode*) * q2_size);
        q1_size = q2_size;
        q2_size = 0;

        level++;
    }
    
    return levelArray;
}


void main()
{
	BinTree bt;
	BinTreeInit(&bt);
	BinTreeCreate(&bt);

	/////////////////////////////////////////////////

	int returnSize = 0;
	int *returnColumnSizes;
	char **result = levelOrder(bt, &returnSize, &returnColumnSizes);
	for(int i=0; i<returnSize; ++i)
	{
		for(int j=0; j<returnColumnSizes[i]; ++j)
		{
			printf("%c \n", result[i][j]);
		}
	}
} 

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    void ConvertList(TreeNode *t, TreeNode **pre)
    {
        if(t == NULL)
            return;
        ConvertList(t->left, pre);
        t->left = *pre;
        if(*pre != NULL)
            (*pre)->right = t;
        *pre = t;
        ConvertList(t->right, pre);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        TreeNode *pre = NULL;
        ConvertList(pRootOfTree, &pre);
        
        TreeNode *pHead = pre;
        while(pHead->left != NULL)
        {
            pHead = pHead->left;
        }
        return pHead;
    }
};

*/