#include <iostream>
#define d 3
using namespace std;
struct Bdnode
{
    int cnt=0;
    int key[d-1];
    Bdnode *ptr[d]={NULL};
    Bdnode *f=NULL;
    Bdnode *e=NULL;
};
typedef Bdnode *bptr;
struct ovnode
{
    int cnt=0;
    int key[d];
    Bdnode *ptr[d+1];
};
typedef ovnode *ovptr;
struct queue
{
  int size=25;
  int front=-1;
  int rear=-1;
  bptr elements[100];
};
void enqueue(struct queue &q,bptr x)
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
bptr dequeue(struct queue &q )
{   bptr t;
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
void search(bptr T,bptr &t,int k)
{
  if(T==NULL)
  {
    return;
  }
        for (int i = 0; i < T->cnt; i++)
        {
            if (k < T->key[i])
            {
                if (T->ptr[i]==NULL)
                {
                    t=T;
                    break;
                }
                search(T->ptr[i],t,k);
        break;
            }
            else if (i==T->cnt-1 && k>T->key[i])
            {
                if (T->ptr[i+1]==NULL)
                {
                    t=T;
                    break;
                }
                search(T->ptr[i+1],t,k);
                break;
            }
        }
}
void insert(bptr T,int k,bptr l,bptr r)
{
    int i;
    for ( i = 0; i < T->cnt; i++)
    {
        if (k<T->key[i])
        {
            break;
        }
    }
    if (i==T->cnt)
    {
        T->key[T->cnt]=k;
        T->cnt++;
        T->ptr[i+1]=r;
        T->ptr[i]=l;
    }
    else
    {
        for (int j = T->cnt; j >i ; j--)
        {
            T->key[j]=T->key[j-1];
        }
        T->key[i]=k;
        T->cnt++;
        for (int j = T->cnt; j >i+1; j--)
        {
            T->ptr[j]=T->ptr[j-1];
        }
        T->ptr[i+1]=r;
        T->ptr[i]=l;
    }

}
void parent(bptr &p,bptr T,bptr t,int k)
{
    if (T==t || T==NULL)
    {
        return;
    }
    else
    {
        for (int i = 0; i < T->cnt; i++)
        {
            if (k < T->key[i])
            {
                if (T->ptr[i]==t)
                {
                    p=T;
                    break;
                }
                parent(p,T->ptr[i],t,k);
                break;
            }
            else if (i==T->cnt-1 && k>T->key[i])
            {
                if (T->ptr[i+1]==t)
                {
                    p=T;
                    break;
                }
                parent(p,T->ptr[i+1],t,k);
                break;
            }
        }
    }
}
void copy(ovptr &ov,bptr t)
{
    ov=new(ovnode);
    for (int i = 0; i < t->cnt; i++)
    {
        ov->key[i]=t->key[i];
        ov->cnt++;
    }
    for (int i = 0; i <= t->cnt; i++)
    {
        ov->ptr[i]=t->ptr[i];
    }
}
void insert_ov(ovptr T,int k,bptr l,bptr r)
{
    int i;
    for ( i = 0; i < T->cnt; i++)
    {
        if (k<T->key[i])
        {
            break;
        }
    }
    if (i==T->cnt)
    {
        T->key[T->cnt]=k;
        T->cnt++;

    }
    else
    {
        for (int j = T->cnt; j >i ; j--)
        {
            T->key[j]=T->key[j-1];
        }
        T->key[i]=k;
        T->cnt++;
        for (int j = T->cnt; j >i+1; j--)
        {
            T->ptr[j]=T->ptr[j-1];
        }
        T->ptr[i+1]=r;
        T->ptr[i]=l;
    }

}
void copy_to(bptr &t,bptr &n,ovptr ov)
{
    n=new(Bdnode);
     int k=ov->cnt/2;
     t->cnt=0;
     for (int i = 0; i < k; i++)
     {
        t->key[i]=ov->key[i];
        t->cnt++;
     }
     for (int i = 0; i <= k; i++)
     {
        t->ptr[i]=ov->ptr[i];
     }
     for (int i = k+1; i < ov->cnt; i++)
     {
        n->key[i-k-1]=ov->key[i];
        n->cnt++;
     }
     for (int i = k+1; i <= ov->cnt; i++)
     {
        n->ptr[i-k-1]=ov->ptr[i];
     }
}
void inorder2(ovptr M)
{
    for(int i=0;i<M->cnt;i++)
    {
        cout<<M->key[i]<<" ";
    }
    cout<<endl;
}
void inorder(bptr M)
{
  if (M==NULL)
  {
    return;
  }
  for (int i = 0; i <= M->cnt; i++)
  {
    inorder(M->ptr[i]);
    if (i<M->cnt)
    {
      cout<<M->key[i]<<" ";
    }
  }
}
void print(bptr M)
{
    for(int i=0;i<M->cnt;i++)
    {
        cout<<M->key[i]<<" ";
    }
    cout<<endl;
}
void add(bptr &T,bptr &t,int k,bptr l,bptr r)
{
    if (T==NULL)
    {
        T=new(Bdnode);
        T->key[0]=k;
        T->cnt++;
    }
    else
    {   if(t==NULL)
         {search(T,t,k);}
        if (t->cnt < d-1)
        {
            insert(t,k,l,r);
        }
        else
        {
            bptr p=NULL;
            parent(p,T,t,k);
            ovptr ov=NULL;
            bptr n=NULL;
            copy(ov,t);
            insert_ov(ov,k,l,r);
            copy_to(t,n,ov);
            if(t->e==NULL && n->f==NULL)
            {
                t->e=n;
                n->f=t;
            }
            else
            {
                n->e=t->e;
                t->e->f=n;
                n->f=t;
                t->e=n;
            }
            int i=ov->cnt/2;
            if (p==NULL)
            {
                p=new(Bdnode);
                p->key[0]=ov->key[i];
                p->cnt++;
                p->ptr[0]=t;
                p->ptr[1]=n;
                T=p;

            }
            else
            {
                add(T,p,ov->key[i],t,n);
            }
        }
    }
}
void levelorder(bptr M)
{
  queue q;
  enqueue(q,M);
  bptr t=NULL;
  enqueue(q,t);
  while(q.front!=q.rear)
  {
    bptr p=dequeue(q);
    if(p!=NULL)
    {
      for (int i = 0; i <= p->cnt; i++)
      {
          if (p->ptr[i]!=NULL)
          {
             enqueue(q,p->ptr[i]);
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
void lr_leaf(bptr T)
{
    while(T->ptr[0]!=NULL)
    {
        T=T->ptr[0];
    }
    while(T!=NULL)
    {
        for(int i=0;i<T->cnt;i++)
        {
            cout<<T->key[i]<<" ";
        }
        T=T->e;
    }
    cout<<endl;
}
void rl_leaf(bptr T)
{
    while(T->ptr[T->cnt]!=NULL)
    {
        T=T->ptr[T->cnt];
    }
    while(T!=NULL)
    {
        for(int i=T->cnt-1;i>=0;i--)
        {
            cout<<T->key[i]<<" ";
        }
        T=T->f;
    }
    cout<<endl;
}
int main()
{
    bptr T=NULL;
    for (int i = 0; i < 18; i++)
    {
        int k;
        cin>>k;
        bptr t=NULL;
        bptr l=NULL;
        bptr r=NULL;
        add(T,t,k,l,r);
    }
    levelorder(T);
    cout<<endl;
    lr_leaf(T);
    rl_leaf(T);
}
