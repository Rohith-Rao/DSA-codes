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
void preorder_store(bstptr B,int a[],int &i1)
{
	if (B==NULL)
	{
		return;
	}
	a[i1]=B->data;
	i1++;
	preorder_store(B->lc,a,i1);
	preorder_store(B->rc,a,i1);
}
void preorder(bstptr B)
{
	if (B==NULL)
	{
		return;
	}
	cout<<B->data<<" ";
	preorder(B->lc);
	preorder(B->rc);
}
void right_rotation(bstptr &BT)
{
    bstptr l = BT->lc;
    BT->lc = l->rc;
    l->rc = BT;
    BT = l;
}
void Rrotate(bstptr &BT, int a)
{
    if(BT->data == a){
        right_rotation(BT);
        return;
    }
    if(a<BT->data)
        Rrotate(BT->lc, a);
    else
        Rrotate(BT->rc, a);
}
void left_rotation(bstptr &BT)
{
    bstptr r = BT->rc;
    BT->rc = r->lc;
    r->lc = BT;
    BT = r;
}
void lrotate(bstptr &BT, int a)
{
    if(BT->data == a){
        left_rotation(BT);
        return;
    }
    if(a<BT->data)
        lrotate(BT->lc, a);
    else
        lrotate(BT->rc, a);
}
void bring(bstptr &B,bstptr &p, int a1[],int n,int flag)
{
	if (B->data==n)
	{
		if (flag==0)
		{
		    right_rotation(p);
		}
		else
		{
			left_rotation(p);
		}
		return;
	}
	if (n< B->data)
	{
		bring(B->lc,B,a1,n,0);
	}
	else
	{
		bring(B->rc,B,a1,n,1);
	}
}
int main()
{
	bstptr B1=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		insert(B1,n);
		cin>>n;
	}
	bstptr B2=NULL;
	cin>>n;
	while(n>0)
	{
		insert(B2,n);
		cin>>n;
	}
	int a2[20];
	int i2=0;
	preorder_store(B2,a2,i2);
	int a1[20];
	int i1=0;
	preorder_store(B1,a1,i1);
	for (int i = 0; i < i2; i++)
	{
		if (a1[i]!=a2[i])
		{
			bstptr p=NULL;
			while(a1[i]!=a2[i])
			{
				bring(B1,p,a1,a2[i],0);
				i1=0;
				preorder_store(B1,a1,i1);
			}
		}
	}
	preorder(B1);
}
