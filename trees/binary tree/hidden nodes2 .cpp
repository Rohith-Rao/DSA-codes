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
void levelorderprintlevel(char a[],btptr B,int i,int &m)
{
  if (B==NULL)
  {
    return;
  }
  if (i==1)
  {
    a[m]=B->data;
    m++;
  }
  else
  {
    levelorderprintlevel(a,B->lchild,i-1,m);
    levelorderprintlevel(a,B->rchild,i-1,m);
  }
}
void leveorder(char a[],btptr B,int &m)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
     levelorderprintlevel(a,B,i,m);
     cout<<endl;
  }
  cout<<endl;
}
void printleft(btptr B,char b[],int &p)
{
    if (B->lchild!=NULL)
    {
        b[p]=B->data;
        p++;
        printleft(B->lchild,b,p);
    }
}
void right(btptr B,char b[],int &p)
{
    if (B!=NULL)
    {
        right(B->rchild,b,p);
        b[p]=B->data;
        p++;
    }
}
void lastlevel(btptr B,char b[],int &p)
{
    if (B==NULL)
    {
        return;
    }
    else if (B->lchild==NULL && B->rchild==NULL)
    {
        b[p]=B->data;
        p++;
    }
    lastlevel(B->lchild,b,p);
    lastlevel(B->rchild,b,p);
}
void boundaries(btptr B,char b[],int &p)
{
    printleft(B,b,p);
    lastlevel(B,b,p);
    right(B,b,p);
}
int main()
{
	btptr B;
	B=NULL;
	char k;
	cin>>k;
	insert(B,k);
	char a[100];
	int m=0;
	leveorder(a,B,m);
    char b[100];
    int p=0;
    boundaries(B,b,p);
    for (int i=0; i<m;i++)
    {
    	int flag=0;
    	for(int j=0;j<p;j++)
    	{
    		if(a[i]==b[j])
    		{
    			flag=1;
    		}

    	}
    	if(flag==0)
    	{
    		cout<<a[i]<<" ";
    	}
    }
}
