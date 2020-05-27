#include<iostream>
#include<vector>
using namespace std;

typedef enum {RED=0, BLACK=1}Color_Type;

template<class Type>
class RBTree;

template<class Type>
class rb_iterator;

template<class Type>
class RBTreeNode
{
	friend class RBTree<Type>;
	friend class rb_iterator<Type>;
public:
	RBTreeNode(const Type &d=Type()) 
		: data(d),leftChild(nullptr),rightChild(nullptr),parent(nullptr),color(RED)
	{}
	~RBTreeNode()
	{}
private:
	Type data;
	RBTreeNode<Type> *leftChild;
	RBTreeNode<Type> *rightChild;
	RBTreeNode<Type> *parent;
	Color_Type        color;
};

template<class Type>
class rb_iterator
{
	typedef rb_iterator<Type> self;
public:
	rb_iterator(RBTreeNode<Type> *p, RBTreeNode<Type> *nil, RBTreeNode<Type> *enode) 
		: node(p),NIL(nil),end_node(enode)
	{}
	Type& operator*()
	{
		return node->data;
	}
	RBTreeNode<Type>* operator->()
	{
		return node;
	}
	
	self& operator++()
	{
		increment();
		return *this;
	}
	self operator++(int);
	self& operator--()
	{
		decrement();
		return *this;
	}
	self operator--(int);

	bool operator==(self & it)
	{
		return node == it.node;
	}
	bool operator!=(self & it)
	{
		return node != it.node;
	}
protected:
	void increment()
	{
		if (node->rightChild != NIL)
		{
			node = node->rightChild;
			if(node == end_node)
				return;
			while (node->leftChild != NIL)
				node = node->leftChild;
		}
		else
		{
			RBTreeNode<Type> *pr = node->parent;
			while (node == pr->rightChild)
			{
				node = pr;
				pr = node->parent;
			}
			node = pr;
		}
	}
	void decrement()
	{
		if(node->leftChild != NIL)
		{
			node = node->leftChild;
			while(node->rightChild != NIL)
				node = node->rightChild;
		}
		else
		{
			RBTreeNode<Type> *pr = node->parent;
			while(node == pr->leftChild)
			{
				node = pr;
				pr = node->parent;
			}
			node = pr;
		}
	}
private:
	RBTreeNode<Type> *node;
	RBTreeNode<Type> *NIL;
	RBTreeNode<Type> *end_node;
};

template<class Type>
class RBTree
{
public:
	typedef rb_iterator<Type> iterator;
	RBTree() : root(NIL), NIL(_Buynode()),end_node(_Buynode())
	{
		NIL->parent = NIL->leftChild = NIL->rightChild = nullptr;
		NIL->color = BLACK;
		end_node->leftChild = end_node->rightChild = end_node->parent = NIL;
	}
public:
	iterator begin()
	{
		RBTreeNode<Type> *p = root;
		while(p!=NIL && p->leftChild!=NIL)
			p = p->leftChild;
		return iterator(p, NIL, end_node);
	}
	iterator end()
	{
		return iterator(end_node, NIL, end_node);
	}
	void set_endnode()
	{
		RBTreeNode<Type> *p = root;
		while(p!=NIL && p->rightChild!=NIL)
			p = p->rightChild;
		p->rightChild = end_node;
		end_node->parent = p;
	}
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
	bool Insert(RBTreeNode<Type> *&t, const Type &x);
	void Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x);
public:
	bool Remove(RBTreeNode<Type> *&t, const Type &key);
	void Remove_FixUp(RBTreeNode<Type> *&t, RBTreeNode<Type> *x);
protected:
	void RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
	void LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p);
protected:
	RBTreeNode<Type>* _Buynode(const Type &x = Type())
	{
		RBTreeNode<Type> *s = new RBTreeNode<Type>(x);
		s->leftChild = s->rightChild = NIL;
		return s;
	}
private:
	RBTreeNode<Type> *NIL;
	RBTreeNode<Type> *root;
	RBTreeNode<Type> *end_node;
};

template<class Type>
bool RBTree<Type>::Insert(RBTreeNode<Type> *&t, const Type &x)
{
	//1 根据bst的规则插入数据
	RBTreeNode<Type> *pr = NIL;
	RBTreeNode<Type> *s = t;
	while(s != NIL)
	{
		if(x == s->data)
			return false;
		pr = s;
		if(x < s->data)
			s = s->leftChild;
		else
			s = s->rightChild;
	}

	s = _Buynode(x);
	if(pr == NIL)
	{
		t = s;
		t->parent = NIL;
	}
	else if(x < pr->data)
		pr->leftChild = s;
	else
		pr->rightChild = s;
	s->parent = pr;

	//2 调整平衡
	Insert_Fixup(t, s);
	return true;
}

