#include <iostream>
#include <string>
using namespace std;
struct dlnode
{
	dlnode *right;
	int data;
	dlnode *left;
};
typedef struct dlnode *dlptr;
void addend(dlptr &p,int n)
{
	dlptr t;
	t=new(dlnode);
	t->data=n;
	t->right=NULL;
	t->left=NULL;
	if (p==NULL)
	{
		p=t;
	}
	else
	{
		dlptr t1=p;
		while(t1->right!=NULL)
		{
			t1=t1->right;
		}
        t1->right=t;
        t->left=t1;
	}
}
void addfront(dlptr &p,int n)
{
	dlptr t;
	t=new(dlnode);
	t->data=n;
	t->right=NULL;
	t->left=NULL;
	t->right=p;
	p->left=t;
	p=t;
}
void print(dlptr p)
{
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->right;
	}
	cout<<endl;
}
void reverseprint(dlptr p)
{
	while(p->right!=NULL)
	{
		p=p->right;
	}
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->left;
	}
	cout<<endl;
}
void sum(dlptr l1,dlptr l2,dlptr &l3)
{
	int s,c=0;
	while(l1->right!=NULL)
	{
		dlptr x=l1;
		dlptr y=l2;
		while(x->right!=NULL)
		{
			x=x->right;
			y=y->right;
		}
		s=x->data+y->data+c;
		if (s>9)
		{
			c=s/10;
			s=s%10;
		}
		else
		{
			c=0;
		}
		addend(l3,s);
		x=x->left;
		x->right=NULL;
		y=y->left;
		y->right=NULL;
	}
	s=l1->data+l2->data+c;
	addend(l3,s);
}

int main()
{
	dlptr l1=NULL;
	string s;
	cin>>s;
	int s1;
	s1=s.length()-1;
	int i=0;
	while(s[i]!='#')
	{
		s[i]=s[i]-'0';
       addend(l1,s[i]);
       i++;
	}
	dlptr l2=NULL;
	cin>>s;
	int s2=s.length()-1;
	i=0;
	while(s[i]!='#')
	{
		s[i]=s[i]-'0';
       addend(l2,s[i]);
       i++;
	}
	if (s1>s2)
	{
		int x=s1-s2;
		while(x>0)
		{
			addfront(l2,0);
			x--;
		}
	}
	else
	{
		int x=s2-s1;
		while(x>0)
		{
			addfront(l1,0);
			x--;
		}
	}
	dlptr l3=NULL;
	sum(l1,l2,l3);
	reverseprint(l3);
}