#include <iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
typedef bstnode *bstptr;
int find(int a[],int i,int l,int h)
{
    for(int k=h;k>=l;k--)
    {
        if(a[k]<a[i])
        {
            return k;
        }
    }
}
void construct(int a[],bstptr &B,int &i,int l,int h)
{
    if(l>h||i<0)
    {
        return;
    }
    if(B==NULL)
    {
        B=new(bstnode);
        B->data=a[i];
        B->lchild=NULL;
        B->rchild=NULL;
    }
    int j=find(a,i,l,h);
    i--;
    h=i;
    construct(a,B->rchild,i,j+1,h);
    construct(a,B->lchild,i,l,j);
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

void levelorderprintlevel(bstptr B,int i)
{
  if (B==NULL)
  {
    return;
  }
  if (i==1)
  {
    cout<<B->data<<" ";
  }
  else
  {
    levelorderprintlevel(B->lchild,i-1);
    levelorderprintlevel(B->rchild,i-1);
  }
}
void leveordermethod2(bstptr B)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
     levelorderprintlevel(B,i);
     cout<<endl;
  }
  cout<<endl;
}
int main()
{
    bstptr B;
    B=NULL;
    int a[100];
    int n;
    cin>>n;
    int h=0;
    while(n>-1)
    {
        a[h]=n;
        h++;
        cin>>n;
    }
    h=h-1;
    int i=h;
    int l=0;
    construct(a,B,i,l,h);
    leveordermethod2(B);
}
