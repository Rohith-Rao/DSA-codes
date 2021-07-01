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
void pushcc2(struct queues &q,int n)
{
  enqueue(q,n);
}
int popcc2(struct queues &q1,struct queues &q2)
{
  while(q1.front!=q1.rear)
  {
    int k=dequeue(q1);
    enqueue(q2,k);
  }
  int l=dequeue(q1);
  while(q2.front!=-1)
  {
    int t=dequeue(q2);
    enqueue(q1,t);
  }
  return l;
}
int main()
{
  struct queues q1,q2;
  q1.size=20;
  q2.size=20;
  pushcc2(q1,3);
  pushcc2(q1,5);
  pushcc2(q1,8);
  popcc2(q1,q2);
  pushcc2(q1,6);
  pushcc2(q1,2);
  popcc2(q1,q2);
  while(q1.front!=-1)
    {
      int k=dequeue(q1);
      cout<<k<<" ";
    }

}