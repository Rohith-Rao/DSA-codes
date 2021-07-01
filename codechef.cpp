#include <iostream>
#include <string>
using namespace std;
int find(char c,string a)
{
    int x=a.length();
	for (int i = 0; i < x; i++)
	{
		if (a[i]==c)
		{
			return 1;
		}
	}
	return 0;
}
string add(string a,string b)
{
	a=a+b;
	int la=a.length();
	string s="";
	for (int i = 0; i < la; i++)
	{
		int f=find(a[i],s);
		if (f==0)
		{
			s=s+a[i];
		}
	}
	return s;
}
int main()
{
	string a,b;
	//cin>>a>>b;
	//string s=add(a,b);
//	cout<<s;
	string s[100];
	s[5]="abc";
	int x=s[5].find("c");
	s[5][x]='x';
	cout<<s[5]<<endl;
}
