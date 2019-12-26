#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;


void PrintList(list<int> &lt)
{
	list<int>::iterator it = lt.begin();
	while(it != lt.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Over."<<endl;
}

void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	//list<int> lt;
	//list<int> lt(10);
	//list<int> lt(10,2);
	list<int> lt(ar, ar+10);
	list<int> lt1(lt.begin(), lt.end()); //

	PrintList(lt1);

}

/*
void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> v(ar,ar+10);

	vector<int>::iterator it = v.begin();
	while(it != v.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
}

/*
void PrintList(list<int> &lt)
{
	list<int>::iterator it = lt.begin();
	while(it != lt.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Over."<<endl;
}

void main()
{
	int ar[10] = {1,2,3,4,5,6,7,8,9,10};
	//list<int> lt;
	//list<int> lt(10);
	//list<int> lt(10,2);
	list<int> lt(ar, ar+10);
	list<int> lt1(lt.begin(), lt.end()); //

	PrintList(lt1);

}

/*
void PrintList(list<int> &lt)
{
	list<int>::iterator it = lt.begin();
	while(it != lt.end())
	{
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Over."<<endl;
}

void main()
{
	list<int> mylist;
	for(int i=1; i<=10; ++i)
	{
		mylist.push_back(i);
	}
	PrintList(mylist);
	mylist.pop_front();
	PrintList(mylist);
	mylist.pop_back();
	PrintList(mylist);
	reverse(mylist.begin(), mylist.end());
	PrintList(mylist);
	
}
*/