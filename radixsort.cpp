#include <iostream>
using namespace std;
int getmax(int a[],int n)
{
    int max=-1;
    for (int i = 0; i < n; i++)
    {
    	if (a[i]>max)
    	{
    		max=a[i];
    	}
    }
    return max;

}
void countsort(int a[],int n,int pos)
{
	int f[10]={0};
	for (int i = 0; i < n; i++)
	{
		f[(a[i]/pos)%10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		f[i]=f[i-1]+f[i];
	}
	int b[n];
	for (int i = n - 1; i >= 0; i--)
    {
        b[f[ (a[i]/pos)%10 ] - 1] = a[i];
        f[ (a[i]/pos)%10 ]--;
    }
	for (int i = 0; i < n; i++)
	{
		a[i]=b[i];
	}
}
void radixsort(int a[],int n)
{
	int k=getmax(a,n);
	for (int pos = 1; k/pos>0; pos=pos*10)
	 {
	 	countsort(a,n,pos);
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
	radixsort(a,n);
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
}