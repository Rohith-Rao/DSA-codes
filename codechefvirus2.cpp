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











struct kstacks
{
	int size;
	int min;
	int max;
	int top;
};
void kpush(struct kstacks &s,int elements[],int n)
{
	if (s.top==s.max)
	{
		cout<<"stack full\n";
	}
	else
	{
		s.top++;
		elements[s.top]=n;
	}
}
int kpop(struct kstacks s,int elements[])
{
	if (s.top==s.min-1)
	{
		cout<<"stack empty\n";
	}
	else
	{
		return elements[s.top--];
	}
}










int main()
{   cout<<"6 question\n";
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


    cout<<"9 question\n";
    string b;
	cin>>b;
	checkbalance(b);

    cout<<"10 question\n";
	int n;
	cin>>n;
	int elements[n];
	int k;
	cin>>k;
	struct kstacks s[k];
	for (int i = 0; i < k; i++)
	{   s[i].min=(i*n)/k;
		s[i].max=(i+1)*(n/k)-1;
		s[i].size=n/k;
		s[i].top=(i*n)/k-1;
	}
   //any functions push or pop
}
