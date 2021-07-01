#include <iostream>
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
void deletefront(dlptr &p)
{
    if(p->right==NULL)
    {
        p=NULL;
        return;
    }
	p=p->right;
	p->left=NULL;
}
void deleteend(dlptr p)
{
	while(p->right!=NULL)
	{
		p=p->right;
	}
	p=p->left;
	p->right=NULL;
}
void addafter(dlptr p,int n,int x)
{
	dlptr t;
	t=new(dlnode);
	t->data=n;
	t->right=NULL;
	t->left=NULL;
	while(p->data!=x)
	{
		p=p->right;
	}
	if(p->right==NULL)
    {
        p->right=t;
        t->left=p;
    }
    else{
	t->right=p->right;
	p->right->left=t;
	t->left=p;
	p->right=t;
    }
}
void addbefore(dlptr &p,int n,int x)
{
	dlptr t;
	t=new(dlnode);
	t->data=n;
	t->right=NULL;
	t->left=NULL;
	if (p->data==x)
	{
	   t->right=p;
       p->left=t;
	   p=t;
	}
	else
	{
		dlptr t1=p;
		while(t1->data!=x)
		{
			t1=t1->right;
		}
		t->left=t1->left;
		t1->left->right=t;
		t->right=t1;
		t1->left=t;
	}
}
void deleteelement(dlptr &p,int n)
{
	if (p->data==n)
	{
		p=p->right;
		p->left=NULL;
	}
	else
	{
		dlptr t=p;
		while(t->data!=n)
		{
			t=t->right;
		}
		if (t->right==NULL)
		{

			t=t->left;
			t->right=NULL;
		}
		else{
		t->left->right=t->right;
		t->right->left=t->left;
	    }
	}
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
		cout<<p->data<<" ";
		p=p->left;
	}
	cout<<endl;
}
void sort(dlptr &p)
{
	dlptr l;
	l=NULL;
	addend(l,p->data);
	deletefront(p);
	while(p!=NULL)
	{
		dlptr t=l;
		int flag=0;
		while(t!=NULL)
		{
            if (t->data > p->data)
            {
            	addbefore(l,p->data,t->data);
            	flag=1;
            	break;
            }
			t=t->right;
		}
        if (flag==0)
        {
           addend(l,p->data);
        }
		deletefront(p);
	}
	p=l;
}
int main()
{
	dlptr D;
	D=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		addend(D,n);
		cin>>n;
	}
	print(D);
	int k;
	cin>>k;
	addfront(D,k);
	print(D);
	cin>>k;
	addend(D,k);
	print(D);
	int x,y;
	cin>>x>>y;
	addbefore(D,x,y);
	print(D);
	cin>>x>>y;
	addafter(D,x,y);
	print(D);
	deletefront(D);
	print(D);
	deleteend(D);
	print(D);
	cin>>k;
	deleteelement(D,k);
	print(D);
	sort(D);
	print(D);
}