template<class Type>
void RBTree<Type>::Insert_Fixup(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
{
	while(x->parent->color == RED)
	{
		RBTreeNode<Type> *s;
		if(x->parent == x->parent->parent->leftChild)//左分支
		{
			s = x->parent->parent->rightChild;
			if(s->color == RED)
			{
				//状况三
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
				continue;
			}
			else if(x == x->parent->rightChild)
			{
				//状况二
				x = x->parent;
				LeftRotate(t, x);
			}
			//状况一
			x->parent->color = BLACK;        //p
			x->parent->parent->color = RED;  //g
			RightRotate(t, x->parent->parent);
		}
		else //右分支
		{
			s = x->parent->parent->leftChild;
			if(s->color == RED)
			{
				x->parent->color = BLACK;
				s->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
				continue;
			}
			else if(x == x->parent->leftChild)
			{
				x = x->parent;
				RightRotate(t, x);
			}
			x->parent->color = BLACK;
			x->parent->parent->color = RED;
			LeftRotate(t, x->parent->parent);
		}
	}
	t->color = BLACK;
}

template<class Type>
bool RBTree<Type>::Remove(RBTreeNode<Type> *&t, const Type &key)
{
	//1 根据bst删除节点
	RBTreeNode<Type> *p = t, *q, *c;
	while(p!=NIL && p->data!=key)
	{
		if(key < p->data)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	if(p == NIL)
		return false;

	//把删除的节点化解为最终只有一个子女节点
	if(p->leftChild!=NIL && p->rightChild!=NIL)
	{
		q = p->rightChild;
		while(q->leftChild != NIL)
			q = q->leftChild;
	}
	else
		q = p;

	if(q->leftChild != NIL)
		c = q->leftChild;
	else
		c = q->rightChild;

	c->parent = q->parent;
	if(q->parent == NIL)
		t = c;
	else if(q = q->parent->leftChild)
		q->parent->leftChild = c;
	else
		q->parent->rightChild = c;

	if(p != q)
		p->data = q->data;

	//2 调整平衡
	if(q->color == BLACK)
		Remove_FixUp(t, c);
	delete q;
	return true;
}

template<class Type>
void RBTree<Type>::Remove_FixUp(RBTreeNode<Type> *&t, RBTreeNode<Type> *x)
{
	RBTreeNode<Type> *w; //兄弟节点
	while(x!=t && x->color==BLACK)
	{
		if(x == x->parent->leftChild) 
		{
			//左分支
			w = x->parent->rightChild;

			//情形四
			if(w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				LeftRotate(t, x->parent);
				w = x->parent->rightChild;
			}

			//情形三
			if(w->leftChild->color==BLACK && w->rightChild->color==BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				//情形二
				//if(w->leftChild->color == RED)
				if (w->rightChild->color == BLACK)
				{
					w->leftChild->color = BLACK;
					w->color = RED;
					RightRotate(t, w);
					w = x->parent->rightChild;
				}
				//情形一
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->rightChild->color = BLACK;
				LeftRotate(t, x->parent);
				x = t;
			}			
		}
		else
		{
			//右分支
			w = x->parent->leftChild;
			//情形四
			if(w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RightRotate(t, x->parent);
				w = x->parent->leftChild;
			}
			//情形三
			if(w->leftChild->color==BLACK && w->rightChild->color==BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				//情形二
				if(w->leftChild->color == BLACK)
				{
					w->rightChild->color = BLACK;
					w->color  = RED;
					LeftRotate(t, w);
					w = x->parent->leftChild;
				}
				//情形一
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->leftChild->color = BLACK;
				RightRotate(t, x->parent);
				x = t;
			}
		}
	}
	x->color = BLACK;
}

template<class Type>
void RBTree<Type>::LeftRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
{
	RBTreeNode<Type> *s = p->rightChild;
	p->rightChild = s->leftChild;
	if(s->leftChild != NIL)
		s->leftChild->parent = p;
	s->parent = p->parent;
	if(p->parent == NIL)
		t = s;
	else if(p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->leftChild = p;
	p->parent = s;
}

template<class Type>
void RBTree<Type>::RightRotate(RBTreeNode<Type> *&t, RBTreeNode<Type> *p)
{
	RBTreeNode<Type> *s = p->leftChild;
	p->leftChild = s->rightChild;
	if(s->rightChild != NIL)
		s->rightChild->parent = p;
	s->parent = p->parent;
	if(p->parent == NIL)
		t = s;
	else if(p == p->parent->leftChild)
		p->parent->leftChild = s;
	else
		p->parent->rightChild = s;
	s->rightChild = p;
	p->parent = s;
}


void main()
{
	vector<int> iv {10, 7, 8, 15, 5, 6, 11};
	//vector<int> iv {10, 7, 8};
	RBTree<int> rb;
	for(const auto &e : iv)
		rb.Insert(e);

	rb.Remove(10);

}
/*
void main()
{
	vector<int> iv {10, 7, 8, 4, 2, 20, 15, 11,12,13};
	//vector<int> iv {10, 7, 8};
	RBTree<int> rb;
	for(const auto &e : iv)
		rb.Insert(e);
	rb.set_endnode();

	auto it = rb.end();
	--it;
	while(it != rb.begin())
	{
		cout<<*it<<" ";
		--it;
	}
	cout<<*it;
	cout<<endl;
}
*/