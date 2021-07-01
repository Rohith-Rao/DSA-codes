#include <iostream>
using namespace std;
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
int main()
{
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
}
