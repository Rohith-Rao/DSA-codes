#include <iostream>
using namespace std;
struct gtnode
{
  char data;
  gtnode *fc=NULL;
  gtnode *ns=NULL;
};
typedef gtnode *gtptr;
void construct(gtptr &GT,char k,int n)
{
    GT=new(gtnode);
    GT->data=k;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        int x;
        cin>>x;
        if(i==0)
        {
            construct(GT->fc,k,x);
        }
        else
        {
            gtptr t=NULL;
            construct(t,k,x);
            gtptr l=GT->fc;
            while(l->ns!=NULL)
            {
                l=l->ns;
            }
            l->ns=t;
        }
    }

}
void print(gtptr GT)
{
	if (GT==NULL)
	{
		cout<<".";
		return;
	}
		cout<<GT->data;
		print(GT->fc);
		print(GT->ns);
}
int main()
{
	gtptr GT=NULL;
	char k;
	int n;
	cin>>k>>n;
	construct(GT,k,n);
	print(GT);
}
