#include<iostream>
#include<stdio.h>
//#include"fun.h"
using namespace std;

// 1 常方法的const 怎么了
// 2 GetData() 与 GetData()const 能否共存
// 3 拷贝构造函数的const 
// 4 赋值语句 
//   Test& operator=(const Test &t)
//   void  operator=(Test t)

class Test
{
public:
	//构造函数
	//Test t;
	Test(int data = 0)
	{
		cout<<"Create Test Object:"<<this<<endl;
		m_data = data;
	}
	//拷贝构造函数
	//语法要求 语义要求
	Test(Test &t)
	{
		cout<<"Copy Create Test Object:"<<this<<endl;
		m_data = t.m_data;
	}
	//赋值语句
	/*
	Test& operator=(const Test &t)
	{
		cout<<"Assign,"<<this<< "="<<&t<<endl; 
		if(this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	*/
	void operator=(Test t)
	{
		cout<<"Assign,"<<this<< "="<<&t<<endl; 
		if(this != &t)
		{
			m_data = t.m_data;
		}
	}
	//析构函数 
	//~t
	~Test()
	{
		cout<<"Free Test Object:"<<this<<endl;
	}
public:
	int GetData()const  //常方法
	{
		return m_data;
	}
	/*
	int GetData()
	{
		return m_data
	}
	*/
private:
	int m_data;
};

void main()
{
	Test t(10);   //  t
	Test t1 = t;  //  t1
	Test t2;
	t2 = t1;
}

