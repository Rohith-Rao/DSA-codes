#include <iostream>
using namespace std;
struct bstnode
{
	int data;
	bstnode *lc;
	bstnode *rc;
};
typedef bstnode *bstptr;
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
void insert(bstptr &B,int k)
{
	if (B==NULL)
	{
		B=new(bstnode);
		B->data=k;
		B->lc=NULL;
		B->rc=NULL;
		return;
	}
	if (k<B->data)
	{
		insert(B->lc,k);
	}
	else
	{
		insert(B->rc,k);
	}
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
int main()
{

   bstptr B=NULL;
   int n;
   cin>>n;
   while(n!=-2)
   {
   	  while(n>0)
   	  {
   	  	insert(B,n);
   	  	cin>>n;
   	  }
   	  cin>>n;
   	  while(n>0)
   	  {
   	  	Rrotate(B,n);
   	  	cin>>n;
   	  }
   	  cin>>n;
   }
   preorder(B);
}
//1 2 3 -1 1 0 4 5 -1 3 0 6 -1 2 0 7 -1 5 0 -2