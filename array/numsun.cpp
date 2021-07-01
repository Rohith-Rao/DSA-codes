#include <iostream>
using namespace std;
struct stackint
{
	int size;
	int top=-1;
	int elements[50];
};
void pushint(struct stackint &s,int n)
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
int popint(struct stackint &s)
{
	if(s.top==-1)
	{
		cout<<"stack empty"<<endl;
	}
	else{
		return s.elements[s.top--];
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







void printingdigits(int n)
{
      struct stackint s;
      s.size=10;
      while(n>0)
      {
      	pushint(s,n%10);
      	n=n/10;
      }
      while(s.top>=0)
      {
      	  int k;
      	  k=popint(s);
      	  cout<<k<<" ";
      }
}








void checkbalance(string b)
{
	struct stackchar s;
	s.size=15;
	int l;
	l=b.length();
	for (int i = 0; i < l; i++)
	{
		if(b[i]=='{')
		{
			pushchar(s,b[i]);
		}
		else if(b[i]=='}')
		{
			popchar(s);
		}
	}
	if(s.top==-1)
	{
		cout<<"balanced\n";
	}
	else cout<<"not balanced\n";
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
void evaluate(string p)
{    struct stackint s;
	s.size=20;
    int l=p.length();
    int i=0;
    while(i<l)
    {
    	if (p[i]=='0') pushint(s,0);
    	else if (p[i]=='1') pushint(s,1);
    	else if (p[i]=='2') pushint(s,2);
    	else if (p[i]=='3') pushint(s,3);
    	else if (p[i]=='4') pushint(s,4);
    	else if (p[i]=='5') pushint(s,5);
    	else if (p[i]=='6') pushint(s,6);
    	else if (p[i]=='7') pushint(s,7);
    	else if (p[i]=='8') pushint(s,8);
    	else if (p[i]=='9') pushint(s,9);
    	else
    	{
    		int operand1,operand2,result;
    		char operato=p[i];
            operand2=popint(s);
            operand1=popint(s);
            result=solve(operand2,operand1,operato);
            pushint(s,result);
    	}
    	i++;
    }
    cout<<s.elements[s.top]<<endl;
}













int checkstrength(char a,char b)
{   if(a==b)
	{
		return 0;
	}
	else if((a=='*' && b=='+') || (a=='*' && b=='-' ) || ( a=='*' &&b=='/') )
	{
        return 1;
	}
	else if((a=='/' && b=='+') || (a=='/' && b=='-'))
	{
		return 1;
	}
	else if((a=='/'&& b=='*'))
	{
		return 0;
	}
	else if((a=='+'&& b=='-'))
	{
		return 1;
	}
	else if((a=='+' && b=='*')|| (a=='+'&& b=='/'))
	{
		return 0;
	}
	else if((a=='-'&& b=='*')|| (a=='-'&& b=='/')|| (a=='-'&& b=='+'))
	{
		return 0;
	}
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
       int k;
       k=checkstrength(ip,x);
       if(k==1)
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
       	   	  h=peepchar(s);
       	   	  g=checkstrength(ip,h);
       	   	  if(g==1)
       	   	  {    pushchar(s,ip);
                   break;
       	   	  }
       	   }
       }

	}
}=
void infixtopostfix(string ip)
{
	int l=ip.length();
	struct stackchar s;
	s.size=20;
	int i=0;
	string ans=" ";
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
		cout<<ans;
}







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
	int s;
	cin>>s;
	switch(s)
	{
		case 1:
           int n;
	       cin>>n;
           printingdigits(n);
           break;
        case 2:
          string b;
           cin>>b;
            checkbalance(b);
            break;
         case 3:
         string p;
	     cin>>p;
	     evaluate(p);
          break;
          case 4:
          string ip;
	     cin>>ip;
	     infixtopostfix(ip);
          break;
          case 5:
          struct twostacks s;


	}
}