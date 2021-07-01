#include <iostream>
#define m 5
using namespace std;
struct mstnode
{
  int cnt=0;
  int key[m-1];
  mstnode *cptr[m]={NULL};
};
typedef struct mstnode *mptr;
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
}