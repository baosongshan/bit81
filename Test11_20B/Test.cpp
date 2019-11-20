#include<iostream>
using namespace std; //ÃüÃû¿Õ¼ä

//
extern "C" int Max(int a, char b, int c)
{
	return a > c ? a : c;
}
extern "C" char Max(char a, char b)
{
	return a > b ? a : b;
}
double Max(double a, double b)
{
	return a > b ? a : b;
}

void main()
{
	cout<<Max(10,20,30)<<endl;
	cout<<Max('A','B')<<endl;
	cout<<Max(12.34,12.45)<<endl;
}