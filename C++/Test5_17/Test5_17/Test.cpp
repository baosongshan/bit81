#include<iostream>
#include<forward_list> //C++11
#include<string>
#include<set>
#include<map>
#include<vector>
#include<list>
#include<functional>
#include<hash_set>
#include<unordered_set>
#include<hash_map>
#include<unordered_map>
using namespace std;

void main()
{
	hash_map<int, string> hmap = {{1,"Student"}, {3,"Friend"},{1,"Student1"}, {4, "Bit"},{1,"Student2"},{2,"Teacher"} };
	hmap[1] = "学生";
	for(auto &e : hmap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<endl;

	

	unordered_map<int, string> unmap = {{1,"Student"}, {3,"Friend"},{1,"Student1"}, {4, "Bit"},{1,"Student2"},{2,"Teacher"} };
	for(auto &e : unmap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<endl;

	cout<<"================================================"<<endl;

	hash_multimap<int, string> hmultimap = {{1,"Student"}, {3,"Friend"},{1,"Student1"}, {4, "Bit"},{1,"Student2"},{2,"Teacher"} };
	for(auto &e : hmultimap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<endl;

	unordered_multimap<int, string> unmultimap = {{1,"Student"}, {3,"Friend"},{1,"Student1"}, {4, "Bit"},{1,"Student2"},{2,"Teacher"} };
	for(auto &e : unmultimap)
		cout<<e.first<<" : "<<e.second<<endl;
	cout<<endl;
}

/*
void main()
{
	hash_set<int> hset = {43 ,31,435,5,43,43,43,43,44,34,4,43,6563,2,13,14,4545};
	for(auto &e : hset)
		cout<<e<<" ";
	cout<<endl;

	unordered_set<int> unset =  {43 ,31,435,5,43,43,43,43,44,34,4,43,6563,2,13,14,4545};
	for(auto &e : unset)
		cout<<e<<" ";
	cout<<endl;

	cout<<"======================================================="<<endl;

	hash_multiset<int> hmultiset = {43 ,31,435,5,43,43,43,43,44,34,4,43,6563,2,13,14,4545};
	for(auto &e : hmultiset)
		cout<<e<<" ";
	cout<<endl;

	unordered_multiset<int> unmultiset =  {43 ,31,435,5,43,43,43,43,44,34,4,43,6563,2,13,14,4545};
	for(auto &e : unmultiset)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	//预判起始位置
	multimap<int, string> ismap = {{1,"Student"}, {1,"Student1"},{1,"Student2"},{2,"Teacher"},{3,"Friend"},  {4, "Bit"}};
	for(const auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
//at() 会检查边界
//[]   不会检查  ->键值不存在时，把数据插入
void main()
{
	//预判起始位置
	map<int, string> ismap = {{1,"Student"}, {1,"Student1"},{1,"Student2"},{2,"Teacher"},{3,"Friend"},  {4, "Bit"}};

	//头插
	ismap.insert(ismap.begin(), make_pair(8,"服务"));
	//尾插
	ismap.insert(ismap.end(), make_pair(0, "666"));
	//在bit之前插入
	auto pos = ismap.find(4);
	if(pos != ismap.end())
	{
		ismap.insert(pos, make_pair(7,"学习"));
	}

	for(const auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	map<int, string> ismap = {{1,"Student"}, {2,"Teacher"},{3,"Friend"},  {4, "Bit"}};

	ismap[1] = "学生";  //[]
	ismap[2] = "老师";
	ismap[3] = "朋友";

	int key = 10;
	auto ret_it = ismap.find(key);
	if(ret_it != ismap.end())
	{
		//
	}
	else
		cout<<"不存在."<<endl;

	ismap[5] = "服务"; //数据插入  <5-服务>

	for(const auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
void main()
{
	map<int, string> ismap;
	pair<int, string> v[] = {{3,"Friend"},{1,"Student"}, {2,"Teacher"},  {4, "Bit"}};
	int n = sizeof(v) / sizeof(v[0]);

	for(int i=0; i<n; ++i)
		ismap.insert(v[i]);

	//auto it = ismap.begin();
	//it->first = 10;
	//it->second[0] = 's';

	for(const auto &e : ismap)
		cout<<e.first<<" : "<<e.second<<endl;
}

/*
class Foo 
{
public:
	Foo(int n, double x) : m_n(n), m_x(x)
	{}
	int m_n;
	double m_x;
};

void main()
{
	vector<Foo> v;

	auto someIterator = v.begin();

	someIterator = v.emplace(someIterator, 42, 3.1416);        // 没有临时变量产生
	//v.insert(someIterator, Foo(42, 3.1416));
	v.insert(someIterator, 42, 3.1416);
}
/*
void main()
{
	vector<int> iv = {43 ,31,435,5,6563,2,13,14,4545};
	set<int> s(iv.begin(), iv.end());

	s.emplace(100);
	//s.insert(100);

	set<int>::iterator it = s.begin();

	while(it != s.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	vector<int> iv = {43 ,31,435,5,6563,2,43,13,43,43,43,43,43,43,43,14,4545};
	set<int> s(iv.begin(), iv.end());

	cout<<"size = "<<s.size()<<endl;
	cout<<"count = "<<s.count(430)<<endl;  //0  1

	set<int>::iterator it = s.begin();
	while(it != s.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	multiset<int> multis(iv.begin(), iv.end());
	cout<<"multi size = "<<multis.size()<<endl;
	cout<<"multi count = "<<multis.count(43)<<endl;  //0  1
	for(auto &e : multis)
		cout<<e<<" ";
	cout<<endl;


}

/*
void main()
{
	vector<int> iv = {43 ,31,435,5,6563,2,43,13,14,4545};
	set<int> s(iv.begin(), iv.end());
	set<int>::iterator it = s.begin();
	while(it != s.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;

	set<int>::reverse_iterator rit = s.rbegin();
	while(rit != s.rend())
	{
		cout<<*rit<<" ";
		++rit;
	}
	cout<<endl;
}


/*
void main()
{
	list<int> mylist = {43 ,31,435,5,6563,2,43,13,14,4545};
	list<int>::iterator it = mylist.begin();

	cout<<*it<<endl;
	*it = 1000;
	cout<<*it<<endl;
}

/*
void main()
{
	list<int> mylist;
	vector<int> iv = {43 ,31,435,5,6563,2,43,13,14,4545};

	set<int> s(iv.begin(), iv.end());

	set<int>::iterator it = s.begin(); //const_it

	//*it = 20;  //const  ==>

}

/*
void main()
{
	list<int> mylist = {43 ,31,435,5,6563,2,43,13,14,4545};
	list<int>::iterator it = mylist.begin();

	cout<<*it<<endl;
	*it = 1000;
	cout<<*it<<endl;
}

/*
void main()
{
	list<int> mylist;
	vector<int> iv = {43 ,31,435,5,6563,2,43,13,14,4545};

	const set<int> s(iv.begin(), iv.end());

	//s.erase(2);
	//s.insert(20);

	set<int>::const_iterator it = s.cbegin(); 

	*it = 20;  //const  ==>

	while(it != s.cend())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void main()
{
	vector<int> iv = {43 ,31,435,5,6563,2,43,13,14,4545};

	set<int> s(iv.begin(), iv.end());
	
	set<int> s1 = s;

	for(const auto &e : s)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> iv = {43 ,31,435,5,6563,2,43,13,14,4545};
	set<int> s;
	set<int, greater<int>> s1  =  {43 ,31,435,5,6563,2,43,13,14,4545}; //C++11
	for(const auto &e : s1)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	pair<int, string> v1 = {1, "abc"};  //值对 
	pair<int, string> v2 = {2, "xyz"};

	cout<<v1.first<<" : "<<v1.second<<endl;

	pair<string,string> v3 = make_pair("1-1", "元旦节");
	cout<<v3.first<<" : "<<v3.second<<endl;
}

/*
void main()
{
	forward_list<int> mylist;
	for(int i=1; i<=10; ++i)
		mylist.push_front(i);

	mylist.reverse();

	for(const auto &e : mylist)
		cout<<e<<"->";
	cout<<endl;
}
*/