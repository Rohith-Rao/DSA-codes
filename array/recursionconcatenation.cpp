#include <iostream>
#include <string>
using namespace std;
char concatenation(string f0,string f1,int x,int n, int k)
{   if(n==0)
      {
          return 'a';
      }
      if(n==1)
      {
          return f1[k-1];
      }
      string c=f0+f1;
      if(n>=2)
      { f0=f1;
        f1=c;
      }
      if(x==n)
        return f1[k-1];
  concatenation(f0,f1,x+1,n,k);
}
int main()
{
  int n,k,x=2;
  cin>>n>>k;
    string f0,f1;
    f0="a";
    f1="bc";
    char p;
  p=concatenation(f0,f1,x,n,k);
  cout<<p;
}