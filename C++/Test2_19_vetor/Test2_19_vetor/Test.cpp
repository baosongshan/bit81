#include<iostream>
#include<assert.h>
#include<string>
#include<vld.h>
#include<vector>
using namespace std;

namespace bit
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator; 
	public:
		vector():start(nullptr),finish(nullptr),end_of_storage(nullptr)
		{}
		vector(size_t n, const T &value=T())
			:start(nullptr),finish(nullptr),end_of_storage(nullptr)
		{
			reserve(n);
			while(n-- != 0)
				push_back(value);
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:start(nullptr),finish(nullptr),end_of_storage(nullptr)
		{
			reserve(last - first);
			while(first != last)
			{
				push_back(*first);
				first++;
			}
		}
		~vector()
		{
			delete []start;
			start = finish = end_of_storage = nullptr;
		}
	public:
		size_t size()const
		{return finish - start;}
		size_t capacity()const
		{return end_of_storage - start;}
		bool empty()const
		{return finish == start;}
	public:
		iterator begin()
		{return start;}
		iterator end()
		{return finish;}
	public:
		void push_back(const T &x)
		{insert(end(), x);}
	public:
		void swap(vector & v)
		{
			std::swap(start, v.start);
			std::swap(finish, v.finish);
			std::swap(end_of_storage, v.end_of_storage);
		}
		void reserve(size_t n)
		{
			if(n > capacity())
			{
				size_t oldsize = size();
				T *new_start = new T[n];
				if(start)
				{
					for(int i=0; i<oldsize; ++ i)
					{
						new_start[i] = start[i];
					}
				}

				//释放原有空间
				if(start)
					delete []start;

				start = new_start;
				finish = start + oldsize;
				end_of_storage = start + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if(n <= size())
			{
				finish = start + n;
				return;
			}

			if(n > capacity())
				reserve(n*2);

			iterator p = finish;
			finish = start + n;
			while(p != finish)
			{
				*p = value;
				p++;
			}
		}
	public:
		iterator insert(iterator pos, const T &x)
		{
			if(finish >= end_of_storage)
			{
				size_t oldpos = pos - start;
				size_t new_cpy = capacity() ? capacity() * 2 : 1;
				reserve(new_cpy);

				//重新定位迭代器
				pos = start + oldpos;
			}

			iterator p = finish;
			while(p != pos)
			{
				*p = *(p-1);
				--p;
			}
			*p = x;
			finish++;
			return pos;
		}
		iterator erase(iterator pos)
		{
			iterator p = pos;
			while(p != finish-1)
			{
				*p = *(p+1);
				p++;
			}
			finish--;
			return pos;
		}

	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
};

void main()
{
	bit::vector<int> v;
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.reserve(2);
	//v.resize(15,1);

	v.insert(v.end(), 1);
	v.insert(v.end(), 2);
	v.insert(v.end(), 3);
	v.insert(v.begin(), 4);

	//4 100 1 2 3
	auto p = find(v.begin(), v.end(), 1);
	v.insert(p, 100);

	v.push_back(200);

	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	p = find(v.begin(), v.end(), 1);
	v.erase(p);

	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;


}

/*
void main()
{
	int ar[] = {1,2,3};
	int br[] = {4,5,6};
	bit::vector<int> v(ar,ar+3);
	bit::vector<int> v1(br,br+3);
	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;
	for(auto &e : v1)
		cout<<e<<" ";
	cout<<endl;

	v.swap(v1);

	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;
	for(auto &e : v1)
		cout<<e<<" ";
	cout<<endl;

}

/*
void main()
{
	int ar[] = {1,2,3,4,5};
	bit::vector<int> v(ar, ar+5);  //int *p1,  int *p2
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	bit::vector<int> v;
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.reserve(2);
	//v.resize(15,1);

	v.insert(v.end(), 1);
	v.insert(v.end(), 2);
	v.insert(v.end(), 3);
	v.insert(v.begin(), 4);

	//4 100 1 2 3
	auto p = find(v.begin(), v.end(), 1);
	v.insert(p, 100);

	v.push_back(200);

	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;


}

/*
void main()
{
	bit::vector<int> v;
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.reserve(10);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.reserve(50);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.reserve(20);
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
}

/*
int main()
{
	vector<int> v{ 1, 2, 3, 4 };
	auto it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}

	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;
	return 0;
}

/*
void main()
{
	vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12};

	auto p = find(v.begin(), v.end(), 10); 

	auto it = find(v.begin(), v.end(), 3); 
	cout<<"*it = "<<*it<<endl;

	//1 it在删除数据的后面，此时数据会往前移动，迭代器失效
	//2 it在删除数据的前面，此时迭代器所指数据不会发生变化，迭代任然有效
	
	v.erase(v.begin());
	//v.erase(p);

	cout<<"*it = "<<*it<<endl;
}

/*
void main()
{
	vector<int> v = {1,2,3,4,5};

	auto it = v.begin();
	cout<<"it = "<<*it<<endl;
	//push_back()
	//v.resize(10);
	v.reserve(10);
	//it = v.begin();
	cout<<"it = "<<*it<<endl;

}

/*
void main()
{
	vector<int> v = {1,2,3,4,5};
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;

	auto it = find(v.begin(), v.end(), 3);  // 3
	cout<<"it = "<<*it<<endl;

	v.push_back(10);
	it = find(v.begin(), v.end(), 3);
	cout<<"it = "<<*it<<endl;  //迭代器失效

	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
}

/*
void main()
{
	vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v2 = {20,21,22,23,34,35};

	for(auto &e : v1)
		cout<<e<<" ";
	cout<<endl;

	for(auto &e : v2)
		cout<<e<<" ";
	cout<<endl;

	v1.swap(v2);

	for(auto &e : v1)
		cout<<e<<" ";
	cout<<endl;

	for(auto &e : v2)
		cout<<e<<" ";
	cout<<endl;

}

/*
void main()
{
	vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
	auto p = find(v1.begin(), v1.end(), 5);
	auto p1 = find(v1.begin(), v1.end(), 10);

	//auto it = v1.erase(p);
	auto it = v1.erase(p, p1);  //[5 6 7 8 9 )

	for(auto &e : v1)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar+n);  //[1 2 3 4 5 6 7 8 9 10]

	//C++11
	vector<int> v1 = {1,2,3,4,5,6,7,8,9,10};
	auto p = find(v1.begin(), v1.end(), 5);

	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 200);
	for(auto &e : v1)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> v;
	for(int i=1; i<=10; ++i)
	{
		v.push_back(i);
	}

	auto it = v.begin();
	while(it != v.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	v.pop_back();
	for(auto &e : v)
		cout<<e<<" ";
	cout<<endl;


}

/*
void main()
{
	vector<int> v; //动态数组
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
	v.push_back(1);  //插入
	cout<<"size = "<<v.size()<<endl;
	cout<<"capacity = "<<v.capacity()<<endl;
}

/*
void main()
{
	vector<int> v;
	for(int i=1; i<=10; ++i)
	{
		//v.push_back(i);
		v.push_front(i);
	}

	for(auto &e : v)
		cout<<e<<" ";
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
		size_t m_size;      // \0
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
	istream& operator>>(istream& _cin, bit::string& s)
	{
		static const size_t default_buf_size = 5;
		int capacity = default_buf_size;
		int count = 1;  //字符个数

		//char *str = (char*)malloc(sizeof(char) * capacity);
		char *str = new char[capacity];
		char *buf = str;

		//跳过开头的空格和回车
		while((*buf=getchar())==' ' || (*buf == '\n'))
		{}

		for(;;)
		{
			if(*buf == ' ' || *buf == '\n')
			{
				*buf = '\0';
				break;
			}
			else if(count >= capacity)
			{
				capacity = capacity *2;
				//str = (char*)realloc(str, capacity);
				
				char *new_str = new char[capacity]; //申请空间
				memcpy(new_str, str, count);
				delete []str;
				str = new_str;

				//重新定位buf
				buf = str + count - 1;
			}
			*++buf = getchar();
			count++;
		}

		s.m_capacity = capacity;
		s.m_size = count-1;

		delete []s.m_str;  //执行原有字符串的空间释放

		s.m_str = str;
		return _cin;
	}
};

void main()
{
	bit::string str;
	cin>>str; //sfjalfjlaf laflajlfalf lkjflal
	cout<<str<<endl;

	bit::string str1("jflajflala");
	cin>>str1;

}

/*
void main()
{
	string str;
	while(1)
	{
		cin>>str;
		cout<<str<<endl;
		system("pause");
	}
}

/*
void main()
{
	bit::string str;
	cin>>str; //sfjalfjlaf laflajlfalf lkjflal
	cout<<str<<endl;
}

/*
void main()
{
	string str;
	while(1)
	{
		cin>>str;
		cout<<str<<endl;
		system("pause");
	}
}
*/

