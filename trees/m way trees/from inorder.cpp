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
void insert1(mptr &M,int n)
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
    insert1(M->cptr[m-1],n);
  }
  else if (n < M->key[0])
  {
     insert1(M->cptr[0],n);
  }
  else
  {
    for (int i = 0; i < M->cnt-1; i++)
    {
      if (n > M->key[i] && n <M->key[i+1])
      {
        insert1(M->cptr[i+1],n);
        break;
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
void search(mptr T,mptr &t,int k)
{


    for (int i = 0; i < T->cnt; i++)
    {
      if (k < T->key[i])
      {
        if (T->cptr[i]==NULL)
        {
          t=T;
           cout<<T->key[i]<<" ";
          break;
        }
        cout<<T->key[i]<<" ";
        search(T->cptr[i],t,k);
        break;
      }
      else if (i==T->cnt-1 && k>T->key[i])
      {
        if (T->cptr[i+1]==NULL)
        {
          t=T;
           cout<<T->key[i]<<" ";
          break;
        }
        cout<<T->key[i]<<" ";
        search(T->cptr[i+1],t,k);
      }
    }
}
void parent(mptr &p,mptr T,mptr t,int k)
{
  /*if (T==t || T==NULL)
  {
    return;
  }
  else*/
  {
        for (int i = 0; i < T->cnt; i++)
    {
      if (k < T->key[i])
      {
        if (T->cptr[i]==t)
        {
          p=T;
          cout<<T->key[i]<<" ";
          break;
        }
        cout<<T->key[i]<<" ";
        parent(p,T->cptr[i],t,k);
        break;
      }
      else if (i==T->cnt-1 && k>T->key[i])
      {
        if (T->cptr[i+1]==t)
        {
          p=T;
          cout<<T->key[i]<<" ";
          break;
        }
        cout<<T->key[i]<<" ";
        parent(p,T->cptr[i+1],t,k);
        break;
      }
    }
  }
}
void insert(mptr T,int k,mptr l,mptr r)
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
      T->cptr[j]=T->cptr[j-1];
    }
    T->cptr[i+1]=r;
    T->cptr[i]=l;
  }

}
int main()
{

  mptr M=NULL;
  int n;
  cin>>n;
  while(n>0)
  {
    insert1(M,n);
    cin>>n;
  }
  inorder(M);
  cout<<endl;
  mptr t,l=NULL,r=NULL;
  search(M,t,4);
  cout<<endl<<t->key[0]<<endl;
  mptr p;
  parent(p,M,t,4);
  cout<<endl<<p->key[0]<<endl;
  //insert(t,4,l,r);
  inorder(M);
}

// 10 18 6 8 11 13 21 3 7 9 12 16 17 -1
