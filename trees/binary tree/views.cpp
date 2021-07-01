#include <iostream>
#include <string>
using namespace std;
struct btnode
{
    btnode *lchild;
    int data;
    int num;
    btnode *rchild;
};
typedef btnode *btptr;
struct queue
{
  int size=25;
  int front=-1;
  int rear=-1;
  bstptr elements[100];
};
void enqueue(struct queue &q,btptr x)
{
    if ((q.rear+1)%q.size==q.front)
    {
      cout<<"full\n";
    }
    else
    {
      if (q.front==-1)
      {
        q.front=0;
        q.rear=0;
      }
      else
      {
        q.rear=(q.rear+1)%q.size;
      }
      q.elements[q.rear]=x;
    }
}
btptr dequeue(struct queue &q )
{   btptr t;
   if (q.front==-1)
   {
      cout<<"empty\n";
   }
   else
   {
       if (q.front==q.rear)
       {   t=q.elements[q.front];
          q.front=-1;
          q.rear=-1;
       }
       else
       {  t=q.elements[q.front];
          q.front=(q.front+1)%q.size;
       }
     return t;
   }
}
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

void leftviewlevel(btptr B,int i,int &x)
{
  if (B==NULL)
  {
    return;
  }
  if (i==1)
  {
      if(x==0){
    cout<<B->data<<" ";
    x++;
    }
  }
  else
  {
    leftviewlevel(B->lchild,i-1,x);
    leftviewlevel(B->rchild,i-1,x);
  }
}
void leftview(btptr B)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
      int x=0;
     leftviewlevel(B,i,x);
     cout<<endl;
  }
  cout<<endl;
}
void rightviewlevel(btptr B,int i,int &x)
{
  if (B==NULL)
  {
    return;
  }
  if (i==1)
  {
    x=B->data;
  }
  else
  {
    rightviewlevel(B->lchild,i-1,x);
    rightviewlevel(B->rchild,i-1,x);
  }
}
void rightview(btptr B)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
    int x=0;
     rightviewlevel(B,i,x);
     cout<<x<<endl;
  }
  cout<<endl;
}
void label(btptr B,int x)
{
   if (B==NULL)
   {
     return;
   }
   B->num=x;
   label(B->lchild,x-1);
   label(B->rchild,x+1);
}
void topview(btptr B)
{
   int x=0;
   label(B,x);
}
int main()
{
    btptr B;
    B=NULL;
    int k;
    cin>>k;
    insert(B,k);
    leftview(B);
    rightview(B);
    
}
