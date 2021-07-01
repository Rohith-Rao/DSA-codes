#include <iostream>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
typedef bstnode *bstptr;
void inorder(bstptr t)
{
	if (t!=NULL)
	{
		cout<<t->data<<" ";
		inorder(t->lchild);
		inorder(t->rchild);
	}
}
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
void consruct(bstptr &B,int a[],int k)
{
	B=new(bstnode);
	B->data=a[0];
	B->lchild=NULL;
	B->rchild=NULL;
	queue q;
	int h=1;
	enqueue(q,B);
	while(h<k)
	{
        bstptr t;
        t=dequeue(q);
        bstptr p;
        p=new(bstnode);
        p->data=a[h];
        h++;
        p->lchild=NULL;
        p->rchild=NULL;
        t->lchild=p;
        bstptr y;
        y=new(bstnode);
        y->data=a[h];
        h++;
        y->lchild=NULL;
        y->rchild=NULL;
        t->rchild=y;
        enqueue(q,p);
        enqueue(q,y);
	}
}
int main()
{
	bstptr B=NULL;
	int a[20];
	int k=0;
	int n;
	cin>>n;
	while (n>0)
	{
		a[k]=n;
		k++;
		cin>>n;
	}
	consruct(B,a,k);
	inorder(B);

}
