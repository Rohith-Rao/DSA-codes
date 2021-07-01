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
void path(btptr B,int &i)
{
    if (B==NULL)
    {
        return;
    }
    else if (i%2==0)
    {
        cout<<B->data<<" ";
        i++;
        path(B->lchild,i);
    }
    else
    {
        cout<<B->data<<" ";
        i++;
        path(B->rchild,i);
    }
}
void maximumbends(btptr B)
{
    int i=0;
   path(B,i);
   i=1;
   cout<<endl;
   path(B,i);

}
int main()
{
    btptr B;
    B=NULL;
    int k;
    cin>>k;
    insert(B,k);
    maximumbends(B);
}

