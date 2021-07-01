#include <iostream>
using namespace std;
void insert(int a[],int &j,int key)
{   
	if(j>=0&&a[j]>key)
	{
		a[j+1]=a[j];
		j=j-1;
		insert(a,j,key);
	}
	else
		return;

}
void recursivesinsertsort(int a[],int n,int i)
{    if(i==n)
	{
		return;
	}
    int key=a[i];
    int j=i-1;
    insert(a,j,key);
    a[j+1]=key;
    recursivesinsertsort(a,n,i+1);

}
int main()
{   int n;
	cin>>n;
	int a[n];
	int i=1;
	
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	recursivesinsertsort(a,n,i);
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
}
