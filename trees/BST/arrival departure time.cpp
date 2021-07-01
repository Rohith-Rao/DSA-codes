#include <iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	int at;
	int dt;
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
void timer(bstptr B,int &i)
{
	if (B==NULL)
	{
		return;
	}
	B->at=i;
	i++;
	timer(B->lchild,i);
	timer(B->rchild,i);
	B->dt=i;
	i++;
}
void print_times(bstptr B)
{
	if (B==NULL)
	{
		return;
	}
	cout<<"( "<<B->at<<" "<<B->dt<<" )\n";
	print_times(B->lchild);
	print_times(B->rchild);
}
void preorder(bstptr B)
{
    if(B==NULL)
    {
        return;
    }
    cout<<B->data<<" ";
    preorder(B->lchild);
    preorder(B->rchild);
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
   preorder(B);
   cout<<endl;
   int i=0;
   timer(B,i);
   print_times(B);
}

// 5 3 7 2 4 6 9 8 1 -1