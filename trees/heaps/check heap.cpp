#include <iostream>
using namespace std;
struct btnode
{
    btnode *lchild;
    int data;
    btnode *rchild;
};
typedef btnode *btptr;
struct queue
{
  int size=25;
  int front=-1;
  int rear=-1;
  btptr elements[100];
};
void enqueue(struct queue &q,btptr x)
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
btptr dequeue(struct queue &q )
{   btptr t;
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
void no_of_nodes(btptr B,int &n)
{
	if (B==NULL)
	{
		return;
	}
	n++;
	no_of_nodes(B->lchild,n);
	no_of_nodes(B->rchild,n);
}
int checkcompleteBT(btptr B)
{
     if (B==NULL)
    {
    	return 1;
    }
    queue q;
    enqueue(q,B);
    int flag=0;
    int x=0;
    while(q.front!=-1)
    {
    	btptr t;
    	t=dequeue(q);
    	if (t->lchild!=NULL)
    	{
    		if (x==1)
    		{
    			flag=1;
    		}
    		enqueue(q,t->lchild);
    	}
    	else x=1;
    	if (t->rchild!=NULL)
    	{
    		if (x==1)
    		{
    			flag=1;
    			break;
    		}
    		enqueue(q,t->rchild);
    	}
    	else x=1;
    }
    return flag;
}
void checkheap(btptr B,int &t)
{
	if (B->lchild==NULL && B->rchild==NULL)
	{
		return ;
	}
    if (B->rchild==NULL)
    {
    	if (B->data >B->lchild->data)
    	{
    		t=1;
    		return;
    	}
    }
    else
    {
    	if (B->data > B->lchild->data || B->data > B->rchild->data)
    	{
    		t=1;
    		return;
    	}
    }
    checkheap(B->lchild,t);
    checkheap(B->rchild,t);
}
int checkheapBT(btptr B)
{
   int k;
   k=checkcompleteBT(B);
   if (k==1)
   {
   	  return 1;
   }
   else
   {
      int t=0;
      checkheap(B,t);
      return t;
   }
}
int checkheaparray(int h[],int i)
{
	int x=0;
	int flag=0;
	while(1>0)
	{
        if ((2*x)+2<i)
        {
        	if ( h[x]>h[(2*x)+1] || h[x]>h[(2*x)+2] )
        	{
        		flag=1;
        		break;
        	}
        }
        else if ((2*x)+1 <i)
        {
        	if ( h[x] > h[(2*x)+1] )
        	{
        		flag=1;
        		break;
        	}
        }
        else
        {
        	break;
        }
        x++;
	}
	return flag;
}
int main()
{
	int h[100];
	int i=0;
	int n;
	cin>>n;
	while(n>0)
	{
		h[i]=n;
		i++;
		cin>>n;
	}
    int k=checkheaparray(h,i);
    if (k==0)
    {
    	cout<<"heap\n";
    }
    else
    {
    	cout<<"not a heap\n";
    }
    btptr B;
    B=NULL;
    cin>>k;
    insert(B,k);
    int t;
    t=checkheapBT(B);
    if (t==0)
    {
    	cout<<"heap\n";
    }
    else
    {
    	cout<<"not a heap\n";
    }
}