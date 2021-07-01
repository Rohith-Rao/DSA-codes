#include <iostream>
using namespace std;
struct queues
{
  int size;
  int front=-1;
  int rear=-1;
  string elements[50];
};
void enqueue(struct queues &q,string x)
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
string dequeue(struct queues &q )
{   string t;
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
void binary(int k)
{
    for(int n=1;n<=k;n++){
            struct queues q;
    q.size=20;
  if(n==0)
  {
      cout<<"0"<<endl;
  }
  else if (n==1)
  {
    cout<<"1"<<endl;
  }
  else
  {
    enqueue(q,"1");
    for (int i = 2; i <= n; i++)
    {    string s;
      s=dequeue(q);
      enqueue(q,s+"0");
      enqueue(q,s+"1");
    }
    string l;
    l=dequeue(q);
    cout<<l<<endl;
  }
    }

}
int main()
{
    int n;
    cin>>n;
    binary(n);
}
