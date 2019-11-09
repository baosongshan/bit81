#ifndef _SORT_H_
#define _SORT_H_

#include"common.h"

void PrintArray(int *ar, int left, int right)
{
	for(int i=left; i<=right; ++i)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}

//≤Â»Î≈≈–Ú
void InsertSort(int *ar, int left, int right)
{
	for(int i=left+1; i<=right; ++i)
	{
		int j = i;
		while(j>left && ar[j]<ar[j-1])
		{
			Swap(&ar[j], &ar[j-1]);
			j--;
		}
	}
}

void InsertSort_1(int *ar, int left, int right)
{
	for(int i=left+1; i<=right; ++i)
	{
		int tmp = ar[i];
		int j = i;
		while(j>left && tmp<ar[j-1])
		{
			ar[j] = ar[j-1];
			j--;
		}
		ar[j] = tmp;
	}
}

void InsertSort_2(int *ar, int left, int right)
{
	for(int i=left+1; i<=right; ++i)
	{
		ar[0] = ar[i];
		int j = i;
		while(ar[0] < ar[j-1])
		{
			ar[j] = ar[j-1];
			j--;
		}
		ar[j] = ar[0];
	}
}

void BinInsertSort(int *ar, int left, int right)
{
	for(int i=left+1; i<=right; ++i)
	{
		int tmp = ar[i];
		int low = left;
		int high = i-1;
		int mid;
		while(low <= high)
		{
			mid = (low+high)/2;
			if(ar[i] >= ar[mid])
				low = mid+1;
			if(	ar[i] < ar[mid])
				high = mid-1;
		}

		for(int j=i; j>low; --j)
		{
			ar[j] = ar[j-1];
		}
		ar[low] = tmp;
	}
}

//O(N)
void TwoWayInsertSort(int *ar, int left, int right)
{
	int n = right-left+1;
	int *tmp = (int*)malloc(sizeof(int) * n); //n

	int first, final;
	tmp[0] = ar[left];
	first = final = 0;

	for(int i=left+1; i<=right; ++i)
	{
		if(ar[i]<tmp[first])
		{
			first = (first-1+n) % n;
			tmp[first] = ar[i];
		}
		else if(ar[i] > tmp[final])
		{
			tmp[++final] = ar[i];
		}
		else
		{
			int end = final;
			while(ar[i] < tmp[end])
			{
				tmp[(end+1)%n] = tmp[end];
				end = (end-1+n) %n;
			}
			tmp[(end+1)%n] = ar[i];
			final++;
		}
	}
	int k = 0;
	for(int i=first; k<n;) // n
	{
		ar[k++] = tmp[i];
		i = (i+1) % n;
	}
	free(tmp);
	tmp = NULL;
}

/*
void _ShellSort(int *ar, int left, int right, int gap)
{
	for(int i=left; i<=right-gap; ++i)
	{
		if(ar[i+gap] < ar[i]) // @@@
		{
			int end = i;
			int tmp = ar[end + gap];
			while (end >= left && tmp < ar[end])
			{
				ar[end + gap] = ar[end];
				end -= gap;
			}
			ar[end + gap] = tmp;
		}
	}
}
int dlta[] = {5, 3, 2, 1};
void ShellSort(int *ar, int left, int right)
{
	int n = sizeof(dlta)/sizeof(int);
	for(int i=0; i<n; ++i)
	{
		_ShellSort(ar, left, right, dlta[i]);
	}
}
*/

