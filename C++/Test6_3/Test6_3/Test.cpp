#include<iostream>
#include<vld.h>
#include<string>
#include<memory>
using namespace std;

//������� -->����ָ��Ŀ�ɽ����
template<class _Ty>
class my_auto_ptr 
{
public:
	my_auto_ptr(_Ty *_P=0) : _Owns(_P!=0), _Ptr(_P)
	{}
	my_auto_ptr(const my_auto_ptr<_Ty> &_Y);
	my_auto_ptr<_Ty>& operator=(const my_auto_ptr<_Ty> &_Y);
	~my_auto_ptr()
	{
		if(_Owns)
			delete _Ptr;
	}
public:
	_Ty& operator*()
	{
		return *_Ptr;
	}
	_Ty* operator->()
	{
		return _Ptr;
	}
private:
	bool _Owns;
	_Ty *_Ptr;
};

class Test
{
public:
	void fun()
	{
		cout<<"This is Test::fun()"<<endl;
	}
};

void main()
{
	int *p = new int(1);    //new int[10]
	my_auto_ptr<int> ap(p); //����������
	cout<<*ap<<endl;

	my_auto_ptr<int> ap1;
	ap1 = ap; //ӵ��Ȩ��ת��
}

/*
//RAII ��Դ��ȡ����ʼ��  �Զ�
void main()
{
	int *p = new int(1);    //new int[10]
	my_auto_ptr<int> ap(p); //����������
	cout<<*ap<<endl;

	my_auto_ptr<Test> ap1(new Test);
	ap1->fun();
}

/*
//����ģʽ
//���� ָ��  -->1   -->2
//raii 
void main()
{
	//�¹���
	int *tmp = new int(100);
	auto_ptr<int> ap(tmp);  //����  �����ͷ�  �쳣�˳�
	cout<<*ap<<endl;

	auto_ptr<string> ap1(new string("Hellobit"));
	cout<<ap1->size()<<endl;
}

/*
//һ��Ҫ��ס --> ����ʧ�֣�����ʧ��

void main()
{
	int *tmp = new int[10];

	try
	{
		Div(10, 0);
		delete []tmp; //
	}
	catch(...)
	{}
	

	
}


/*
 //ջ���쳣����
template<typename T>
class pushOnFull
{
	T _value;
public:
	pushOnFull(T i)
	{
		_value=i;
	}
	T value()const
	{
		return _value;
	}
	void print()const
	{
		cerr<<"ջ����"<<value()<<"δѹ��ջ"<<endl;
	}
};

//ջ���쳣����
template<typename T>
class popOnEmpty
{
public:
	void print()const
	{
		cerr<<"ջ�ѿգ��޷���ջ"<<endl;
	}
};

template<typename T>
class Stack
{
	int top;                                    //ջ��ָ�루�±꣩
	T *elements;                               //��̬��������ֵ
	int maxSize;                               //ջ������ɵ�Ԫ�ظ���
public:
	Stack(int sz=5)
	{
		maxSize = sz > 5 ? sz : 5;
		elements = new T[maxSize];
		top = 0;
	}
	~Stack()
	{
		delete[] elements;
	}
public:
	void Push(const T &data) 
	{
		if(IsFull())
			throw pushOnFull<T>(data);
		elements[top++] = data;
	}
	T Pop()
	{
		if(IsEmpty())
			throw popOnEmpty<T>();
		top--;
	}
public:
	T GetElem(int i)
	{
		return elements[i];
	} 
	void MakeEmpty()
	{
		top= 0;
	}
	bool IsEmpty() const
	{
		return top == 0;
	}
	bool IsFull() const
	{
		return top==maxSize;
	}   
	void PrintStack()
	{
		for(int i=top-1; i>=0; --i)
			cout<<elements[i]<<endl;
	}
};


void main()
{
	Stack<int> st;
	try
	{
		//st.Pop();
		st.Push(1);
		st.Push(2);
		st.Push(3);
		st.Push(4);
		st.Push(5);

		st.Push(6);
	}
	catch(const popOnEmpty<int> &e)
	{
		e.print();
	}
	catch(const pushOnFull<int> &e)
	{
		e.print();
	}
	catch(...)
	{
		cout<<"Unkown Exception."<<endl;
	}
	
}


/*
void fun(int ar[], int pos)
{
	if(pos >= 10)
	{
		throw out_of_range("array out of range.....");
	}
	cout<<ar[pos]<<endl;
}

void main()
{
	try
	{
		int ar[10] = {0};
		fun(ar, 10);
	}
	catch(const out_of_range &e)
	{
		cout<<e.what()<<endl;
	}
}

/*
void main()
{
	try
	{
		int *ptr = new int[536870911];

		cout<<"new int OK."<<endl;
		delete []ptr;
	}
	catch(const bad_alloc &e)
	{
		cout<<"bad_alloc :"<<endl;
		//e.what();
	}
}

/*
class Exception
{
public:
	virtual void What() = 0;
public:
	string _errmsg = "Have a Exception.";
};
class SqlException : public Exception
{
public:
	virtual void What()
	{
		cout<<"SqlException Exception"<<endl;
	}
};
class CacheException : public Exception
{
public:
	virtual void What()
	{
		cout<<"CacheException Exception"<<endl;
	}

};
class HttpServerException : public Exception
{
public:
	virtual void What()
	{
		cout<<"HttpServerException Exception"<<endl;
	}
};

void Startup()
{
	//throw SqlException();
	throw HttpServerException();
}

int main()
{
	try
	{
		Startup();
	}
	catch (Exception& e)
	{
		e.What(); //��̬
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;
}

/*
double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	int* array = new int[10];
	try 
	{
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;  //
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;    //˦��
	}
	cout << "delete []" << array << endl;
	delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}

/*
class Test
{};
//�����׳�һ���쳣
//�쳣�淶 Linux
int Div(int a, int b)
{
	//char ch = 'A';
	//double d = 12.34;
	Test t;
	if(b == 0)
	{
		throw t;  //�׳��쳣  
	}
	cout<<"aaaaaaaaaaaaaaaaa"<<endl;
	return a / b;   // 0
}

void main()
{
	try  //�п���
	{
		int *p = new int[10];

		cout<<Div(10,0)<<endl;

		cout<<"qqqqqqqqqqqqqqqq"<<endl;
		delete []p;
	}
	catch(int &e)
	{
		cout<<"e1 = "<<e<<" Div Error, b == 0."<<endl;
	}
	catch(char &e)
	{
		cout<<"e2 = "<<e<<" Div Error, b == 0."<<endl;
	}
	catch(...)
	{
		cout<<"e3  Div Error."<<endl;
	}
}

/*
//ֱ�ӽ�������
//����
//�쳣
int Div(int a, int b)
{
	if(b == 0)
	{
		cout<<"Div Error, b == 0."<<endl;
		exit(1);
	}
	return a / b;   // 0
}

void main()
{
	cout<<Div(10,0)<<endl;
}
*/