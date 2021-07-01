#include <iostream>
using namespace std;
void merge(int a[],int b[],int start,int mid,int end)
{
	int i=start;
	int j=mid+1;
	int k=end;
    while(i<mid+1 && j<=end)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<mid+1)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=end)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=start;i<=end;i++)
		a[i]=b[i];
		return;
}
void mergesort(int a[],int b[],int start,int end)
{
   if(start<end)
   {
   	int x=start;
     for(int i=start;i<end;i+=2)
     {
     	b[x]=a[i];
     	x=x+1;
     }
     for(int i=start+1;i<end;i+=2)
     {
     	b[x]=a[i];
     	x++;
     }
     for(int i=start;i<end;i++)
     {
     	a[i]=b[i];
     }
      for(int i=start;i<end+1;i++)
      {
      	a[i]=b[i];
      }
     int mid=(start+end-1)/2;
     mergesort(a,b,start,mid);
     mergesort(a,b,mid+1,end);
     merge(a,b,start,mid,end);

   }
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	int b[n];
	int start=0,end=n-1;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	mergesort(a,b,start,end);
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}

}