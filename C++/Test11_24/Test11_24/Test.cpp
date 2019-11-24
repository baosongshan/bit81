#include<iostream>
#include<stdio.h>
#include"fun.h"
using namespace std;

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
