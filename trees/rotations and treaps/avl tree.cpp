#include <iostream>
#include <cstdlib>
using namespace std;
struct bstnode
{
	int data;
	bstnode *lc;
	bstnode *rc;
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
int height(bstptr B)
{
	if (B==NULL)
	{
		return -1;
	}
	int h1=height(B->lc);
	int h2=height(B->rc);
	if (h1>h2)
	{
		return h1+1;
	}
	else
	{
	   return h2+1;
	}
}
void preorder(bstptr B)
{
	if (B==NULL)
	{
		return;
	}
	cout<<B->data<<" ";
	preorder(B->lc);
	preorder(B->rc);
}
void right_rotation(bstptr &BT)
{
    bstptr l = BT->lc;
    BT->lc = l->rc;
    l->rc = BT;
    BT = l;
}
void left_rotation(bstptr &BT)
{
    bstptr r = BT->rc;
    BT->rc = r->lc;
    r->lc = BT;
    BT = r;
}
void levelorder(bstptr B)
{
	if (B==NULL)
	{
		return;
	}
	queue q;
	enqueue(q,B);
	bstptr t=NULL;
	enqueue(q,t);
	while(q.front!=q.rear)
	{
		bstptr t;
		t=dequeue(q);
		if(t==NULL)
        {
            cout<<endl;
            enqueue(q,t);
        }
        else {
		cout<<t->data<<" ";
		if(t->lc!=NULL)
        {
            enqueue(q,t->lc);
        }
		if(t->rc!=NULL)
        {
            enqueue(q,t->rc);
        }
        }
	}
	cout<<endl;
}
void insert(bstptr &B,bstptr &k2,int n,int flag)
{
	if (B==NULL)
	{
		B=new(bstnode);
		B->data=n;
		B->lc=NULL;
		B->rc=NULL;
		return;
	}
	else
	{
		if (n<B->data)
		{
			flag=0;
			insert(B->lc,k2,n,flag);
		}
		else
		{
			flag=1;
			insert(B->rc,k2,n,flag);
		}
	}
	int h1=height(B->lc);
	int h2=height(B->rc);
        bstptr k1;
		if(flag==0)
        {
            k1=B->lc;
        }
        else
        {
            k1=B->rc;
        }
	if (abs(h1-h2)>1)
	{
		if (flag==0)
		{
			if (k2==NULL)
			{
				right_rotation(B);
			}
			else
			{
				if (k2==k1->lc)
				{
					right_rotation(B);
				}
				else
				{
					left_rotation(k1);
					right_rotation(B);
				}
			}
		}
		else
		{
			if (k2==NULL)
			{
				left_rotation(B);
			}
			else
			{
				if (k2==k1->rc)
				{
					left_rotation(B);
				}
				else
				{
					right_rotation(k1);
					left_rotation(B);
				}
			}
		}
	}
	k2=k1;
}
int main()
{
	bstptr B=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		bstptr k2=NULL;
		int flag;
		insert(B,k2,n,flag);
		cin>>n;

	}
	levelorder(B);
	preorder(B);
}
