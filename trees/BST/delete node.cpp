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
void no_of_children(bstptr B,int k,int &n)
{
	if (B==NULL)
	{
		return;
	}
	if (B->data==k)
	{
		if (B->lchild==NULL && B->rchild==NULL)
		{
			n=0;
		}
		else if (B->lchild==NULL || B->rchild==NULL)
		{
			n=1;
		}
		else n=2;
		return;
	}
	else{
	no_of_children(B->lchild,k,n);
	no_of_children(B->rchild,k,n);
    }
}
void delete_leaf_node(bstptr &B,int k)
{
	if (B==NULL)
	{
		return;
	}
	if (B->lchild!=NULL && B->lchild->data==k)
	{
		B->lchild=NULL;
	}
	else if (B->rchild!=NULL && B->rchild->data==k)
	{
		B->rchild=NULL;
	}
	else{
	delete_leaf_node(B->lchild,k);
	delete_leaf_node(B->rchild,k);
    }
}
void delete_child(bstptr &B,int k)
{
	if (B==NULL)
	{
		return;
	}
	if (B->lchild!=NULL && B->lchild->data ==k)
	{
		if (B->lchild->lchild==NULL)
		{
			B->lchild=B->lchild->rchild;
		}
		else
		{
			B->lchild=B->lchild->lchild;
		}
	}
	else if (B->rchild!=NULL && B->rchild->data ==k)
	{
		if (B->rchild->lchild==NULL)
		{
			B->rchild=B->rchild->rchild;
		}
		else
		{
			B->rchild=B->rchild->lchild;
		}
	}
	else{
	delete_child(B->lchild,k);
	delete_child(B->rchild,k);
    }
}
void find_max(bstptr B,int &max)
{
	if (B->rchild==NULL)
	{
		max=B->data;
		return;
	}
	find_max(B->rchild,max);
}
void delete_value(bstptr &B,int k)
{
	if (B==NULL)
	{
		return;
	}
	if (B->data==k)
	{
		int max;
		find_max(B->lchild,max);
        int n;
        no_of_children(B->lchild,max,n);
        if (n==0)
        {
   	       delete_leaf_node(B,max);
        }
        else if (n==1)
        {
   	       delete_child(B,max);
        }
        B->data=max;
	}
	else{
	delete_value(B->lchild,k);
	delete_value(B->rchild,k);
    }
}
void deletenode(bstptr &B,int k)
{
   int n;
   no_of_children(B,k,n);
   if (n==0)
   {
   	 delete_leaf_node(B,k);
   }
   else if (n==1)
   {
   	  delete_child(B,k);
   }
   else
   {
   	  delete_value(B,k);
   }
}
int main()
{
   bstptr B=NULL;
   int n;
   cin>>n;
   while(n>0)
   {
   	  insert(B,n);
   	  cin>>n;
   }
   inorder(B);
   cout<<endl;
   int k;
   cin>>k;
   deletenode(B,k);
   inorder(B);
}
//5 8 3 4 1 9 6 7 2 -1