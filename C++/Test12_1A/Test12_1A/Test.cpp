#include<iostream>
#include<stdio.h>
#include"datetime.h"
using namespace std;


void main()
{
	CDateTime dt;
	//cout<<dt<<endl;
	dt.DShowDateTime();

	//dt1 = dt + 100
}


/*
class List;
class ListNode
{
	friend class List;
public:
	ListNode():m_data(0), next(nullptr)
	{}
	ListNode(int data, ListNode *n=nullptr) 
		: m_data(data), next(n)
	{}
	~ListNode()
	{}
private:
	int m_data;
	ListNode *next;
};

class List
{
public:
	List() : head(nullptr)
	{}
public:
	void push_back(const int &x)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		s->m_data = x;
		s->next = nullptr;

		if(head == nullptr)
			head = s;
		else
		{
			ListNode *p = head;
			while(p->next != nullptr)
				p = p->next;
			p->next = s;
		}
	}
public:
	//内部类
	class iterator
	{
	public:
		iterator(ListNode *p=nullptr) : ptr(p)
		{}
	public:
		iterator begin()
		{
			return ptr;
		}
 	private:
		ListNode *ptr;
	};
private:
	ListNode *head;
};

void main()
{
	List mylist;
	
	List::iterator it;
	it.begin();
}


/*
typedef struct Test
{
	int a;
	struct tmp
	{
		short b;
		double c;
		char d;
	};
	long e;
}Test;

void main()
{
	///cout<<sizeof(Test)<<endl;
	printf("%d\n",sizeof(Test));
	Test::tmp t;
}


/*
class List;
class ListNode
{
	friend class List;
public:
	ListNode():m_data(0), next(nullptr)
	{}
	ListNode(int data, ListNode *n=nullptr) 
		: m_data(data), next(n)
	{}
	~ListNode()
	{}
private:
	int m_data;
	ListNode *next;
};

class List
{
public:
	List() : head(nullptr)
	{}
public:
	void push_back(const int &x)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		s->m_data = x;
		s->next = nullptr;

		if(head == nullptr)
			head = s;
		else
		{
			ListNode *p = head;
			while(p->next != nullptr)
				p = p->next;
			p->next = s;
		}
	}
public:
	class iterator
	{
	public:
		iterator(ListNode *p) : ptr(p)
		{}
	public:
		iterator begin()
		{
			return ptr;
		}
 	private:
		ListNode *ptr;
	};
private:
	ListNode *head;
};

void main()
{
	List mylist;
}

/*
void main()
{
	List mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);
	mylist.push_back(5);
}

/*
class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	//ostream& operator<<(ostream &out)
	//{
	//	out<<m_data;
	//	return out;
	//}
public:
	//1 构造对象
	//2 初始化对象
	//3 类型转换
	explicit Test(int data = 0) 
		: m_data(data)
	{
		m_count++;
	}
	Test& operator=(const Test &t)
	{
		if(this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		m_count--;
	}
public:
	void Increment_Count()
	{
		m_count++;
	}

public:
	
public:
	void fun()
	{
		GetUseCount();
	}
	static int GetUseCount()  //this
	{
		//fun();
		return m_count;
	}
private:
	int m_data; 
	static int m_count ;  //
};

/////////////////////////////////////////
int Test::m_count = 0;
////////////////////////////////////////

ostream& operator<<(ostream &out, const Test &t)
{
	out<<t.m_data;
	return out;
}

void main()
{
	Test t(100);
	//t<<cout<<endl; //t.operator<<(cout)
	cout<<"t = "<<t<<endl;
}

/*
ostream& operator<<(ostream &out, const Test &t)
{
	out<<t.m_data;
	return out;
}

void main()
{
	Test t(100);
	cout<<"t = "<<t<<endl;
}

/*
void main()
{
	cout<<Test::GetUseCount()<<endl;
	Test t1;
	Test t2;
	cout<<Test::GetUseCount()<<endl;
	{
		Test t3;
		cout<<Test::GetUseCount()<<endl;
	}
	cout<<t1.GetUseCount()<<endl;

	//cout<<t2.GetUseCount()<<endl;

	//t1.Increment_Count();
	//t2.Increment_Count();
}

/*
void main()
{
	Test t;
	cout<<"t = "<<t<<endl;
	t = (Test)100;  
	cout<<"t = "<<t<<endl;

	int value = t;
	cout<<"value = "<<value<<endl;

}

/*
class Test
{
public:
	Test(int value, int data, int count)
		: m_count(count), m_data(data),m_value(value) 
	{}
	~Test()
	{}
private:
	int m_value;
	int m_count;
	int m_data;
};

void main()
{
	Test t(0,0,0);
}

/*
class Base
{
public:
	Base(int x, int y) : a(x), b(y)
	{}
private:
	int a;
	int b;
};

class Test
{
public:
	Test(int data) : m_data(1), ref(data),base(1,2)
	{
	}
private:
	int m_data; //C++11  vs2010
	int &ref;
	const int count;
	Base base;
};

void main()
{
	Test t(10);
}
*/