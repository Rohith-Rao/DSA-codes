#include <iostream>
using namespace std;
struct stackint
{
	int size;
	int top=-1;
	int elements[50];
};
void pushint(struct stackint &s,int n)
{
	if(s.top==s.size-1)
	{
		cout<<"no space\n";
	}
	else
	{
		s.top++;
		s.elements[s.top]=n;
		return;
	}
}
int popint(struct stackint &s)
{
	if(s.top==-1)
	{
		cout<<"stack empty"<<endl;
	}
	else{
		return s.elements[s.top--];
	}
}
void printingdigits(int n)
{
      struct stackint s;
      s.size=10;
      while(n>0)
      {
      	pushint(s,n%10);
      	n=n/10;
      }
      while(s.top>=0)
      {
      	  int k;
      	  k=popint(s);
      	  cout<<k<<" ";
      }
}
int main()
{
	int n;
	cin>>n;
   printingdigits(n);

}
