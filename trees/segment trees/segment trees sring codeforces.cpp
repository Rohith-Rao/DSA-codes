#include <iostream>
using namespace std;
struct node
{
	int sum;
	int min;
	int max;
};



int segment_tree(node s[],int a[],int i,int l,int r)
{
	if (l==r)
	{
		s[i].sum=a[l];
		return s[i].sum;
	}
	else
	{
		int mid=(l+r)/2;
		s[i].sum=segment_tree(s,a,(2*i)+1,l,mid)+segment_tree(s,a,(2*i)+2,mid+1,r);
		return s[i].sum;
	}
}
int get_sum(node s[],int i,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return s[i].sum;
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
void update(node s[],int i,int ind,int l,int r,int diff)
{
	if (ind<l || ind>r)
	{
		return;
	}
	s[i].sum=s[i].sum+diff;
	if (l!=r)
	{
		int mid=(l+r)/2;
		update(s,(2*i)+1,ind,l,mid,diff);
		update(s,(2*i)+2,ind,mid+1,r,diff);
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
int segment_tree_min(node s[],int a[],int i,int l,int r)
{
	if (l==r)
	{
		s[i].min=a[l];
		return s[i].min;
	}
	else
	{
		int mid=(l+r)/2;
		s[i].min=min(segment_tree_min(s,a,(2*i)+1,l,mid),segment_tree_min(s,a,(2*i)+2,mid+1,r));
		return s[i].min;
	}
}
int get_min(node s[],int i,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return s[i].min;
	}
	else if (sr<l || sl > r)
	{
		return 1000;
	}
	else
	{
		int mid=(l+r)/2;
		return min(get_min(s,(2*i)+1,l,mid,sl,sr),get_min(s,(2*i)+2,mid+1,r,sl,sr));
	}
}
void update_min_up(node s[],int i)
{
	if (i==0)
	{
		s[i].min=min(s[(2*i)+1].min,s[(2*i)+2].min);
		return;
	}
	else
	{
		int j=(i-1)/2;
		s[j].min=min(s[(2*j)+1].min,s[(2*j)+2].min);
		update_min_up(s,j);
	}
}
void update_min(node s[],int i,int l,int r,int ind,int val)
{
	if (ind<l || ind>r)
	{
		return;
	}
	if (l==ind && r==ind)
	{
		s[i].min=val;
		update_min_up(s,i);
	}
	else
    {
        int mid=(l+r)/2;
        if(mid>=ind)
        {
            update_min(s,(2*i)+1,l,mid,ind,val);
        }
        else
        {
            update_min(s,(2*i)+2,mid+1,r,ind,val);
        }
    }
}













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
int segment_tree_max(node s[],int a[],int i,int l,int r)
{
	if (l==r)
	{
		s[i].max=a[l];
		return s[i].max;
	}
	else
	{
		int mid=(l+r)/2;
		s[i].max=max(segment_tree_max(s,a,(2*i)+1,l,mid),segment_tree_max(s,a,(2*i)+2,mid+1,r));
		return s[i].max;
	}
}
int get_max(node s[],int i,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return s[i].max;
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
void update_max_up(node s[],int i)
{
	if (i==0)
	{
		s[i].max=max(s[(2*i)+1].max,s[(2*i)+2].max);
		return;
	}
	else
	{
		int j=(i-1)/2;
		s[j].max=max(s[(2*j)+1].max,s[(2*j)+2].max);
		update_max_up(s,j);
	}
}
void update_max(node s[],int i,int l,int r,int ind,int val)
{
	if (ind<l || ind>r)
	{
		return;
	}
	if (l==ind && r==ind)
	{
		s[i].max=val;
		update_max_up(s,i);
	}
	else
    {
        int mid=(l+r)/2;
        if(mid>=ind)
        {
            update_max(s,(2*i)+1,l,mid,ind,val);
        }
        else
        {
            update_max(s,(2*i)+2,mid+1,r,ind,val);
        }
    }
}

















int main()
{
	int a[100];
	node s[1000];
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int l=0;
	int r=n-1;
	segment_tree(s,a,0,l,r);
	segment_tree_min(s,a,0,l,r);


	int w;
	cin>>w;
	while(w--)
	{
		int z;
		cin>>z;
		if (z==0)
		{
			int ind;
	        cin>>ind;
	        ind--;
	        int q;
	        cin>>q;
	        int diff=q-a[ind];
	        a[ind]=q;
	        update(s,0,ind,l,r,diff);
	        update_min(s,0,l,r,ind,q);
	        update_max(s,0,l,r,ind,q);
		}
		else if (z==3)
		{
			int sl,sr;
	        cin>>sl>>sr;
	        sl--;
	        sr--;
	        int k=get_sum(s,0,l,r,sl,sr);
	        cout<<k<<endl;
		}
		else if (z==1)
		{
			int sl,sr;
	        cin>>sl>>sr;
	        sl--;
	        sr--;
	        int k=get_min(s,0,l,r,sl,sr);
	        cout<<k<<endl;
		}
		else if (z==4)
		{
			int sl,sr;
	        cin>>sl>>sr;
	        sl--;
	        sr--;
	        int k=get_sum(s,0,l,r,sl,sr);
	        float f=float(k)/float(sr-sl+1);
	        cout<<f<<endl;
		}
		else if (z==2)
		{
			int sl,sr;
	        cin>>sl>>sr;
	        sl--;
	        sr--;
	        int k=get_max(smax,0,l,r,sl,sr);
	        cout<<k;
		}
	}
}


