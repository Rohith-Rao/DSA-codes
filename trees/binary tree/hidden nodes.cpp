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
void print(btptr p)
{
    if (p==NULL)
    {
        return;
    }
    if (p->lchild ==NULL && p->rchild==NULL)
    {
        return;
    }
    cout<<p->data<<" ";
    print(p->lchild);
    print(p->rchild);
}
void left(btptr B)
{
    if (B==NULL)
    {
        return;
    }
    print(B->rchild);
    left(B->lchild);
}
void right(btptr B)
{
    if (B==NULL)
    {
        return;
    }
    print(B->lchild);
    right(B->rchild);
}
void hiddennodes(btptr B)
{
    left(B->lchild);
    right(B->rchild);
}
int main()
{
    btptr B;
    B=NULL;
    int k;
    cin>>k;
    insert(B,k);
    hiddennodes(B);
}
