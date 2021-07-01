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
void printleft(btptr B)
{
    if (B->lchild!=NULL)
    {
        cout<<B->data<<" ";
        printleft(B->lchild);
    }
}
void right(btptr B)
{
    if (B->rchild!=NULL)
    {
        right(B->rchild);
        cout<<B->data<<" ";
    }
}
void lastlevel(btptr B)
{
    if (B==NULL)
    {
        return;
    }
    else if (B->lchild==NULL && B->rchild==NULL)
    {
        cout<<B->data<<" ";
    }
    lastlevel(B->lchild);
    lastlevel(B->rchild);
}
void boundaries(btptr B)
{
    printleft(B);
    lastlevel(B);
    right(B);
}
int main()
{
    btptr B;
    B=NULL;
    int k;
    cin>>k;
    insert(B,k);
    boundaries(B);
}

