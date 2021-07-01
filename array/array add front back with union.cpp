#include <iostream>
using namespace std;
union u 
{
	int in;
	char c;
};
int main()
{
	int n;
	cout<<"enter n"<<endl;
	cin>>n;
	union u a[n];
	int tag[n];
	int i=0,k=n-1;
	int p;
	while(1>0)
	{
		cout<<"enter 1 for int or 2 for char"<<endl;
		cin>>p;
		
		if(p==1)
		{	if(i>k)
			{
				cout<<"no space"<<endl;
				break;
			}
			else
			{
				
				
				tag[i]=1;
					cin>>a[i].in;
					i++;


			}
		}
		if (p==2)
		{
			if(i>k)
			{
				cout<<"no space"<<endl;
				break;
			}
			else
			{
				
			         tag[k]=k;
					cin>>a[k].c;
					k--;

			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (tag[i]==1)
		{
			cout<<a[i].in<<" ";
		}
		else
		{
			cout<<a[i].c<<" ";
		}
	}
}