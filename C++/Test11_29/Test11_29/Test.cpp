#include<iostream>
#include<vld.h>
using namespace std;


class String
{
public:
	//String(const char *str = NULL)
	String(const char *str = "")//
	{
		m_data = (char *)malloc(strlen(str)+1);
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = (char *)malloc(strlen(s.m_data)+1);
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		//1
		if(this != &s)
		{
			//2
			free(m_data);  //异常不安全 

			//3
			m_data = (char*)malloc(strlen(s.m_data)+1);
			strcpy(m_data, s.m_data);
		}
		//4
		return *this;
	}
	~String()
	{
		free(m_data);
	}
public:
	void Show()const
	{
		cout<<m_data<<endl;
	}
private:
	char *m_data;
};

void main()
{
	String s1("Hello");
	//String s2(s1);
	String s2("world");
	s2 = s1;  //s2.m_data = s1.m_data
	s1.Show();
	s2.Show();
}


/*
class String
{
public:
	//String(const char *str = NULL)
	String(const char *str = "")//
	{
		m_data = (char *)malloc(strlen(str)+1);
		strcpy(m_data, str);
	}
	String(const String &s)
	{
		m_data = (char *)malloc(strlen(s.m_data)+1);
		strcpy(m_data, s.m_data);
	}
	String& operator=(const String &s)
	{
		//1
		if(this == &s)
			return *this;

		//2
		free(m_data);

		//3
		m_data = (char*)malloc(strlen(s.m_data)+1);
		strcpy(m_data, s.m_data);

		//4
		return *this;
	}
	~String()
	{
		free(m_data);
	}
public:
	void Show()const
	{
		cout<<m_data<<endl;
	}
private:
	char *m_data;
};

void main()
{
	String s1("Hello");
	//String s2(s1);
	String s2("world");
	s2 = s1;  //s2.m_data = s1.m_data
	s1.Show();
	s2.Show();
}

/*
//sizeof
//strlen

void main()
{
	//int ar[10][10];
	short (*ar)[10][10];
	cout<<sizeof(ar)<<endl;  // 4 // 400  //40  200
}

/*
void main()
{
	char ar[10];
	for(int i=0; i<5; ++i)
	{
		ar[i] = 'a' + i;
	}
	cout<<strlen(ar)<<endl;  // 5   随机值
	cout<<sizeof(ar)<<endl;  // 10  10
}

/*
void main()
{
	char *ar = "Hellongfalflafl";
	cout<<strlen(ar)<<endl;  // 5
	cout<<sizeof(ar)<<endl;  // 4
}

/*
char ar[10];
void main()
{
	cout<<strlen(ar)<<endl;  // 随机值
	cout<<sizeof(ar)<<endl;  // 10
}


/*
void main()
{
	char ar[10] = {'H','e','l','l','o','w','o','r','l','d'};
	cout<<strlen(ar)<<endl;  // 随机值
	cout<<sizeof(ar)<<endl;  // 10
}


void main()
{
	char ar[10] = {'H','e','l','l','o'};
	cout<<strlen(ar)<<endl;  //  随机数 10 12 16
	cout<<sizeof(ar)<<endl;  // 10
}
/*
void main()
{
	char ar[10] = "Hello";  // \0
	cout<<strlen(ar)<<endl;  // 
	cout<<sizeof(ar)<<endl;  // 
}

/*
void main()
{
	char ar[] = "Hello";
	cout<<strlen(ar)<<endl;  // 5
	cout<<sizeof(ar)<<endl;  // 6
}

// 1
// 2
/*
class String
{
public:
	//String(const char *str = NULL)
	String(const char *str = "")//
	{
		m_data = (char *)malloc(strlen(str)+1);
	}
private:
	char *m_data;
};

void main()
{
	String s1("Hello Bit.jflafkajlfjalkjaklfjlak");
}

/*
class Test
{
public:
	Test()
	{
		m_data = 0;
	}
private:
	int m_data;
};

void main()
{
	Test t;
	Test t1 = t;
	Test t2;
	t2 = t1;
}

/*
class Test
{
public:
	//普通构造函数
	Test(int d = 0) : m_data(d)  //参数列表 初始化
	{
		cout<<"Create Test Object:"<<this<<endl;
	}
	//拷贝构造函数   //对象初始化对象的时候
	Test(const Test &t)
	{
		cout<<"Copy Create Test Object:"<<this<<endl;
		//t.m_data = 200;
		m_data = t.m_data;
	}
	//运算符的重载  =  . ? : ::
	//Test& operator=(const Test &t)
	// t1 = t2;  // t1.operator=(t2)  //operator=(&t1, t2)
	
	Test& operator=(const Test &t)
	{
		cout<<"Assign:"<<this <<" = "<<&t<<endl;
		//1 自我赋值检测
		if(this == &t)
			return *this;

		// 2 释放当前对象的空间

		// 3 重新开辟空间并赋值
		m_data = t.m_data;

		// 4 返回当前对象
		return *this;
	}
	// 析构函数
	~Test()
	{
		cout<<"Free Test Object:"<<this<<endl;
	}
public:
	/*
	//int GetData(Test * const this)
	int GetData()
	{
		return m_data;
	}
	
	//int GetData(const Test * const this)
	int GetData()const
	{
		return m_data;
		//return (*this).m_data;
	}
	
	void Show()const
	{
		cout<<m_data<<endl;
	}
private:
	int m_data;
};

void main()
{
	Test t1(10);
	Test &t2 = t1;
	Test &t3 = t2;
	t1 = t3;
}

/*
class Test
{
public:
	//普通构造函数
	Test(int d = 0) : m_data(d)  //参数列表 初始化
	{
		cout<<"Create Test Object:"<<this<<endl;
	}
	//拷贝构造函数   //对象初始化对象的时候
	Test(const Test &t)
	{
		cout<<"Copy Create Test Object:"<<this<<endl;
		//t.m_data = 200;
		m_data = t.m_data;
	}
	//运算符的重载  =  . ? : ::
	//Test& operator=(const Test &t)
	// t1 = t2;  // t1.operator=(t2)  //operator=(&t1, t2)
	Test& operator=(const Test &t)
	{
		cout<<"Assign:"<<this <<" = "<<&t<<endl;
		//1 自我赋值
		if(this != &t) //自我赋值
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout<<"Free Test Object:"<<this<<endl;
	}
public:
	/*
	//int GetData(Test * const this)
	int GetData()
	{
		return m_data;
	}
	
	//int GetData(const Test * const this)
	int GetData()const
	{
		return m_data;
		//return (*this).m_data;
	}
	
	void Show()const
	{
		cout<<m_data<<endl;
	}
private:
	int m_data;
};

void main()
{
	Test t1(10);
	Test &t2 = t1;
	Test &t3 = t2;
	t1 = t3;
}

/*
void main()
{
	int a, b, c;
	a = b = c = 0; //连等赋值
	Test t0(10);
	Test t1, t2, t3;

	//t1.operator=(t2)

	t1 = t2 = t3 = t0;
	//t1 = t0;
}

/*
void main()
{
	Test t(10);
	//cout<<t.GetData()<<endl;
	Test t1;
	t1 = t;  // t1.operator=(t);
	cout<<t1.GetData()<<endl;
}

/*
void main()
{
	Test t(10);
	const Test t1(100);
	//GetData(&t);
	cout<<t.GetData()<<endl;
	//GetData(&t1);
	cout<<t1.GetData()<<endl;
}

/*
Test fun(Test x)
{
	int value = x.GetData();
	Test tmp(value);
	return tmp;
}

void main()
{
	//Test t(1);
	Test t = 1;  //
	Test t0 = t; //拷贝构造函数  //初始化
	Test t1;
	t1 = t;  //赋值语句          //赋值
}

/*
void main()
{
	Test t(1);
	Test t1(t);  // 1 
	Test t2 = fun(t);      // 2  //3
}

/*
void main()
{
	Test t(1);
	//Test t1 = t;
	Test t1(t);
	fun
}

/*
class Test
{
public:
	Test(int d = 0) : m_data(d)  //参数列表 初始化
	{
		//m_data = 0;  //赋值
	}
public:
	void Show()const
	{
		cout<<m_data<<endl;
	}
private:
	//int m_data = 0;  //C++11
	int m_data;
};

void main()
{
	Test t;
	t.Show();
}
*/