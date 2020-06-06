#include<iostream>
#include<vld.h>
#include<string>
#include<memory>
#include<thread>
#include<mutex>
using namespace std;

template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)	: _ptr(ptr)	, _pRefCount(new int(1)), _pMutex(new mutex)
	{}
	SharedPtr(const SharedPtr<T>& sp) : _ptr(sp._ptr), _pRefCount(sp._pRefCount),_pMutex(sp._pMutex)
	{
		AddRefCount();
	}
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			Release();
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			AddRefCount();
		}
		return *this;
	}
	~SharedPtr() 
	{
		Release();
	}
public:
	void AddRefCount()
	{
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
	void Release()
	{
		bool deleteflag = false;
		_pMutex->lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex->unlock();
		if(deleteflag)
			delete _pMutex;
	}
	T& operator*() 
	{
		return *_ptr;
	}
	T* operator->() 
	{
		return _ptr; 
	}
	int UseCount()
	{
		return *_pRefCount; 
	}
	T* Get()
	{
		return _ptr;
	}
private:
	int* _pRefCount; // 引用计数
	T*   _ptr;       // 指向管理资源的指针
	mutex *_pMutex;
};

class Date
{
public:
	Date() { cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }
	int _year = 0;
	int _month = 0;
	int _day = 0;
};

mutex mt;
void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	SharedPtr<Date> copy(sp);
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		// 这里智能指针拷贝会++计数，智能指针析构会--计数，这里是线程安全的。
		//SharedPtr<Date> copy(sp);
		// 这里智能指针访问管理的资源，不是线程安全的。所以我们看看这些值两个线程++了2n次，但
		//是最终看到的结果，并一定是加了2n
		//mt.lock();   //把异步进行顺序-->同步机制
		copy->_year++;
		copy->_month++;
		copy->_day++;
		//mt.unlock();
	}
}

int main()
{
	SharedPtr<Date> p(new Date);
	cout << p.Get() << endl;
	const size_t n = 10000000;

	thread t1(SharePtrFunc, p, n);   //t1
	thread t2(SharePtrFunc, p, n);   //t2

	t1.join();
	t2.join();

	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;
	return 0;
}

