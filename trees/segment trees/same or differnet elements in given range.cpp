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
int segment_tree_max(int s[],int a[],int i,int l,int r)
{
	if (l==r)
	{
		s[i]=a[l];
		return s[i];
	}
	else
	{
		int mid=(l+r)/2;
		s[i]=max(segment_tree_max(s,a,(2*i)+1,l,mid),segment_tree_max(s,a,(2*i)+2,mid+1,r));
		return s[i];
	}
}
int get_max(int s[],int i,int l,int r,int sl,int sr)
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
		return max(get_max(s,(2*i)+1,l,mid,sl,sr),get_max(s,(2*i)+2,mid+1,r,sl,sr));
	}
}
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
int segment_tree_min(int s1[],int a[],int i,int l,int r)
{
	if (l==r)
	{
		s1[i]=a[l];
		return s1[i];
	}
	else
	{
		int mid=(l+r)/2;
		s1[i]=min(segment_tree_min(s1,a,(2*i)+1,l,mid),segment_tree_min(s1,a,(2*i)+2,mid+1,r));
		return s1[i];
	}
}
int get_min(int s1[],int i,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return s1[i];
	}
	else if (sr<l || sl > r)
	{
		return 1000;
	}
	else
	{
		int mid=(l+r)/2;
		return min(get_min(s1,(2*i)+1,l,mid,sl,sr),get_min(s1,(2*i)+2,mid+1,r,sl,sr));
	}
}
int check_same(int a[],int l,int r,int sl,int sr)
{
   int s[100];
   int s1[100];
   segment_tree_max(s,a,0,l,r);
   segment_tree_min(s1,a,0,l,r);
   int x=get_max(s,0,l,r,sl,sr);
   int y=get_min(s1,0,l,r,sl,r);
   if (x==y)
   {
   	 return 1;
   }
   else
   {
   	return 0;
   }
}
int main()
{
	int a[100];
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int l=0;
	int r=n-1;
	int sl,sr;
	cin>>sl>>sr;
	int k=check_same(a,l,r,sl,sr);
	if(k==1)
    {
        cout<<"same\n";
    }
    else
    {
        cout<<"not same\n";
    }
}

