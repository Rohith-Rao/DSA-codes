#include <iostream>
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
void find(btptr B,int a,int b,int c,int &p)
{
    if (B==NULL)
    {
        return;
    }
    if (B->data==a || B->data==b || B->data==c)
    {
        p++;
    }
    find(B->lchild,a,b,c,p);
    find(B->rchild,a,b,c,p);
}
int lca(btptr B,int a,int b,int c)
{
    int p=0;
    find(B->lchild,a,b,c,p);
    if (p==3)
    {
        lca(B->lchild,a,b,c);
    }
    else if (p==0)
    {
        lca(B->rchild,a,b,c);
    }
    else
    {
        return B->data;
    }
}
int main()
{
    btptr B=NULL;
    int n;
    cin>>n;
    insert(B,n);
    int a,b,c;
    cin>>a>>b>>c;
    int k;
    k=lca(B,a,b,c);
    cout<<k;
}
