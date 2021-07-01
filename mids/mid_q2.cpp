#include <iostream>
using namespace std;
struct lnode
{
	int data;
	lnode *next;
};
typedef struct lnode *lptr;
struct bstnode
{
	lptr l;
	bstnode *lchild;
	bstnode *rchild;
};
typedef struct bstnode *bstptr;
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
void insert(bstptr &B,lptr t,lptr p,int i,int d)
{
	if (B==NULL)
	{
		B=new(bstnode);
		B->l=t;
		B->lchild=NULL;
		B->rchild=NULL;
	}
	else
	{
		lptr x;
		int y=0;
		lptr z=B->l;
		lptr w=t;
		while(y<i)
		{
			w=w->next;
			z=z->next;
			y++;
		}
		if (w->data < z->data)
		{
			insert(B->lchild,t,p,(i+1)%d,d);
		}
		else
		{
			insert(B->rchild,t,p,(i+1)%d,d);
		}
	}
}
void inorder(bstptr B)
{
	if (B==NULL)
	{
		return;
	}
	else
	{
		inorder(B->lchild);
		lptr t=B->l;
		while(t!=NULL)
		{
			cout<<t->data<<" ";
			t=t->next;
		}
		cout<<endl;
		inorder(B->rchild);
	}
}
int main()
{
	int d;
	cin>>d;
	lptr t=NULL;
	int i=1;
	bstptr B=NULL;
	int n;
	cin>>n;
    while(n>0)
    {
        if (i==6)
        {
           i=1;
           lptr p=t;
           insert(B,t,p,0,d);
           t=NULL;
        }
        addend(t,n);
        cin>>n;
        i++;
    }
    inorder(B);
}