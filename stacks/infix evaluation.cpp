#include <iostream>
#include <string>
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
int solve(int operand2,int operand1,char operato)
{
	switch(operato)
	{
		case '+':
		 return (operand1+operand2);

		case '-':
		return (operand1-operand2);

		case '*':
		return (operand1*operand2);

		case '/':
		return (operand1/operand2);
	}
}
void infixevaluate(string s1)
{
	struct stack1 s;
	s.size=20;
	int l=s1.length();
	for (int i = 0; i < l; i++)
	{
		if (s1[i]>='0' && s1[i]<='9')
		{
			int x=s1[i]-'0';
			push1(s,x);
		}
		else if (s1[i]=='*' || s1[i]=='/')
		{
		    int m=s1[i+1]-'0';
		    push1(s,m);
		    s1[i+1]='b';
			int operand2=pop1(s);
			int operand1=pop1(s);
			int k=solve(operand2,operand1,s1[i]);
			push1(s,k);
		}
	}
	for (int j=l-1;j>=0;j--)
	{
		if (s1[j]=='+'|| s1[j]=='-')
		{
		    int p=pop1(s);
		    int q=pop1(s);
		    int x=solve(p,q,s1[j]);
		    push1(s,x);
		}
	}
	int r=pop1(s);
	cout<<r;
}
int main()
{
    string s1;
    cin>>s1;
    infixevaluate(s1);
}