/*
void main()
{
	SharedPtr<int> sp(new int(10));
	SharedPtr<int> sp1 = sp;

	SharedPtr<int> sp2(new int(20));
	SharedPtr<int> sp3 = sp2;

	sp1 = sp3;
	//SharedPtr<int> sp1(new int(20));
	//SharedPtr<int> sp2 = sp1;
}

/*
//#include<boost/smart_ptr.hpp>
//using namespace boost;

void main()
{
	int *p = new int(10);
	int *q = new int(20);
	shared_ptr<int> sp(p);
	cout<<*sp<<endl;
	cout<<"sp use  count = "<<sp.use_count()<<endl;
	sp.reset(q);
	cout<<*sp<<endl;
	cout<<"sp use  count = "<<sp.use_count()<<endl;

	shared_ptr<int> sp1 = sp;
	cout<<sp.unique()<<endl;
}

/*
void main()
{
	int *p = new int(10);
	shared_ptr<int> sp(p);
	cout<<*sp<<endl;
	cout<<"sp use  count = "<<sp.use_count()<<endl;
	shared_ptr<int> sp1 = sp;
	cout<<"sp use  count = "<<sp.use_count()<<endl;
	{
		shared_ptr<int> sp2;
		sp2 = sp1;
		cout<<"sp use  count = "<<sp.use_count()<<endl;
	}
	cout<<"sp use  count = "<<sp.use_count()<<endl;

	sp.
}

/*
//C++11
void main()
{
	int *p = new int(10);
	int *q = new int(20);
	unique_ptr<int> sp(p);   //拥有权不允许转移  scoped_ptr
	cout<<*sp<<endl;
	unique_ptr<int> sp1;
	sp1 = sp;
}

/*
void main()
{
	int *p = new int[10] {1,2,3,4,5,6,7,8,9,10};
	scoped_array<int> sa(p);  //数组

	cout<<sa[0]<<endl;
}

/*
namespace bit
{
	template<class T> 
	inline void checked_delete(T * x)
	{
		//用于类型完整度的检查
		typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
		(void) sizeof(type_must_be_complete);

		delete x;
	}

	template<class T> 
	inline void checked_array_delete(T * x)
	{
		typedef char type_must_be_complete[sizeof(T) ? 1 : -1];
		(void) sizeof(type_must_be_complete);
		
		delete[] x;
	}

	template<class T>
	class scoped_ptr 
	{
	private:

		T * px;

		scoped_ptr(scoped_ptr const &);
		scoped_ptr & operator=(scoped_ptr const &);
		typedef scoped_ptr<T> this_type;
		void operator==(scoped_ptr const&) const;
		void operator!=(scoped_ptr const&) const;

	public:

		typedef T element_type;

		explicit scoped_ptr(T * p = 0) : px(p) // never throws
		{  }

		~scoped_ptr() // never throws
		{
			//boost::checked_delete(px);
			delete px;
		}

		void reset(T * p = 0) // never throws
		{
			this_type(p).swap(*this);
		}

		T & operator*() const // never throws
		{
			return *px;
		}

		T * operator->() const // never throws
		{
			return px;
		}

		T * get() const // never throws
		{
			return px;
		}

		void swap(scoped_ptr & b) // never throws
		{
			T * tmp = b.px;
			b.px = px;
			px = tmp;
		}
	};
};

void main()
{
	int *p = new int(10);
	int *q = new int(20);
	bit::scoped_ptr<int> sp(p);   //拥有权不允许转移
	cout<<*sp<<endl;

	sp.reset(q);
	cout<<*sp<<endl;
}

/*
void main()
{
	int *p = new int(10);
	//int *q = new int(20);
	scoped_ptr<int> sp(p);   //拥有权不允许转移
	cout<<*sp<<endl;

	scoped_ptr<string> sp1(new string("bit"));
	cout<<sp1->size()<<endl;

	//scoped_ptr<int> sp2;
	//sp2 = sp;
}

/*
namespace bit
{
	//VS auto_ptr
	
	template<class _Ty>
	class auto_ptr
	{
		typedef auto_ptr<_Ty> _Myt;
	public:
	auto_ptr(_Ty *_Ptr = 0)	: _Myptr(_Ptr)
	{}
	auto_ptr(_Myt& _Right): _Myptr(_Right.release())
	{}
	_Myt& operator=(_Myt& _Right)
	{	
		reset(_Right.release());
		return (*this);
	}
	~auto_ptr() 
	{	
		delete _Myptr;
	}
	public:
		_Ty& operator*() const
		{	
			return (*get());
		}
		_Ty *release()
		{	
			_Ty *_Tmp = _Myptr;
			_Myptr = 0;
			return (_Tmp);
		}
		_Ty *get() const 
		{
			return (_Myptr);
		}
		void reset(_Ty *_Ptr = 0)
		{
			if(_Ptr != _Myptr)
				delete _Myptr;
			_Myptr = _Ptr;
		}
	private:
		_Ty *_Myptr;   //
	};
};

void main()
{
	int *p = new int(10);
	int *q = new int(20);

	int *&s = p;

	bit::auto_ptr<int> ap(p);
	cout<<*ap<<endl;
	ap.reset(s);
	//bit::auto_ptr<int> ap1 = ap;
	cout<<*ap<<endl;
}

/*
namespace bit
{
	//VC   auto_ptr
	template<class _Ty>
	class auto_ptr
	{
	public:
		auto_ptr(_Ty *_P = 0) : _Owns(_P != 0), _Ptr(_P)
		{}
		auto_ptr(const auto_ptr<_Ty> &_Y) : _Owns(_Y._Owns), _Ptr(_Y.release())
		{}
		auto_ptr<_Ty>& operator=(const  auto_ptr<_Ty>& _Y)
		{
			if (this != &_Y) 
			{
				if (_Ptr != _Y.get())
				{
					if (_Owns)
						delete _Ptr;
					_Owns = _Y._Owns;
				}
				else if (_Y._Owns)   //false
					_Owns = true;
				_Ptr = _Y.release();
			}
			return (*this);
		}
		~auto_ptr()
		{
			if (_Owns)
				delete _Ptr;
		}
	public:
		_Ty& operator*()const
		{
			return *_Ptr;
		}
		_Ty* operator->()const
		{
			return _Ptr;
		}
	public:
		_Ty* release()const
		{
			//_Owns = false;
			//*((bool*)&_Owns) = false;
			((auto_ptr<_Ty>*)this)->_Owns = false;  //强制转换 忽略类型
			return _Ptr;
		}
		_Ty* get()const
		{
			return _Ptr;
		}
	private:
		bool _Owns;
		_Ty *_Ptr;
	};
};


/*
void main()
{
	int *p = new int(10);
	bit::auto_ptr<int> ap(p);
	cout<<*ap<<endl;

	bit::auto_ptr<int> ap1 = ap;

	bit::auto_ptr<int> ap2;
	ap2 = ap1;
}

/*
void main()
{
	int *p = new int(10);
	int *q = new int(20);

	bit::auto_ptr<int> ap1(p);
	ap1.release();

	bit::auto_ptr<int> ap2(p);
	ap2 = ap1;
}

/*
void main()
{
	int *p = new int(10);
	int *q = new int(20);

	bit::auto_ptr<int> ap1(p);
	bit::auto_ptr<int> ap2(q);
	cout<<*ap2<<endl;
	ap2 = ap1;
	cout<<*ap2<<endl;
}

/*
//0 RAII
//1 忘记delete 
//2 异常安全
void main()
{
	int *p = new int(10);
	bit::auto_ptr<int> ap(p);
	cout<<*ap<<endl;

	bit::auto_ptr<int> ap1 = ap;
	bit::auto_ptr<int> ap2;
	ap2 = ap1;
}
*/