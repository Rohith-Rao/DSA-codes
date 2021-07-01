#include <iostream>
using namespace std;
union u{
int in;
char c;
};
int main()
{   cout<<"enter n"<<endl;
int n;
cin>>n;
	union u a[n];
	int tag[n];
	int i;
	for (int i = 0; i < n; i++)
	{
         cout<<"enter 1 for int or 2 for char"<<endl;
         cin>>tag[i];
         if (tag[i]==1)
         {
         	cin>>a[i].in;
         	
         }
         else{
         	cin>>a[i].c;
         	
         }
	}
    for (int i = 0; i < n; i++)
    {
    	/* code */
    	if (tag[i]==1)
        {
            cout<<a[i].in<<" ";
        }
        else
        {
            cout<<a[i].c<<" ";
        }
    }

	return 0;
}
