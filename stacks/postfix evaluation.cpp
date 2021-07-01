#include <iostream>
#include <string>
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
int main()
{
	string p;
	cin>>p;
	evaluate(p);
}
