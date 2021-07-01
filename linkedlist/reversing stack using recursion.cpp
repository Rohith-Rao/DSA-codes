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
void reversestack(struct stack1 &s)
{
    if(s.top==-1)
    {
        return;
    }
    int k;
    k=pop1(s);
    reversestack(s);
    push1(s,k);
}
int main()
{
    struct stack1 s;
    s.size=20;
    for(int i=1;i<=5;i++)
    {
        push1(s,i);
    }
    reversestack(s);
    int g;
    for(int i=1;i<=5;i++)
    {
        g=pop1(s);
        cout<<g<<" ";
    }
}
