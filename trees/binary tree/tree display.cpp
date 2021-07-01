#include <iostream>
#include <string>
using namespace std;
struct btnode
{
	btnode *lchild;
	char data;
	int space;
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
    char  c;
    cin>>c;
    if (c!='#')
    	{
    		insert(B->lchild,c);
    	}
    cin>>c;
    if (c!='#')
    {
        insert(B->rchild,c);
    }
}
void inorder(btptr B,int &i)
{
	if (B==NULL)
	{
		return;
	}
	inorder(B->lchild,i);
	B->space=i;
	i++;
	inorder(B->rchild,i);
}
void levelorderprintlevel(btptr B,int i,int &x)
{
  if (B==NULL)
  {
    return;
  }
  if (i==1)
  {
  	for (int j = 1; j < B->space-x; j++)
  	{
  		cout<<" ";
  	}
  	x=B->space;
    cout<<B->data;
  }
  else
  {
    levelorderprintlevel(B->lchild,i-1,x);
    levelorderprintlevel(B->rchild,i-1,x);
  }
}
void levelorderprintlevel1(btptr B,int i,int &x,int &p)
{
  if (B==NULL)
  {
    return;
  }
  if (i==1)
  {
  	for (int j = 2; j < B->space-x-p; j++)
  	{
  		cout<<" ";
  	}
  	x=B->space;
    p++; 
  	char a='/';
    char b=char(92);
    if(B->lchild!=NULL && B->rchild!=NULL)
    {
        cout<<a<<" "<<b;
    }
    else if(B->lchild==NULL)
    {
        cout<<" "<<b;
    }
    else
    {
        cout<<a<<" ";
    }
  }
  else
  {
    levelorderprintlevel1(B->lchild,i-1,x,p);
    levelorderprintlevel1(B->rchild,i-1,x,p);
  }
}
int height(btptr p)
{
  if (p==NULL)
  {
    return 0;
  }
  int lheight=height(p->lchild);
  int rheight=height(p->rchild);
  if (lheight>rheight)
  {
    return lheight+1;
  }
  else
  {
    return rheight+1;
  }
}
void leveordermethod2(btptr B)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
  	int x=0;
     levelorderprintlevel(B,i,x);
     cout<<endl;
     x=0;
     int p=0;
     if(i!=h){
     levelorderprintlevel1(B,i,x,p);
     cout<<endl;}
  }
  cout<<endl;
}

int main()
{
	btptr B;
	B=NULL;
	char k;
	cin>>k;
	insert(B,k);
	int i=1;
	inorder(B,i);
	leveordermethod2(B);
}
