#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
void qsort(int start, int end, int k, int*& num);
int main()
{
	int* num = new int[1000]();
	int sum = 0;
	int n, k;
	cin >> n;
	char charr;
	charr = getchar();
	cin >> k;
	charr = getchar();
	while (sum < n)
	{
		cin >> num[sum++];
		charr = getchar();
	}
	qsort(0, sum - 1, k, num);
	cout << num[k - 1];
	return 0;
}
void qsort(int start, int end, int k, int*& num)
{
	if (start > end)
	{
		return;
	}
	int base = num[start];
	int i = start;
	int j = end;
	while (i < j)
	{
		while (num[i] < base && i < j)
		{
			i++;
		}
		while (num[j] > base && i < j)
		{
			j--;
		}
		int t = num[i];
		num[i] = num[j];
		num[j] = t;
	}
	int s = i - start;
	if (s >= k)
	{
		qsort(start, i - 1, k, num);
	}
	else
	{
		qsort(i + 1, end, k, num);
	}
}



