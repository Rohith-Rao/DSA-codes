#include <iostream>
using namespace std;
struct kdnode
{
	int data[100];
	kdnode *lchild;
	kdnode *rchild;
};
typedef struct kdnode *kdptr;
void insert(kdptr &T,kdptr t,int d,int i)
{
	if (T==NULL)
	{
		T=t;
		return;
	}
    else
    {
    	if (t->data[i%d]<T->data[i%d])
    	{
    		insert(T->lchild,t,d,i+1);
    	}
    	else
    	{
    		insert(T->rchild,t,d,i+1);
    	}
    }
}
void preorder(kdptr T,int d)
{
	if (T==NULL)
	{
		return;
	}
	cout<<"( ";
    for (int i = 0; i < d; i++)
    {
    	cout<<T->data[i]<<" ";
    }
    cout<<")\n";
    preorder(T->lchild,d);
    preorder(T->rchild,d);
}
int main()
{
	int d;
	cin>>d;
    kdptr T;
    T=NULL;
    while(1>0)
    {
    	kdptr t;
    	t=new(kdnode);
    	t->lchild=NULL;
    	t->rchild=NULL;
    	for (int i = 0; i < d; i++)
    	{
    		cin>>t->data[i];
    	}
    	int flag=0;
    	for (int i = 0; i < d; i++)
    	{
    		if (t->data[i]==-1)
    		{
    			flag = 1;
    		}
    	}
    	if (flag==1)
    	{
    	   break;
    	}
    	else
    	{
    		insert(T,t,d,0);
    	}

    }
    preorder(T,d);
}
