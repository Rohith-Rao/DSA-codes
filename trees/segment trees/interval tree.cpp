#include <iostream>
using namespace std;
struct node
{
	int low;
	int high;
	int max;
	node *lchild;
	node *rchild;
};
typedef struct node *bstptr;
void insert(bstptr &B,int l,int h,int max)
{
	if (B==NULL)
	{
		B=new(node);
        B->low=l;
        B->high=h;
        B->max=max;
        B->lchild=NULL;
        B->rchild=NULL;
	}
	else
	{
		if (l<B->low)
		{
		    insert(B->lchild,l,h,max);
		}
		else
		{
			insert(B->rchild,l,h,max);
		}
	}
}
void max_val(bstptr B,int &m)
{
	if (B==NULL)
	{
		return;
	}
	if (B->high > m)
	{
		m=B->high;
	}
	max_val(B->lchild,m);
	max_val(B->rchild,m);
}
void update(bstptr B)
{
   if (B==NULL)
   {
   	   return;
   }
   int m=B->high;
   max_val(B->lchild,m);
   max_val(B->rchild,m);
   B->max=m;
   update(B->lchild);
   update(B->rchild);
}
void interval(bstptr B,int sl,int sr)
{
	if (B==NULL)
	{
		return;
	}
	if (sl>=B->low && sr<=B->high)
	{
		cout<<B->low<<" "<<B->high<<endl;
	}
	interval(B->lchild,sl,sr);
	interval(B->rchild,sl,sr);
}
int main()
{
	bstptr B=NULL;
    int x=8;
    while(x--)
    {
    	int n;
    	cin>>n;
    	if (n==1)
    	{
    		int low;
    		int high;
    		int max;
    		cin>>low>>high>>max;
    		insert(B,low,high,max);
    		update(B);
    	}
    	else if (n==2)
    	{
    		int sl,sr;
    		cin>>sl>>sr;
            interval(B,sl,sr);
    	}
    }
}