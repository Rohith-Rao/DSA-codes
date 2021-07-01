#include <iostream>
using namespace std;
void reordering()
{
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin>>b[i];
	}
	int c[n];
	int k=0;
	for (int i = 0; i < m; i++)
	{
		for(int j=0;j<n;j++)
		{
               if(a[j]==b[i])
               {
               	  c[k]=a[j];
               	  a[j]=-1;
               	  k++;
               }
		}
	}
	while(k<n)
	{
		int min=1000,p;
		for (int i = 0; i < n; i++)
		{
			if(a[i]!=-1 && a[i]<min)
			{
				min=a[i];
				p=i;
			}
		}
		c[k]=min;
		a[p]=-1;
		k++;

	}
	for (int i = 0; i < n; i++)
	{
		cout<<c[i]<<" ";
	}
}
int main()
{
	reordering();
}
