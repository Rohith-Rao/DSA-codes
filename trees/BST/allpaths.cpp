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
void allpaths(bstptr B,queue q,queue &k)
{
   if (B==NULL)
   {
   	  return;
   }
   enqueue(q,B);
   if(B->lchild==NULL && B->rchild==NULL)
   {
       bstptr t;
   	  while(q.front!=-1)
   	  {
   	  	t=dequeue(q);
   	  	enqueue(k,t);
   	  }
   	  enqueue(k,NULL);
   }
   else{
   allpaths(B->lchild,q,k);
   allpaths(B->rchild,q,k);
   }
}
void printallpaths(queue k)
{
	while(k.front!=-1)
	{
		while(1>0)
		{
			bstptr t;
			t=dequeue(k);
			if (t==NULL)
			{
				break;
			}
			else
			{
				cout<<t->data<<" ";
			}
		}
		cout<<endl;
	}
}
void leftmost(queue k)
{
  while(1>0)
  {
    bstptr t;
    t=dequeue(k);
    if (t==NULL)
    {
      break;
    }
    cout<<t->data<<" ";
  }
  cout<<endl;
}
void rightmost(bstptr B)
{
  if (B==NULL)
  {
    cout<<endl;
    return;
  }
  cout<<B->data<<" ";
  rightmost(B->rchild);
}
void maximumsumpath(queue k)
{
  int max=-1;
  int n;
  int i=0;
  while(i<4)
  {
    int s=0;
    i++;
    while(1>0)
    {
      bstptr t;
      t=dequeue(k);
      if (t==NULL)
      {
          enqueue(k,t);
        break;
      }
      else
      {
        s=s+t->data;
      }
      enqueue(k,t);
    }
    if (s>max)
    {
       max=s;
       n=i;
    }
  }
  i=0;
  while(k.front!=-1)
  {
     i++;
     while(1>0)
     {
       bstptr t;
       t=dequeue(k);
       if (t==NULL)
       {
         break;
       }
       else
       {
          if (i==n)
          {
            cout<<t->data<<" ";
          }
       }
     }
  }
  cout<<endl;

}
void minimumsumpath(queue k)
{
  int min=1000;
  int n;
  int i=0;
  while(i<4)
  {
    int s=0;
    i++;
    while(1>0)
    {
      bstptr t;
      t=dequeue(k);
      if (t==NULL)
      {
          enqueue(k,t);
        break;
      }
      else
      {
        s=s+t->data;
      }
      enqueue(k,t);
    }
    if (s<min)
    {
       min=s;
       n=i;
    }
  }
  i=0;
  while(k.front!=-1)
  {
     i++;
     while(1>0)
     {
       bstptr t;
       t=dequeue(k);
       if (t==NULL)
       {
         break;
       }
       else
       {
          if (i==n)
          {
            cout<<t->data<<" ";
          }
       }
     }
  }
  cout<<endl;

}
void sum22path(queue k)
{
  int n;
  int i=0;
  while(i<4)
  {
    int s=0;
    i++;
    while(1>0)
    {
      bstptr t;
      t=dequeue(k);
      if (t==NULL)
      {
          enqueue(k,t);
        break;
      }
      else
      {
        s=s+t->data;
      }
      enqueue(k,t);
    }
    if (s==22)
    {
       n=i;
       break;
    }
  }
  i=0;
  while(k.front!=-1)
  {
     i++;
     while(1>0)
     {
       bstptr t;
       t=dequeue(k);
       if (t==NULL)
       {
         break;
       }
       else
       {
          if (i==n)
          {
            cout<<t->data<<" ";
          }
       }
     }
  }
  cout<<endl;

}
void maxevenpath(queue k)
{
  int max=-1;
  int n;
  int i=0;
  while(i<4)
  {
    int s=0;
    i++;
    while(1>0)
    {
      bstptr t;
      t=dequeue(k);
      if (t==NULL)
      {
          enqueue(k,t);
        break;
      }
      else
      {
        if (t->data%2==0)
        {
          s++;
        }
      }
      enqueue(k,t);
    }
    if (s>max)
    {
      max=s;
       n=i;
    }
  }
  i=0;
  while(k.front!=-1)
  {
     i++;
     while(1>0)
     {
       bstptr t;
       t=dequeue(k);
       if (t==NULL)
       {
         break;
       }
       else
       {
          if (i==n)
          {
            cout<<t->data<<" ";
          }
       }
     }
  }
  cout<<endl;

}
void maxoddpath(queue k)
{
  int max=-1;
  int n;
  int i=0;
  while(i<4)
  {
    int s=0;
    i++;
    while(1>0)
    {
      bstptr t;
      t=dequeue(k);
      if (t==NULL)
      {
          enqueue(k,t);
        break;
      }
      else
      {
        if (t->data%2==1)
        {
          s=s+1;
        }
      }
      enqueue(k,t);
    }
    if (s>max)
    {
      max=s;
       n=i;
    }
  }
  i=0;
  while(k.front!=-1)
  {
     i++;
     while(1>0)
     {
       bstptr t;
       t=dequeue(k);
       if (t==NULL)
       {
         break;
       }
       else
       {
          if (i==n)
          {
            cout<<t->data<<" ";
          }
       }
     }
  }
  cout<<endl;

}
int main()
{	bstptr B;
	B=NULL;
	int n;
	cin>>n;
	while(n>0)
	{
		insert(B,n);
		cin>>n;
	}
    queue q,k;
    allpaths(B,q,k);
    printallpaths(k);
    leftmost(k);
    rightmost(B);
    maximumsumpath(k);
    minimumsumpath(k);
    sum22path(k);
    maxevenpath(k);
    maxoddpath(k);
}
