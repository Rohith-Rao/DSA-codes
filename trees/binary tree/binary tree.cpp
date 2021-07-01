#include <iostream>
#include <string>
using namespace std;
struct btnode
{
	btnode *lchild;
	char data;
	btnode *rchild;
};
typedef btnode *btptr;
void insert(btptr &B,char k)
{
	if (B==NULL)
	{
	    B=new(btnode);
		B->data=k;
		B->lchild=NULL;
		B->rchild=NULL;
	}
    char c;
    cin>>c;
    if (c!='.')
    	{
    		insert(B->lchild,c);
    	}
    cin>>c;
    if (c!='.')
    {
        insert(B->rchild,c);
    }
}
void preorder(btptr B)
{
	if (B==NULL)
	{
		return;
	}
	cout<<B->data<<" ";
	preorder(B->lchild);
	preorder(B->rchild);
}
void inorder(btptr B)
{
	if (B==NULL)
	{
		return;
	}
	inorder(B->lchild);
	cout<<B->data<<" ";
	inorder(B->rchild);
}
void postorder(btptr B)
{
	if (B==NULL)
	{
		return;
	}
	postorder(B->lchild);
	postorder(B->rchild);
	cout<<B->data<<" ";
}
void serialsize(btptr B)
{
	if (B==NULL)
	{
		cout<<". ";
		return;
	}
	cout<<B->data<<" ";
	serialsize(B->lchild);
	serialsize(B->rchild);
}
void no_of_leafnodes(btptr B,int &c)
{
	if (B==NULL)
	{
		return;
	}
	if (B->lchild==NULL && B->rchild==NULL)
	{
		c++;
	}
	no_of_leafnodes(B->lchild,c);
	no_of_leafnodes(B->rchild,c);
}
void no_of_nonleafnodes(btptr B,int &c)
{
	if (B==NULL)
	{
		return;
	}
	if (B->lchild!=NULL || B->rchild!=NULL)
	{
		c++;
	}
	no_of_nonleafnodes(B->lchild,c);
	no_of_nonleafnodes(B->rchild,c);
}
void no_of_nodes(btptr B,int &c)
{
	if (B==NULL)
	{
		return;
	}
		c++;
	no_of_nodes(B->lchild,c);
	no_of_nodes(B->rchild,c);
}
int find(char k,string ldr,int l,int h)
{
    for (int i = l; i <= h; i++)
    {
    	if (ldr[i]==k)
    	{
    		return i;
    	}
    }
}
void construct(btptr &B,string dlr,string ldr,int &i,int l,int h)
{
    if(l>h)
    {
        return;
    }
	if (B==NULL)
	{
		B=new(btnode);
        B->data=dlr[i];
        B->lchild=NULL;
        B->rchild=NULL;
	}
    int j=find(dlr[i],ldr,l,h);
    i++;
    construct(B->lchild,dlr,ldr,i,l,j-1);
    construct(B->rchild,dlr,ldr,i,j+1,h);
}
int main()
{
	/*btptr B;
	B=NULL;
	char k;
	cin>>k;
	insert(B,k);
	preorder(B);
	serialsize(B);
	int c=0;
	no_of_leafnodes(B,c);
	cout<<c<<endl;
	c=0;
	no_of_nonleafnodes(B,c);
	cout<<c<<endl;
	c=0;
	no_of_nodes(B,c);
	cout<<c<<endl;*/
    string dlr,ldr;
    cin>>dlr>>ldr;
    int h=ldr.length();
    h=h-1;
    int l=0,i=0;
    btptr T=NULL;
    construct(T,dlr,ldr,i,l,h);
    preorder(T);
}
// A M B . . D F . . . J . R H . . K . .
AMBDFJRHK
BMFDAJHRK