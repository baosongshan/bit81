#include<stdio.h>

//жиди
char Max(char a, char b)  //_Max
{
	return a > b ? a : b;
}

int Max(int a, int b)     //_Max
{
	return a > b ? a : b;
}
/*double Max(double a, double b)
{
	return a > b ? a : b;
}
*/
void main()
{
	Max('A','B');

}