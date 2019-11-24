//int fun(int a, int b);
#include<iostream>
using namespace std;

class CGoods
{
public:
	void  Register(char *n, int c, float p);
	int   GetCount();
	float GetPrice();
	float GetTotalPrice();
protected:
private:
	char name[10];
	int  count;
	float price;
	float total_prive;
};