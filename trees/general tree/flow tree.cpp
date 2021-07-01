//Life is a flow
//Love to   follow
#include <iostream>
#include <algorithm>
using namespace std;
struct gtnode
{
  char data;
  gtnode *fc;
  gtnode *ns;
};
typedef gtnode *gtptr;
void construct(gtptr &GT,char k)
{
  GT=new(gtnode);
  GT->data=k;
  GT->fc=NULL;
  GT->ns=NULL;
  char c;
  cin>>c;
  if (c!='.')
  {
    construct(GT->fc,c);
  }
  cin>>c;
  if (c!='.')
  {
    construct(GT->ns,c);
  }
}
int time(gtptr GT)
{
	gtptr t=GT;
	gtptr x;
	t=t->fc;
	x=t;
	int n=0;
	while(t!=NULL)
	{
		n++;
		t=t->ns;
	}
	int ti[n];
	if (n==0)
	{
		return 0;
	}
	else if (GT->fc->fc==NULL && GT->fc->ns==NULL)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i <n ; i++)
		{
			ti[i]=time(x);
			x=x->ns;
		}
		sort(ti,ti+n);
		int max=ti[0];
		int p=1;
		for (int i = n-1; i >=0;i--)
		{
			ti[i]=ti[i]+p;
			p++;
			if (ti[i]>max)
			{
				max=ti[i];
			}
		}
		return max;
	}
}
int main()
{
  gtptr GT=NULL;
  char k;
  cin>>k;
  construct(GT,k);
  int t=time(GT);
  cout<<t<<endl;
}