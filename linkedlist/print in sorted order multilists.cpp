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
void printsort(mlptr ml)
{
	
}
int main()
{
	mlptr ML;
	ML=NULL;
	insert(ML);
}