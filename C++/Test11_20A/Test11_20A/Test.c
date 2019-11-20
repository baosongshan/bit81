#include<stdio.h>

//жиди
char Max(char a, char b)
{
	return a > b ? a : b;
}
/*
int Max(int a, int b)
{
	return a > b ? a : b;
}
double Max(double a, double b)
{
	return a > b ? a : b;
}
*/
void main()
{
	Max('A','B');
	//cout<<Max(10,20)<<endl;
	//cout<<Max('A','B')<<endl;
	//cout<<Max(12.34,12.45)<<endl;
	//Max(10,20);
	//Max('A', 'B');
	//Max(12.34, 12.45);
}