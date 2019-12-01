#include<iostream>
using namespace std;

class Int
{
	friend ostream& operator<<(ostream &out, const Int &x);
	friend istream& operator>>(istream &in, Int &x);
public:
	Int(int i=0) : m_i(i)
	{}
	~Int()
	{}
public:
	Int operator+(const Int &x);
	Int operator-(const Int &x);
	Int operator*(const Int &x);
	Int operator/(const Int &x);
	Int operator%(const Int &x);
public:
	//a+=b
	Int& operator+=(const Int &x);
	Int& operator-=(const Int &x);
	Int& operator*=(const Int &x);
	Int& operator/=(const Int &x);
	Int& operator%=(const Int &x);
public:
	bool operator==(const Int &x);
	bool operator!=(const Int &x);
	bool operator>(const Int &x);
	bool operator<=(const Int &x);
	bool operator<(const Int &x);
	bool operator>=(const Int &x);
public:
	Int& operator++()  // ++i
	{
		m_i++;
		return *this;
	}
	Int operator++(int)
	{
		//Int tmp(m_i); //
		//m_i++;
		//return tmp;

		Int tmp(*this);
		++*this;
		return tmp;

	}
	Int& operator--();
	Int  operator--(int);
private:
	int m_i;
};

ostream& operator<<(ostream &out, const Int &x)
{
	out<<x.m_i;
	return out;
}
istream& operator>>(istream &in, Int &x)
{
	in>>x.m_i;
	return in;
}
///////////////////////////////////////////////////
Int Int::operator+(const Int &x)
{
	return Int(m_i + x.m_i);
}
Int Int::operator-(const Int &x)
{
	return Int(m_i - x.m_i);
}
Int Int::operator*(const Int &x)
{
	return Int(m_i * x.m_i);
}
Int Int::operator/(const Int &x)
{
	return Int(m_i / x.m_i);
}
Int Int::operator%(const Int &x)
{
	return Int(m_i % x.m_i);
}
/////////////////////////////////////////////////////
Int& Int::operator+=(const Int &x)
{
	m_i += x.m_i;
	return *this;
}
Int& Int::operator-=(const Int &x)
{
	m_i -= x.m_i;
	return *this;
}
Int& Int::operator*=(const Int &x)
{
	m_i *= x.m_i;
	return *this;
}
Int& Int::operator/=(const Int &x)
{
	m_i /= x.m_i;
	return *this;
}
Int& Int::operator%=(const Int &x)
{
	m_i %= x.m_i;
	return *this;
}

//////////////////////////////////////////////////////////////
bool Int::operator==(const Int &x)
{
	return m_i == x.m_i;
}
bool Int::operator!=(const Int &x)
{
	//return m_i != x.m_i;
	return !(*this == x);
}
bool Int::operator>(const Int &x)
{
	return m_i > x.m_i;
}
bool Int::operator<=(const Int &x)
{
	//return m_i <= x.m_i;
	return !(*this > x);
}
bool Int::operator<(const Int &x)
{
	return m_i < x.m_i;
}
bool Int::operator>=(const Int &x)
{
	//return m_i >= x.m_i;
	return !(*this < x);
}

void main()
{
	Int a = 1;
	Int b = 2;
	if(a == b)
		cout<<"a == b"<<endl;
	else
		cout<<"a != b"<<endl;

	Int v = a + b;
}

