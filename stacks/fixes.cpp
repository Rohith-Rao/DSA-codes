#include<iostream>
using namespace std;
struct stack1
{
	int t;
	char a[100];
	char top();
	void push(char);
	void pop();
	bool empty();
};
struct stackstr
{
	int t;
	string a[100];
	string top();
	void push(string);
	void pop();
	bool empty();
	int size();
};
struct stack
{
	int t;
	char a[100];
	char top();
	void push(int);
	void pop();
	bool empty();
};
void conv(string s,string a[],int i,int j)
{
	if(i==-1)
	{
		cout<<a[0]<<endl;
		return;
	}
	if(s[i]>='0' && s[i]<='9')
	{
		a[j]=s[i];
		conv(s,a,i-1,j+1);
	}
	else
	{
		a[j-2]=a[j-1]+a[j-2]+s[i];
		conv(s,a,i-1,j-1);
	}
}
void prob1();
void prob2();
void prob3();
void prob4();
void prob5();
void prob6();
int main()
{
    cout<<"enter problem no: ";
    int x;cin>>x;
    switch(x)
    {
        case 1:
        {
            prob1();
            break;
        }
        case 2:
        {
            prob2();
            break;
        }
        case 3:
        {
            prob3();
            break;
        }
        case 4:
        {
            prob4();
            break;
        }
        case 5:
        {
            prob5();
            break;
        }
        case 6:
        {
            prob6();
            break;
        }
    }
    return 0;
}
string stackstr::top()
{
	return a[t];
}
void stackstr::push(string x)
{
	t++;
	a[t]=x;
}
void stackstr::pop()
{
	t--;
}
bool stackstr::empty()
{
	if(t==-1)
		return true;
	return false;
}
int stackstr::size()
{
	return t+1;
}
char stack1::top()
{
	return a[t];
}
void stack1::push(char x)
{
	t++;
	a[t]=x;
}
void stack1::pop()
{
	t--;
}
bool stack1::empty()
{
	if(t==-1)
		return true;
	return false;
}
char stack::top()
{
	return a[t];
}
void stack::push(int x)
{
	t++;
	a[t]=x;
}
void stack::pop()
{
	t--;
}
bool stack::empty()
{
	if(t==-1)
		return true;
	return false;
}
void prob1()
{
    stack1 s;
	s.t=-1;
	string b;
	cin>>b;
	string a="";
	for(int i=b.size()-1;i>=0;i--)
	{
		if(b[i]=='(')
			a+=')';
		else if(b[i]==')')
			a+='(';
		else
			a+=b[i];
	}
	string c="";
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='(')
			s.push(a[i]);
		else if(a[i]==')')
		{
			while(s.top()!='(')
			{
				c+=s.top();
				s.pop();
			}
			s.pop();
			continue;
		}
		else if(a[i]=='+'||a[i]=='-')
		{
			if(!s.empty() && s.top()!='(')
			{
				while(!s.empty()){
				c+=s.top();
				s.pop();}
			}
			s.push(a[i]);
		}
		else if(a[i]=='*'||a[i]=='/')
		{
			if(!s.empty())
			{
				if(!s.empty() && s.top()!='(')
				{
					{
				c+=s.top();
				s.pop();}
				}
			}
			s.push(a[i]);
		}
		else
			c+=a[i];
	}
	while(!s.empty())
	{
		c+=s.top();
		s.pop();
	}
	for(int i=c.size()-1;i>=0;i--)
		cout<<c[i];
	cout<<endl;
}
void prob2()
{
    string a;
	cin>>a;
	stack s;
	s.t=-1;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='(')
			s.push(a[i]);
		else if(a[i]==')')
		{
			while(s.top()!='(')
			{
				cout<<s.top();
				s.pop();
			}
			s.pop();
			continue;
		}
		else if(a[i]=='+'||a[i]=='-')
		{
			if(!s.empty() && s.top()!='(')
			{
				while(!s.empty()){
				cout<<s.top();
				s.pop();}
			}
			s.push(a[i]);
		}
		else if(a[i]=='*'||a[i]=='/')
		{
			if(!s.empty())
			{
				if(s.top()=='*'||s.top()=='/')
				{
					cout<<s.top();
					s.pop();
				}
			}
			s.push(a[i]);
		}
		else
			cout<<a[i];
	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
	cout<<endl;
}
void prob3()
{
    string s;
	cin>>s;
	stackstr st;
	st.t=-1;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			string a(1,s[i]);
			st.push(a);
		}
		else
		{
			string a=st.top();
			st.pop();
			string b=st.top();
			st.pop();
			st.push('('+a+s[i]+b+')');
		}
	}
	cout<<st.top()<<endl;
}
void prob4()
{
    string s,a[100];
	cout<<"enter prefix expression: ";
	cin>>s;
	conv(s,a,s.size()-1,0);
	//return 0;
}
void prob5()
{
    string s;
	cin>>s;
	stackstr st;
	st.t=-1;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			string a(1,s[i]);
			st.push(a);
			//cout<<s[i]<<" "<<s[i]+""<<endl;
		}
		else
		{
			string a=st.top();
			st.pop();
			//cout<<a<<endl;
			string b=st.top();
			st.pop();
			//cout<<b<<endl;
			st.push('('+b+s[i]+a+')');
		}
	}
	cout<<st.top()<<endl;
}
void prob6()
{
    string s;
	cin>>s;
	stackstr st;
	st.t=-1;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0' && s[i]<='9')
			st.push(string(1,s[i]));
		else
		{
			string a=st.top();
			st.pop();
			string b=st.top();
			st.pop();
			st.push(s[i]+b+a);
		}
	}
	cout<<st.top()<<endl;
}
	