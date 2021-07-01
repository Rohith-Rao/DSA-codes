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
struct ptrmax
{
  int max;
  mptr node;
};
struct queue
{
  int size=25;
  int front=-1;
  int rear=-1;
  ptrmax elements[100];
};
void enqueue(struct queue &q,mptr x,int max)
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
      q.elements[q.rear].node=x;
      q.elements[q.rear].max=max;
    }
}
ptrmax dequeue(struct queue &q )
{   ptrmax t;
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
void construct(mptr &M,int a[],int ind)
{
  int h=0;
    M=new(mstnode);
    for (int i = 0; i < m-1; i++)
    {
      M->key[i]=a[h];
      h++;
      M->cnt++;
    }
    queue q;
    enqueue(q,M,1000);
    while(h<ind)
    {
      ptrmax g=dequeue(q);
      mptr t=g.node;
      int max=g.max;
      for (int i = 0; i < m; i++)
      {
          if (i < m-1 && a[h] < t->key[i])
          {
            mptr p=new(mstnode);
            t->cptr[i]=p;
                for (int j = 0; j < m-1; j++)
                    {
                        if(h==ind)
                        {
                            break;
                        }
                      p->key[j]=a[h];
                      h++;
                      p->cnt++;
                    }
                enqueue(q,p,t->key[i]);
          }
          else if (i==m-1 && (a[h]>t->key[i-1] && a[h]<max) )
          {
            mptr p=new(mstnode);
            t->cptr[i]=p;
                for (int j = 0; j < m-1; j++)
                    {
                        if(h==ind)
                        {
                            break;
                        }
                      p->key[j]=a[h];
                      h++;
                      p->cnt++;
                    }
                enqueue(q,p,100);
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
void levelorder(mptr M)
{
  queue q;
  enqueue(q,M,0);
  mptr t=NULL;
  enqueue(q,t,0);
  while(q.front!=q.rear)
  {
    ptrmax r=dequeue(q);
    mptr p=r.node;
    if(p!=NULL)
    {
      for (int i = 0; i <= p->cnt; i++)
      {
          if (p->cptr[i]!=NULL)
          {
             enqueue(q,p->cptr[i],0);
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
      enqueue(q,p,0);
    }
  }
}
void del(mptr M,int i)
{
  if (M->cptr[i+1]==NULL)
  {
     for (int j = 0; j < M->cnt-1; j++)
     {
        M->key[j]=M->key[j+1];
     }
     for(int j=0;j<= M->cnt;j++)
     {
         M->cptr[j]=M->cptr[j+1];
     }
     M->cnt--;
     return;
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
    delete_element(M->cptr[i],k);
    if (i<M->cnt)
    {
      if (M->key[i]==k)
      {
        del(M,i);
        break;
      }
    }
  }
}
int main()
{
    int k;
    cin>>k;
  int a[50];
  int ind=0;
  int n;
  cin>>n;
  while(n>0)
  {
    a[ind]=n;
    ind++;
    cin>>n;
  }
    mptr M=NULL;
    construct(M,a,ind);
    levelorder(M);
    cout<<endl;
    cin>>k;
    delete_element(M,k);
    cin>>k;
    delete_element(M,k);
    levelorder(M);

}