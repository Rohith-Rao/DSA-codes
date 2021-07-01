#include <iostream>
using namespace std;
void mergexy()
{
	int m,n;
	cin>>m>>n;
	int x[m],y[n];
	for (int i = 0; i < m; i++)
	{
	    cin>>x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin>>y[i];
	}
	int z[m],k=0;
	for (int i = 0; i < m; i++)
	{
		if(x[i]!=0)
		{
			z[k]=x[i];
			k++;
		}
	}
	for (int i = 0; i < m; i++)
	{
	    x[i]=0;
	}

	int e=0,f=0,g=0;
	while(e<k&&f<n)
	{
		if(z[e]<y[f])
		{
			x[g]=z[e];
			g++;
			e++;
		}
		else
		{
			x[g]=y[f];
			g++;
			f++;
		}

	}
    for(;e<k;e++)
    {
        x[g]=z[e];
        g++;
    }
	for (; f < n; f++)
	{
		x[g]=y[f];
		g++;
	}
	for (int i = 0; i < m; i++)
	{
		cout<<x[i]<<" ";
	}

}
int main()
{
	mergexy();
}