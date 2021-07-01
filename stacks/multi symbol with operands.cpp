#include <iostream>
#include <string>
using namespace std;
struct stackchar
{
	int size;
	int top=-1;
	char elements[50];
};
void pushchar(struct stackchar &s,char c)
{
	if(s.top==s.size-1)
	{
		cout<<"no space\n";
	}
	else
	{
		s.elements[++s.top]=c;
	}
}
char popchar(struct stackchar &s)
{
	if(s.top==-1)
	{
		cout<<"empty stack\n";
	}
	else
	{
		return s.elements[s.top--];
	}
}
char peepchar(struct stackchar &s)
{
	if(s.top==-1)
	{
		cout<<"stack empty\n";
	}
	else
		return s.elements[s.top];
}
void checkbalance(string b)
{
	struct stackchar s;
	s.size=20;
	int l=b.length();
	int i=0;
	int flag=0;
	while(i<l)
	{
		if ( b[i]!=')' || b[i]!=']' || b[i]!='}' )
		{
			pushchar(s,b[i]);
		}
		else
		{
			while(2>0)
			{
				char k;
				k=popchar(s);
				if (k=='{' || k=='(' || k=='[')
				{
					if (k==b[i])
					{
						break;
					}
					else 
					{
						flag=1;
						break;
					}
				}
			}

		}
		if (flag==1)
		{
			break;
		}
		i++;
	}
	if (flag==1)
	{
		cout<<"not balanced\n";
	}
	else cout<<"balanced\n";
}
int main()
{
	string b;
	cin>>b;
	checkbalance(b);
}