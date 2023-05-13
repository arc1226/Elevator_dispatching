#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
void MergeSort(int a[], int sum);
int main()
{
	int num[100];
	char ch = ',';
	int nN = 0;
	while (ch == ',')
	{
		cin >> num[nN];
		nN++;
		ch = getchar();
	}
	MergeSort(num, nN);
	for (int i = 0; i < nN - 1; i++)
	{
		cout << num[i] << ",";
	}
	cout << num[nN - 1] << endl;
	return 0;
}
void MergeSort(int a[], int sum)
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



