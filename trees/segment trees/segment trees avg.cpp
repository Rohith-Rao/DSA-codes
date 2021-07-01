#include <iostream>
using namespace std;
int segment_tree_avg(int savg[],int a[],int i,int l,int r)
{
	if (l==r)
	{
		savg[i]=a[l];
		return savg[i];
	}
	else
	{
		int mid=(l+r)/2;
		savg[i]=(segment_tree_avg(savg,a,(2*i)+1,l,mid)*(mid-l+1)+segment_tree_avg(savg,a,(2*i)+2,mid+1,r)*(r-mid-1+1))/(r-l+1);
		return savg[i];
	}
}
int get_avg(int savg[],int i,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return savg[i];
	}
	else if (sr<l || sl > r)
	{
		return 0;
	}
	else
	{
		int mid=(l+r)/2;
		return (get_avg(savg,(2*i)+1,l,mid,sl,sr)*(mid-l+1)+get_avg(savg,(2*i)+2,mid+1,r,sl,sr)*(r-mid-1+1))/(r-l+1);
	}
}
int main()
{
	int a[100];
	int savg[100];
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int l=0;
	int r=n-1;
	segment_tree_avg(savg,a,0,l,r);
	int sl,sr;
	cin>>sl>>sr;
	int k=get_avg(savg,0,l,r,sl,sr);
	cout<<k;
}
