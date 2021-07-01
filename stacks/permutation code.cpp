#include <iostream>
using namespace std;
void swap(int &p,int &q)
{
	int t;
	t=p;
	p=q;
	q=t;
	return;
}
void permutation(char a[],int l,int r)
{
	if (l==r)
	{
		cout<<a<<endl;
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l],a[i]);
			permutation(a,l+1,r);
			swap(a[l],a[i]);
		}
	}
}
int main()
{
	char a[100];
	int n;
	cin>>n;
	cin>>a;
	permutation(a,0,n-1);

}