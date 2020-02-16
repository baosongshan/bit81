#include<iostream>
#include<string>
#include<vld.h>
#include<assert.h>
using namespace std;

namespace bit
{
	class string
	{
		friend ostream& operator<<(ostream &out, const string &s);
		friend istream& operator>>(istream& _cin, bit::string& s);
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
		string& operator+=(char c);
		void append(const char* str);
		string& operator+=(const char* str);
		void resize(size_t newSize, char c = '\0');
		const char& operator[](size_t index)const;
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator>(const string& s);
		bool operator>=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);
		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const;
		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const;
		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c);
		string& insert(size_t pos, const char* str);
		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len);
	public:
		char& operator[](int i)
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
				memcpy(new_str, m_str, m_size);
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
		out<<s.m_str;
		return out;
	}
};

void main()
{
	bit::string str("Hello C++");
	cout<<"str = "<<str<<endl;
	str.push_back('x');
	cout<<"str = "<<str<<endl;
}

/*
void main()
{
	bit::string str("Hello C++");
	cout<<"str = "<<str<<endl;

	const char *res = str.c_str();
	cout<<"res = "<<res<<endl;
}

/*
void main()
{
	bit::string str("Hello C++");
	cout<<"str = "<<str<<endl;

	for(int i=0; i<str.size(); ++i)
	{
		cout<<str[i];
	}
	cout<<endl;

}

/*
void main()
{
	bit::string str("C++");
	cout<<"str = "<<str<<endl;
	bit::string str1 = str;
	cout<<"str1 = "<<str1<<endl;
	bit::string str2;
	str2 = str1;
	cout<<"str2 = "<<str2<<endl;

	bit::string::iterator  it = str2.begin();
	while(it != str2.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;
}

/*
class String
{
	friend ostream& operator<<(ostream &out, const String &s);
	friend istream& operator>>(istream &in,  String &s);
public:
	String(const char *str = "")
	{
		m_str = new char[strlen(str)+1];
		strcpy(m_str, str);
	}
	String(const String &s) : m_str(nullptr)
	{
		String tmp(s.m_str);
		std::swap(this->m_str, tmp.m_str);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			String tmp(s);
			std::swap(m_str, tmp.m_str);
		}
		return *this;
	}
	~String()
	{
		if(m_str)
		{
			delete []m_str;
			m_str = nullptr;
		}
	}
private:
	char *m_str;
};

ostream& operator<<(ostream &out, const String &s)
{
	out<<s.m_str;
	return out;
}

void main()
{
	String str1("Bit.");
	cout<<"str1 = "<<str1<<endl;

	String str2 = str1;
	cout<<"str2 = "<<str2<<endl;

	String str3("Hello");
	str3 = str2;
	cout<<"str3 = "<<str3<<endl;
}

/*
//传统写法
class String
{
	friend ostream& operator<<(ostream &out, const String &s);
	friend istream& operator>>(istream &in,  String &s);
public:
	String(const char *str = "")
	{
		m_str = new char[strlen(str)+1];
		strcpy(m_str, str);
	}
	String(const String &s)
	{
		m_str = new char[strlen(s.m_str)+1];
		strcpy(m_str, s.m_str);
	}
	String& operator=(const String &s)
	{
		if(this != &s)
		{
			delete []m_str;
			m_str = new char[strlen(s.m_str)+1];
			strcpy(m_str, s.m_str);
		}
		return *this;
	}
	~String()
	{
		if(m_str)
		{
			delete []m_str;
			m_str = nullptr;
		}
	}
private:
	char *m_str;
};

ostream& operator<<(ostream &out, const String &s)
{
	out<<s.m_str;
	return out;
}

istream& operator>>(istream &in,  String &s)
{
	char buf[500] = {0};  //
	//自动增长
	//in>>buf; //101

	//赋值 s.m_str
	return in;
}

void main()
{
	String s;
	//cin>>s;
	cout<<"s = "<<s<<endl;

	string s1;
	cin>>s1;

}

/*
void main()
{
	String s;
	String s1("Bit.");
	cout<<"s1 = "<<s1<<endl;

	String s2 = s1;  //String s2(s1)
	cout<<"s2 = "<<s2<<endl;

	s = s2;
	cout<<"s = "<<s<<endl;


}


/*
string reverseOnlyLetters(string S)
{
	size_t start = 0;
	size_t end = S.size() - 1;

	while (start < end)
	{
		//查找左边第一个字母
		while (start < end)
		{
			if ((S[start] >= 'a'&&S[start] <= 'z') || (S[start] >= 'A'&&S[start] <= 'Z'))
				break;
			start++;
		}

		//查找右边第一个字母
		while (start < end)
		{
			if ((S[end] >= 'a'&&S[end] <= 'z') || (S[end] >= 'A'&&S[end] <= 'Z'))
				break;
			end--;
		}

		if (start < end)
		{
			char tmp = S[start];
			S[start] = S[end];
			S[end] = tmp;
			start++;
			end--;
		}
	}
	return S;
}

 string reverseOnlyLetters(string S) 
{
    int start = 0;
    int end = S.size()-1;
    while(start < end)
    {
        while(start < end)
        {
            if((S[start]>='a' && S[start]<='z')||(S[start]>='A'&&S[start]<='Z'))
                break;
            start++;
        }
        while(start < end)
        {
            if((S[end]>='a' && S[end]<='z')||(S[end]>='A'&&S[end]<='Z'))
                break;
                end--;;
        }
            
        if(start < end)
        {
            char tmp = S[start];
            S[start] = S[end];
            S[end] = tmp;
            start++;
            end--;
        }
    }    
    return S;
}

void main()
{
	string str = "a-bC-dEf-ghIj";
	string res = reverseOnlyLetters(str);
	cout<<"res = "<<res<<endl;
}

/*
void main()
{
	string str = "Hello Bit.";
	
	//直接输出
	cout<<str<<endl;

	//operator[]
	for(int i=0; i<str.size(); ++i)
	{
		cout<<str[i];
	}
	cout<<endl;

	//C++11
	for(auto &e : str)
	{
		//if(e == 'H')
		//	e = 'h';
		cout<<e;
	}
	cout<<endl;

	//at()
	for(int i=0; i<str.size(); ++i)
	{
		cout<<str.at(i);
	}
	cout<<endl;

	//iterator ++ --
	string::iterator it = str.begin();
	while(it != str.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;

	string::reverse_iterator rit = str.rbegin();
	while(rit != str.rend())
	{
		cout<<*rit;
		++rit;
	}
	cout<<endl;

	//
	string::iterator it1 = str.end()-1;
	while(it1 != str.begin())
	{
		cout<<*it1;
		--it1;
	}
	cout<<*it1;
	cout<<endl;
}

/*
size_t find (const string& str, size_t pos = 0) const;	
size_t find (const char* s, size_t pos = 0) const;
size_t find (const char* s, size_t pos, size_t n) const;
size_t find (char c, size_t pos = 0) const;


void main()
{
	string email = "32@c5690203@qq.com";
	string substr("60.c");

	size_t pos = email.find_first_of(substr);
	cout<<pos<<endl;
}

/*
void main()
{
	string email = "36@5690203@qq.com";
	size_t pos = email.find('@', 3);
	cout<<"pos = "<<pos<<endl;

	pos = email.find("569", 4);
	if(pos == string::npos)
		cout<<"find not."<<endl;
	else
		cout<<"pos = "<<pos<<endl;

	string str = "qq";
	pos = email.find(str);
	cout<<"pos = "<<pos<<endl;
}
*/