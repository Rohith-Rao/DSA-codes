#include <iostream>
using namespace std;
int segment_tree(int s[],int a[],int i,int l,int r)
{
	if (l==r)
	{
		s[i]=a[l];
		return s[i];
	}
	else
	{
		int mid=(l+r)/2;
		s[i]=segment_tree(s,a,(2*i)+1,l,mid)+segment_tree(s,a,(2*i)+2,mid+1,r);
		return s[i];
	}
}
int get_sum(int s[],int i,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return s[i];
	}
	else if (sr<l || sl > r)
	{
		return 0;
	}
	else
	{
		int mid=(l+r)/2;
		return get_sum(s,(2*i)+1,l,mid,sl,sr)+get_sum(s,(2*i)+2,mid+1,r,sl,sr);
	}
}
void update(int s[],int i,int ind,int l,int r,int diff)
{
	if (ind<l || ind>r)
	{
		return;
	}
	s[i]=s[i]+diff;
	if (l!=r)
	{
		int mid=(l+r)/2;
		update(s,(2*i)+1,ind,l,mid,diff);
		update(s,(2*i)+2,ind,mid+1,r,diff);
	}
}
int main()
{
	int a[100];
	int s[100];
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int l=0;
	int r=n-1;
	segment_tree(s,a,0,l,r);
	int sl,sr;
	cin>>sl>>sr;
	int k=get_sum(s,0,l,r,sl,sr);
	cout<<k;
	int ind;
	cin>>ind;
	int q;
	cin>>q;
	int diff=q-a[ind];
	a[ind]=q;
	update(s,0,ind,l,r,diff);
	k=get_sum(s,0,l,r,sl,sr);
	cout<<k;
}
