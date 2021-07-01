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
int main()
{
      string b;
      cin>>b;
      checkbalance(b);
}
