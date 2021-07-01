
#include <iostream>
using namespace std;
struct gtnode
{
  int data;
  gtnode *fc;
  gtnode *ns;
};
typedef gtnode *gtptr;
void construct(gtptr &GT,int k)
{
  GT=new(gtnode);
  GT->data=k;
  GT->fc=NULL;
  GT->ns=NULL;
  int c;
  cin>>c;
  if (c!=0)
  {
    construct(GT->fc,c);
  }
  cin>>c;
  if (c!=0)
  {
    construct(GT->ns,c);
  }
}
void dls(gtptr GT,int n,int l,int &t)
{
    if(GT!=NULL && l >=0){
		if (GT->data==n)
	{
		t=1;
	}
	dls(GT->fc,n,l-1,t);
	dls(GT->ns,n,l-1,t);
	}
}
int iddfs(gtptr GT,int n)
{
	for (int i = 0; i < 10; i++)
	{
		int t=0;
		dls(GT,n,i,t);
		if (t==1)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
  gtptr GT=NULL;
  int k;
  cin>>k;
  construct(GT,k);
  int q;
  cin>>q;
  while(q--)
  {
  	int n;
  	cin>>n;
  	k=iddfs(GT,n);
    cout<<k<<endl;
  }
}