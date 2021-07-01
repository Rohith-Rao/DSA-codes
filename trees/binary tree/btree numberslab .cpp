#include <iostream>
#include <string>
using namespace std;
struct btnode
{
    btnode *lchild;
    int data;
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
void levelorderprintlevel(btptr B,int i,int a[],int &index,int &max,int &min)
{
  if (B==NULL)
  {
    return;
  }
  if (i==1)
  {
    a[index]=B->data;
    index++;
    if (B->data >max)
    {
        max=B->data;
    }
    else if(B->data < min)
    {
       min=B->data;
    }
  }
  else
  {
    levelorderprintlevel(B->lchild,i-1,a,index,max,min);
    levelorderprintlevel(B->rchild,i-1,a,index,max,min);
  }
}
void leveordermethod2(btptr B)
{
  int h=height(B);
  int a[50];
  int index=0;
  int min=1000,max=-5;
  for (int i = 1; i <= h; i++)
  {
     levelorderprintlevel(B,i,a,index,max,min);
     a[index]=-1;
     index++;
  }
  cout<<endl<<max<<endl;
  cout<<min<<endl;
int  i=1;
  int k=0;
  while(i<=h)
  {
     int flag=0;
    while(a[k]!=-1)
    {
        if (a[k+1]!=-1)
        {
           if (a[k+1]<a[k])
           {
               flag=1;
           }

        }
        k++;
    }
    k++;
    if (flag==0 && i>1)
    {
        cout<<(i-1)<<endl;
    }
    i++;

  }
  i=1;
  k=0;
  while(i<h)
  {
     int flag=0;
    while(a[k]!=-1)
    {
        if (a[k+1]!=-1)
        {
           if (a[k+1]>a[k])
           {
               flag=1;
           }

        }
        k++;
    }
    k++;
    if (flag==0 && i>1)
    {
        cout<<(i-1)<<endl;
    }
    i++;


  }
  i=1;
  k=0;
  while(i<h)
  {
     int flag=0;
    while(a[k]!=-1)
    {
        if (a[k+1]!=-1)
        {
            if (k==0 || a[k-1]==-1)
            {
                k++;
                continue;
            }
           else if (a[k+1]<a[k] && a[k]<a[k-1] )
           {
               flag=1;
           }

        }
        k++;
    }
    k++;
    if (flag==0 && i>1)
    {
        cout<<(i+1)<<endl;
    }
    i++;

  }
  cout<<endl;
}
int main()
{
    btptr B;
    B=NULL;
    int k;
    cin>>k;
    insert(B,k);
    leveordermethod2(B);
}
