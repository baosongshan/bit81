#include<iostream>
#include<vld.h>
using namespace std;

//++
class Test
{
public:
	Test(int data = 0) : m_data(data)
	{
		cout<<"Create Test Object : "<<this<<endl;
	}
	Test(const Test &t)
	{
		cout<<"Copy Create Test Object : "<<this<<endl;
	}
	Test& operator=(const Test &t)
	{
		cout<<"Assign,"<<this<<" = "<<&t<<endl;
		if(this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout<<"Free Test Object : "<<this<<endl;
	}
public:
	void InitObject(int data = 0)
	{
		cout<<"Init Test Object."<<endl;
		m_data = data;
	}
	void DestroyObject()
	{
		cout<<"Destroy Test Object."<<endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};

void* operator new(size_t sz)
{
	void *p = malloc(sz);
	return p;
}
void operator delete(void *ptr)
{
	free(ptr);
}

void main()
{
	Test *pt = new Test[10];   //new operator 
	delete []pt;
}

/*
void main()
{
	//Test *pt = new Test;   //new operator 
	Test *pt = (Test*)malloc(sizeof(Test));
	//Test *pt = (Test*)operator new(sizeof(Test));
	delete pt;
}

void UseMallocFree()
{
	Test *pt = (Test*)malloc(sizeof(Test));
	pt->InitObject(1);

	pt->DestroyObject();
	free(pt);
}

void UseNewDelete()
{
	Test *pt = new Test(1); //1 申请空间  2 调动构造函数
	delete pt;              //1 析构对象  2 释放空间
}
void main()
{
	//UseMallocFree();
	UseNewDelete();
}


/*
void main()
{
	int *p1 = new int[10];
	//cout<<*p1<<endl;
	delete [10]p1;
}

/*
void main()
{
	int *p1 = new int(10);
	cout<<*p1<<endl;
	delete p1;
}

/*
void main()
{
	//int *p1 = (int *)malloc(sizeof(int) * 10); //动态分配
	int *p1 = new int;
	delete p1;
}

/*
void main()
{
	int ar[10] = {0}; // 静态分配
	int *p1 = (int *)malloc(sizeof(int) * 10); //动态分配
	free(p1);
	int *p2 = (int*)calloc(10, sizeof(int));
	free(p2);

	int *pa = (int*)malloc(sizeof(int)*50);
	int *p3 = (int*)realloc(pa, sizeof(int)*10);
	free(p3);

	int *p4 = (int*)_alloca(sizeof(int) * 10);
	//free(p4);
}

/*
void main()
{
	char str[] = "abc"; //
	char *str1 = "abc";
}

/*
class Test
{
public:
	Test(int data = 0) : m_data(data)
	{
		cout<<"Create Test Object : "<<this<<endl;
	}
	Test(const Test &t)
	{
		cout<<"Copy Create Test Object : "<<this<<endl;
	}
	Test& operator=(const Test &t)
	{
		cout<<"Assign,"<<this<<" = "<<&t<<endl;
		if(this != &t)
		{
			m_data = t.m_data;
		}
		return *this;
	}
	~Test()
	{
		cout<<"Free Test Object : "<<this<<endl;
	}
public:
	int GetData()const
	{
		return m_data;
	}
private:
	int m_data;
};

Test fun(const Test &x)
{
	int value = x.GetData();
	return Test(value);    
}

void main()
{
	Test t(10);
	Test y = fun(t);
}

/*
Test fun(Test x)
{
	int value = x.GetData();
	return Test(value);     //
}

void main()
{
	Test t(10);
	Test y;
	y = fun(t);
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
	Test t(10);
	Test y = fun(t);
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
	Test t(10);
	Test y;
	y = fun(t);
}

/*
void fun(const Test &x)
{
	int value = x.GetData();
	Test tmp(value);
}

void main()
{
	Test t(10);
	fun(t);
}

/*
void fun(Test x)
{
	int value = x.GetData();
	Test tmp(value);
}

void main()
{
	Test t(10);
	fun(t);
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
	int GetWeek(int year, int month, int day);
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
	if(_year > d._year)
		return true;
	else if(_year < d._year)
		return false;
	else if(_month > d._month)
		return true;
	else if(_month < d._month)
		return false;
	else if(_day > d._day)
		return true;
	return false;
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
	//
}

//dt1 - dt2
int Date::operator-(const Date& d)
{
	//
}
int Date::GetWeek(int year, int month, int day)
{
	//
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
	Date dt1(2019,12,9);
	cout<<dt1<<endl;
	Date dt = dt1 - 20;
	cout<<dt1<<endl;
}

/*
void main()
{
	Date dt1(2019,12,9);
	cout<<dt1<<endl;
	//Date dt = dt1 + 35;
	++dt1;  //dt1.operator++()
	dt1++;  //dt1.operator++(0)

	//dt = dt1 + dt2;  //dt1.operator+(dt2) //==> operator+(&dt1, dt2);

	cout<<dt1<<endl;
	cout<<tmp<<endl;
}

/*
void main()
{
	Date dt1(2011,12,29);
	Date dt2(2019,12,19);

	//dt1.operator!=(dt2);
	if(dt1 == dt2)
		cout<<"dt1 == dt2"<<endl;

	if(dt1 != dt2)
		cout<<"dt1 != dt2"<<endl;

	if(dt1 > dt2)
		cout<<"dt1 > dt2"<<endl;

	if(dt1 <= dt2)
		cout<<"dt1 <= dt2"<<endl;

	Date dt3 = dt2;
}
*/