void ShellSort(int *ar, int left, int right)
{
	int gap = right - left + 1;
	while(gap > 1)
	{
		gap = gap/3 + 1;  //…Ëº∆Œƒµµ
		for(int i=left; i<=right-gap; ++i)
		{
			if(ar[i+gap] < ar[i])
			{
				int end = i;
				int tmp = ar[end+gap];
				while(end>=left && tmp < ar[end])
				{
					ar[end+gap] = ar[end];
					end -= gap;
				}
				ar[end+gap] = tmp;
			}
		}
	}
}
/////////////////////////////////////////////////////////////
//—°‘Ò≈≈–Ú
int GetMinIndex(int *ar, int left, int right)
{
	int min_value = ar[left];
	int index = left;
	for(int i=left+1; i<=right; ++i)
	{
		if(ar[i] < min_value)
		{
			min_value = ar[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int *ar, int left, int right)
{
	for(int i=left; i <right; ++i)
	{
		int index = GetMinIndex(ar, i, right);
		if(index != i)
		{	
			Swap(&ar[index], &ar[i]);
		}
	}
}

//∂—≈≈
void _AdjustDown(int *ar, int left, int right, int start)
{
	int n = right - left + 1;
	int i = start;
	int j = 2 * i + 1;
	while(j < n)
	{
		if(j+1<n && ar[j]<ar[j+1])
			j++;
		if(ar[i] < ar[j])
		{
			Swap(&ar[i], &ar[j]);
			i = j;
			j = 2*i+1;
		}
		else
			break;
	}
}
void HeapSort(int *ar, int left, int right)
{
	int n = right-left+1;
	int cur = n/2 - 1;
	while(cur)
	{
		_AdjustDown(ar, left, right, cur);
		cur--;
	}
	int end = right;
	while(end > left)
	{
		Swap(&ar[left], &ar[end]);
		end--;
		_AdjustDown(ar, left, end, 0);
	}
}

/////////////////////////////////////////////////////
//Ωªªª≈≈–Ú
//√∞≈›≈≈–Ú

void BubbleSort(int *ar, int left, int right)
{
	int n = right-left+1;
	for(int i=left; i<right-1; ++i)
	{
		for(int j=left; j<n-i-1; ++j)
		{
			if(ar[j] > ar[j+1])
			{
				Swap(&ar[j], &ar[j+1]);
				//ar[j] = ar[j+1];
			}
		}
	}
}

void BubbleSort_1(int *ar, int left, int right)
{
	int n = right-left+1;
	bool is_swap = false;
	for(int i=left; i<right-1; ++i)
	{
		for(int j=left; j<n-i-1; ++j)
		{
			if(ar[j] > ar[j+1])
			{
				Swap(&ar[j], &ar[j+1]);
				is_swap = true;
			}
		}
		if(!is_swap)
			break;
		else
			is_swap = false;
	}
}

/////////////////////////////////////////////////
void TestSort(int *ar, int left, int right)
{
	//InsertSort(ar, left, right);
	//InsertSort_1(ar, left, right);
	//InsertSort_2(ar, left, right);
	//BinInsertSort(ar, left, right);
	//TwoWayInsertSort(ar, left, right);
	//ShellSort(ar, left, right);
	//SelectSort(ar, left, right);
	//HeapSort(ar, left, right);
	BubbleSort_1(ar, left, right);
	PrintArray(ar, left, right);
}

void TestSrotEfficiency()
{
	int n = 20000;
	int *a = (int*)malloc(sizeof(int) * n);
	int *a1 = (int*)malloc(sizeof(int) * n);
	int *a2 = (int*)malloc(sizeof(int) * n);
	int *a3 = (int*)malloc(sizeof(int) * n);
	int *a4 = (int*)malloc(sizeof(int) * n);
	int *a5 = (int*)malloc(sizeof(int) * n);
	int *a6 = (int*)malloc(sizeof(int) * n);
	int *a7 = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for(int i=0; i<n; ++i)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
		a4[i] = a[i];
		a5[i] = a[i];
		a6[i] = a[i];
		a7[i] = a[i];
	}

	time_t start = clock();
	InsertSort(a, 0, n-1);
	time_t end = clock();
	printf("InsertSort: %u\n", end-start);

	start = clock();
	InsertSort_1(a1, 0, n-1);
	end = clock();
	printf("InsertSort_1: %u\n", end-start);

	start = clock();
	BinInsertSort(a2, 0, n-1);
	end = clock();
	printf("BinInsertSort: %u\n", end-start);

	start = clock();
	TwoWayInsertSort(a3, 0, n-1);
	end = clock();
	printf("TwoWayInsertSort: %u\n", end-start);

	start = clock();
	ShellSort(a4, 0, n-1);
	end = clock();
	printf("ShellSort: %u\n", end-start);

	start = clock();
	SelectSort(a5, 0, n-1);
	end = clock();
	printf("SelectSort: %u\n", end-start);

	start = clock();
	HeapSort(a6, 0, n-1);
	end = clock();
	printf("HeapSort: %u\n", end-start);

	start = clock();
	BubbleSort_1(a7, 0, n-1);
	end = clock();
	printf("BubbleSort: %u\n", end-start);
}


#endif /* _SORT_H_ */