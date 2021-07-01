#include <iostream>
using namespace std;
int max(int a,int b)
{
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int segment_tree_max(int smax[],int a[],int i,int l,int r)
{
	if (l==r)
	{
		smax[i]=a[l];
		return smax[i];
	}
	else
	{
		int mid=(l+r)/2;
		smax[i]=max(segment_tree_max(smax,a,(2*i)+1,l,mid),segment_tree_max(smax,a,(2*i)+2,mid+1,r));
		return smax[i];
	}
}
int get_max(int smax[],int i,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return smax[i];
	}
	else if (sr<l || sl > r)
	{
		return 0;
	}
	else
	{
		int mid=(l+r)/2;
		return max(get_max(smax,(2*i)+1,l,mid,sl,sr),get_max(smax,(2*i)+2,mid+1,r,sl,sr));
	}
}
void update_max_up(int smax[],int i)
{
	if (i==0)
	{
		smax[i]=max(smax[(2*i)+1],smax[(2*i)+2]);
		return;
	}
	else
	{
		int j=(i-1)/2;
		smax[j]=max(smax[(2*j)+1],smax[(2*j)+2]);
		update_max_up(smax,j);
	}
}
void update_max(int smax[],int i,int l,int r,int ind,int val)
{
	if (ind<l || ind>r)
	{
		return;
	}
	if (l==ind && r==ind)
	{
		smax[i]=val;
		update_max_up(smax,i);
	}
	else
    {
        int mid=(l+r)/2;
        if(mid>=ind)
        {
            update_max(smax,(2*i)+1,l,mid,ind,val);
        }
        else
        {
            update_max(smax,(2*i)+2,mid+1,r,ind,val);
        }
    }
}
int main()
{
	int a[100];
	int smax[100];
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int l=0;
	int r=n-1;
	segment_tree_max(smax,a,0,l,r);
	int sl,sr;
	cin>>sl>>sr;
	int k=get_max(smax,0,l,r,sl,sr);
	cout<<k;
	cin>>k;
	int val;
	cin>>val;
	a[k]=val;
	update_max(smax,0,l,r,k,val);
	k=get_max(smax,0,l,r,sl,sr);
	cout<<k;
}
