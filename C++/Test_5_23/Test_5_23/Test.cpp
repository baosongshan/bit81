#include<iostream>
#include<list>
#include<vector>
#include<functional>
#include<algorithm>
#include<unordered_set>
#include<bitset>
using namespace std;

//结构
void main()
{
	bitset<10> bt;
	cout<<bt<<endl;
	bt.set(4);
	cout<<bt<<endl;
	bt.flip();
	cout<<bt<<endl;
	cout<<bt.count()<<endl;
	cout<<bt.size()<<endl;

	cout<<bt.to_ulong()<<endl;

	bt.reset();
	cout<<bt<<endl;
}

/*
void main()
{
	unordered_set<int> unset;
}

/*
template<class T>  
size_t BKDRHash(const T *str)  
{  
    register size_t hash = 0;  
    while (size_t ch = (size_t)*str++)  
    {         
        hash = hash * 131 + ch;         
    }  
    return hash;  
} 

void main()
{
	const char *str = "hellobit";
	size_t index = BKDRHash(str);

	atoi("136479"); //==>136479
}

/*
int main()
{
	// 统计v2中有多少个偶数
	vector<int> v2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,12,14 };
	cout << count_if(v2.begin(), v2.end(), [](int a)->bool{return (a%2==0);}) << endl;
	return 0;
}

/*
int	_Count_if(int *_First, int *_Last, _Pr _Pred)
{	
	int  _Count = 0;

	for (; _First != _Last; ++_First)
		if (_Pred(*_First))  //if(IsOdd(*_First))
			++_Count;
	return (_Count);
}

bool IsOdd(int i)
{
	return ((i % 2) == 0);
}
int main()
{
	// 统计v2中有多少个偶数
	vector<int> v2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << count_if(v2.begin(), v2.end(), IsOdd) << endl;
	return 0;
}

/*
struct gt
{
	bool operator()(int a, int b)  //函数对象
	{
		return a > b;
	}
};


bool lt(int a, int b)
{
	return a < b;
}

void main()
{
	list<int>  mylist = {7,4,9,0,3,2,1,8};

	//mylist.sort(greater<int>());
	mylist.sort(gt()); //gt();

	for(const auto &e : mylist)
		cout<<e<<"-->";
	cout<<endl;

}
*/