#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
void MergeSort(int a[], int sum, int& k);
int main()
{
	int k = 0;
	int num[100];
	char chh = ',';
	int n = 0;
	while (chh == ',')
	{
		cin >> num[n];
		n++;
		chh = getchar();
	}
	MergeSort(num, n, k);
	cout << k << endl;
	return 0;
}
void MergeSort(int a[], int sum, int& k)
{
	int* temp = new int[sum]();
	for (int gap = 1; gap < sum; gap = gap * 2)
	{
		int begin1 = 0;
		int end1 = 0;
		int begin2 = 0;
		int end2 = 0;
		for (begin1 = 0; begin1 < sum; begin1 = end2 + 1)
		{
			end1 = begin1 + gap - 1;
			begin2 = end1 + 1;
			end2 = begin2 + gap - 1;
			if (end2 >= sum)
			{
				end2 = sum - 1;
			}
			int j = 0;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					temp[j++] = a[begin1++];
				}
				else
				{
					k += end1 - begin1 + 1;
					temp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				temp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				temp[j++] = a[begin2++];
			}
			while (j > 0)
			{
				a[--begin2] = temp[--j];
			}
		}
	}
}
