#include<iostream>
#include"Everything.h"
using namespace std;

void main()
{
	Everything_SetSearchA("alibaba");
	Everything_QueryA(TRUE);
	
	for(int i=0;i<Everything_GetNumResults();i++)
	{
		cout << Everything_GetResultFileNameA(i) << endl;
	}
}

/*

#include "..\include\Everything.h"

int main(int argc,char **argv)
{
	Everything_SetSearchW(L"hello");
	Everything_QueryW(TRUE);
	
	{
		DWORD i;
		
		for(i=0;i<Everything_GetNumResults();i++)
		{
			wcout << Everything_GetResultFileNameW(i) << L"\n";
		}
	}
	
	return 0;
}

*/