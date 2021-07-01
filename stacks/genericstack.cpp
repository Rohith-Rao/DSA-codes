#include <iostream>
using namespace std;
union u
{
	int in;
	char c;
};
struct genericstack
{
	int size;
	int top=-1;
	union u elements[50];
};
void pushgenericstackint(struct genericstack &s,int n)
{
	if (s.top>=s.size-1)
	{
		cout<<"stack is full\n";
	}
	else
		{
		   s.elements[s.top].in=n;

		}
}
void pushgenericstackchar(struct genericstack &s,char n)
{
	if (s.top>=s.size-1)
	{
		cout<<"stack is full\n";
	}
	else
		{
		   s.elements[s.top].c=n;

		}
}
int popgenericstackint(struct genericstack &s )
{
	if(s.top==-1)
	{
		cout<<"stack is empty\n";
	}
	else
	{
       int x=s.elements[s.top].in;
       s.top--;
       return x;
	}
}
char popgenericstackchar(struct genericstack &s )
{
	if(s.top==-1)
	{
		cout<<"stack is empty\n";
	}
	else
	{
       char x=s.elements[s.top].c;
       s.top--;
       return x;
	}
}
int main()
{
	struct genericstack s;
	s.size=20;
	int a;char b;
	int x;char y;
	int tag[s.size];
    	s.top++;
    	cout<<"enter 1 for int or 0 for char\n";
	    cin>>tag[s.top];
	    if (tag[s.top]==1)
	    {
	        cin>>a;
	        pushgenericstackint(s,a);
	    }
	    else
	    {
	    	cin>>b;
	    	pushgenericstackchar(s,b);
	    }
	    if (tag[s.top]==1)
	    {
	    	x=popgenericstackint(s);
	    	cout<<x;
	    }
	    else
        {y=popgenericstackchar(s);
        cout<<y;
        }
}
