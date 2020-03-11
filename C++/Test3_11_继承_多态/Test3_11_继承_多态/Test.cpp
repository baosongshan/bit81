#include<iostream>
using namespace std;

class Base
{
public:
	int m_n;
};

//虚拟继承
class A : virtual public Base   //A 有自己的虚基表
{
public:
	int m_a;
};
class B : virtual public Base  //B 有自己的虚基表
{
public:
	int m_b;
};
class D : public A, public B
{
public:
	int m_d;
};

void main()
{
	D d;
	d.m_d = 0;
	d.m_a = 1;
	d.m_b = 2;

	d.A::m_n = 3; //A  ?  B
	d.B::m_n = 4;

}

/*
#define DISPLAY

class Base
{
public:
	Base(int a) :m_a(a), m_b(a)
	{
#ifdef DISPLAY
		cout<<"Base::Base()"<<endl;
#endif
	}
	~Base()
	{
#ifdef DISPLAY
		cout<<"Base::~Base()"<<endl;
#endif
	}
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	void fun(int,int)
	{
		cout<<"Base::fun(int,int)"<<endl;
	}
	void show()
	{
		cout<<"Base::show()"<<endl;
	}
public:
	int m_a = 0;
	int m_b = 0;
};

class Base1
{
public:
	Base1(int a, int b):m_a1(a),m_b1(b)
	{
#ifdef DISPLAY
		cout<<"Base1::Base1()"<<endl;
#endif
	}
	~Base1()
	{
#ifdef DISPLAY
		cout<<"Base1::~Base1()"<<endl;
#endif
	}
public:
	void fun()
	{
		cout<<"Base1::fun()"<<endl;
	}
	void fun(int,int)
	{
		cout<<"Base1::fun(int,int)"<<endl;
	}
	void show()
	{
		cout<<"Base1::show()"<<endl;
	}
public:
	int m_a1 = 0;
	int m_b1 = 0;
};

//多继承
class D : public Base1, virtual public Base
{
public:
	D() : bs(0), Base(1),   bs1(1,2),Base1(1,2)
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
private:
	int m_x;
	int m_y;
	Base bs;
	Base1 bs1;
};

void main()
{
	//1 先按照继承的顺序构造父类
	//2 按照对象的顺序实例化对象成员
	//3 在构造子类
	D d;

}

/*
class Base
{
public:
	int m_n;
};
class A : virtual public Base
{
public:
	int m_a;
};
class B : virtual public Base
{
public:
	int m_b;
};
class D : public A, public B
{
public:
	int m_d;
};

void main()
{
	D d;
	d.m_d = 0;
	d.m_a = 1;
	d.m_b = 2;

	d.A::m_n = 3; //A  ?  B
	d.B::m_n = 10;

}

/*
#define DISPLAY

class Base
{
public:
	Base(int a) :m_a(a), m_b(a)
	{
#ifdef DISPLAY
		cout<<"Base::Base()"<<endl;
#endif
	}
	~Base()
	{
#ifdef DISPLAY
		cout<<"Base::~Base()"<<endl;
#endif
	}
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	void fun(int,int)
	{
		cout<<"Base::fun(int,int)"<<endl;
	}
	void show()
	{
		cout<<"Base::show()"<<endl;
	}
public:
	int m_a = 0;
	int m_b = 0;
};

class Base1
{
public:
	Base1(int a, int b):m_a1(a),m_b1(b)
	{
#ifdef DISPLAY
		cout<<"Base1::Base1()"<<endl;
#endif
	}
	~Base1()
	{
#ifdef DISPLAY
		cout<<"Base1::~Base1()"<<endl;
#endif
	}
public:
	void fun()
	{
		cout<<"Base1::fun()"<<endl;
	}
	void fun(int,int)
	{
		cout<<"Base1::fun(int,int)"<<endl;
	}
	void show()
	{
		cout<<"Base1::show()"<<endl;
	}
public:
	int m_a1 = 0;
	int m_b1 = 0;
};

//多继承
class D : public Base1, public Base
{
public:
	D() : bs(0), Base(1),   bs1(1,2),Base1(1,2)
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
private:
	int m_x;
	int m_y;
	Base bs;
	Base1 bs1;
};

void main()
{
	//1 先按照继承的顺序构造父类
	//2 按照对象的顺序实例化对象成员
	//3 在构造子类
	D d;

}

/*
class Base
{
public:
	Base()
	{
		++m_count;
	}
	~Base()
	{
		--m_count;
	}
public:
	int GetCount()const
	{
		return m_count;
	}
public:
	void Increment()
	{
		m_count++;
	}
private:
	static int m_count; //用于统计对象的个数
};

int Base::m_count = 0;

class D : public Base
{
public:
	D()
	{}
public:
	
};

void main()
{
	cout<<sizeof(Base)<<endl;
	cout<<sizeof(D)<<endl;   //1  //1  默认值

	D d; //开辟空间 1   8
}

/*
void main()
{
	D d;
	cout<<"object count = "<<d.GetCount()<<endl;
	{
		D d1;
		cout<<"object count = "<<d.GetCount()<<endl;
	}
	cout<<"object count = "<<d.GetCount()<<endl;
}

/*
//#define DISPLAY

class D;
class C;

class Base
{
	friend void PrintData(const Base &b, const D &d, const C &c);
public:
	Base(int a, int b) : m_a(a),m_b(b)
	{
#ifdef DISPLAY
		cout<<"Base::Base()"<<endl;
#endif
	}
	~Base()
	{
#ifdef DISPLAY
		cout<<"Base::~Base()"<<endl;
#endif
	}
public:
	void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	void fun(int,int)
	{
		cout<<"Base::fun(int,int)"<<endl;
	}
	void show()
	{
		cout<<"Base::show()"<<endl;
	}
public:
	int m_a = 0;
	int m_b = 0;
};

class D : public Base
{
	friend void PrintData(const Base &b, const D &d, const C &c);
public:
	D() : Base(1,2)
	{
#ifdef DISPLAY
		cout<<"D::D()"<<endl;
#endif
	}
	~D()
	{
#ifdef DISPLAY
		cout<<"D::~D()"<<endl;
#endif
	}
public:
	void fun()
	{
		cout<<"D::fun()"<<endl;
	}
public:
	int m_x = 0;
	int m_y = 0;
};

class C
{
	friend void PrintData(const Base &b, const D &d, const C &c);
public:
private:
	int m_n = 0;
	int m_k = 0;
};

void PrintData(const Base &b, const D &d, const C &c)
{
	cout<<b.m_a<<" : "<<b.m_b<<endl;
	cout<<d.m_x<<" : "<<d.m_y<<endl;
	cout<<c.m_n<<" : "<<c.m_k<<endl;
}

//继承体系里面的友元函数不具备传递性  // 父类 <--> 子类 
void main()
{
	D d;
	//d.fun();
	//d.fun(0,0);
	//d.show();
	Base b(1,2);
	C c;
	PrintData(b, d, c);
}

/*
void main()
{
	Base b(0, 0);
	D d;

	//赋值兼容规则
	b = d;
	Base *pb = &d;
	Base &rb = d;
}
*/