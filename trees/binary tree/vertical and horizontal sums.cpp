#include <iostream>
#include <string>
using namespace std;
struct btnode
{
    btnode *lchild;
    int data;
    int lable;
    btnode *rchild;
};
typedef btnode *btptr;
void insert(btptr &B,int k)
{
    if (B==NULL)
    {
        B=new(btnode);
        B->data=k;
        B->lchild=NULL;
        B->rchild=NULL;
    }
    int c;
    cin>>c;
    if (c!=0)
        {
            insert(B->lchild,c);
        }
    cin>>c;
    if (c!=0)
    {
        insert(B->rchild,c);
    }
}
void labling(btptr B,int i)
{
  if (B==NULL)
  {
     return;
  }
  B->lable=i;
  labling(B->lchild,i-1);
  labling(B->rchild,i+1);
}
void preorder(btptr B,int i,int &s)
{
  if (B==NULL)
  {
     return;
  }
  if (B->lable==i)
  {
    s=s+B->data;
  }
  preorder(B->lchild,i,s);
  preorder(B->rchild,i,s);
}
int height(btptr p)
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
void levelorderprintlevel(btptr B,int i,int &s)
{
  if (B==NULL)
  {
    return;
  }
  if (i==1)
  {
    s=s+B->data;
  }
  else
  {
    levelorderprintlevel(B->lchild,i-1,s);
    levelorderprintlevel(B->rchild,i-1,s);
  }
}
void horizontal_sum(btptr B,int hs[],int &hindex)
{
    int h=height(B);
  for (int i = 1; i <= h; i++)
  {
    int s=0;
     levelorderprintlevel(B,i,s);
     hs[hindex]=s;
     hindex++;
  }
}
void minmax_lables(btptr t,int &mi,int &ma,int &x)
{
    if(t!=NULL)
    {
      if (x==0)
      {
        if (t->lchild!=NULL)
        {
          minmax_lables(t->lchild,mi,ma,x);
        }
        else
        {
          mi=t->lable;
          x=1;
        }
      }
        if (x==1)
        {
            if(t->rchild!=NULL) minmax_lables(t->rchild,mi,ma,x);
            else ma=t->lable;
        }
    }
}
void vertical_sum(btptr B,int min_lable,int max_lable,int vs[],int &vindex)
{
    for (int i = min_lable; i <= max_lable; i++)
    {
        int s=0;
        preorder(B,i,s);
        vs[vindex]=s;
        vindex++;
    }
}
int main()
{
    btptr B;
    B=NULL;
    int k;
    cin>>k;
    insert(B,k);
    int hs[10];
    int hindex=0;
    horizontal_sum(B,hs,hindex);
    for (int i = 0; i < hindex; i++)
    {
       cout<<hs[i]<<endl;
    }
    int i=0;
    labling(B,i);
    int x=0;
    int min_lable,max_lable;
    minmax_lables(B,min_lable,max_lable,x);
    int vs[10];
    int vindex=0;
    vertical_sum(B,min_lable,max_lable,vs,vindex);
    for (int i = 0; i < vindex; i++)
    {
       cout<<vs[i]<<" ";
    }
    cout<<endl;
}

  
// 5 2 7 0 0 4 9 0 0 6 0 0 8 3 0 15 0 0 1 0 12 0 0