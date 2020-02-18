#include<iostream>
#include<vld.h>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;


void main()
{
	vector<int> v;
	v.reserve(100);
	for(int i=0; i<100; ++i)
	{
		cout<<"capacity = "<<v.capacity()<<endl;
		v.push_back(i);
	}
}

/*
void Print(vector<int> &v)
{
	for(int i=0; i<v.size(); ++i)
		cout<<v[i]<<" ";
	cout<<endl;
}

void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v(ar, ar+10);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	Print(v);
	v.resize(5, 2);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	Print(v);

}

/*
void main()
{
	int ar[3] = {1,2,3};
	vector<int> v(ar, ar+3);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	Print(v);
	v.reserve(10);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.reserve(100);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.reserve(50);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	Print(v);

}

/*
void main()
{
	vector<int> v;
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(1);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(2);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(3);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(4);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(5);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(6);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(7);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

}

/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v4(ar, ar+10);
	//利用下标[]  operator[]
	for(int i=0; i<v4.size(); ++i)
		cout<<v4[i]<<" ";
	cout<<endl;

	//利用at()  会检查下标是否越界
	for(int i=0; i<v4.size(); ++i)
		cout<<v4.at(i)<<" ";
	cout<<endl;

	//利用迭代器
	vector<int>::iterator it = v4.begin();
	while(it != v4.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	//利用反向迭代器
	vector<int>::reverse_iterator rit = v4.rbegin();
	while(rit != v4.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}

/*
void main()
{
	//默认构造 vector()
	vector<int> v1;

	//vector（size_type n, const value_type& val = value_type()） 构造并初始化n个val
	vector<int> v2(10,5);
	for(int i=0; i<v2.size(); ++i)
		cout<<v2[i]<<" ";
	cout<<endl;

	//vector (const vector& x); （重点） 拷贝构造
	vector<int> v3(v2);
	for(int i=0; i<v3.size(); ++i)
		cout<<v3[i]<<" ";
	cout<<endl;

	//vector( value_type *first, value_type *last);
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v4(ar, ar+10);
	for(int i=0; i<v4.size(); ++i)
		cout<<v4[i]<<" ";
	cout<<endl;

	//vector (InputIterator first, InputIterator last);
	vector<int> v5(v4.begin(), v4.end());
	for(int i=0; i<v5.size(); ++i)
		cout<<v5[i]<<" ";
	cout<<endl;
}

/*
namespace bit
{
	class string
	{
		friend ostream& operator<<(ostream &out, const string &s);
		friend istream& operator>>(istream& _cin, bit::string& s);
	public:
		static const size_t npos = -1;
	public:
		typedef char* iterator;
	public:
		string(const char *str=""):m_str(nullptr)
		{
			m_capacity = m_size = strlen(str);
			m_str = new char[m_capacity + 1];  // \0
			strcpy(m_str, str);
		}
		string(const string &s) : m_str(nullptr), m_capacity(0),m_size(0)
		{
			string tmp(s.m_str);
			_swap(*this, tmp);
		}
		string& operator=(const string &s)
		{
			if(this != &s)
			{
				string tmp(s);
				_swap(*this, tmp);
			}
			return *this;
		}
		~string()
		{
			if(m_str)
			{
				delete []m_str;
				m_str = nullptr;
			}
			m_capacity = m_size = 0;
		}
	public:
		iterator begin()
		{return m_str;}
		iterator end()
		{return m_str+size();}
	public:
		size_t size()const
		{return m_size;}
		size_t capacity()const
		{return m_capacity;}
		bool empty()const
		{return m_size == 0;}
		void clear()
		{
			m_size = 0;
			m_str[0] = '\0';
		}
	public:
		const char* c_str()const
		{
			return m_str;
		}
	public:
		void push_back(char c)
		{
			if(m_size >= m_capacity)
				reserve(m_capacity * 2);
			m_str[m_size++] = c;
			m_str[m_size] = '\0';
		}
	public:
		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}
		void append(const char* str) 
		{
			int str_len = strlen(str);
			if(str_len+m_size > m_capacity)
			{
				reserve((m_capacity+str_len) * 2);
			}
			strcpy(m_str+m_size, str);
			m_size += str_len;
		}
		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		void resize(size_t newSize, char c = '\0')
		{
			if(newSize > m_size)
			{
				if(newSize > m_capacity)
				{
					reserve(newSize * 2);
				}
				memset(m_str+m_size, c, newSize-m_size);
			}
			m_size = newSize;
			m_str[m_size] = '\0';
		}
		
		bool operator<(const string& s)
		{
			return (strcmp(m_str, s.m_str) < 0);
		}
		bool operator<=(const string& s)
		{
			return !(*this > s);
		}
		bool operator>(const string& s)
		{
			return (strcmp(m_str, s.m_str) > 0);
		}
		bool operator>=(const string& s)
		{
			return !(*this < s);
		}
		bool operator==(const string& s)
		{
			return (strcmp(m_str, s.m_str) == 0);
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for(int i=pos; i<m_size; ++i)
			{
				if(m_str[i] == c)
					return i;
			}
			return npos;
		}
		// 返回子串s在string中第一次出现的位置
		//朴素的模式匹配 -->  KMP  strstr
		size_t find(const char* s, size_t pos = 0) const
		{
			size_t i=pos, j=0;
			size_t s_len = strlen(s);
			while(i<m_size && j<s_len)
			{
				if(m_str[i] == s[j])
				{
					i++;
					j++;
				}
				else
				{
					i = i - j + 1;
					j = 0;
				}
			}
			if(j >= s_len)
			{
				return i - j;
			}
			return npos;
		}

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			if(m_size+1 > m_capacity)
			{
				reserve((m_size+1)*2);
			}

			for(size_t i=m_size; i>pos; --i)
			{
				m_str[i] = m_str[i-1];
			}
			m_str[pos] = c;
			m_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			//
			return *this;
		}
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len)
		{
			memcpy(m_str+pos, m_str+pos+len, m_size-pos-len+1);
			m_size -= len;
			return *this;
		}
	public:
		char& operator[](int i)
		{
			assert(i>=0 && i<m_size);
			return m_str[i];
		}
		const char& operator[](size_t i)const
		{
			assert(i>=0 && i<m_size);
			return m_str[i];
		}
	public:
		void reserve(size_t new_cpy)
		{
			if(new_cpy > m_capacity)
			{
				char *new_str = new char[new_cpy+1];
				memcpy(new_str, m_str, m_size+1);
				m_capacity = new_cpy;
				delete []m_str;
				m_str = new_str;
			}
		}
	protected:
		static void _swap(string &s1, string &s2)
		{
			std::swap(s1.m_str, s2.m_str);
			std::swap(s1.m_capacity, s2.m_capacity);
			std::swap(s1.m_size, s2.m_size);
		}
	private:
		char * m_str;
		size_t m_capacity;
		size_t m_size;
	};

	ostream& operator<<(ostream &out, const string &s)
	{
		for(int i=0; i<s.m_size; ++i)
		{
			out<<s.m_str[i];
		}
		//out<<s.m_str;
		return out;
	}

	////////////////////////////////////////////////////////////////
	//?????????
	istream& operator>>(istream& _cin, bit::string& s)
	{
		char *str = (char *)malloc(sizeof(char) * 10);
		char *buf = str;

		size_t count = 1;

		//跳过字符串起始位置的空格或者换行
		while((*buf=getchar())==' ' || (*buf=='\n'));

		for(;;)
		{
			if(*buf=='\n' || *buf==' ')
			{
				*buf = '\0';
				break;
			}
			else if(count % 10 == 0)
			{
				str = (char *)realloc(str, count*2);
				//重新定位buf的位置
				buf = str + count;
				count++;
				*buf = getchar();
			}
			else
			{
				*++buf = getchar();
				count++;
			}
		}

		s.m_str = str;
		s.m_capacity = s.m_size = count;
		return _cin;
	}
};

void main()
{
	bit::string str;
	cin>>str;
	cout<<str<<endl;
}

/*
void main()
{
	string str("abcABCxyzXYZ@qq.com");
	//string::iterator p = str.begin();
	//string::iterator p = find(str.begin(), str.end(), 'B');
	//string::iterator it = str.erase(p);
	string::iterator p1 = find(str.begin(), str.end(), 'B');
	string::iterator p2 = find(str.begin(), str.end(), 'Z');
	str.erase(p1, p2); //[p1, p2);
	cout<<str<<endl;
}

/*
void main()
{
	bit::string str("abcABCxyzXYZ@qq.com");
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl; 
	str.erase(3,3);
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl; 
	cout<<str<<endl;
}

/*
void main()
{
	bit::string str("365692697690203@qq.com");
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl; 
	str.insert(6, '@');
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl; 
	cout<<str<<endl; //("365692 @ 697690203@qq.com");
}

/*
void main()
{
	bit::string str("Hello C++");
	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl; 
	cout<<"str = "<<str<<endl;
	//str.push_back('x');
	//str.reserve(20);
	//str += 'x';
	//str.append(" Linux.");
	//str += " Linux";
	//str.reserve(20);
	//str.resize(15, '@');

	cout<<"size = "<<str.size()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl; 
	cout<<"str = "<<str<<endl;
}


/*
class String
{
public:
	String(const char *str = "")
	{
		m_str = new char[strlen(str)+1];
		strcpy(m_str, str);
	}
	String(const String &s) : m_str(nullptr)
	{
		//m_str = new char[strlen(s.m_str)+1];
		//strcpy(m_str, s.m_str);

		String tmp(s.m_str);
		std::swap(m_str, tmp.m_str);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			//delete []m_str; //忘记
			//m_str = new char[strlen(s.m_str)+1];
			//strcpy(m_str, s.m_str);

			String tmp(s);  //临时对象
			std::swap(m_str, tmp.m_str);
		}
		return *this;
	}
	~String()
	{
		if(m_str)
		{
			delete []m_str;
			m_str = nullptr; //预防野指针
		}
	}
private:
	char *m_str;
};

void main()
{
	String str("Hello");  //H e l l o \0
	String str1 = str;
	String str2("Bit.");
	str2 = str1;

}
*/