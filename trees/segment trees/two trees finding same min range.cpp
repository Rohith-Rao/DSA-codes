#include <iostream>
using namespace std;
struct node
{
	int min[2];
};
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
int segment_tree_min(node s[],int a[],int k,int i,int l,int r)
{
	if (l==r)
	{
		s[i].min[k]=a[l];
		return s[i].min[k];
	}
	else
	{
		int mid=(l+r)/2;
		s[i].min[k]=min(segment_tree_min(s,a,k,(2*i)+1,l,mid),segment_tree_min(s,a,k,(2*i)+2,mid+1,r));
		return s[i].min[k];
	}
}
void get_ranges(node s[],int i,int l,int r)
{
    if(l==r)
    {
        return;
    }

		if (s[i].min[0]==s[i].min[1])
		{
			cout<<l<<" "<<r<<endl;
		}
         int mid=(l+r)/2;
		get_ranges(s,(2*i)+1,l,mid);
		get_ranges(s,(2*i)+2,mid+1,r);
		cout<<"1\n";




}
int get_min(node s[],int i,int k,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return s[i].min[k];
	}
	else if (sr<l || sl > r)
	{
		return 1000;
	}
	else
	{
		int mid=(l+r)/2;
		return min(get_min(s,(2*i)+1,k,l,mid,sl,sr),get_min(s,(2*i)+2,k,mid+1,r,sl,sr));
	}
}
int main()
{
	int a1[100];
	int a2[100];
	int n1;
	cin>>n1;
	for (int i = 0; i < n1; i++)
	{
		cin>>a1[i];
	}
	int n2;
	cin>>n2;
	for (int i = 0; i < n2; i++)
	{
	    cin>>a2[i];
	}
	int l1,l2,r1,r2;
	l1=0;
	l2=0;
	r1=n1-1;
	r2=n2-1;
	node s[100];
	segment_tree_min(s,a1,0,0,l1,r1);
	segment_tree_min(s,a2,1,0,l2,r2);
	get_ranges(s,0,l1,r1);
}
