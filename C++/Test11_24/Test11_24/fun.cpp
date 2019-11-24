#include"fun.h"

void  CGoods::Register(char *n, int c, float p)
{
	strcpy(name, n);
	count = c;
	price = p;
}

int CGoods::GetCount()
{
	return count;
}

float CGoods::GetPrice()
{
	return price;
}
float CGoods::GetTotalPrice()
{
	return count * price;
}

