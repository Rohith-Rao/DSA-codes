#include <iostream>
#include <string>
using namespace std;
struct tnode
{
	int wrd=0;
	tnode *ptr[26]={NULL};
};
typedef tnode *tptr;
void add(tptr T,string s)
{
	tptr t=T;
   int l=s.length();
   for (int i = 0; i < l; i++)
   {
   	  int ind=s[i]-'a';
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
void get_all(tptr T,int &c)
{
    tptr t=T;
    for(int i=0;i<26;i++)
    {
        if(t->ptr[i]!=NULL)
        {
            c++;
            if(t->wrd==0)
            {get_all(t->ptr[i],c);}
        }
    }
}
void find(tptr T,string s,int &c)
{
	tptr t=T;
	int l=s.length();
	int flag=0;
	for (int i = 0; i < l; i++)
	{
		int ind=s[i]-'a';
		if (t->ptr[ind]==NULL)
		{
           c=0;
           flag=1;
           break;
		}
		else
		{
			t=t->ptr[ind];
		}
	}
	if(flag==0)
	{get_all(t,c);}
}
int main()
{
	tptr T;
	T=new(tnode);
	int n;
	cin>>n;
	while(n--)
	{
       string s;
       cin>>s;
       if (s=="add")
       {
       	   cin>>s;
       	   add(T,s);
       }
       else
       {
       	  cin>>s;
       	  int c=0;
       	  find(T,s,c);
       	  cout<<c<<endl;
       }
	}
}
