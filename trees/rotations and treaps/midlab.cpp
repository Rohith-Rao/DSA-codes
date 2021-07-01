#include <iostream>
using namespace std;
struct bstnode
{
	int data;
	bstnode *lc;
	bstnode *rc;
};
typedef bstnode *bstptr;
void insert(bstptr &B,int n)
{
	if (B==NULL)
	{
		B=new(bstnode);
		B->data=n;
		B->lc=NULL;
		B->rc=NULL;
		return;
	}
	if (n<B->data)
	{
		insert(B->lc,n);
	}
	else
	{
		insert(B->rc,n);
	}
}
void preorder(bstptr B,int p[],int &ind)
{
    if (B==NULL)
    {
    	return;
    }
    p[ind]=B->data;
    ind++;
    preorder(B->lc,p,ind);
    preorder(B->rc,p,ind);
}
void find_lca(bstptr B,bstptr &lca,int x,int y,int &flag)
{
	if (B==NULL)
	{
		return;
	}
	if (B->data==x || B->data==y)
	{
		lca=B;
		if (B->data==x)
		{
			flag=1;
		}
		else
		{
			flag=2;
		}
	}
	else if (x > B->data && y> B->data)
	{
	   find_lca(B->rc,lca,x,y,flag);
	}
	else if (x < B->data && y < B->data)
	{
		find_lca(B->lc,lca,x,y,flag);
	}
	else
	{
		lca=B;
	}
}
void get_distance(bstptr B,int n,int &k)
{
	if (B->data==n)
	{
		return;
	}
	if (n<B->data)
	{
		k++;
		get_distance(B->lc,n,k);
	}
	else
	{
		k++;
		get_distance(B->rc,n,k);
	}
}
int distances(bstptr B)
{
   int p[100];
   int ind=0;
   preorder(B,p,ind);
   int count=0;
   for (int i = 0; i < ind-1; i++)
   {
   	  for (int j = i+1; j < ind; j++)
   	  {
   	  	 int x=p[i];
   	  	 int y=p[j];
   	  	 bstptr lca=NULL;
   	  	 int flag=3;
         find_lca(B,lca,x,y,flag);
         if (flag==3)
         {
         	int k=0;
         	get_distance(lca,x,k);
         	count=count+k;
         	k=0;
         	get_distance(lca,y,k);
         	count=count+k;
         }
         else if (flag==1)
         {
         	int k=0;
         	get_distance(lca,y,k);
         	count=count+k;
         }
         else if (flag==2)
         {
         	int k=0;
         	get_distance(lca,x,k);
         	count=count+k;
         }
   	  }
   }
   return count;
}
int main()
{
	bstptr B=NULL;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
	    int n1;
	    cin>>n1;
		insert(B,n1);
		if (i==0)
		{
			cout<<"0 ";
		}
		else if (i==1)
		{
			cout<<"1 ";
		}
		else
		{
			int k=distances(B);
			cout<<k<<" ";
		}

	}
}
