#include <iostream>
using namespace std;
int min(int a,int b)
{
	if (a<b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int segment_tree_min(int smin[],int a[],int i,int l,int r)
{
	if (l==r)
	{
		smin[i]=a[l];
		return smin[i];
	}
	else
	{
		int mid=(l+r)/2;
		smin[i]=min(segment_tree_min(smin,a,(2*i)+1,l,mid),segment_tree_min(smin,a,(2*i)+2,mid+1,r));
		return smin[i];
	}
}
int get_min(int smin[],int i,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return smin[i];
	}
	else if (sr<l || sl > r)
	{
		return 1000;
	}
	else
	{
		int mid=(l+r)/2;
		return min(get_min(smin,(2*i)+1,l,mid,sl,sr),get_min(smin,(2*i)+2,mid+1,r,sl,sr));
	}
}
void update_min_up(int smin[],int i)
{
	if (i==0)
	{
		smin[i]=min(smin[(2*i)+1],smin[(2*i)+2]);
		return;
	}
	else
	{
		int j=(i-1)/2;
		smin[j]=min(smin[(2*j)+1],smin[(2*j)+2]);
		update_min_up(smin,j);
	}
}
void update_min(int smin[],int i,int l,int r,int ind,int val)
{
	if (ind<l || ind>r)
	{
		return;
	}
	if (l==ind && r==ind)
	{
		smin[i]=val;
		update_min_up(smin,i);
	}
	else
    {
        int mid=(l+r)/2;
        if(mid>=ind)
        {
            update_min(smin,(2*i)+1,l,mid,ind,val);
        }
        else
        {
            update_min(smin,(2*i)+2,mid+1,r,ind,val);
        }
    }
}
int main()
{
	int a[100];
	int smin[100];
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int l=0;
	int r=n-1;
	segment_tree_min(smin,a,0,l,r);
	int sl,sr;
	cin>>sl>>sr;
	int k=get_min(smin,0,l,r,sl,sr);
	cout<<k;
	cin>>k;
	int val;
	cin>>val;
	a[k]=val;
	update_min(smin,0,l,r,k,val);
	k=get_min(smin,0,l,r,sl,sr);
	cout<<k;
}

