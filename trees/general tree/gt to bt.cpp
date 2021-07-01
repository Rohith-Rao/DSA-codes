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

int main()
{
  gtptr GT=NULL;
  char k;
  cin>>k;
  construct(GT,k);
}