#include <iostream>
#define m 4
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
mptr top(struct queue &q )
{   mptr t;
   if (q.front==-1)
   {
      cout<<"empty\n";
   }
   else
   {
       if (q.front==q.rear)
       {   t=q.elements[q.front];

       }
       else
       {  t=q.elements[q.front];

       }
     return t;
   }
}
void left_view(mptr M)
{
  queue q;
  enqueue(q,M);
  mptr t=NULL;
  enqueue(q,t);
  mptr prev=NULL;
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
          if (i<p->cnt && i==0)
          {
            mptr g=top(q);
            if(prev==NULL)
             {cout<<p->key[i]<<" ";}
          }
      }
    }
    if (p==NULL)
    {
      cout<<endl;
      enqueue(q,p);
    }
    prev=p;
  }
}
void right_view(mptr M)
{
  queue q;
  enqueue(q,M);
  mptr t=NULL;
  enqueue(q,t);
   mptr aft;
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
          if (i==p->cnt-1)
          {
            aft=top(q);
            if(aft==NULL)
             {cout<<p->key[i]<<" ";}
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
  else if (n < M->key[0] && M->cnt==m-1)
  {
     insert(M->cptr[0],n);
  }
  else if(M->cnt==m-1)
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
  else
  {
    if (n<M->key[0])
    {
      for (int i = M->cnt; i >0 ; i--)
      {
        M->key[i]=M->key[i-1];
      }
      M->key[0]=n;
      M->cnt++;
    }
    else
    {
      int i;
      for (i = 0; i < M->cnt-1; i++)
        {
          if (n > M->key[i] && n <M->key[i+1])
          {
            break;
          }
        }
        for (int j = M->cnt; j > i+1; j--)
        {
          M->key[j]=M->key[j-1];
        }
        M->key[i+1]=n;
        M->cnt++;
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
int height(mptr M)
{
  if (M==NULL)
  {
    return 0;
  }
  int h[M->cnt+1];
  for (int i = 0; i <= M->cnt; i++)
  {
     h[i]=height(M->cptr[i]);
  }
  int max=-1;
  for (int i = 0; i < M->cnt+1; i++)
  {
     if (h[i]>max)
     {
       max=h[i];
     }
  }
  return max+1;
}
void level_print(mptr M,int l)
{
  if (M==NULL)
  {
    return;
  }
  if (l==1)
  {
     for (int i = 0; i < M->cnt; i++)
     {
        cout<<M->key[i]<<" ";
     }
  }
  else if(l>1)
  {
    for (int i = 0; i <= M->cnt; i++)
    {
       level_print(M->cptr[i],l-1);
    }
  }
}
void level_print_reverse(mptr M,int l)
{
  if (M==NULL)
  {
    return;
  }
  if (l==1)
  {
     for (int i = M->cnt-1; i >=0; i--)
     {
        cout<<M->key[i]<<" ";
     }
  }
  else if(l>1)
  {
    for (int i = M->cnt; i >=0; i--)
    {
       level_print_reverse(M->cptr[i],l-1);
    }
  }
}
void level(mptr M)
{
  int h=height(M);
  int x=0;
   for (int i = h; i>=1; i--)
   {
       if (x==0)
       {
         level_print(M,i);
         x=1;
       }
       else if (x==1)
       {
         level_print_reverse(M,i);
         x=0;
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
  level(M);
}
