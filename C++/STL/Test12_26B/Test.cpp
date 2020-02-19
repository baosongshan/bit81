#include<iostream>
#include<assert.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void main()
{
	int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	vector<int> v(ar, ar+12);

	vector<int>::iterator p = find(v.begin(), v.end(), 10); 

	vector<int>::iterator it = find(v.begin(), v.end(), 3); 
	cout<<"*it = "<<*it<<endl;

	//1 it在删除数据的后面，此时数据会往前移动，迭代器失效
	//2 it在删除数据的前面，此时迭代器所指数据不会发生变化，迭代任然有效
	//v.erase(v.begin());
	v.erase(p);

	cout<<"*it = "<<*it<<endl;
}