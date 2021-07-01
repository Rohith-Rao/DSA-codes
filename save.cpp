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
void swap3(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
	return;
}
void partition(int a[],int start,int end,int &p1index,int &p2index)
{
    if(a[start]>a[end])
    {
    	swap3(a[start],a[end]);
    }
    int pivot1=a[start];
    int pivot2=a[end];

    int j=start+1,g=end-1;

    int k=start+1;
    for(int i=k;k<=g;k++)
    {
    	if(a[k]<pivot1)
    	{
    		swap3(a[k],a[j]);
    		j++;
    	}
    	else if(a[k]>=pivot2)
    	{
    		while(a[g]<pivot2)
    		{
    			g--;
    		}
    		swap3(a[k],a[g]);
    		g--;
    		if(a[k]<pivot1)
    		{
    			swap3(a[k],a[j]);
    			j++;
    		}
    	}
    }
    j--;
    g++;
    swap3(a[start],a[j]);
    swap3(a[end],a[g]);
    p1index=j;
    p2index=g;

}
void dualpivot(int a[],int start,int end)
{
	if(start<end)
	{
		int p1index,p2index;
		partition(a,start,end,p1index,p2index);
		dualpivot(a,start,p1index-1);
		dualpivot(a,p1index+1,p2index-1);
		dualpivot(a,p1index+1,end);

	}
}
void insert(int a[],int &j,int key)
{   
	if(j>=0&&a[j]>key)
	{
		a[j+1]=a[j];
		j=j-1;
		insert(a[],j,key);
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
    insert(a[],j,key);
    a[j+1]=key;
    recursivesinsertsort(a[],n,i+1);

}

int main()
{
	int p;
	cin>>p;
	switch(p)
	{
		case 1:
		int n;
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
	  break;

	  case 2:
       int n;
	cin>>n;
	int a[n];
	int start=0,end=n-1;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	dualpivot(a,start,end);
	for (int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	break;

	 case 3:

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
     break;



	}

}