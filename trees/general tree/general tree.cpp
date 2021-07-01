#include <iostream>
using namespace std;
struct gtnode
{
  char data;
  gtnode *fc;
  gtnode *ns;
};
typedef gtnode *gtptr;
struct queue
{
  int size=25;
  int front=-1;
  int rear=-1;
  gtptr elements[100];
};
void enqueue(struct queue &q,gtptr x)
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
gtptr dequeue(struct queue &q )
{   gtptr t;
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
void construct(gtptr &GT,char k)
{
  GT=new(gtnode);
  GT->data=k;
  GT->fc=NULL;
  GT->ns=NULL;
  char c;
  cin>>c;
  if (c!='.')
  {
    construct(GT->fc,c);
  }
  cin>>c;
  if (c!='.')
  {
    construct(GT->ns,c);
  }
}
void levelorder(gtptr GT, queue &q)
{
    if(GT==NULL)
    {
        return;
    }
    queue qq;
   while(GT!=NULL)
   {
    cout<<GT->data<<" ";
    if (GT->fc!=NULL)
    {
      enqueue(q,GT->fc);
      enqueue(qq,GT->fc);
    }
    GT=GT->ns;
   }
   if(qq.front!=-1)
   {
       cout<<endl;
   }
   while(q.front!=-1)
   {
      gtptr x=dequeue(q);
      levelorder(x,q);
   }
}
int main()
{
  gtptr GT=NULL;
  char k;
  cin>>k;
  construct(GT,k);
  queue q;
  levelorder(GT,q);
}
