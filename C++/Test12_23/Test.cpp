#include<iostream>
#include"fun.h"
#include<bitset>
using namespace std;

template<typename Type>
class BinTreeNode
{
public:
	//零初始化
	BinTreeNode(Type d = Type(), BinTreeNode<Type> *left=nullptr,BinTreeNode<Type>*right=nullptr)
		: data(d), leftChild(left),rightChild(right)
	{}
private:
	Type data;
	BinTreeNode<Type> *leftChild;
	BinTreeNode<Type> *rightChild;
};

void main()
{
	BinTreeNode<int> node;
}

/*
class Test
{
public:
	Test(int d = 0) : m_data(d)
	{}
	~Test()
	{}
public:
	bool operator>(const Test &t)
	{
		return m_data > t.m_data;
	}
private:
	int m_data;
};

void main()
{
	BinTreeNode<double> node;

	int a = int();   //产生临时的对象
	char ch = char();
	double d = double();
	Test t = Test();
}


/*
void main()
{
	int a = 0;   //  x
	a = 10;
}


template<size_t _Bits>
class bitset

void main()
{
	bitset<100> bt;
}


/*
int fun(int a=0, int b=0)
{
	return a + b;
}


class Test
{};

void main()
{
	//类型
	//template<typename Type=int, size_t SIZE=100>
	//class Array
	Array<int> ar;
}


/*
void main()
{
	Array<int> ar(10);
	Array<Test> br(10);
	Array<double> cr(10);
	Array<char> dr(10);

	fun(1,2);
}


/*
//vector 动态数组 向量
void main()
{
	Array<int> ar(100);
	for(int i=1; i<=100; ++i)
	{
		ar[i-1] = i;
	}

	for(int i=0; i<100; ++i)
	{
		cout<<ar[i]<<" ";
		if(i!=0 && i % 10 == 0)
			cout<<endl;
	}

	for(int i=0; i<100; ++i)
	{
		*(ar+i) = i;
	}
}

/*
void main()
{
	cout<<fun(12.34, 23.45)<<endl;
	cout<<fun(100,200)<<endl;
}

/*
//模板就是将类型设置成一个参数的函数或类
//函数模板
//泛型 -- 不能跟类型有关系

//模板的运行效率都比较低下

// 模板不支持分离编译

template<typename Type1, typename Type2>
Type2 Max(Type1 a, Type2 b);

void main()
{
	cout<<Max(12.34,23)<<endl; 
	cout<<Max(10,20)<<endl;
}

template<typename Type1, typename Type2>
Type2 Max(Type1 a, Type2 b)
{
	cout<<typeid(a).name()<<endl;
	return a > b ? a : b;
}

/*
template<typename Type1, typename Type2>
Type2 Max(Type1 a, Type2 b)
{
	cout<<typeid(a).name()<<endl;
	return a > b ? a : b;
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

void main()
{
	cout<<Max(12.34,23)<<endl; 
	cout<<::Max(10,20)<<endl;
}

/*
class Test
{
public:
	Test(int d = 0) : m_data(d)
	{}
	~Test()
	{}
public:
	bool operator>(const Test &t)
	{
		return m_data > t.m_data;
	}
private:
	int m_data;
};


template<typename Type>
Type Max(Type a, Type b)
{
	cout<<typeid(a).name()<<endl;
	return a > b ? a : b;
}

void main()
{
	cout<<Max('a','b')<<endl;
	cout<<Max(12.34,23)<<endl; 
	cout<<Max<int>(10,20)<<endl; 

	Test t1(10), t2(20);
	Max(t1, t2);
}

/*
void main()
{
	cout<<Max<char>('a','b')<<endl;
	cout<<Max<double>(12.34,23.45)<<endl; //23
	cout<<Max<int>(10,20)<<endl;       //20
}

/*
template<class Type>
Type Max(Type a, Type b)
{
	cout<<typeid(a).name()<<endl;
	return a > b ? a : b;
}
void main()
{
	cout<<Max('a','b')<<endl;
	cout<<Max(12.34,23.45)<<endl; //23
	cout<<Max(10,20)<<endl;       //20
}

/*
template<typename Type>
Type Max(Type a, Type b)
{
	cout<<typeid(a).name()<<endl;
	return a > b ? a : b;
}
void main()
{
	cout<<Max('a','b')<<endl;
	cout<<Max(12.34,23.45)<<endl; //23
	cout<<Max(10,20)<<endl;       //20
}

/*
char Max(char a, char b)
{
	cout<<typeid(a).name()<<endl;
	return a > b ? a : b;
}


// C++ 类型的要求更加严格
// C++
void main()
{
	cout<<Max('a','b')<<endl;
	cout<<Max(12.34,23.45)<<endl; //23
	cout<<Max(10,20)<<endl;       //20
}

/*
char Max(char a, char b)
{
	return a > b ? a : b;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}
double Max(double a, double b)
{
	return a > b ? a : b;
}
float Max(float a, float b)
{
	return a > b ? a : b;
}

// C++ 类型的要求更加严格
// C++
void main()
{
	Max('a','b');
	Max(12.34,23.45);
	Max(10,20);
}
*/