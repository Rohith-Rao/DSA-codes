#include <iostream>
#include <string>
using namespace std;
struct ternode
{
	char data;
	int flag;
	ternode *lc=NULL;
	ternode *rc=NULL;
	ternode *mid=NULL;
};
typedef ternode *terptr;
void insert(terptr &T,string s,int ind,int l)
{
	if (ind==l)
	{
		return;
	}
	if (T==NULL)
	{
		T=new(ternode);
		T->data=s[ind];
		if (ind==l-1)
		{
			T->flag=1;
		}
		else
		{
			T->flag=0;
		}
		insert(T->mid,s,ind+1,l);
	}
	else
	{
		if (s[ind]<T->data)
		{
			insert(T->lc,s,ind,l);
		}
		else if(s[ind]>T->data)
		{
			insert(T->rc,s,ind,l);
		}
		else
		{
		    if(ind==l-1)
            {
                T->flag=1;
            }
			insert(T->mid,s,ind+1,l);
		}
	}
}
void inorder(terptr T)
{
	if (T==NULL)
	{
		return;
	}
	cout<<T->data<<" "<<T->flag<< endl;
	inorder(T->lc);
	inorder(T->mid);
	inorder(T->rc);
}
void find(terptr T,string s,int ind,int l,int &f)
{
	if (ind==l)
	{
		return;
	}
	if (T->data==s[ind])
	{
		if (ind==l-1)
		{
			if (T->flag==1)
			{
				f=1;
			}
			else
			{
				f=0;
			}
		}
		find(T->mid,s,ind+1,l,f);
	}
	else
	{
		if (s[ind]<T->data)
		{
			find(T->lc,s,ind,l,f);
		}
		else
		{
			find(T->rc,s,ind,l,f);
		}
	}
}
int main()
{
	terptr T=NULL;
    for (int i = 0; i < 4; i++)
    {
    	string s;
    	cin>>s;
    	int ind=0;
    	int l=s.length();
    	insert(T,s,ind,l);
    }
    for (int i = 0; i < 2; i++)
    {
    	string s;
    	cin>>s;
    	int ind=0;
    	int l=s.length();
    	int f;
    	find(T,s,ind,l,f);
    	cout<<f<<endl;
    }
}