/*
void main()
{
	Int i = 0;
	Int v = i++;

	cout<<"v = "<<v<<endl;
	cout<<"i = "<<i<<endl;

}


/*
Int operator++(int)
	{
		Int tmp(m_i); //
		m_i++;
		return tmp;
	}

void main()
{
	Int a = 3;
	Int b = 10;

	// v = a - b;
	//cout<<"v = "<<v<<endl;

	a += b;
	cout<<"a = "<<a<<endl;

	
}

/*
class Complex
{
	friend ostream& operator<<(ostream &out, const Complex &c);
	friend Complex operator+(int x, const Complex &c);
public:
	            //3           0
	Complex(int real=0, int imag=0) : m_real(real),m_imag(imag)
	{}
	~Complex()
	{}
public:
	int GetReal()const
	{return m_real;}
	int GetImag()const
	{return m_imag;}
public:
	//  a + b  a.operator(b) ==> operator+(&a, b);
	Complex operator+(const Complex &c)
	{
		Complex tmp(m_real+c.m_real, m_imag+c.m_imag);
		return tmp;
		//无名临时对象的语法
		//return Complex(m_real+c.m_real, m_imag+c.m_imag);
	}
	Complex operator-(const Complex &c);
	//c + x
	Complex operator+(int x)
	{
		Complex tmp(m_real+x, m_imag);
		return tmp;
	}
	//a += b
	Complex& operator+=(const Complex &c)
	{
		m_real += c.m_real;
		m_imag += c.m_imag;
		return *this;
	}
private:
	int m_real;
	int m_imag;
};

//ostream cout

ostream& operator<<(ostream &out, const Complex &c)
{
	out<<"("<<c.GetReal()<<":"<<c.GetImag()<<")";
	return out;
}

Complex operator+(int x, const Complex &c)
{
	Complex tmp(c.m_real+x, c.m_imag);
	return tmp;
}


void main()
{
	Complex c1(1,2);
	Complex c2(2,3);

	Complex c(0,0);
	c = c1 + c2;
	cout<<c<<endl;

	c1 += c2;
	cout<<c1<<endl;

	//c = c2 + 3;  // c + c
	c = 3 + c2;
	cout<<c<<endl;

}

/*
void main()
{
	Complex c1(1,2);
	Complex c2(2,3);

	//内置类型
	int a = 10;
	char ch = 'A';
	cout<<a<<endl;
	cout<<ch<<endl;

	//(operator<<(cout, c1))<<endl;
	cout<<c1<<endl;

	//cout<<c1<<endl;
	//cout<<c2<<endl;
}


/*
class Complex;
void Print(const Complex &c);

class Complex
{
	friend void Print(const Complex &c); //友元  //成员
public:
	Complex(int real=0, int imag=0) : m_real(real),m_imag(imag)
	{}
	~Complex()
	{}
public:
	int GetReal()const
	{return m_real;}
	int GetImag()const
	{return m_imag;}
private:
	int m_real;
	int m_imag;
};

void Print(const Complex &c)
{
	cout<<c.m_real<<":"<<c.m_imag<<endl;
	//cout<<"("<<c.GetReal()<<":"<<c.GetImag()<<")"<<endl;
}

void main()
{
	Complex c1(1,2);
	Complex c2(2,3);

	//cout<<c1<<endl;
	//cout<<c2<<endl;
	Print(c1);
}

/*
class Test;
ostream& operator<<(ostream &out, const Test &t);

class Test
{
	friend ostream& operator<<(ostream &out, const Test &t);
public:
	Test(int data = 0);
	Test(const Test &t);
	Test& operator=(const Test &t);
	~Test();
public:
	Test* operator&(); //取址函数  重载
	const Test* operator&()const;
public:
	//t1 +t2 ==> t1.Add(t2);
	Test Add(const Test &t)
	{
		int sum = m_data + t.m_data;
		Test tmp(sum);
		return tmp;
	}
	Test operator+(const Test &t)
	{
		int sum = m_data + t.m_data;
		Test tmp(sum);
		return tmp;
	}
public:
	void Print()const
	{
		cout<<m_data<<endl;
	}
private:
	int m_data;
};
/////////////////////////////////////////////////

Test::Test(int data) : m_data(data) //初始化列表
{
	//m_data = data;
}
Test::Test(const Test &t)
{
	m_data = t.m_data;
}
Test& Test::operator=(const Test &t)
{
	if(this != &t)
	{
		m_data = t.m_data;
	}
	return *this;
}
Test::~Test()
{}

Test* Test::operator&()
{
	return this;
}
const Test* Test::operator&()const
{
	return this;
}
ostream& operator<<(ostream &out, const Test &t)
{
	out<<t.m_data;
	return out;
}

void main()
{
	Test t1(100);
	Test t2(20);

	Test t = t1 + t2;
	//Test t = t1.operator+(t2);
	//Test t = t1.Add(t2);
	cout<<t<<endl;
}

/*
void main()
{
	const Test t(10);
	const Test *pt = &t; //&t ==> t.operator&() ==>operator&(&t)
	//cout<<t<<endl;
	//t.Print();

	cout<<t<<endl;
}
*/