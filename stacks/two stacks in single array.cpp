#include <iostream>
using namespace std;
struct twostacks
{
	int size;
	int top1;
	int top2;
	int elements[100];
};
int popstack1(struct twostacks &s)
{
	if(s.top1==-1)
	{
		cout<<"stack1 empty\n";
	}
	else
	{
		return s.elements[s.top1--];
	}
}
int popstack2(struct twostacks &s)
{
	if(s.top==s.size)
	{
		cout<<"stack2 empty\n";
	}
	else
	{
		return s.elements[s.top2++];
	}
}
void push1(struct twostacks &s,int n)
{
	if(s.top1+1==s.top2)
	{
		cout<<"stack1 full\n";
	}
	else
	{
		s.top1++;
		s.elements[s.top1]=n;
	}
}
void push2(struct twostacks &s,int n)
{
	if(s.top2-1==s.top1)
	{
		cout<<"stack2 full\n";
	}
	else
	{
		s.top2--;
		s.elements[s.top2]=n;
	}
}
int peep1(struct twostacks &s)
{
	if(s.top1+1==s.top2)
	{
		cout<<"stack1 full\n";
	}
	else
		return s.else[s.top1];
}
int peep2(struct twostacks &s)
{
	if(s.top2-1==s.top1)
	{
		cout<<"stack2 full\n";
	}
	else
	{
		
		return s.elements[s.top2];
	}
}
int main()
{
	struct twostacks s;
	
}