#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<class Type>
class AVLTree;

template<class Type>
class AVLNode
{
	friend class AVLTree<Type>;
public:
	AVLNode(Type d=Type(), AVLNode<Type> *left=nullptr, AVLNode<Type> *right=nullptr)
		:data(d), leftChild(left), rightChild(right), bf(0)
	{}
	~AVLNode()
	{}
public:
	//�����ڴ������Զ��庯��
private:
	Type           data;
	AVLNode<Type> *leftChild;
	AVLNode<Type> *rightChild;
	int            bf; //ƽ������ 0 -1 1 -2 2
};

template<class Type>
class AVLTree
{
public:
	AVLTree() : root(nullptr)
	{}
public:
	bool Insert(const Type &x)
	{
		return Insert(root, x);
	}
	bool Remove(const Type &key)
	{
		return Remove(root, key);
	}
protected:
	bool Insert(AVLNode<Type> *&t, const Type &x);
	bool Remove(AVLNode<Type> *&t, const Type &key);
protected:
	void RotateL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		ptr = ptr->rightChild;
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;

		ptr->bf = subL->bf = 0;
	}
	void RotateR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subR = ptr;
		ptr = ptr->leftChild;
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;

		ptr->bf = subR->bf = 0;
	}
	void RotateLR(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr->leftChild;
		AVLNode<Type> *subR = ptr;
		ptr = subL->rightChild;

		//����ת
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//subL bf
		if(ptr->bf == 1)
			subL->bf = -1;
		else
			subL->bf = 0;

		//����ת
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//subR bf
		if(ptr->bf == -1)
			subR->bf = 1;
		else
			subR->bf = 0;

		ptr->bf = 0;
	}
	void RotateRL(AVLNode<Type> *&ptr)
	{
		AVLNode<Type> *subL = ptr;
		AVLNode<Type> *subR = ptr->rightChild;
		ptr = subR->leftChild;

		//����ת
		subR->leftChild = ptr->rightChild;
		ptr->rightChild = subR;
		//subR bf
		if(ptr->bf >= 0)
			subR->bf = 0;
		else
			subR->bf = 1;

		//����ת
		subL->rightChild = ptr->leftChild;
		ptr->leftChild = subL;
		//subL bf

		if(ptr->bf <= 0)
			subL->bf = 0;
		else
			subL->bf = -1;

		ptr->bf = 0;
	}
private:
	AVLNode<Type> *root;
};

//����ʵ��
template<class Type>
bool AVLTree<Type>::Insert(AVLNode<Type> *&t, const Type &x)
{
	//1���ڵ�Ĳ���,����bst����
	AVLNode<Type> *pr = nullptr; //pr����ǰ�ڵ�ĸ��ڵ�
	AVLNode<Type> *p = t;
	stack<AVLNode<Type>*> st;
	while(p != nullptr)
	{
		if(x == p->data)
			return false;

		pr = p;
		st.push(pr);

		if(x < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	p = new AVLNode<Type>(x);

	//�ж��Ƿ�����Ϊ���ڵ�
	if(pr == nullptr)
	{
		t = p;
		return true;
	}

	//���ӽڵ�
	if(pr->data > x)
		pr->leftChild = p;
	else
		pr->rightChild = p;

	//2��ƽ�����
	while(!st.empty())
	{
		pr = st.top();
		st.pop();
		if(p == pr->leftChild)
			pr->bf--;
		else
			pr->bf++;

		if(pr->bf == 0)
			break;
		if(pr->bf==1 ||pr->bf==-1)
			p = pr;
		else
		{
			//��ת����
			if(pr->bf > 0)
			{
				if(p->bf > 0)   //    \ 
				{
					RotateL(pr);
					//cout<<"RotateL"<<endl;
				}
				else            //    >
				{
					RotateRL(pr);
					//cout<<"RotateRL"<<endl;
				}
			}
			else
			{
				if(p->bf < 0)    //    /
				{
					RotateR(pr);
					//cout<<"RotateR"<<endl;
				}
				else             //   <
				{
					RotateLR(pr); //RotateL(pr), RotateR(pr);
					//cout<<"RotateLR"<<endl;
				}
			}
			break;
		}
	}

	//���¶�pr���Ӹ��ڵ�
	if(st.empty())
		t = pr;
	else
	{
		AVLNode<Type> *ppr = st.top();
		if(ppr->data > pr->data)
			ppr->leftChild = pr;
		else
			ppr->rightChild = pr;
	}

	return true;
}

template<class Type>
bool AVLTree<Type>::Remove(AVLNode<Type> *&t, const Type &key)
{
	AVLNode<Type> *pr = nullptr;
	AVLNode<Type> *p = t, *q;
	stack<AVLNode<Type>*> st;
	while(p != nullptr)
	{
		if(key == p->data)
			break;

		pr = p;
		st.push(pr);
		
		if(key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if(p == nullptr)
		return false;

	if(p->leftChild!=nullptr && p->rightChild!=nullptr)
	{
		pr = p;
		st.push(pr);

		q = p->rightChild;
		while(q->leftChild != nullptr)
		{
			pr = q;
			st.push(pr);
			q = q->leftChild;
		}
		p->data = q->data;
		p = q;
	}

	if(p->leftChild != nullptr)
		q = p->leftChild;
	else
		q = p->rightChild;

	//p��ɾ���ڵ㣬qɾ���ڵ���Ů�ڵ�
	if(pr == nullptr)
		t = q;
	else
	{
		if(p == pr->leftChild)
			pr->leftChild = q;
		else
			pr->rightChild = q;

		//����ƽ��
		while(!st.empty())
		{
			pr = st.top();
			st.pop();

			if(p->data < pr->data)
				pr->bf++;
			else
				pr->bf--;

			if(pr->bf==1 || pr->bf==-1)
				break;

			if(pr->bf != 0)
			{
				//��qָ��ϸ�����
				if(pr->bf < 0)
					q = pr->leftChild;
				else
					q = pr->rightChild;

				if(q->bf == 0)
				{
					if(pr->bf < 0)
					{
						RotateR(pr);
						pr->bf = 1;
						pr->rightChild->bf = -1;
					}
					else
					{
						RotateL(pr);
						pr->bf = -1;
						pr->leftChild->bf = 1;
					}

					if(!st.empty())
					{
						AVLNode<Type> *ppr = st.top();
						if (ppr->data < pr->data)
							ppr->rightChild = pr;
						else
							ppr->leftChild = pr;
					}
					else
						t = pr;
					
					break;
				}

				if(pr->bf < 0)
				{
					if(q->bf < 0)
					{
						RotateR(pr);
					}
					else
					{
						RotateLR(pr);
					}
				}
				else
				{
					if(q->bf > 0)
					{
						RotateL(pr);
					}
					else
					{
						RotateRL(pr);
					}
				}

				if (!st.empty())
				{
					AVLNode<Type> *ppr = st.top();
					if (ppr->data < pr->data)
						ppr->rightChild = pr;
					else
						ppr->leftChild = pr;
				}
				else
					t = pr;
			}

			q = pr;

		}//end while
	}

	delete p;
	return true;
}

int  main()
{
	//vector<int> iv{10, 7, 3, 5, 20, 13, 16, 19, 23, 14};
	//vector<int> iv{10, 70, 300 };

	vector<int> iv{16,3,7,11,9,26,18,14,15};

	AVLTree<int> avl;
	for(const auto &e : iv)
		avl.Insert(e);

	avl.Remove(14);
	avl.Remove(16);
	avl.Remove(15);
	avl.Remove(26);

	avl.Remove(18);

	return 0;
}