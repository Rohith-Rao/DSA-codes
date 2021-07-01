#include <iostream>
using namespace std;
void countingsort(int a[],int n)
{
    int max=-1;
     for (int i = 0; i < n; i++)
     {
     	if (a[i]>max)
     	{
     		max=a[i];
     	}
     }
     int f[max+1]={0};
     for (int i = 0; i < n; i++)
     {
     	f[a[i]]++;
     }
     for (int i = 1; i < max+1; i++)
     {
     	f[i]=f[i-1]+f[i];
     }
     int b[n];
     for (int i = 0; i < n; i++)
     {
     	b[f[a[i]]-1]=a[i];
     	f[a[i]]--;
     }
     for (int i = 0; i < n; ++i)
     {
     	a[i]=b[i];
     }
     for (int i = 0; i < n; ++i)
     {
     	cout<<a[i]<<" ";
     }
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];

	}
	countingsort(a,n);
}
