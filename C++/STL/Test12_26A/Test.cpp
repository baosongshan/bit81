#include<iostream>
#include<assert.h>
using namespace std;

//STL _内部方法
//    p 前面


//list
template<class _Ty>
class list
{
public:
	//类型的萃取
	typedef size_t          size_type;
	typedef size_t          difference_type;
	typedef _Ty*            pointer;
	typedef const _Ty*      const_pointer;
	typedef _Ty&            reference;
	typedef const _Ty&      const_reference;
	typedef _Ty             value_type;
public:
	struct _Node;
	typedef _Node* _Nodeptr;
	struct _Node 
	{
		_Nodeptr _Next, _Prev;
		_Ty _Value;
	};
	struct _Acc //?????  3glt
	{
		typedef _Node* & _Nodepref;
		typedef _Ty&     _Vref;
		static _Nodepref _Next(_Nodeptr _P)
			{return ((_Nodepref)(*_P)._Next); }
		static _Nodepref _Prev(_Nodeptr _P)
			{return ((_Nodepref)(*_P)._Prev); }
		static _Vref _Value(_Nodeptr _P)
			{return ((_Vref)(*_P)._Value); }
	};
public:
	//内部类  迭代器
	class iterator
	{
	public:
		iterator():_Ptr(NULL)
		{}
		iterator(_Nodeptr _P) : _Ptr(_P)
		{}
	public:
		bool operator!=(const iterator &it)
		{
			return (_Ptr != it._Ptr);
		}
		_Ty& operator*()
		{
			return _Ptr->_Value;
		}
		iterator& operator++()
		{
			_Ptr = _Ptr->_Next;
			return *this;
		}
		_Nodeptr _Mynode()
		{
			return _Ptr;
		}
	protected:
		_Nodeptr _Ptr;
	};

public:
	explicit list():_Head(_Buynode()), _Size(0) 
	{}
public:
	iterator begin()
	{
		return iterator(_Acc::_Next(_Head));
	}
	iterator end()
	{
		return iterator(_Head);
	}
public:
	void push_back(const _Ty& _X)
	{insert(end(), _X);}
	void push_front(const _Ty & _X)
	{insert(begin(), _X);}
public:
	iterator insert(iterator _P, const _Ty& _X = _Ty())
	{
		_Nodeptr _S = _P._Mynode();
		_Acc::_Prev(_S) = _Buynode(_S, _Acc::_Prev(_S));
		_S = _Acc::_Prev(_S);
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Value(_S) =  _X;
		++_Size;
		return (iterator(_S));
	}
protected:
	_Nodeptr _Buynode(_Nodeptr _Narg = 0, _Nodeptr _Parg = 0)
	{
		_Nodeptr _S = (_Node*)malloc(sizeof(_Node));
		_Acc::_Next(_S) = _Narg!=0 ? _Narg : _S;
		_Acc::_Prev(_S) = _Parg!=0 ? _Parg : _S;
		return (_S); 
	}
private:
	_Nodeptr _Head;
	size_type _Size;
};

void main()
{
	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	mylist.push_back(5);
	mylist.push_front(10);

	list<int>::iterator it = mylist.begin();
	while(it != mylist.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Over."<<endl;
}


/*
void push_back(const _Ty& _X)
	{
		_Node *_S = _Buynode(_Head, _Acc::_Prev(_Head));
		_Acc::_Value(_S) = _X;
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Prev(_Head) = _S;
		_Size++;
	}

void push_back(const _Ty& _X)
	{
		_Node *_S = _Buynode();
		_Acc::_Value(_S) = _X;
		_Acc::_Prev(_S) = _Acc::_Prev(_Head);
		_Acc::_Next(_Acc::_Prev(_S)) = _S;
		_Acc::_Next(_S) = _Head;
		_Acc::_Prev(_Head) = _S;
		_Size++;
	}

void PrintList(list<int> &lt)
{
	list<int>::iterator it = lt.begin();
	while(it != lt.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Over."<<endl;
}

class Test
{};

void main()
{
	list<Test> lt;
	list<int> mylist;
	for(int i=1; i<=10; ++i)
	{
		mylist.push_back(i);
	}
	PrintList(mylist);
	mylist.pop_front();
	PrintList(mylist);
	mylist.pop_back();
	PrintList(mylist);
	reverse(mylist.begin(), mylist.end());
	PrintList(mylist);
	
}

/*
template<typename Type>
class ListNode
{
private:
	Type data;
	ListNode<Type> *next;
};
template<typename Type>
class List
{
public:
	List() : _head(nullptr)
	{}
public:
	void push_back();
	void push_front();
	//..........
private:
	ListNode<Type> *_head;
};

void main()
{
	List<int> mylist;
	List<char> youlist;
}
*/