#include<iostream>
//#include<vld.h>
#include<assert.h>
using namespace std;


int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}

/*
class Test
{
public:
	static Test* GetInstance()
	{
		if(_instance == nullptr)	
		{
			_instance = new Test;  //1
		}
		return _instance;
	}
private:
	Test(int data=0) : m_data(data)
	{
		cout<<"Create Test Object."<<endl;
	}
private:
	int m_data;
	static Test *_instance;
};
Test* Test::_instance = nullptr;

void main()
{
	Test *pt = Test::GetInstance();
	Test *pt1 = Test::GetInstance();
	Test *pt2 = Test::GetInstance();
	Test *pt3 = Test::GetInstance();
	Test *pt4 = Test::GetInstance();
}

/*
class Test
{
public:
	Test(int data=0) : m_data(data)
	{
		cout<<"Create Test Object."<<endl;
	}
	~Test()
	{
		cout<<"Free Test Object."<<endl;
	}
protected:
	void* operator new(size_t sz);
private:
	int m_data;
};

void main()
{
	//Test *pt = new Test;
	//n
	Test t;
	Test t1;
	Test t2;

}

/*
class Test
{
public:
	static Test* GetInstance()
	{
		return new Test;
	}
public:
	~Test()
	{
		cout<<"Free Test Object."<<endl;
	}
protected:
	Test(int data=0) : m_data(data)
	{
		cout<<"Create Test Object."<<endl;
	}
	Test(const Test &t);
	Test& operator=(const Test &t);
private:
	int m_data;
};

void main()
{
	Test *pt = Test::GetInstance();
}

/*
void handle_out_of_memory()
{
	cout<<"Out Of Memory."<<endl;
	exit(1);
}

void main()
{
	set_new_handler(handle_out_of_memory); //预防内存不足
	int *p = new int[536870911];
	
	//1 申请成功 
	//2 申请不成功 
    //  如果没有设置set_new_handler  直接抛出异常 bad_alloc
	//  设置了set_new_handler 则执行设置的函数
	cout<<"OK."<<endl;
}

/*
class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data=0) : m_data(data)
	{
		cout<<"Create Test Object."<<endl;
	}
	~Test()
	{
		cout<<"Free Test Object."<<endl;
	}
private:
	int m_data;
};

void main()
{
	//空间配置器
	Test *pt = (Test *)malloc(sizeof(Test));
	new(pt) Test(1);
}

/*
void* operator new(size_t sz, int *ptr, int pos)
{
	//return (ptr + pos);
	return &ptr[pos];
}

void main()
{
	//int ar[10] = {0};
	int *ar = (int*)malloc(sizeof(int)*10);
	new(ar, 0)  int(1); //  new(ptr) object(value)
	new(ar, 8)  int(2);
	new(ar, 5)  int(3);
	new(ar, 3)  int(4);
}

/*
class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data=0) : m_data(data)
	{
		cout<<"Create Test Object."<<endl;
	}
	~Test()
	{
		cout<<"Free Test Object."<<endl;
	}
private:
	int m_data;
};

void main()
{
	//STL
	Test *pt = (Test*)operator new(sizeof(Test)); //malloc
	operator delete(pt);                          //free
}

/*
class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data=0) : m_data(data)
	{
		cout<<"Create Test Object."<<endl;
	}
	~Test()
	{
		cout<<"Free Test Object."<<endl;
	}
public:
	void* operator new(size_t sz)
	{
		void *ptr = malloc(sz);
		assert(ptr != nullptr); //成功
		return ptr;
	}
	void operator delete(void *ptr)
	{
		cout << "3333333333333" << endl;
		free(ptr);
	}
private:
	int m_data;
};

ostream& operator<<(ostream &out, const Test &t)
{
	out<<t.m_data;
	return out;
}

/////////////////////////////////////////////
//针对的是单个对象
void* operator new(size_t sz)
{
	void *ptr = malloc(sz);
	assert(ptr != nullptr); //成功
	return ptr;
}
void operator delete(void *ptr)
{
	cout<<"111111111111111"<<endl;
	free(ptr);
}

////////////////////////////////////////////////
//针对的是数组对象
void* operator new[](size_t sz)
{
	void *ptr = malloc(sz);
	assert(ptr != nullptr);
	return ptr;
}
void operator delete[](void *ptr)
{
	cout<<"2222222222222222"<<endl;
	free(ptr);
}

void main()
{
	Test *pt = new Test;
	delete pt;
}
/*
//new operator 
void main()
{
	//Test *pt = new Test(10);
	//delete pt;

	Test *pt = (Test*)malloc(sizeof(Test)*10);
	free(pt);

	Test *pt1 = (Test*)operator new(sizeof(Test)*10); //
	operator delete(pt1); //
}

/*
class String
{
public:
	String(const char *str = "")
	{
		m_data = new char[strlen(str)+1];
		strcpy(m_data, str);
	}
	~String()
	{
		delete []m_data;
	}
private:
	char *m_data;
};

void main()
{
	String *ps = new String("Hello");
	delete ps;
}

/*
class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data) : m_data(data)
	{
		cout<<"Create Test Object."<<endl;
	}
	~Test()
	{
		cout<<"Free Test Object."<<endl;
	}
private:
	int m_data;
};

ostream& operator<<(ostream &out, const Test &t)
{
	out<<t.m_data;
	return out;
}

//new 
//1 new operator 
//2 operator new
//3 placement new

void main()
{
	Test t1(100);
	Test *pt = new Test(3); //1 开辟空间  2 调动构造函数初始化对象
	cout<<*pt<<endl;
	delete pt;              //1 调动析构函数析构对象 2 释放空间
	pt = &t1;
	cout<<*pt<<endl;
}

/*
void main()
{
	int *p = new int;
	delete p;

	int *p1 = new int(10);
	delete p1;

	int *p2 = new int[10];
	delete []p2; 
}


/*
class Date
{
	friend ostream& operator<<(ostream &out, const Date &dt);
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);
	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
public:
	int GetWeek();
private:
	int _year;
	int _month;
	int _day;
};

///////////////////////////////////////////////////////////
Date::Date(int year, int month, int day)
	:_year(year), _month(month),_day(day)
{
	//_year = year;
	//_month = month;
	//_day = day;
}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}
Date& Date::operator=(const Date& d)
{
	if(this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

bool Date::operator==(const Date& d)const
{
	return (_year==d._year && _month==d._month && _day==d._day);
}
bool Date::operator!=(const Date& d)const
{
	//return _year!=d._year || _month!=d._month || _day=!d._day;
	return !(*this == d);
}
bool Date::operator>(const Date& d)const
{
	return (_year>d._year) 
		   || (_year==d._year&&_month>d._month)
		   || (_year==d._year&&_month==d._month&&_day>d._day);
}
bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}

bool Date::operator<(const Date& d)const
{
	if(_year < d._year)
		return true;
	else if(_year > d._year)
		return false;
	else if(_month < d._month)
		return true;
	else if(_month > d._month)
		return false;
	else if(_day < d._day)
		return true;
	return false;
}

bool Date::operator>=(const Date& d)const
{
	return !(*this<d);
}

ostream& operator<<(ostream &out, const Date &dt)
{
	out<<dt._year<<"年"<<dt._month<<"月"<<dt._day<<"日";
	return out;
}
//////////////////////////////////////////////////////////
bool IsLeap(int year)
{
	if((year%4==0 && year%100!=0) || (year%400==0))
		return true;
	return false;
}
int GetDayByYearMonth(int year, int month)
{
	int days[13] = {29,31,28,31,30,31,30,31,31,30,31,30,31};//查表
	if(month == 2)
	{
		if(IsLeap(year))
			month = 0;
	}
	return days[month];
}

Date Date::operator+(int days)
{
	Date tmp = *this;
	int mdays = GetDayByYearMonth(tmp._year, tmp._month);
	while(days + tmp._day > mdays)
	{
		tmp._month++;
		if(tmp._month > 12)
		{
			tmp._month = 1;
			tmp._year++;	
		}
		days -= mdays;
		mdays = GetDayByYearMonth(tmp._year, tmp._month);
	}
	tmp._day += days;
	return tmp;
}

Date Date::operator-(int days)
{
	int mdays;
	Date tmp = *this;
	while(tmp._day - days < 1)
	{
		tmp._month--;
		if(tmp._month < 1)
		{
			tmp._month = 12;
			tmp._year--;
		}
		mdays = GetDayByYearMonth(tmp._year, tmp._month);
		days -= mdays;
	}
	tmp._day -= days;
	return tmp;
}

/*
//dt1 - dt2
int Date::operator-(const Date& d)
{
	//
}


//W=(Y-1)+[(Y-1)/4]-[(Y-1)/100]+[(Y-1)/400]+D．
//return W % 7
//D 代表day在这一年的累计天数
int Date::GetWeek()
{
	int D = 0;
	for(int i=1; i<_month; ++i)
	{
		D += GetDayByYearMonth(_year, i);
	}
	D += _day;

	int W = (_year-1)+(_year-1)/4 - (_year-1)/100 + (_year-1)/400 + D;
	return W % 7; // 0 1 2 3 4 5 6 
}

Date& Date::operator++()
{
	*this = *this + 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp = *this;
	++*this;
	return tmp;
}

///////////////////////////////////////////////////////////
void main()
{
	Date dt1(2020,4,16);
	cout<<dt1.GetWeek()<<endl;
}
*/