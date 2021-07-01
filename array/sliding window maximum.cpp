#include <iostream>
using namespace std;
int findmax(int a[],int start,int end)
{
	int max=-1;
	for (int i = start; i <= end; i++)
	{
		if (a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}
int slidingwindow(int a[],int n,int b,int c[])
{   int start,end,m;
	if (b>=n)
	{
		m=findmax(a,0,n-1);
		c[0]=m;
		return 1;
	}
	else
	{
	int i=0;
	while(1>0)
	{
		start=i;
		end=i+b-1;
		m=findmax(a,start,end);
		c[i]=m;
		start=start+1;
		end=end+1;
		i++;
		if (end>n-1)
		{
			break;
		}

	}
	return i;
    }
}
int main()
{
	int n;
	cin>>n;
	int a[n],c[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int b;
	cin>>b;
	int k;
	k=slidingwindow(a,n,b,c);
	for (int i = 0; i < k; i++)
	{
		cout<<c[i]<<" ";
	}

}