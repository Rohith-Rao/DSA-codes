#include <iostream>
#include <string>
using namespace std;
struct tnode
{
	int wrd=0;
	tnode *ptr[36]={NULL};
};
typedef struct tnode *tptr;
void construct(tptr T,string s)
{
	tptr t=T;
	int l=s.length();
	for (int i = 0; i < l; i++)
	{
		int ind;
		if (int(s[i])<97)
		{
			ind=s[i]-'0';
			ind=ind+26;
		}
		else
		{
			ind=s[i]-'a';
		}
		if (t->ptr[ind]==NULL)
		{
			t->ptr[ind]=new(tnode);
			t=t->ptr[ind];
		}
		else
		{
			t=t->ptr[ind];
		}
		if (i==l-1)
		{
			t->wrd=1;
		}
	}
}
void print(tptr T,string s)
{
    if(T->wrd==1)
    {
        cout<<s<<endl;
    }
	for (int i = 0; i < 36; i++)
	{
	    string s2;
		if (T->ptr[i]!=NULL)
		{
			if (i<26)
			{
				s2=s+char(i+97);
			}
			else
			{
				s2=s+char(i-26+48);
			}

			print(T->ptr[i],s2);
		}
	}
}
int main()
{
	tptr T=NULL;
	T=new(tnode);
	string s;
		cin>>s;
	while(s!="#")
	{
		construct(T,s);
		cin>>s;
	}
	s="";
	print(T,s);
}
