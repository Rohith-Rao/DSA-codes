#include <iostream>
using namespace std;
struct stack1
{
  int size;
  int top=-1;
  char elementstack[50];
};
void push1(struct stack1 &s,char n)
{
  if(s.top==s.size-1)
  {
    cout<<"no space\n";
  }
  else
  {
    s.top++;
    s.elementstack[s.top]=n;
    return;
  }
}
char pop1(struct stack1 &s)
{
  if(s.top==-1)
  {
    cout<<"stack empty"<<endl;
  }
  else{
    return s.elementstack[s.top--];
  }
}
struct queues
{
  int size;
  int front=-1;
  int rear=-1;
  char elements[50];
};
void enqueue(struct queues &q,char x)
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
char dequeue(struct queues &q )
{   char t;
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
void reversequeue(struct queues &q,int n)
{
    struct stack1 s;
    s.size=20;
    char k;
    for (int i = 0; i < n; i++)
    {
      k=dequeue(q);
      push1(s,k);

    }

    for (int i = 0; i < n; i++)
    {
        k=pop1(s);
        enqueue(q,k);

    }
}
int main()
{
   struct queues q;
   q.size=20;
   char k;
   char a[100];
   int n=0;
   int i=0;
   while(1>0)
   {
      cin>>k;
      if (k=='#')
      {
        break;
      }
      else
      {  a[i]=k;
        i++;
        enqueue(q,k);
        n++;
      }
   }
   reversequeue(q,n);
   int flag=0;
   for (int i = 0; i < n; i++)
   {   k=dequeue(q);
     if (a[i]!=k)
     {
       flag=1;
       break;
     }
   }
   if (flag==0)
   {
     cout<<"palindrome\n";
   }
   else
   {
    cout<<"not palindrome\n";
   }

}