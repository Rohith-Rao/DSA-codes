#include <iostream>
using namespace std;
struct node
{
    int data;
    node *lc=NULL;
    node *rc=NULL;
};
typedef node *bptr;
bptr parent(bptr B,bptr q)
{
    if (B!=NULL)
    {
        if (B->lc==q || B->rc==q)
        {
            return B;
        }
        return parent(B->lc,q);
        return parent(B->lc,q);
    }
}
void insert(bptr &B,bptr t,int n,bptr l,bptr r)
{
   if (B==NULL)
   {
       B=new(node);
       B->data=n;
       return;
   }
   else
   {
    if (t==NULL)
    {
     bptr q=B;
     while(q->rc!=NULL)
     {
        q=q->rc;
     }
    }
    bptr p;
    p=parent(B,q);
   }

}
int main()
{
    bptr B=NULL;
    while(1>0)
    {
        int n;
        bptr t=NULL;
        if (n==-100)
        {
            break;
        }
        bptr l=NULL,r=NULL;
        insert(B,t,n,l,r);
    }
}


void print2(bptr t,bptr root)
{
  if (t==NULL)
  {
    return;
  }
  if(t->lc&&t->lc->data==root->data)
  {
    print2(t->lc,root);
  }
  else
  {
    print2(t->rc,root);
  }
}