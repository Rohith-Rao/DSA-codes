#include <iostream>
using namespace std;
void wrongswap()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int f,l;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			f=i;
			break;
		}

	}
	for (int i = n-1; i>0; i--)
	{
	    if(a[i-1]>a[i])
	    {
            l=i;
            break;
	    }
	}
	int t;
	t=a[f];
	a[f]=a[l];
	a[l]=t;
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	wrongswap();
}
