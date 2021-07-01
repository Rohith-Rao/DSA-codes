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
int precedence(char c)
{
	switch(c)
	{
		case '+':
		case '-':
		      return 1;
		case '*':
		case '/':
		     return 2;
	}
}
void reversestring(string &s)
{
	int k=s.length();
	string g="";
	for (int i = k-1; i >=0; i--)
	{
		g=g+s[i];
	}
	s=g;
	return;

}
void optr(struct stackchar &s,char ip,string &ans)
{
	if(s.top==-1)
	{
		pushchar(s,ip);
	}
	else
	{
       char x=peepchar(s);
       int m,n;
       m=precedence(ip);
       n=precedence(x);

       if(m>n)
       {
       	 pushchar(s,ip);
       }
       else
       {
       	   while(1>0)
       	   {
       	   	  char t;
       	   	  t=popchar(s);
       	   	  ans=ans+t;
       	   	  if(s.top==-1)
       	   	  {
       	   	  	pushchar(s,ip);
       	   	  	break;
       	   	  }
       	   	  int g,h;
       	   	  char o;
       	   	  o=peepchar(s);
       	   	  g=precedence(ip);
       	   	  h=precedence(o);
       	   	  if(g>h)
       	   	  {    pushchar(s,ip);
                   break;
       	   	  }
       	   }
       }

	}
}
void infixtoprefix(string ip)
{
	int l=ip.length();
	reversestring(ip);
	struct stackchar s;
	s.size=20;
	int i=0;
	string ans="";
	while(i<l)
		{
            if (ip[i]=='0'|| ip[i]=='1'|| ip[i]=='2'||ip[i]=='3'||ip[i]=='4'||ip[i]=='5'||ip[i]=='6'||ip[i]=='7'||ip[i]=='8'||ip[i]=='9')
            {
            	ans=ans+ip[i];
            }
            else
            {
            	optr(s,ip[i],ans);
            }
            i++;
		}
		reversestring(ans);
		cout<<ans;



}
int main()
{
	string ip;
	cin>>ip;
	infixtoprefix(ip);
}