#include <iostream>
#include <string>
using namespace std;
int find(char c,string a)
{
    int x=a.length();
	for (int i = 0; i < x; i++)
	{
		if (a[i]==c)
		{
			return 1;
		}
	}
	return 0;
}
string add(string a,string b)
{
	a=a+b;
	int la=a.length();
	string s="";
	for (int i = 0; i < la; i++)
	{
		int f=find(a[i],s);
		if (f==0)
		{
			s=s+a[i];
		}
	}
	return s;
}
string segment_tree(string stree[],int i,string s,int l,int r)
{
	if (l==r)
	{
		stree[i]=s[l];
		return stree[i];
	}
	else
	{
        int mid=(l+r)/2;
        stree[i]=add(segment_tree(stree,(2*i)+1,s,l,mid),segment_tree(stree,(2*i)+2,s,mid+1,r));
        return stree[i];
	}
}
string distint_num(string stree[],int i,int l,int r,int sl,int sr)
{
	if (sl<=l && sr>=r)
	{
		return stree[i];
	}
	else if (sr<l || sl > r)
	{
		return "";
	}
	else
	{
		int mid=(l+r)/2;
		string k=add(distint_num(stree,(2*i)+1,l,mid,sl,sr),distint_num(stree,(2*i)+2,mid+1,r,sl,sr));
		return k;
	}
}
void update_up(string stree[],int i)
{
    if(i==0)
    {
        stree[i] = add(stree[2*i+1], stree[2*i+1]);
        return;
    }
    int j = (i-1)/2;
    stree[j] =add(stree[2*j+1], stree[2*j+2]);
    update_up(stree, j);
}
void update(string stree[],int pos,char c,int i,int l,int r)
{
	if(l>r||(l==r && l!=pos))
    return;
    if(l == pos && r == pos)
    {
        stree[i] = "";
        stree[i]+=c;
        update_up(stree,i);
        return;
    }
    else
    {
        int mid = (l+r)/2;
        if(mid>=pos)
        {
            update(stree,pos,c,(2*i)+1,l,mid);
        }
        else
        {
            update(stree,pos,c,(2*i)+2,mid+1,r);
        }
    }
}
int main()
{
	string s;
	cin>>s;
	int l,r;
	l=0;
	r=s.length()-1;
	string stree[1000];
    segment_tree(stree,0,s,l,r);
    int q;
    cin>>q;
    while(q--)
    {
    	int n;
    	cin>>n;
    	if (n==2)
    	{
    		int sl,sr;
    		cin>>sl>>sr;
    		sl--;
    		sr--;
    		string k=distint_num(stree,0,l,r,sl,sr);
    		int x=k.length();
    		cout<<x<<endl;
    	}
    	else if (n==1)
    	{
    		int pos;
    		char c;
    		cin>>pos>>c;
    		pos--;
    		char q=s[pos];
            s[pos]=c;
            update(stree,pos,c,0,l,r);
    	}
    }
}
