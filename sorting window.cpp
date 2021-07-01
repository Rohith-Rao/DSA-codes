#include <iostream>
using namespace std;
void sortingwindow()
{
   	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
    int max,min,f,l;
    int x=0,y=n-1;
    while(true)
    {    min=100;
        for(int i=x;i<n;i++)
        {
            if(a[i]<min)
            {
                min=a[i];
            }
        }
        if(a[x]!=min)
        {
            f=x;
            break;
        }
        x++;
        if(x>n-1)
        {
            break;

        }
    }
    while(true)
    {    max=0;
        for(int i=0;i<=y;i++)
        {
            if(a[i]>max)
            {

                max=a[i];
            }
        }
        if(a[y]!=max)
        {
            l=y;
            break;
        }
        y--;
        if(y<0)
        {
            break;
        }
    }
    cout<<f<<" "<<l;
}
int main()
{
	sortingwindow();
}