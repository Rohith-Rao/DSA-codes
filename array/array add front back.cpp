#include <iostream>
using namespace std;
int main()
{   int n;
    cout<< "enter n"<<endl;
    cin>>n;
	int ar[n];
	int i=0,k=n-1;
	string pos;
	while(1>0)
	{
		cout<<"front or back"<<endl;
		cin>>pos;
		if(pos=="front")
		{
			if (i>k)
			{
				cout<<"no space"<<endl;
				break;
			}
			else
			{
				cin>>ar[i];
				i++;
			}

		}
		if (pos=="back")
		{
			if (i>k)
			{
				cout<<"no space"<<endl;
				break;
			}
			else
			{
				cin>>ar[k];
				k--;
			}
		}

	}
			for (int i = 0; i < n; i++)
		{
			cout<<ar[i]<<" ";
		}
}
