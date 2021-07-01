#include <iostream>
using namespace std;
union u
{
	char cno[10];
	int hno;
};
struct st
{
	int roll;
	int tag;
	union u adr;

};

int main()
{
	  st *s[5];
	for (int i = 0; i < 5; i++)
	{
		s[i]=new(st);
		cin>>s[i]->roll;
		cout<<"enter 1 for cno or 2 for hno"<<endl;
		cin>>s[i]->tag;
		if (s[i]->tag==1)
		{
			for(int j=0;j<10;j++)
			{
				cin>>s[i]->adr.cno[j];
			}

		}
		else
		{
			cin>>s[i]->adr.hno;
		}

	}
	for(int i=0;i<5;i++)
	{
		cout<<"roll: "<<s[i]->roll<<endl;
		if(s[i]->tag==1)
		{
			cout<<"adr: ";
			for(int j=0;j<10;j++)
			{
				cout<<s[i]->adr.cno[j];
			}
			cout<<endl;
		}
		else
		{
			cout<<"adr: "<<s[i]->adr.hno<<endl;;
		}

	}
}
