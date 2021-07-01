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
void levelorderprintlevel(btptr B,int i)
{
  if (B==NULL)
  {
    return;
  }
  if (i==1)
  {
    cout<<B->data<<" ";
  }
  else
  {
    levelorderprintlevel(B->lchild,i-1);
    levelorderprintlevel(B->rchild,i-1);
  }
}
void leveorder(btptr B)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
     levelorderprintlevel(B,i);
     cout<<endl;
  }
  cout<<endl;
}
void constructlevel(btptr &B,string s,int &i,int level)
{
    if (s[i]=='$')
    {
        cout<<i<<endl;
    	return;
    }
    if (level==0)
    {
    	if (s[i]=='#')
    	{
    		B=NULL;
    		i++;
    	}
    	else
    	{
    	B=new(btnode);
    	B->data=s[i];
    	B->lchild=NULL;
    	B->rchild=NULL;
    	i++;
        }
    }
    else
    {
       constructlevel(B->lchild,s,i,level-1);
       constructlevel(B->rchild,s,i,level-1);
   }
}
void construct(btptr &B,string s)
{
	int level=0;
	int i=0;
	while (s[i]!='$')
	{
		constructlevel(B,s,i,level);
		level++;
	}
}
int main()
{
	btptr B;
	B=NULL;
	string s;
	cin>>s;
	construct(B,s);
    leveorder(B);
}
