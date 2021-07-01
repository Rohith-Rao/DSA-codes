#include <iostream>
using namespace std;
struct stack1
{
  int size;
  int top=-1;
  int elements[50];
};
void push1(struct stack1 &s,int n)
{
  if(s.top==s.size-1)
  {
    cout<<"no space\n";
  }
  else
  {
    s.top++;
    s.elements[s.top]=n;
    return;
  }
}
int pop1(struct stack1 &s)
{
  if(s.top==-1)
  {
    cout<<"stack empty"<<endl;
  }
  else{
    return s.elements[s.top--];
  }
}
int peep1(struct stack1 s )
{
    if(s.top==-1)
  {
    cout<<"stack empty"<<endl;
  }
  else{
    return s.elements[s.top];
  }
}
void sortstack(struct stack1 &s,int n)
{
   struct stack1 temp;
   temp.size=20;
   int i=0;
   while(1>0)
   {
       int k=pop1(s);
       if (temp.top==-1)
       {
         push1(temp,k);
       }
       else
       {
            int j=peep1(temp);
            if (k>=j)
            {
              push1(temp,k);
            }
            else
            {
                while(1>0)
                {
                   int t=pop1(temp);
                   push1(s,t);
                   if (temp.top==-1)
                   {
                     push1(temp,k);
                     break;
                   }
                   int u=peep1(temp);
                   if (k>=u)
                   {
                      push1(temp,k);
                      break;
                   }

                }
            }
       }
       if (s.top==-1)
       {
         break;
       }
   }
   int q;
   for (int i = 0; i < n; i++)
   {
       q=pop1(temp);
       push1(s,q);
   }
}
int main()
{
  int n;
  cin>>n;
  struct stack1 s;
  s.size=20;
  int k;
  for (int i = 0; i < n; i++)
  {
    cin>>k;
    push1(s,k);
  }
  sortstack(s,n);
  int h;
  for(int i=0;i<n;i++)
  {
      h=pop1(s);
      cout<<h<<" ";
  }
}
