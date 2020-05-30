#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<list>
#include<map>
using namespace std;

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
	String(String &&s) : _str(s._str)
	{
		s._str = nullptr;
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
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
		return strRet;
	}

	~String()
	{
		if (_str) delete[] _str;
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2("world");
	String s3(s1 + s2);
	return 0;
}

/*
void main()
{
	int a = 10;
	const int &refa = 10;

	int &&ref = 10; //有什么用
}

/*
class Test
{
	friend Test Add(Test &a, Test &b);
public:
	Test(int data) :m_data(data)
	{
		cout<<"Create Test obj:"<<this<<endl;
	}
	Test(const Test &t)
	{
		cout<<"Copy Create Test obj : "<<this<<endl;
		m_data = t.m_data;
	}
private:
	int m_data = 0;
};

Test Add(Test &a, Test &b)
{
	Test tmp(a.m_data +b.m_data);
	return tmp;
}

void main()
{
	const int a = 10;
	const int &b = a;

	int &&c = 10;
	Test t1(10);
	Test t2(20);
	Test &&v = Add(t1, t2);
}

/*
class Test
{
public:
	Test() = default;
	Test(int data) :m_data(data)
	{}
	Test(const Test &t) = delete;
private:
	//Test(const Test &t);
private:
	int m_data = 0;
};

void main()
{
	Test t;
	Test t1 = t;
}


/*
void main()
{
	map<int, string> ismap;
	ismap.insert(make_pair(1, "abc"));
	ismap.insert(make_pair(5, "xyz"));
	ismap[3] = "lmn";
	ismap[2] = "utr";

	auto it = ismap.begin();

	while(it != ismap.end())
	{
		cout<<it->first<<" : "<<it->second<<endl;
		++it;
	}

	cout<<typeid(it).name()<<endl;

	decltype(it) it1;
	it1 = ismap.begin();
	while(it1 != ismap.end())
	{
		cout<<it1->first<<" : "<<it1->second<<endl;
		++it1;
	}


}

/*
template<class Type>
class MyVector
{
public:
	MyVector(initializer_list<Type> list) :size(0)
	{
		capacity = list.size();
		base = new Type[capacity];

		for(const auto &e : list)
			base[size++] = e;
	}
private:
	Type *base;
	size_t capacity;
	size_t size;
};

void main()
{
	MyVector<int> mv = {1,2,3,4,5,}; 
	list<int> mylist = {1,2,3};
}

/*
class Pointer
{
public:
	Pointer(int x, int y) :m_x(x), m_y(y)
	{}
private:
	int m_x;
	int m_y;
};

void main()
{
	Pointer p1(1,2);
	Pointer p2 = {2,3};
	Pointer pa[]{{1,2},{3,4}, {4,5}};
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v = {1,2,3,4,5,6};   //C++11
	list<int> mylist = {1,2,3,4,5};

	int *ptr = new int[10] {1,2,3,4,5};
}


/*
struct StrToInt1
{
	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;    
		}
		return hash;
	}
	size_t operator()(const string &str)
	{
		return BKDRHash(str.c_str());
	}
};

struct StrToInt2
{
	size_t SDBMHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
		}
		return hash;
	}
	size_t operator()(const string &str)
	{
		return SDBMHash(str.c_str());
	}
};


struct StrToInt3
{
	size_t RSHash(const char *str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
	size_t operator()(const string &str)
	{
		return RSHash(str.c_str());
	}
};

#define _N 1000

//误判率 --> 误判率到底如何计算 0.01%  在

template<class K, class HashFunc1 = StrToInt1,
				  class HashFunc2 = StrToInt2,
				  class HashFunc3 = StrToInt3>
class BloomFilter
{
public:
	BloomFilter() : m_size(0)
	{}
public:
	void Insert(const string &str)
	{
		size_t bit_capacity = m_bmp.size();
		size_t index1 = HashFunc1()(str) % bit_capacity;
		m_bmp.set(index1);
		size_t index2 = HashFunc2()(str) % bit_capacity;
		m_bmp.set(index2);
		size_t index3 = HashFunc3()(str) % bit_capacity;
		m_bmp.set(index3);
		m_size++;
	}
	bool Test(const string &str)
	{
		size_t bit_capacity = m_bmp.size();
		size_t index1 = HashFunc1()(str) % bit_capacity;
		if(!m_bmp.test(index1))
		   return false;
		size_t index2 = HashFunc2()(str) % bit_capacity;
		if(!m_bmp.test(index2))
		   return false;
		size_t index3 = HashFunc3()(str) % bit_capacity;
		if(!m_bmp.test(index3))
		   return false;

		return true; //可能存在
	}
private:
	bitset<_N*5> m_bmp;  //  0 1
	size_t       m_size;
};

void main()
{
	BloomFilter<string> bf;
	string str0 = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
	string str1 = "ttps://www.cnb";
	string str2 = "https://www.cnblogs";
	string str3 = "https://www.cnblogs.com/clq/archive/2012/05/31/2528153.html";
	bf.Insert(str0);
	bf.Insert(str1);
	bf.Insert(str2);
	bf.Insert(str3);

	cout<<bf.Test(str2)<<endl;

	string str = "https://www.cnblogs.com/.clq/archive/2012/05/31/2528153.html";
	cout<<bf.Test(str)<<endl;

	string str4 = "baidu.com";
	cout<<bf.Test(str4)<<endl;
}

/*
template<size_t _N>
class Bitset;

ostream& operator<<(ostream &out, const Bitset<10> &bt);

template<size_t _N>
class  Bitset
{
	friend ostream& operator<<(ostream &out, const Bitset<10> &bt);
public:
	Bitset() : m_bit((_N-1)/32+1), m_size(_N)
	{}
	void set(size_t pos)
	{
		if(pos >= m_size)
			return;
		size_t index = pos / 32;
		size_t offset = pos % 32;

		m_bit[index] |= (1<<offset);
	}
	bool test(size_t pos)
	{
		if(pos >= m_size)
			return false;
		size_t index = pos / 32;
		size_t offset = pos % 32;
		return (m_bit[index] & (1<<offset));
	}
public:
	size_t count()const
	{
		int bitCnttable[256] = {
			0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
			3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
			3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
			4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
			3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
			6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
			4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
			6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
			3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
			4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
			6, 7, 6, 7, 7, 8 };

		//1111 1111   bitCnttable[127] = 0111 111
		//0000 0000 0000 0000 0000 0000 0001 0100

		size_t size = m_bit.size();
		size_t count = 0;
		for (size_t i = 0; i < size; ++i)
		{
			int value = m_bit[i];
			int j = 0;
			while (j < sizeof(m_bit[0]))
			{
				unsigned char c = value;
				count += bitCnttable[c];
				++j;
				value >>= 8;
			}
		}
		return count;
	}

private:
	vector<int> m_bit;
	size_t      m_size;
};


ostream& operator<<(ostream &out, const Bitset<10> &bt)
{
	cout<<bt.m_bit[0]<<endl;
	for(int i=9; i>=0; --i)
	{
		if(bt.m_bit[i/32] & (0x01<<i))
			out<<1;
		else
			out<<0;
	}
	return out;
}

void main()
{
	Bitset<10> bt;
	cout<<bt<<endl;
	//0000 0001 00
	bt.set(2);
	bt.set(1);
	cout<<bt.test(3)<<endl;

	cout<<bt.count()<<endl;
}


/*

//471979179
char* Convert_16(unsigned long value)
{
	//
}

void main()
{
	int index;
	cout<<"input index :";
	cin>>index;
	int val = "\0\1\2\3\4\5\6\7"[index];
	cout<<val<<endl;  // '5'==> 53
}

*/