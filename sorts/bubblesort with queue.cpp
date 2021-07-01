#include <iostream>
using namespace std;
struct queues
{
	int size;
	int front=-1;
	int rear=-1;
	int elements[50];
};
void enqueue(struct queues &q,int x)
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
int dequeue(struct queues &q )
{   int t;
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
int max(queues &q,int n)
{
   
  int a,b,max;
  if (n==1)
  {
    a=dequeue(q);
    return a;
  }
  else{
  a=dequeue(q);
  b=dequeue(q);
  if (a>b)
  {
    enqueue(q,b);
    max=a;
  }
  else
  {
    enqueue(q,a);
    max=b;
  }
  n=n-2;
  while(n>0)
  {
     a=dequeue(q);
     if (a>max)
     {
       enqueue(q,max);
       max=a;
     }
     else
     {
        enqueue(q,a);
     }
     n--;
  }
  return max;
 }
}
void bubblesort(queues &q,int n)
{
   if (n==0)
   {
     return ;
   }
   int m;
   m=max(q,n);
   bubblesort(q,n-1);
   enqueue(q,m);

}
int main()
{
  queues q;
  q.size=20;
  int n;
  cin>>n;
  int k;
  for (int i = 0; i < n; i++)
  {
    cin>>k;
    enqueue(q,k);
  }
  bubblesort(q,n);
  for (int i = 0; i < n; i++)
  {
    k=dequeue(q);
    cout<<k<<" ";
  }
}