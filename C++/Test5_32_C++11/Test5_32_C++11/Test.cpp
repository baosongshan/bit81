#include<iostream>
#include<vld.h>
#include<algorithm>
#include<functional>
#include<thread>
#include<windows.h>
#include<mutex>
#include<atomic>
using namespace std;

//RAII

int number = 0;
mutex g_lock;

int ThreadProc1()
{
	for (int i = 0; i < 100; i++)
	{
		//g_lock.lock();
		lock_guard<mutex> lock(g_lock);
		//unique_lock<mutex> lock(g_lock);
		++number;
		cout << "thread 1 :" << number << endl;

		//return;

		//g_lock.unlock();
	}
	return 0;
}

int ThreadProc2()
{
	for (int i = 0; i < 100; i++)
	{
		//g_lock.lock();
		lock_guard<mutex> lock(g_lock);
		--number;
		cout << "thread 2 :" << number << endl;
		//g_lock.unlock();
	}
	return 0;
}

int main()
{
	thread t1(ThreadProc1);
	thread t2(ThreadProc2);
	t1.join();
	t2.join();

	cout << "number:" << number << endl;
	system("pause");
	return 0;
}

/*
//线程同步-->共享资源

mutex mt;

//unsigned long sum = 0L;
atomic_long sum = {0};

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		sum++;
	}
}
int main()
{
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);

	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;
	return 0;
}

/*
class mythread
{
public:
	explicit mythread(std::thread &t) :m_t(t){}
	~mythread()
	{
		if (m_t.joinable())
			m_t.join();
	}
	mythread(mythread const&) = delete;
	mythread& operator=(const mythread &) = delete;
private:
	std::thread &m_t;
};

void ThreadFunc() { cout << "ThreadFunc()" << endl; }
bool DoSomething() { return false; }

int main()
{
	thread t(ThreadFunc);
	mythread q(t);

	if (DoSomething())
		return -1;

	return 0;
}

/*
void ThreadFunc() { cout << "ThreadFunc()" << endl; }
void Test1() { throw 1; }
void Test2()
{
	int* p = new int[10];
	
	std::thread t(ThreadFunc);   //多线程 退化成 单线程
	
	try
	{
		Test1();
	}
	catch (...)
	{
		delete[] p;
		throw;
	}
	
	t.join(); //阻塞
}

/*
void ThreadFunc() 
{
	cout << "ThreadFunc()" << endl; 
}
bool DoSomething()
{
	return false; 
}

int main()
{
	thread t(ThreadFunc);
	
	if (!DoSomething())
		return -1;

	t.join();
	return 0;
}

/*
void ThreadFunc1(int &x)
{
	x += 10;
}
void ThreadFunc2(int *x)
{
	*x += 10;
}


class Test
{
public:
	void show()
	{
		cout<<"This is Test::show()"<<endl;
	}
};

void main()
{
	Test t;
	thread th(&Test::show, &t);   //this->show

	th.join();
	th.join();
}

/*
int main()
{
	int a = 10;
	thread t1(ThreadFunc2, &a);
	t1.join();
	cout << a << endl;
	

	return 0;
}

/*
int main()
{
	int a = 10;
	thread t1(ThreadFunc1, ref(a));
	t1.join();
	cout << a << endl;
	

	return 0;
}

/*
void thread_fun(int n)
{
	for(int i=0; i<n; ++i)
	{
		cout<<"This is Child Thread."<<endl;
	}
	Sleep(2000);
	cout<<"Child Thread End."<<endl;
}

struct ThreadObj
{
	void operator()(int n)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << "This is Child Thread." << endl;
		}
		Sleep(2000);
		cout << "Child Thread End." << endl;
	}
};

void main()
{
	thread th(thread_fun, 10);
	//th.detach();

	//thread th(ThreadObj(), 10);

	//thread th([]{cout<<"This is Child Thread Lamuda."<<endl;});

	thread &&th1 = move(th);

	for(int i=0; i<10; ++i)
	{
		cout<<"This is Main Thread."<<endl;
	}

	th.join();

	cout<<"Main Thread End."<<endl;
}

/*
int main()
{
	std::thread t1;
	cout << t1.get_id() << endl;
	return 0;
}

/*
void thread_fun()
{
	for(int i=0; i<10; ++i)
	{
		cout<<"This is Child Thread."<<endl;
	}
	Sleep(2000);
	cout<<"Child Thread End."<<endl;
}

void main()
{
	thread th(thread_fun);
	//th.detach();

	for(int i=0; i<10; ++i)
	{
		cout<<"This is Main Thread."<<endl;
	}

	cout<<"Main Thread End."<<endl;
}


/*
void thread_fun()
{
	for(int i=0; i<10; ++i)
	{
		cout<<"This is Child Thread."<<endl;
	}
}

void main()
{
	thread th(thread_fun);
	cout<<"thread id = "<<th.get_id();
	//if(th.joinable())
	for(int i=0; i<10; ++i)
	{
		cout<<"This is Main Thread."<<endl;
	}

	th.join();  //阻塞
}

/*
void main()
{
	auto f1 = []{cout<<"This is f1."<<endl;};  //匿名函数
	auto f2 = []{cout<<"This is f2."<<endl;};
	f1();
	f2();

	cout<<typeid(f1).name()<<endl;

	//f1 = f2;
	auto f3 = f1;
	f3();

	void(*pfun)() = f1;
	pfun();
}

/*
int z = 300;
void main()
{
	
	int x = 100;
	int y = 200;
	auto fun = [&](int a, int b)mutable->int
	{
		x = 1;
		y = 2;
		z = 3;
		return a + b + x+y + z;
	};   //value
	
	cout<<fun(10,20)<<endl;

	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"z = "<<z<<endl;
}

/*
// []()->{}
int z = 300;
void main()
{
	
	int x = 100;
	int y = 200;
	auto fun = [x,y](int a, int b)mutable->int
	{
		x = 1;
		return a + b + x+y + z;
	};   //value
	
	cout<<fun(10,20)<<endl;

	cout<<"x = "<<x<<endl;
}

/*
void main()
{
	auto fun = []{cout<<"This is Lamuda ."<<endl;};
	fun();
}

/*
struct Goods
{
	string _name;
	double _price;
};

void main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, {"菠萝", 1.5} };
	int n = sizeof(gds) / sizeof(gds[0]);
	sort(gds, gds+n, [](const Goods &gds1, const Goods &gds2)->bool{return gds1._price < gds2._price;});
}

/*
struct Goods
{
	string _name;
	double _price;
};
struct Compare
{
	bool operator()(const Goods &gds1, const Goods &gds2)const
	{
		return gds1._price < gds2._price;
	}
};

void main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, {"菠萝", 1.5} };
	int n = sizeof(gds) / sizeof(gds[0]);
	sort(gds, gds+n, Compare());

}

/*
struct Goods
{
	string _name;
	double _price;
	bool operator<(const Goods &gds)const
	{
		return _price < gds._price;
	}
};

void main()
{
	Goods gds[] = { { "苹果", 2.1 }, { "相交", 3 }, { "橙子", 2.2 }, {"菠萝", 1.5} };
	int n = sizeof(gds) / sizeof(gds[0]);
	sort(gds, gds+n, less<Goods>());

}
/*
void  main()
{
	int ar[] = {43,432,32,4,3,21,9,0,7,8,6,5};
	int n = sizeof(ar) / sizeof(ar[0]);

	//sort(ar, ar+n); //
	sort(ar, ar+n, greater<int>());

}

/*
void Fun(int &x)
{
	cout << "lvalue ref" << endl;
}
void Fun(int &&x)
{
	cout << "rvalue ref" << endl;
}
void Fun(const int &x)
{
	cout << "const lvalue ref" << endl;
}
void Fun(const int &&x)
{
	cout << "const rvalue ref" << endl;
}


template<typename T>
void PerfectForward(T &&t)
{
	cout<<typeid(t).name()<<endl;
	Fun(forward<T>(t));           //完美转发
	//Fun(t);
}
int main()
{
	PerfectForward(10); // rvalue ref
	int a = 10;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;
}

/*
class String
{
public:
	String(char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s) : _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String(String &&s) : _str(s._str)
	{
		s._str = nullptr;
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
		return *this;
	}
	String operator+(const String& s)
	{
		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
		strcpy(pTemp, _str);
		strcpy(pTemp + strlen(_str), s._str);
		String strRet(pTemp);
		delete []pTemp;
		return strRet;
	}
	~String()
	{
		if (_str) 
			delete[] _str;
	}
private:
	char* _str;
};

class Person
{
public:
	Person(char* name, char* sex, int age)
		: _name(name)
		, _sex(sex)
		, _age(age)
	{}
	Person(Person && p)
		: _name(move(p._name))
		, _sex(move(p._sex))
		, _age(p._age)
	{}
private:
	String _name;
	String _sex;
	int _age;
};
Person GetTempPerson()
{
	Person p("prety", "male", 18);
	return p;
}
int main()
{
	Person p(GetTempPerson());
	return 0;
}

/*
void fun(const int &a)
{
	cout<<a<<endl;
}
void fun(int &&a)
{
	cout<<a<<endl;
}

void main()
{
	String s1("Hello");
	String s2(move(s1));
}

/*
void main()
{
	String s1("Hello");
	String s2("Bit.");
	String s3 = s1 + s2;

	String s4 = s3;
}

/*
void main()
{
	fun(10);
}

/*
void main()
{
	String s1("Hello");
	String s2("Bit.");
	String s3 = s1 + s2;

	const int &a = 10;
	int &&b = 10;
}
*/