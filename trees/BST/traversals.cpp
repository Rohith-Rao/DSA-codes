#include <iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
typedef bstnode *bstptr;
struct queue
{
  int size=25;
  int front=-1;
  int rear=-1;
  bstptr elements[100];
};
void enqueue(struct queue &q,bstptr x)
{
    if ((q.rear+1)%q.size==q.front)
    {
      cout<<"full\n";
    }
    else
    {
      if (q.front==-1)
      {
        q.front=0;
        q.rear=0;
      }
      else
      {
        q.rear=(q.rear+1)%q.size;
      }
      q.elements[q.rear]=x;
    }
}
bstptr dequeue(struct queue &q )
{   bstptr t;
   if (q.front==-1)
   {
      cout<<"empty\n";
   }
   else
   {
       if (q.front==q.rear)
       {   t=q.elements[q.front];
          q.front=-1;
          q.rear=-1;
       }
       else
       {  t=q.elements[q.front];
          q.front=(q.front+1)%q.size;
       }
     return t;
   }
}
void insert(bstptr &t,int k)
{
	if (t==NULL)
	{
		t=new(bstnode);
        t->data=k;
        t->rchild=NULL;
        t->lchild=NULL;
	}
	else
	{
		if (k<t->data)
		{
			insert(t->lchild,k);
		}
		else
		{
			insert(t->rchild,k);
		}
	}
}
int height(bstptr p)
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
















void levelorder(bstptr B)
{
	if (B==NULL)
	{
		return;
	}
	queue q;
	enqueue(q,B);
	while(q.front!=-1)
	{
		bstptr t;
		t=dequeue(q);
		cout<<t->data<<" ";
		if(t->lchild!=NULL)
        {
            enqueue(q,t->lchild);
        }
		if(t->rchild!=NULL)
        {
            enqueue(q,t->rchild);
        }
	}
	cout<<endl;
}













void levelorderprintlevel(bstptr B,int i)
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
void leveordermethod2(bstptr B)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
     levelorderprintlevel(B,i);
  }
  cout<<endl;
}


















void reverselevelorderprintlevel(bstptr B,int i)
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
    reverselevelorderprintlevel(B->lchild,i-1);
    reverselevelorderprintlevel(B->rchild,i-1);
  }
}
void reverselevelorder(bstptr B)
{
  int h=height(B);
  for (int i = h; i >= 1; i--)
  {
     reverselevelorderprintlevel(B,i);
  }
  cout<<endl;
}




















void reversereversedlevelorderprint(bstptr B,int i)
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
    reversereversedlevelorderprint(B->rchild,i-1);
    reversereversedlevelorderprint(B->lchild,i-1);
  }
}
void reversereversedlevelorder(bstptr B)
{
  int h=height(B);
  for (int i = h; i >= 1; i--)
  {
    reversereversedlevelorderprint(B,i);
  }
  cout<<endl;
}















void squrielclockwise(bstptr B)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
     if (i%2==0)
     {
       reversereversedlevelorderprint(B,i);
     }
     else
     {
      reverselevelorderprintlevel(B,i);
     }
  }
  cout<<endl;
}














void squrielanticlockwise(bstptr B)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
    if (i%2==0)
    {
      reverselevelorderprintlevel(B,i);
    }
    else
    {
      reversereversedlevelorderprint(B,i);
    }
  }
  cout<<endl;
}







void alternateoddreverse(bstptr B)
{
     int h=height(B);
  for (int i = 1; i <= h; i++)
  {
     if (i%2==0)
     {
       reversereversedlevelorderprint(B,i);
     }
     else
     {
      reverselevelorderprintlevel(B,i);
     }
  }
  cout<<endl;
}





void alternateevenreverse(bstptr B)
{
  int h=height(B);
  for (int i = 1; i <= h; i++)
  {
    if (i%2==0)
    {
      reverselevelorderprintlevel(B,i);
    }
    else
    {
      reversereversedlevelorderprint(B,i);
    }
  }
  cout<<endl;
}





void inorder(bstptr t)
{
	if (t!=NULL)
	{
        inorder(t->lchild);
		cout<<t->data<<" ";
		inorder(t->rchild);
	}
  else
  {
    cout<<endl;
  }
}






int main()
{
	bstptr B;
	B=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		insert(B,n);
		cin>>n;
	}
  leveordermethod2(B);
  reversereversedlevelorder(B);
  reverselevelorder(B);
  squrielclockwise(B);
  squrielanticlockwise(B);
  alternateoddreverse(B);
  alternateevenreverse(B);

}
