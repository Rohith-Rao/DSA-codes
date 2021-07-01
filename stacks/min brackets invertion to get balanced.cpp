#include <iostream>
#include <string>
using namespace std;
int checkinversions(string b)
{
	int l=b.length();
	if (l==0||l%2==1)
	{
		return -1;
	}
	else
	{
		int open=0,inversion=0;
		for (int i = 0; i < l; i++)
		{
			if (b[i]=='{')
			{
				open++;
			}
			else if (b[i]=='}' && open>0)
			{
				open--;
			}
			else
			{
				inversion++;
				open++;
			}
		}
		return inversion+open/2;
	}
}
int main()
{
    string b;
    cin>>b;
    int k;
    k=checkinversions(b);
    if (k==-1)
    {
    	cout<<"can not balance\n";

    }
    else{
    	cout<<k;
    }
}