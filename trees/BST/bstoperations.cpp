#include <iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
typedef bstnode *bstptr;
void insert(bstptr &t,int k)
{
	if (t==NULL)
	{
		t=new(bstnode);
        t->data=k;
        t->rchild=NULL;
        t->lchild=NULL;
	}
	else
	{
		if (k<t->data)
		{
			insert(t->lchild,k);
		}
		else
		{
			insert(t->rchild,k);
		}
	}
}
void inorder(bstptr t)
{
	if (t!=NULL)
	{
		inorder(t->lchild);
		cout<<t->data<<" ";
		inorder(t->rchild);
	}
}
int height(bstptr p)
{
	if (p==NULL)
	{
		return 0;
	}
	int lheight=height(p->lchild);
	int rheight=height(p->rchild);
	if (lheight>rheight)
	{
		return lheight+1;
	}
	else
	{
		return rheight+1;
	}
}
int min(bstptr t)
{
	if (t->lchild==NULL)
	{
		return t->data;
	}
	else
	{
		min(t->lchild);
	}
}
int max(bstptr t)
{
	if (t->rchild==NULL)
	{
		return t->data;
	}
	else
	{
		max(t->rchild);
	}
}
void minmax(bstptr t,int &mi,int &ma,int &x)
{
    if(t!=NULL)
    {
    	if (x==0)
    	{
    		if (t->lchild!=NULL)
    		{
    			minmax(t->lchild,mi,ma,x);
    		}
    		else
    		{
    			mi=t->data;
    			x=1;
    		}
    	}
        if (x==1)
        {
            if(t->rchild!=NULL) minmax(t->rchild,mi,ma,x);
            else ma=t->data;
        }
    }
}
//5 8 3 4 1 9 6 7 2 -1
int main()
{
   bstptr t=NULL;
   int n;
   cin>>n;
   while(n>0)
   {
   	  insert(t,n);
   	  cin>>n;
   }
   inorder(t);
   cout<<endl;
   int mi,ma;
   mi=min(t);
   ma=max(t);
   cout<<mi<<" "<<ma<<endl;
   int x=0;
   minmax(t,mi,ma,x);
   cout<<mi<<" "<<ma<<endl;
}
