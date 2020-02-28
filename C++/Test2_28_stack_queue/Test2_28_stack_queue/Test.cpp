#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<functional>
using namespace std;

void main()
{
	vector<int> v = {5,7,9,30,4,1,0,2};
	//make_heap(v.begin(), v.end(), greater<int>());
	make_heap(v.begin(), v.end());

	v.push_back(20);
	push_heap(v.begin(), v.end());

	for(int i=0; i<v.size(); ++i)
		pop_heap(v.begin(), v.end()-i);
	for(const auto &e : v)
		cout<<e<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> v = {5,7,9,30,7,4,1,0,2};
	//priority_queue<int, vector<int>, greater<int>> pq; //小堆
	priority_queue<int> pq; 
	for(const auto &e : v)
		pq.push(e);
	//优先级 -->
	pq.pop(); // 0
	pq.pop(); // 1

	cout<<pq.top()<<endl;

}

/*
void main()
{
	int ar[] =  {5,7,9,30,7,4,1,0,2};
	make_heap(ar, ar+9);
	for(int i=0; i<9; ++i)
		cout<<ar[i]<<" ";
	cout<<endl;
}

/*
void main()
{
	vector<int> v = {5,7,9,30,7,4,1,0,2};
	priority_queue<int> pq;
	for(const auto &e : v)
		pq.push(e);

	cout<<pq.top()<<endl;

}

/*
void main()
{
	deque<int> de;  //好像连续  ，实际上 部分连续
	//5 6
	de.push_back(5);
	de.push_back(6);
	de.push_back(7);
	de.push_front(1);
	de.push_front(2);

	for(const auto &e : de)
		cout<<e<<" ";
	cout<<endl;

	de.pop_back();
	de.pop_front();
	for(const auto &e : de)
		cout<<e<<" ";
	cout<<endl;
}

/*
namespace bit
{
	template<class T, class Cont=deque<T>>
	class stack 
	{
		typedef size_t size_type;
		typedef T      value_type;
	public:
		explicit stack()
		{}
		bool empty() const
		{return c.empty();}
		size_type size() const
		{return c.size();}
		value_type& top()
		{return c.back();}
		const value_type& top() const
		{return c.back();}
		//1 2 3 4
		void push(const value_type& x)
		{c.push_back(x);}
		void pop()
		{c.pop_back();}
	protected:
		Cont c; 
	};

	template<class T, class Cont=deque<T>>
    class queue 
	{
		typedef size_t size_type;
		typedef T      value_type;
	public:
		explicit queue()
		{}
		bool empty() const
		{return c.empty();}
		size_type size() const
		{return c.size();}
		value_type& front()
		{return c.front();}
		const value_type& front()const
		{return c.front();}
		value_type& back()
		{return c.back();}
		const value_type& back()const
		{return c.back();}
		void push(const value_type& x)
		{c.push_back(x);}
		void pop()
		{c.pop_front();}
	protected:
		Cont c;
	};
};

void main()
{
	bit::stack<string, list<string>> st;
	st.push("abc");
	st.push("xyz");
	st.push("fjlajfklajlkfajl");

	st.pop();
	cout<<st.top()<<endl;

	bit::queue<string> Q;
	Q.push("abcd");
	Q.push("falfjla");

	Q.pop();
	cout<<Q.front()<<endl;


}


/*
namespace bit
{
	template<class T>
	class stack   //容器 适配器
	{
		typedef size_t size_type;
		typedef T      value_type;
	public:
		explicit stack()
		{}
		bool empty() const
		{return c.empty();}
		size_type size() const
		{return c.size();}
		value_type& top()
		{return c.back();}
		const value_type& top() const
		{return c.back();}
		//1 2 3 4
		void push(const value_type& x)
		{c.push_back(x);}
		void pop()
		{c.pop_back();}
	protected:
		vector<T> c;
		//list<T> c;  //100  适配
		//string c;
	};

	template<class T>
    class queue 
	{
		typedef size_t size_type;
		typedef T      value_type;
	public:
		explicit queue()
		{}
		bool empty() const
		{return c.empty();}
		size_type size() const
		{return c.size();}
		value_type& front()
		{return c.front();}
		const value_type& front()const
		{return c.front();}
		value_type& back()
		{return c.back();}
		const value_type& back()const
		{return c.back();}
		void push(const value_type& x)
		{c.push_back(x);}
		void pop()
		{c.pop_front();}
	protected:
		list<T> c;
	};
};

void main()
{
	bit::stack<string> st;
	st.push("abc");
	st.push("xyz");
	st.push("fjlajfklajlkfajl");

	st.pop();
	cout<<st.top()<<endl;

	bit::queue<string> Q;
	Q.push("abcd");
	Q.push("falfjla");

	Q.pop();
	cout<<Q.front()<<endl;


}

/*
//C      中餐   白菜 萝卜 肉 鸡蛋 辣椒 。。。。。  --》刀
//C++    西餐   薯条 半成品 

void main()
{
	queue<int>  Q;
	cout<<"empty = "<<Q.empty()<<endl;
	for(int i=1; i<=5; ++i)
		Q.push(i);
	cout<<"size = "<<Q.size()<<endl;
	cout<<"front = "<<Q.front()<<endl;
	cout<<"back = "<<Q.back()<<endl;

	//1 2 3 4 5
	int value = Q.front();
	Q.pop();
	value = Q.front();
	Q.pop();
	cout<<"value = "<<value<<endl;

}

/*
void main()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(50);
	//cout<<"empty = "<<st.empty()<<endl;
	cout<<"size = "<<st.size()<<endl;
	cout<<"top = "<<st.top()<<endl;

	int value = st.top();
	st.pop();

	cout<<"size = "<<st.size()<<endl;

}
*/