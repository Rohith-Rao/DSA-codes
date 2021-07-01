#include <iostream>
using namespace std;
struct Dequeue
{
	int size;
	int front=-1;
	int rear=-1;
	int elements[50];
};
void enqueue(struct Dequeue &q,int x)
{
    if ((q.rear+1)%q.size==q.front)
    {
    	cout<<"queue full\n";
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
int dequeue(struct Dequeue &q )
{   int t;
   if (q.front==-1)
   {
   	  cout<<"queue empty\n";
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
void push(Dequeue &q,int x)
{
   if ((q.rear+1)%q.size==q.front)
    {
      cout<<"queue full\n";
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
int pop(Dequeue &q)
{
   int t;
   if (q.rear==-1)
   {
      cout<<"queue empty\n";
   }
   else
   {
       if (q.front==q.rear)
       {   t=q.elements[q.rear];
          q.front=-1;
          q.rear=-1;
       }
       else
       {  t=q.elements[q.rear];
          q.rear=(q.rear-1);
          if (q.rear<q.front)
          {
            q.rear=q.rear+q.size-1;
          }
       }
     return t;
   } 
}
int main()
{
  Dequeue q;
  q.size=20;
}