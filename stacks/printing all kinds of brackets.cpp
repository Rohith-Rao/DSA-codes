#include <iostream>
#include <string>
using namespace std;
void brackets(char s[],int i,int n,int o,int c)
{
	if(c==n)
	{   cout<<s<<endl;
		return;
	}
	else
	{
		if (o>c)
		{
			s[i]='}';
			brackets(s,i+1,n,o,c+1);

		}
		if (o<n)
		{
			s[i]='{';
			brackets(s,i+1,n,o+1,c);
		}
	}
}
int main()
{
	int n,i=0,o=0,c=0;
	cin>>n;
	char s[100];
	brackets(s,i,n,o,c);
}