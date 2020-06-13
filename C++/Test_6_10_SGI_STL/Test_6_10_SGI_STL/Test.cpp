//#include"stl_alloc.h"
#include"stl_vector.h"

void main()
{
	vector<int> iv;
}

/*
void main()
{
	int *ptr = (int*)__default_alloc_template<0,0>::allocate(sizeof(int) * 100);
	int *ptr1 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	int *ptr2 = (int*)__default_alloc_template<0,0>::allocate(sizeof(int));
	int *ptr3= (int*)__default_alloc_template<0,0>::allocate(sizeof(int) * 16);
	//int *ptr4= (int*)__default_alloc_template<0,0>::allocate(sizeof(int) * 8);
	int *ptr5= (int*)__default_alloc_template<0,0>::allocate(sizeof(int) * 24);

	__default_alloc_template<0,0>::deallocate();
}

/*
void OutOfMemory()
{
	cout<<"Out Of Memory."<<endl;
	exit(1);
}
void main()
{
	__malloc_alloc_template<0>::set_malloc_handler(OutOfMemory);
	try
	{
		//int *p = (int *)__malloc_alloc_template<0>::allocate(sizeof(int) *536870911);
		int *p = (int *)__malloc_alloc_template<0>::allocate(sizeof(int));
		__malloc_alloc_template<0>::deallocate(p, sizeof(int));
	}
	catch(bad_alloc &e)
	{
		cout<<e.what()<<endl;
	}
}


/*
void OutOfMemory()
{
	//释放空间
	//垃圾回收器
	cout<<"Out Of Memory."<<endl;
	//exit(1);
}

void main()
{
	set_new_handler(OutOfMemory);  //new
	try
	{
		int *p = new int[536870911];  //malloc
		cout<<"new OK"<<endl;
		delete []p;
	}
	catch(bad_alloc &e)
	{
		cout<<e.what()<<endl;
	}	
}

/*
void main()
{
	try
	{
		int *p = new int[536870911];
		cout<<"new OK"<<endl;
		delete []p;
	}
	catch(bad_alloc &e)
	{
		cout<<e.what()<<endl;
	}	
}



/*
namespace bit
{
	template<class T>
	T* _allocate(size_t size, T*)
	{
		cout<<typeid(T).name()<<endl;
		T *tmp = (T*)(::operator new(size * sizeof(T)));
		if(tmp == 0)
		{
			cout<<"Out of Memory."<<endl;
			exit(1);
		}
		return tmp;
	}
	template<class T>
	void _deallocate(T *buffer)
	{
		::operator delete(buffer);
	}

	template<class T1, class T2>
	void _construct(T1 *p, const T2 &value)
	{
		new(p) T1(value); //定位new
	}
	template<class T>
	void _destroy(T *ptr)
	{
		ptr->~T();
	}

	template<class T>
	class allocator
	{
	public:
		//类型萃取
		typedef T        value_type;
		typedef T*       pointer;
		typedef T&       reference_type;
		typedef const T* const_pointer;
		typedef const T& const_reference;
		typedef size_t   size_type;
		typedef size_t   difference_type;
	public:
		pointer allocate(size_type n, const void *hint=0)
		{
			return _allocate(n, (pointer)nullptr);
		}
		void deallocate(pointer p, size_type n)
		{
			_deallocate(p);
		}
		void construct(pointer p, const T& value)
		{
			_construct(p, value);
		}
		void destroy(pointer p)
		{
			_destroy(p);
		}
	};
};

void main()
{
	list<int, bit::allocator<int> > lt;
	vector<int, bit::allocator<int> > iv(1);
}


/*
void main()
{
	double d = 12.34;
	int a = 10;

	int *p = reinterpret_cast<int*>(&d);
}

/*
class Base
{
public:
	virtual void fun()const
	{
		cout<<"This is Base::fun()"<<endl;
	}
private:
	int m_a = 0;
};

class D : public Base
{
public:
	void fun()const
	{
		cout<<"This is D::fun()"<<endl;
	}
	void show()const
	{
		cout<<"This is D::show()"<<endl;
	}

private:
	int m_c = 0;
};


void Active(Base *pb)
{
	pb->fun();
	//(dynamic_cast<D*>(pb))->show(); //避免
	D *pd = dynamic_cast<D*>(pb);  //用于检查向下转换的合法性
	if(pd != NULL)
		pd->show();
	else
		cout<<"非法的转换...."<<endl;
}

void main()
{
	D d;
	Base b;
	Active(&b);
	
}

/*
class A
{
private:
	int m_a = 0;
};
class B
{
private:
	int m_b = 0;
};

class D : public A, public B
{
private:
	int m_c = 0;
};
void main()
{
	D d;
	printf("%p, %p, %p\n", &d,  static_cast<B*>(&d), reinterpret_cast<B*>(&d)); //重解释
}

/*
void main()
{
	double d = 12.34;
	int *p2 = reinterpret_cast<int*>(&d);
	cout<<*p2<<endl;
}

/*
void main()
{
	const int a = 10;
	int *p = const_cast<int*>(&a);  //用于去掉const 和 volatile

	volatile int b = 10;
	int *p1 = const_cast<int*>(&b);

	double d = 12.34;
	int *p2 = const_cast<int*>(&d);
}


void main()
{
	int a = 10;
	double d = 12.34;
	a = static_cast<int>(d);  //用于替换C中隐式转换
	int *p = static_cast<int*>(&d);
}
*/