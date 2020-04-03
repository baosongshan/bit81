#include<iostream>
using namespace std;

class Base
{
public:
	virtual void f()
	{
		cout<<"Base::f()"<<endl;
	}
	virtual void g()
	{
		cout<<"Base::g()"<<endl;
	}
	virtual void h()
	{
		cout<<"Base::h()"<<endl;
	}
};

class Base1
{
public:
	virtual void f()
	{
		cout<<"Base1::f()"<<endl;
	}
	virtual void g()
	{
		cout<<"Base1::g()"<<endl;
	}
	virtual void h()
	{
		cout<<"Base1::h()"<<endl;
	}
};

class Base2
{
public:
	virtual void f()
	{
		cout<<"Base2::f()"<<endl;
	}
	virtual void g()
	{
		cout<<"Base2::g()"<<endl;
	}
	virtual void h()
	{
		cout<<"Base2::h()"<<endl;
	}
};

class D : public Base, public Base1, public Base2
{
public:
	virtual void f()
	{
		cout<<"D::f()"<<endl;
	}
	virtual void g1()
	{
		cout<<"D::g1()"<<endl;
	}
	virtual void h1()
	{
		cout<<"D::h1()"<<endl;
	}
};

void main()
{
	D    d;   //
	Base  *pb = &d;
	Base1 *pb1 = &d;
	Base2 *pb2 = &d;

	pb2->f();
}


/*
class Base
{
public:
	virtual void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	virtual void show()
	{
		cout<<"Base::show()"<<endl;
	}
};

class D : public Base
{
public:
	virtual void fun()
	{
		cout<<"D::fun()"<<endl;
	}
	virtual void show()
	{
		cout<<"D::show()"<<endl;
	}
	virtual void print()
	{
		cout<<"D::print()"<<endl;
	}
};

typedef void(*vfptr_t)();
void PrintVirtualTable(vfptr_t *vfptr)
{
	for(int i=0; vfptr[i]!=nullptr; ++i)
	{
		vfptr[i]();
	}
}
void main()
{
	D d;
	vfptr_t *vfptr_a = (vfptr_t*)(*(int*)&d);
	PrintVirtualTable(vfptr_a);
}

/*
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
private:
	int _b;
	int _a;
	int _c;
};

class D : public Base
{
public:
	void Func1()
	{
		cout << "D::Func1()" << endl;
	}
public:
	int _x;
	int _y;
	int _z;
};

void main()
{
	D d;
	memset(&d, 0, sizeof(D)); //nullptr
	Base *pb = &d;
	pb->Func1();   //1父类  2子类  3程序崩溃  
}

/*
//抽象类
class A
{
public:
	//定义接口
	virtual void Eat() = 0;  //纯虚方法
	virtual void Sleep() = 0; //纯虚方法
	virtual void Foot() = 0; //纯虚方法
};

class Dog : public A
{
public:
	virtual void Eat()
	{
		cout<<"Dog::Eat()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"Dog::Sleep()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"Dog::Foot()"<<endl;
	}
};

class Person : public A
{
public:
	virtual void Eat()
	{
		cout<<"Person::Eat()"<<endl;
	}
	virtual void Sleep()
	{
		cout<<"Person::Sleep()"<<endl;
	}
	virtual void Foot()
	{
		cout<<"Person::Foot()"<<endl;
	}
};

void Active(A *pa)
{
	pa->Eat();
	pa->Foot();
	pa->Sleep();
}

void main()
{
	Dog d;
	Person p;

	Active(&p);
}

/*
class Base
{
public:
	void f(int x)  //重载
	{ 
		cout << "Base::f(int) " << x << endl;
	}
	void f(float x)
	{ 
		cout << "Base::f(float) " << x << endl; 
	}
	virtual void g(void) //覆盖
	{
		cout << "Base::g(void)" << endl;
	}
};

class Derived : public Base
{
public:
	virtual void g(void) //重写
	{ 
		cout << "Derived::g(void)" << endl;
	}
	void f(char ch) //同名隐藏了父类的方法
	{
		cout<<"D::f(char)"<<endl;
	}
};

/*
class Base
{
public:
	virtual void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
};

class D : public Base
{
public:
	virtual void fun()override
	{
		cout<<"D::fun()"<<endl;
	}
};

void main()
{
	Base *pb = new D;
	pb->fun();
}

/*
class A
{
public:
	virtual void fun()
	{

	}
};

class Base : public A
{
public:
	void fun()final
	{
		cout<<"Base::fun()"<<endl;
	}
};

class D : public Base
{
public:
	virtual void fun(int a)
	{
		cout<<"D::fun()"<<endl;
	}
};

void main()
{
	Base *pb = new D;
	pb->fun();
}

/*
class Base
{
public:
	Base()
	{
		cout<<"Base::Base()"<<endl;
	}
	virtual ~Base()
	{
		cout<<"Base::~Base()"<<endl;
	}
public:
	virtual void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
public:
	virtual Base* show()
	{
		cout<<"Base::show()"<<endl;
		return this;
	}
};

class D : public Base
{
public:
	D()
	{
		cout<<"D::D()"<<endl;
	}
	~D()
	{
		cout<<"D::~D()"<<endl;
	}
public:
	virtual void fun()
	{
		cout<<"D::fun()"<<endl;
	}
public:
	virtual D* show()  //
	{
		cout<<"D::show()"<<endl;
		return this;
	}
};
void main()
{
	//D d;  //静态 栈区
	Base *pb = new D; //动态 手工
	delete pb;
}

/*
class Base
{
public:
	virtual void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
public:
	virtual Base* show()
	{
		cout<<"Base::show()"<<endl;
		return this;
	}
};

class D : public Base
{
public:
	virtual void fun()
	{
		cout<<"D::fun()"<<endl;
	}
public:
	virtual D* show()  //
	{
		cout<<"D::show()"<<endl;
		return this;
	}
};
void main()
{
	D d;
	Base *pb = &d;
	pb->show();     // pb->fun 永远都不能调动子类的方法
				   // 狸猫换太子
}
*/