#include <iostream>
#define d 3
using namespace std;
struct Bdnode
{
  int cnt=0;
  int key[d-1];
  Bdnode *ptr[d]={NULL};
};
typedef Bdnode *bptr;
struct ovnode
{
  int cnt=0;
  int key[d];
  Bdnode *ptr[d+1]={NULL};
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
void parent(bptr &p,bptr T,bptr t,int k,int &ind)
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
          ind=i+1;
          break;
        }
        parent(p,T->ptr[i],t,k,ind);
                break;
      }
      else if (i==T->cnt-1 && k>T->key[i])
      {
        if (T->ptr[i+1]==t)
        {
          p=T;
          ind=i+1;
          break;
        }
        parent(p,T->ptr[i+1],t,k,ind);
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
void copy_back(ovptr v,bptr &t)
{
  t->cnt=0;
    for (int i = 1; i < v->cnt; i++)
    {
      t->key[i-1]=v->key[i];
      t->cnt++;
    }
}
void distribute_left(bptr p,int ind,int ind1,int k,bptr l,bptr r)
{
    for (int i = ind;  i>ind1 ; i--)
    {
      int t;
      if (k < p->ptr[i]->key[0])
      {
        t=p->key[i-1];
        p->key[i-1]=k;
      }
      else
      {
        ovptr v=NULL;
        copy(v,p->ptr[i]);
        insert_ov(v,k,l,r);
        t=p->key[i-1];
        p->key[i-1]=v->key[0];
        copy_back(v,p->ptr[i]);
      }
      k=t;
    }
    p->ptr[ind1]->key[p->ptr[ind1]->cnt]=k;
    p->ptr[ind1]->cnt++;
    p->ptr[ind1]->ptr[p->ptr[ind1]->cnt]=NULL;

}
void copy_back2(ovptr v,bptr t)
{
  t->cnt=0;
  for (int i = 0; i < v->cnt-1; i++)
  {
    t->key[i]=v->key[i];
    t->cnt++;
  }
}
void distribute_right(bptr p,int ind,int ind1,int k,bptr l,bptr r)
{
    
  for (int i = ind; i < ind1; i++)
  {
    int t;
    if (p->ptr[i]->key[p->ptr[i]->cnt-1] < k)
    {
      t=p->key[i];
      p->key[i]=k;
    }
    else
    {
      ovptr v;
      copy(v,p->ptr[i]);
      insert_ov(v,k,l,r);
      t=p->key[i];
      p->key[i]=v->key[v->cnt-1];
      copy_back2(v,p->ptr[i]);
    }
    k=t;
  }
  insert(p->ptr[ind1],k,l,r);
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
          int ind;
          parent(p,T,t,k,ind);
          int flag1=0;
          if (p!=NULL)
          {
            int flag=0;
            int ind1=ind-1;
             while(ind1>=0)
             {
                   if (p->ptr[ind1]->cnt < d-1)
                   {
                      flag=1;
                      flag1=1;
                      distribute_left(p,ind,ind1,k,l,r);
                      break;
                   }
                   ind1--;
             }
             if (flag==0)
              {
                  ind--;
                ind1=ind+1;
                while(ind1<=p->cnt)
                {
                  if (p->ptr[ind1]->cnt < d-1)
                  {
                    flag1=1;
                    distribute_right(p,ind,ind1,k,l,r);
                    break;
                  }
                  ind1++;
                }
              }
          }
          if(flag1==0)
          {
          ovptr ov=NULL;
          bptr n=NULL;
          copy(ov,t);
          insert_ov(ov,k,l,r);
          copy_to(t,n,ov);
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
int main()
{
  bptr T=NULL;
    while(1>0)
    {
      int k;
      cin>>k;
      if(k<=0)
        {
            break;
        }
      bptr t=NULL;
        bptr l=NULL;
        bptr r=NULL;
        add(T,t,k,l,r);

    }
    levelorder(T);
}
