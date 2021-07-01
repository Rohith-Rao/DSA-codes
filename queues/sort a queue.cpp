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
void sort(struct queues &q,int n)
{
    int m=-1;
    int x=n;
    int k;
    while(x>0)
    {    
    	for (int i = 1; i <=x; i++)
    	{
    		k=dequeue(q);
    		if (m==-1)
    		{
    			m=k;
    		}
    		else if (k<m)
    		{
    			enqueue(q,m);
    			m=k;
    		}
    		else
    		{
                enqueue(q,k);
    		}
    	}
      enqueue(q,m);
      x--;
    }
    
}
int main()
{
    struct queues q;
    q.size=20;
    int k,n=0;
    cin>>k;
    while(k!=-1)
    {
    	enqueue(q,k);
    	n++;
    	cin>>k;
    }
    for (int i = 0; i < n; i++)
    {
    	k=dequeue(q);
    	cout<<k<<" ";
    	enqueue(q,k);
    }
    sort(q,n);
    for (int i = 0; i < n; i++)
    {
    	k=dequeue(q);
    	cout<<k<<" ";
    	enqueue(q,k);
    }

}