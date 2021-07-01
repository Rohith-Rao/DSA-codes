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
void inorder(btptr t,int a[],int &index)
{
    if (t!=NULL)
    {
        inorder(t->lchild);
        a[index]=t->data;
        index++;
        inorder(t->rchild);
    }
}
void findmxbst(int a[],int size)
{
    int b[20];
    int i=0;
    
}
int main()
{
     btptr B;
    B=NULL;
    int k;
    cin>>k;
    insert(B,k);
    int a[100];
    int index=0;
    inorder(B,a,index);
    int size=index;
    findmxbst(a,size);
}