/*
class Test
{
public:
	//构造函数  自动  
	Test() //默认构造函数
	{
		cout<<"Create Test() Object."<<endl;
	}
	Test(int data)
	{
		cout<<"Create Test(int) Object."<<endl;
		m_data = data;
	}
	Test(int data, int value)
	{
		cout<<"Create Test(int,int) Object."<<endl;
		m_data = data;
		m_value = value;
	}
public:
	void fun()
	{}
private:
	int m_data; //
	int m_value;
};

void main()
{
	Test t; //
	Test t1(10);
	Test t2(10,20);
}

/*
class A
{
public:
	void PrintA()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "Show()" << endl;
	}
private:
	int _a;
};


int main()
{
	A a;
	//A* p = NULL;
	A *p = &a;
	p->PrintA();
	p->Show();
}

/*
class CGoods
{
public:
	void RegisterGoods(char *name, int count, float price)
	{
		strcpy(this->name, name);
		this->count = count;
		this->price = price;
	}
	void SetName(char *name)
	{
		strcpy(this->name, name);
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	void SetPrice(float price)
	{
		this->price = price;
	}
public:
	char* GetName()
	{
		return this->name;
	}
	int GetCount()
	{
		return count;
	}
	float GetPrice()
	{
		return price;
	}
	float GetTotalPrice()
	{
		return price*count;
	}
private:
	char name[10];
	int  count;
	float price;
	float total_price;
};
//测试
void main()
{
	CGoods c1, c2;
	//RegisterGoods(&c1, "C++", 10, 35);
	c1.RegisterGoods("C++", 10, 35);
	c2.RegisterGoods("C++", 10, 35);
	//GetName(&c1);
	cout<<c1.GetName()<<endl;
	c1.SetName("Java");
	cout<<c1.GetName()<<endl;
}


/*
class Test  //1
{
public:
	//void SetData(Test *const this, int data = 0)
	void SetData(int data = 0)  //2
	{
		this->m_data = data;
	}
	//int GetData(Test *const this)
	int GetData()
	{
		return this->m_data;   //this?
	}
	//void SetValue(Test *const this, int value = 0)
	void SetValue(int value = 0)  //2
	{
		this->m_value = value;
	}
	//int GetValue(Test * const this);
	int GetValue()
	{
		return this->m_value;
	}

public:
	void ShowData()
	{
		//cout<<"data = "<<m_data<<endl;
		printf("data = %d, value = %d\n",m_data, m_value);
	}
	void ListData()
	{
		printf("data = %d, value = %d\n",m_data, m_value);
	}
public:
	int m_data;   //2
	int m_value;
};

void main()
{
	Test t1, t2;
	t1.SetData(1); //SetData(&t1, 1);
	t1.SetValue(2);
	t2.SetData(10);//SetData(&t2, 10);
	t2.SetValue(20);

	cout<<"t1 data = "<<t1.GetData()<<endl;   //GetData(&t1);
	cout<<"t2 data = "<<t2.GetData()<<endl;

}

/*
struct Student
{
	char name[10];
	char sex[3];
	int age;
	int height;
	int weight;
};
//////////////////////////////////////////////
void InitStu(Student *_this)
{
	_this->name[0] = '\0';
	_this->sex[0] = '\0';
	_this->age = 0;
	_this->height = 0;
	_this->weight = 0;
}
char *GetName(Student *_this)
{
	return _this->name;
}

void main()
{
	Student s1,s2;
	InitStu(&s1);
	InitStu(&s2);
	char *n1 = GetName(&s1);
	char *n2 = GetName(&s2);
}


/*
//先定义后使用


/*
void main()
{
	cout<<sizeof(Test)<<endl;
}

/*
void main()
{
	Test t1, t2;
	t1.SetData(1);
	t1.SetValue(2);
	t2.SetData(10);
	t2.SetValue(20);

	cout<<"t1 data = "<<t1.GetData()<<endl;
	cout<<"t2 data = "<<t2.GetData()<<endl;
}


/*
void main()
{
	Test t;  //开空间
	t.m_data = 10;

	Test.m_data = 10;
	Test::m_data = 100;
}


/*
void main()
{
	Test t;
	t.SetData();
	//int value = t.GetData();
	//cout<<"t = "<<t<<endl;
	t.ShowData();
}


/*
void main()
{
	CGoods c1, c2;
	c1.Register("C++", 10, 35.6);
	c2.Register("Java", 5, 28);
}

/*
//C++
//:: 作用域访问符

class Student
{
public:
	void Register(char *n, char *s, int a, int h, int w);
private:
	char name[10];  //成员数据  数据成员
	char sex[3];
	int age;
	int height;
	int weight;
};



void CGoods::Register(char *n, int c, float p)
{
	strcpy(name, n);
	count = c;
	price = p;
}

void Student::Register(char *n, char *s, int a, int h, int w)
{
	strcpy(name, n); 
	strcpy(sex,s);
	age = a;
	height = h;
	weight = w;
}

void main()
{
	Student s, s1;  // 实例化 对象
	s.RegisterStu("距离","男", 20, 170, 50);
	s1.RegisterStu("力扣","女", 22, 180,60);
}

/*
class Student
{
public:
	void RegisterStu(char *n, char *s, int a, int h, int w)
	{
		strcpy(name, n); 
		strcpy(sex,s);
		age = a;
		height = h;
		weight = w;
	}
private:
	char name[10];  //成员数据  数据成员
	char sex[3];
	int age;
	int height;
	int weight;
};
void main()
{
	Student s, s1;  // 实例化 对象
	s.RegisterStu("距离","男", 20, 170, 50);
	s1.RegisterStu("力扣","女", 22, 180,60);
}

/*
struct Student
{

	char name[10];
	char sex[3];
	int age;
	int height;
	int weight;
};

void main()
{
	Student s;  // 实例化 对象
	s.age = 10;
}

/*
class Student
{
public:
	char name[10];  //成员数据  数据成员
private:
	char sex[3];
	int age;
protected:
	int height;
	int weight;
};
void main()
{
	Student s;  // 实例化 对象
	//s.age = 10;
	strcpy(s.name,"放假啊");
}

/*
struct Student
{
	char name[10];
	char sex[3];
	int age;
	int height;
	int weight;
};

void main()
{
	Student s;  // 实例化 对象
	s.age = 10;
}

/*
class Student
{
	char name[10];
	char sex[3];
	int age;
	int height;
	int weight;
};
void main()
{
	Student s;  // 实例化 对象
	s.age = 10;
}

/*
struct Student
{
	char name[10];
	char sex[3];
	int age;
	int height;
	int weight;

	void SetAge(int a)
	{
		age = a;
	}
};
//////////////////////////////////////////////
void InitStu(Student *ps)
{
	ps->name[0] = '\0';
	ps->sex[0] = '\0';
	ps->age = 0;
	ps->height = 0;
	ps->weight = 0;
}

void main()
{
	Student s1;  //结构体变量
	Student s2;

	InitStu(&s1);
}


/*
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
void f(nullptr_t)
{
	cout<<"f(nullptr_t)"<<endl;
}
int main()
{
	//int *p = nullptr;
	f(0);
	f(NULL);
	f((int*)NULL);
	f(nullptr);  //类型检测
	return 0;
}

/*
void main()
{
	int *p = 0;  //NULL  0 
}

/*
void fun(int ar[]) // *  int *ar;  [......]
{
	for(auto e : ar)
		cout<<e;
	cout<<endl;
}

void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	fun(ar);
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(int);
	for(int i=0; i<n; ++i)
		cout<<ar[i]<<" ";
	cout<<endl;

	for(auto ele : ar)  //
	{
		ele = 11;
		cout<<ele<<" ";
	}
	cout<<endl;
}

/*
void main()
{
	auto a = 12.34;
	//typeid(a).name() b;  //"int"
	decltype(a) b;
	cout<<typeid(b).name()<<endl;
}

/*
//占位符
void fun(auto x)
{
	cout<<x<<endl;
}

void main()
{
	fun(10);
}


void main()
{
	int a = 10;
	auto b = 20;
	int ar[5] = {0};
	
	auto par = &ar;

	//auto x;  //

	cout<<typeid(b).name()<<endl; 
	cout<<typeid(par).name()<<endl; 
}

/*
struct Test
{};

void main()
{
	int a = 10;
	auto b = 20;

	int ar[5] = {0};
	int *pa = &a;
	Test t;
	cout<<typeid(b).name()<<endl; 
	cout<<typeid(ar).name()<<endl;
	cout<<typeid(pa).name()<<endl;
	cout<<typeid(t).name()<<endl;
}

/*
//内联方法  建议  效率

inline int fun(int a, int b)
{
	return a + b;
}

void main()
{
	int value = fun(10,20);
	fun(10,20);
	fun(10,20);
	fun(10,20);
	fun(10,20);
	fun(10,20);
	fun(10,20);
	fun(10,20);
	fun(10,20);
}


/*
void main()
{
	int ar[5] = {1,2,3,4,5};
	int(&br)[5] = ar; //3

	int(*par)[5] = &ar;

	cout<<sizeof(br)<<endl;
	cout<<sizeof(par)<<endl;
}

/*
int main()
{
	int a = 10;
	int& ra = a;   // *  ra const 
	ra = 20;

	int* pa = &a;
	*pa = 20;
	return 0;
}

/*
int& fun(const int &a, const int &b)
{
	int v = a + b;
	return v;
}

void main()
{
	int a = 10;
	int b = 20;

	int &value = fun(a, b);
	fun(100, 200);
	cout<<value<<endl;  //30
}

/*
void Swap(int &a, int &b) //4
{
	int tmp = a; 
	a = b;
	b = tmp;
}

int& fun(int a, int b, int &v)
{
	v = a + b;
	return v;
}

void fun1(int a, int b, int &v)
{
	v = a + b;
}

void main()
{
	int a = 10;
	int b = 20;
	int &ra = a; //1

	int *p = &a;
	int *&q = p; //2

	int ar[5] = {1,2,3,4,5};
	int(&br)[5] = ar; //3

	Swap(a, b);

	int res;
	int &value = fun(a, b, res);  //int &value = res;

	fun1(100,200,res);
}


/*
void main()
{
	int *p = (int*)malloc(sizeof(int)*3);
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;

	free(p);
}

/*
void Swap(int &a, int &b) //4
{
	int tmp = a; 
	a = b;
	b = tmp;
}

int fun(int a, int b, int &v)
{
	v = a + b;
	return v;
}

void main()
{
	int a = 10;
	int b = 20;
	int &ra = a; //1

	int *p = &a;
	int *&q = p; //2

	int ar[5] = {1,2,3,4,5};
	int(&br)[5] = ar; //3

	Swap(a, b);

}

/*
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	return 0;
}


void main()
{
	const int a = 10;
	const int &ra = a;
}

/*
//const
void main()
{
	int a = 10;
	int &ra = a;

	const int &rb = a;

	a = 100;
	rb = 200;
}

/*
void main()
{
	int a = 10;
	int &ra = a;
	int &rb = a;
	int &rc = ra;

	int b = 20;
	ra = b;
}

/*
void main()
{
	int a = 10;
	int &ra = a;

	double d = 12.34;
	int &rd = (int)d; //隐式  float

	//ra = 100;
}
*/
