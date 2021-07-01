#include <iostream>
#define m 3
using namespace std;
struct mstnode
{
  int cnt=0;
  int key[m-1];
  mstnode *cptr[m]={NULL};
};
typedef struct mstnode *mptr;
struct queue
{
  int size=25;
  int front=-1;
  int rear=-1;
  mptr elements[100];
};
void enqueue(struct queue &q,mptr x)
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
mptr dequeue(struct queue &q )
{   mptr t;
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
void insert(mptr &M,int n)
{
  if (M==NULL)
  {
    M=new(mstnode);
        M->key[0]=n;
        M->cnt++;
  }
  else if (M->cnt < m-1  && n > M->key[M->cnt-1])
  {
    M->key[M->cnt]=n;
    M->cnt++;
  }
  else if (M->cnt == m-1 && n > M->key[M->cnt-1])
  {
    insert(M->cptr[m-1],n);
  }
  else if (n < M->key[0])
  {
     insert(M->cptr[0],n);
  }
  else
  {
    for (int i = 0; i < M->cnt-1; i++)
    {
      if (n > M->key[i] && n <M->key[i+1])
      {
        insert(M->cptr[i+1],n);
        break;
      }
    }

  }
}
void levelorder(mptr M)
{
  queue q;
  enqueue(q,M);
  mptr t=NULL;
  enqueue(q,t);
  while(q.front!=q.rear)
  {
    mptr p=dequeue(q);
    if(p!=NULL)
    {
      for (int i = 0; i <= p->cnt; i++)
      {
          if (p->cptr[i]!=NULL)
          {
             enqueue(q,p->cptr[i]);
          }
          if (i<p->cnt)
          {
             cout<<p->key[i]<<" ";
          }
      }
    }
    if (p==NULL)
    {
      cout<<endl;
      enqueue(q,p);
    }
  }
}
void del(mptr M,int i)
{
  if (M->cptr[i+1]==NULL)
  {
     for (int i = 0; i < M->cnt-1; i++)
     {
        M->key[i]=M->key[i+1];
     }
     M->cnt--;
  }
  else
  {
    M->key[i]=M->cptr[i+1]->key[0];
    del(M->cptr[i+1],0);
  }
}
void delete_element(mptr M,int k)
{
  if (M==NULL)
  {
    return;
  }
  for (int i = 0; i <= M->cnt; i++)
  {
    delete_element(M->cptr[i]);
    if (i<M->cnt)
    {
      if (M->key[i]==k)
      {
        del(M,i);
      }
    }
  }
}
void inorder(mptr M)
{
  if (M==NULL)
  {
    return;
  }
  for (int i = 0; i <= M->cnt; i++)
  {
    inorder(M->cptr[i]);
    if (i<M->cnt)
    {
      cout<<M->key[i]<<" ";
    }
  }
}
int main()
{

  mptr M=NULL;
  int n;
  cin>>n;
  while(n>0)
  {
    insert(M,n);
    cin>>n;
  }
  inorder(M);
  cout<<endl;
    levelorder(M);
    delete_element(M,25);
    delete_element(M,54);
    levelorder(M);
}