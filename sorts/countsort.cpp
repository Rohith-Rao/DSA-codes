#include <iostream>
using namespace std;
void countsort()
{
	int n;
	int a[n];
	int max=-1;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
		if (a[i]>max)
		{
			max=a[i];
		}
	}
	int count[max+1]={0};
	for (int i = 0; i < n; i++)
	{
		count[a[i]]++;
	}
	for (int i = 1; i <=max ; i)
	{
		count[i]=count[i]+count[i-1];
	}
	int b[n];
	for (int i = n-1; i >=0; i--)
	{
	     b[--count[i]]=a[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i]=b[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	countsort();
}