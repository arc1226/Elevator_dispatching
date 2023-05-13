#include <iostream>
#include<stdio.h>
#include<ctime>
using namespace std;

int FindMaxSubarray(int array[], int length)
{
    int start = 0, end = 0; 
    int MaxSumSub; 
    int* d = new int[length];  

    d[0] = array[0];  
    MaxSumSub = d[0]; 
    int temp = 0;  

    for (int i = 1; i < length; i++)
    {
        if (d[i - 1] <= 0)  
        {
            d[i] = array[i];
            temp = i; 
        }
        else
            d[i] = array[i] + d[i - 1];  

        if (d[i] > MaxSumSub)  
        {
            MaxSumSub = d[i];  
            start = temp;  
            end = i;  
        }
    }

    cout << "X[" << start << "," << end << "]=";
    return MaxSumSub;

}

int main()
{
    int a[100];
    int i = 0;
    char ch = ',';
    clock_t st, et;
    st = clock();
    while (ch == ',')
    {
        cin >> a[i];
        i++;
        ch = getchar();
    }
    int max = FindMaxSubarray(a, i);
    et = clock();
    cout << max << endl;
    return 0;
}