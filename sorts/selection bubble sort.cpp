#include <iostream>
using namespace std;
void shift(int a[],int f,int last)
{
	if (f==last)
	{
		return;
	}
	if(a[f]>a[f+1])
	{
		int t;
		t=a[f];
		a[f]=a[f+1];
		a[f+1]=t;
	}
	shift(a,f+1,last);
}
void bubblesort(int a[],int last,int n)
{
	if(last==0)
		{return;}
	int f=0;
	shift(a,f,last);
	bubblesort(a,last-1,n);

}
void selection_sort(int a[], int max, int p, int q)
{
    if (p == q)
    {
        int temp = a[q];
        a[q] = a[max];
        a[max] = temp;

        if (q > 1)
            selection_sort(a, 0, 0, q - 1);
    }
    else
    {
        if (a[max] < a[p + 1])
            max = p + 1;
        selection_sort(a, max, p + 1, q);
    }
}

int main()
{
	int a[6];
	int b[6];
	for(int i=0;i<6;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<6;i++)
    {
        cin>>b[i];
    }
	
	selection_sort(a,0,0,5);
	bubblesort(b,5,6);
    for(int i=0;i<6;i++)
	{
		cout<<a[i]<<" ";
	}
	for(int i=0;i<6;i++)
    {
        cout<<b[i]<<" ";
    }	

}


