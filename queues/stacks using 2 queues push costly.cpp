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
void pushcc(struct queues &q1,struct queues &q2,int n)
{
  if (q1.front==-1)
  {
    enqueue(q1,n);
  }
  else
  {
    while(q1.front!=-1)
    {
      int k=dequeue(q1);
      enqueue(q2,k);
    }
    enqueue(q1,n);
    while(q2.front!=-1)
    {
      int l=dequeue(q2);
      enqueue(q1,l);
    }

  }
}
int popcc(struct queues &q)
{

    int k=dequeue(q);
    return k;
}
int main()
{
    struct queues q1,q2;
    q1.size=20;
    q2.size=20;
    pushcc(q1,q2,3);
    pushcc(q1,q2,5);
    pushcc(q1,q2,8);
    popcc(q1);
    pushcc(q1,q2,6);
    pushcc(q1,q2,8);
    popcc(q1);
    while(q1.front!=-1)
    {
      int k=dequeue(q1);
      cout<<k<<" ";
    }
}
