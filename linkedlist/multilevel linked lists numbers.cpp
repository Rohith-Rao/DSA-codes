#include <iostream>
using namespace std;
struct dnode
{
	int ddata;
	dnode *ddown;
};
typedef struct dnode *dlptr;
struct mlnode
{
	int data;
	mlnode *next;
	dnode *down;
};
typedef struct mlnode *mlptr;
struct node
{
	int data;
	node *next;
};
typedef struct node *lptr;
void print(lptr p)
{
	if (p==NULL)
	{  cout<<endl;
		return;
	}

	cout<<p->data<<" ";
	print(p->next);
}
void addend(lptr &p,int n)
{
	lptr T;
	T=new(node);
	T->data=n;
	T->next=NULL;
	if(p==NULL)
    {
        p=T;
        return;
    }
    lptr t1=p;
	while(t1->next!=NULL)
	{
		t1=t1->next;
	}
    t1->next=T;
}
void downinsert(dlptr &k)
{
	int n;
	cin>>n;
	if (n==-1)
	{
		return;
	}
	else
	{
		dlptr t;
		t=new(dnode);
		t->ddata=n;
		t->ddown=NULL;
		if (k==NULL)
		{
			k=t;
		}
		else
		{
			dlptr l;
			l=k;
			while(l->ddown!=NULL)
			{
				l=l->ddown;
			}
			l->ddown=t;
		}
		downinsert(k);
	}
}
void insert(mlptr &p)
{
	int n;
	cin>>n;
	if (n==-2)
	{
		return;
	}
	mlptr t;
	t=new(mlnode);
	t->data=n;
	t->next=NULL;
	t->down=NULL;
	if (p==NULL)
	{
		p=t;
	}
	else
	{
		mlptr l=p;
		while(l->next!=NULL)
		{
			l=l->next;
		}
		l->next=t;
	}
	cin>>n;
	if (n==1)
	{
		downinsert(t->down);
	}
    insert(p);
}
void dlist(dlptr p,lptr &l)
{
	if (p==NULL)
	{
		return;
	}
	addend(l,p->ddata);
	dlist(p->ddown,l);
}
void list(mlptr ml,lptr &l)
{
	if (ml==NULL)
	{
		return;
	}
		addend(l,ml->data);
		dlist(ml->down,l);
	
	list(ml->next,l);
}
int main()
{
	mlptr ML;
	ML=NULL;
	insert(ML);
    lptr L;
    L=NULL;
    list(ML,L);
    print(L);
}
