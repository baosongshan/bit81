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

//插入排序
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
		gap = gap/3 + 1;  //设计文档
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
//选择排序
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

//堆排
void _AdjustDown(int *ar, int left, int right, int start)
{
	int n = right - left + 1;
	int i = start;
	int j = 2 * i + 1 + left; //+left
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
	int cur = n/2 - 1 + left; //+left
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
//交换排序
//冒泡排序

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

//快排
int GetMidIndex(int *ar, int left, int right)
{
	int mid = (left+right) / 2;
	if(ar[left]>ar[mid] && ar[left]<ar[right])
		return left;
	if(ar[mid]>ar[left] && ar[mid]<ar[right])
		return mid;
	return right;
}

int _Partition_1(int *ar, int left, int right)
{
	int key = ar[left];
	while(left < right)
	{
		while(left<right && ar[right] >= key)
			right--;
		Swap(&ar[left], &ar[right]);
		while(left<right && ar[left] < key)
			left++;
		Swap(&ar[left], &ar[right]);
	}
	return left;
}
int _Partition_2(int *ar, int left, int right)
{
	int key = ar[left];
	while(left < right)
	{
		while(left<right && ar[right] >= key)
			right--;
		ar[left] = ar[right];
		while(left<right && ar[left] < key)
			left++;
		ar[right] = ar[left];
	}
	ar[left] = key;
	return left;
}
int _Partition_3(int *ar, int left, int right)
{
	int index = GetMidIndex(ar, left, right);
	if(index != left)
		Swap(&ar[index], &ar[left]);

	int key = ar[left];
	int pos = left;
	for(int i=left+1; i<=right; ++i)
	{
		if(ar[i] < key)
		{
			pos++;
			if(pos != i)
			{
				Swap(&ar[pos], &ar[i]);
			}
		}
	}
	Swap(&ar[left], &ar[pos]);
	return pos;
}

#define M 5
void QuickSort(int *ar, int left, int right)
{
	if(left >= right)
		return;

	if(right-left+1 <= M)
	{
		InsertSort_1(ar, left, right);
	}
	else
	{
		int pos = _Partition_3(ar, left, right);
		QuickSort(ar, left, pos-1);
		QuickSort(ar, pos+1, right);
	}
}

////////////////////////////////////////////////////
//归并排序
void _MergeSort(int *ar, int left, int right, int *tmp)
{
	if(left >= right)
		return;
	int mid = (left+right)/2;
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid+1, right, tmp);

	//归并
	int begin1, end1, begin2, end2, i;
	begin1 = left, end1 = mid;
	begin2 = mid+1, end2 = right;
	i = left;
	while(begin1<=end1 && begin2<=end2)
	{
		if(ar[begin1] < ar[begin2])
			tmp[i++] = ar[begin1++];
		else
			tmp[i++] = ar[begin2++];
	}

	while(begin1 <= end1)
	{
		tmp[i++] = ar[begin1++];
	}
	while(begin2 <= end2)
	{
		tmp[i++] = ar[begin2++];
	}
	//
	memcpy(ar+left, tmp+left, sizeof(int)*(right-left+1));
}
void MergeSort(int *ar, int left, int right)
{
	int n = right - left + 1;
	int *tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(ar, left, right, tmp);
	free(tmp);
	tmp = NULL;
}

//基数排序
#include"slist.h"
#define K 3
#define RADIX 10
SList list[RADIX]; // 0 1 2 3 4 5 6 7 8 9

//278
int GetKey(int value, int k)
{
	int key;
	while(k >= 0)
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}

void Distribute(int *ar, int left, int right, int k)
{
	for(int i=left; i<=right; ++i)
	{
		int key = GetKey(ar[i], k);
		SListPushBack(&list[key], ar[i]);
	}
}

void Collect(int *ar)
{
	int k = 0;
	for(int i=0; i<RADIX; ++i)
	{
		if(!SListEmpty(&list[i]))
		{
			SListNode *p = list[i].first->next;
			while(p != NULL)
			{
				ar[k++] = p->data;
				p = p->next;
			}
		}
	}

	for(int i=0; i<RADIX; ++i)
		SListClear(&list[i]);
}
void RadixSort(int *ar, int left, int right)
{
	for(int i=0; i<RADIX; ++i)
	{
		SListInit(&list[i]);
	}
	for(int i=0; i<K; ++i)
	{
		//1 分发
		Distribute(ar, left, right, i);
		//2 回收
		Collect(ar);
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
	//BubbleSort_1(ar, left, right);
	//QuickSort(ar, left, right);
	//MergeSort(ar, left, right);
	RadixSort(ar, left, right);
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
	int *a8 = (int*)malloc(sizeof(int) * n);
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
		a8[i] = a[i];
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

	start = clock();
	QuickSort(a8, 0, n-1);
	end = clock();
	printf("QuickSort: %u\n", end-start);
}


#endif /* _SORT_H_ */