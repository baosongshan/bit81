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

	//1 it��ɾ�����ݵĺ��棬��ʱ���ݻ���ǰ�ƶ���������ʧЧ
	//2 it��ɾ�����ݵ�ǰ�棬��ʱ��������ָ���ݲ��ᷢ���仯��������Ȼ��Ч
	//v.erase(v.begin());
	v.erase(p);

	cout<<"*it = "<<*it<<endl;
}