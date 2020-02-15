#include<iostream>
#include<string>
using namespace std;

void main()
{
	string email = "kkkzkkbaosongshan2006@163.com";
	size_t pos = email.find('song'); //完全匹配

	string sub("abcxyz");
	pos = email.find_first_of(sub);
	cout<<pos<<endl;

	pos = email.find_first_not_of(sub);
	cout<<pos<<endl;

	pos = email.find_last_of(sub);
	cout<<pos<<endl;

	pos = email.find_last_not_of(sub);
	cout<<pos<<endl;
}

/*
void main()
{
	string str = "Hello Bit.";

	//迭代器  iterator
	string::iterator it = str.begin();  // iterator
	while(it != str.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;

	//反向输出
	string::reverse_iterator rit = str.rbegin();  //reverse_iterator
	while(rit != str.rend())
	{
		cout<<*rit;
		++rit;
	}
	cout<<endl;
}

/*
void main()
{
	string s1 = "Hello";
	string s2 = "Bit.";

	bool res = (s1 > s2);
	cout<<"res = "<<res<<endl;
}

/*
class Test
{};

void main()
{
	string s1 = "Hello";
	string s2 = "Bit.";

	string s3 = s1 + s2;
	cout<<"s3 = "<<s3<<endl;

	string s4;
	cout<<"请输入字符串:>";
	//cin>>s4;  // \n   space

	getline(cin, s4);

	cout<<"s4 = "<<s4<<endl;
}

/*
void main()
{
	string email = "baosongshan2006@163.com";
	string email_type;

	size_t start_pos = email.find('@');
	size_t end_pos = email.rfind('.');

	email_type = email.substr(start_pos+1, end_pos-start_pos-1);

	cout<<"type :"<<email_type<<endl;


}

/*
void main()
{
	string email = "baosongshan@2006@163.com";
	size_t pos = email.find('@');
	if(pos != string::npos)   //string::npos  -1
	{
		cout<<"pos = "<<pos<<endl;
	}
	else
		cout<<"not find."<<endl;	

	pos = email.find("song");
	if(pos != string::npos)
	{
		cout<<"pos = "<<pos<<endl;
	}

	pos = email.rfind('@');
	if(pos != string::npos) 
	{
		cout<<"pos = "<<pos<<endl;
	}
}

/*
void main()
{
	char *s1 = "Hello bit.";
	char *s2 = "Hello bit.";

	string str1 = "Hello bit.";  // x
	string str2 = "Hello bit.";
}


void main()
{
	string str = "Hello bit.";
	int len = strlen(str.c_str());
	cout<<"len = "<<len<<endl;

	//const char*  str.c_str();
}


void main()
{
	//C:\\C++\\STL.pdf
	string path = "C:";  //连接
	path += "\\";
	path += "C++";
	path += "\\";
	path += "STL.pdf";

	cout<<"path = " <<path<<endl;
}

/*
void main()
{
	//C:\\C++\\
	//string path = "C:";
	char *str = "C:\\C++\\STL.pdf";  //转义字符
	cout<<str<<endl;

}

/*
void main()
{
	char *s = "Hello C++";
	string str;
	while(*s != '\0')
	{
		str.push_back(*s);
		s++;
	}
	
	cout<<"str = "<<str<<endl;

	str.append(" Linux");
	cout<<"str = "<<str<<endl;
}

/*
void main()
{
	string str = "Hello Bit.";
	cout<<str<<endl;

	//char *str1 = "Hello Bit.";
	//str1[1] ==> *(str1 + 1);

	//operator[]
	for(int i=0; i<str.size(); ++i)
		cout<<str[i];  //str.operator[](i);
	cout<<endl;

	//C++11 
	for(auto ele : str)  //引用
	{
		if(ele == 'H')
			ele = 'h';
		cout<<ele;
	}
	cout<<endl;

	//迭代器  iterator
	string::iterator it = str.begin();
	while(it != str.end())
	{
		cout<<*it;
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	string str("Hello Bit.");
	cout<<"size = "<<str.size()<<endl; //字符串的有效大小，不包含\0
	cout<<"capacity = "<<str.capacity()<<endl;
	cout<<"str = "<<str<<endl;

	str.clear();

	cout<<"size = "<<str.size()<<endl; //字符串的有效大小，不包含\0
	cout<<"capacity = "<<str.capacity()<<endl;
	cout<<"str = "<<str<<endl;
}

/*
void main()
{
	string str;
	str.reserve(100);
	for(int i=1; i<=100; ++i)  //4
	{
		cout<<"capacity = "<<str.capacity()<<endl;
		str += i + '0';
	}
}

/*
void main()
{
	string str;
	for(int i=1; i<=100; ++i)  //4
	{
		cout<<"capacity = "<<str.capacity()<<endl;
		str += i + '0';
	}
}

/*
void main()
{
	string str("Hello Bit.");
	cout<<"size = "<<str.size()<<endl; //字符串的有效大小，不包含\0
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;
	str.reserve(100);
	cout<<"size = "<<str.size()<<endl; //字符串的有效大小，不包含\0
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;  //111

	str.reserve(20);
	cout<<"size = "<<str.size()<<endl; //字符串的有效大小，不包含\0
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl; //20
}

/*
void main()
{
	string str("Hello Bit.");
	cout<<"size = "<<str.size()<<endl; //字符串的有效大小，不包含\0
	cout<<"length = "<<str.length()<<endl;
	cout<<"capacity = "<<str.capacity()<<endl;

	string str1;
	cout<<"empty = "<<str1.empty()<<endl;

	cout<<"str = "<<str<<endl;
	str.clear();
	cout<<"str = "<<str<<endl;

	string str2 = "Hello";
	cout<<"str2 size = "<<str2.size()<<endl;
	cout<<"str2 capacity = "<<str2.capacity()<<endl;

	str2 += "string";
	cout<<"str2 size = "<<str2.size()<<endl;
	cout<<"str2 capacity = "<<str2.capacity()<<endl;

	str2 += "Linux";
	cout<<"str2 size = "<<str2.size()<<endl;
	cout<<"str2 capacity = "<<str2.capacity()<<endl;

	string str3 = "Hello";
	cout<<"str3 size = "<<str3.size()<<endl;
	cout<<"str3 capacity = "<<str3.capacity()<<endl;
	str3.reserve(100);
	cout<<"str3 size = "<<str3.size()<<endl;
	cout<<"str3 capacity = "<<str3.capacity()<<endl;

	string str4 = "Hello";
	cout<<"str4 size = "<<str4.size()<<endl;
	cout<<"str4 capacity = "<<str4.capacity()<<endl;
	cout<<"str4 = "<<str4<<endl;
	str4.resize(20,'@');  //Hello00000
	cout<<"str4 size = "<<str4.size()<<endl;
	cout<<"str4 capacity = "<<str4.capacity()<<endl;
	cout<<"str4 = "<<str4<<endl;

	string str5 = "Hello";
	cout<<"str5 size = "<<str5.size()<<endl;
	cout<<"str5 capacity = "<<str5.capacity()<<endl;
	cout<<"str5 = "<<str5<<endl;
	str5.resize(50,'@');
	cout<<"str5 size = "<<str5.size()<<endl;
	cout<<"str5 capacity = "<<str5.capacity()<<endl;
	cout<<"str5 = "<<str5<<endl;
	str5.resize(2);
	cout<<"str5 size = "<<str5.size()<<endl;
	cout<<"str5 capacity = "<<str5.capacity()<<endl;
	cout<<"str5 = "<<str5<<endl;

}

/*
//string对象的构造
void main()
{
	//string();
	string str1;
	cout<<"str1 = "<<str1<<endl;

	//string(const char *);
	const char *s = "Hello Bit.";
	string str2(s);
	cout<<"str2 = "<<str2<<endl;

	//string(const char *);
	string str3("Hello C++");
	cout<<"str3 = "<<str3<<endl;

	//string(size_t n, char c);
	string str4(10, 'k');
	cout<<"str4 = "<<str4<<endl;

	//string(const string &s)
	string str5(str3);
	cout<<"str5 = "<<str5<<endl;

	//string(const string &s)
	string str6 = str5;
	cout<<"str6 = "<<str6<<endl;
}

/*
void main()
{
	//C数组
	char str1[] = {'B','i','t','\0'};
	cout<<str1<<endl;

	char *str2 = "Bit";
	cout<<str2<<endl;

	//typedef basic_string<char, char_traits<char>, allocator<char> >	string;

	string str3("Bit");
	cout<<str3<<endl;

	cout<<"str1 len = "<<strlen(str1)<<endl;
	cout<<"str3 len = "<<str3.size()<<endl;
	cout<<"str3 len = "<<str3.length()<<endl;
}
*/