#include <iostream>
using namespace std;
void triplet()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int b[3],x=0,j=0;
    for(int i=0;i<n;i++)
    {
    	if(a[i]>x)
    	{
    		b[j]=a[i];
    		x=a[i];
    		j++;
    	}
    	if(j>2)
    	{
    		break;
    	}
    }
    for (int i = 0; i < 3; i++)
    {
    	cout<<b[i]<<" ";
    }
}
int main()
{
	triplet();
}